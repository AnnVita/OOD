import { CCanvasControl } from "./Canvas";
import { CCircle } from "./Circle";
import { Point } from "./Point";
import { CRectangle } from "./Rectangle";
import { CShape, ShapeType } from "./Shape";
import { CTriangle } from "./Triangle";

export class CApplication {
    private canvas: CCanvasControl;

    private shape: [CRectangle, CTriangle, CCircle];
    private currentShape: number;

    private shapeSelectElement: HTMLInputElement;

    private colorParametersElement: HTMLElement;
    private rectangleParametersElement: HTMLElement;
    private triangleParametersElement: HTMLElement;
    private circleParametersElement: HTMLElement;

    private fillColorElement: HTMLInputElement;
    private outlineColorElement: HTMLInputElement;

    private xRectangleCoordinateElement: HTMLInputElement;
    private yRectangleCoordinateElement: HTMLInputElement;
    private widthRectangleElement: HTMLInputElement;
    private heightRectangleElement: HTMLInputElement;

    private xCircleCoordinateElement: HTMLInputElement;
    private yCircleCoordinateElement: HTMLInputElement;
    private circleRadiusElement: HTMLInputElement;

    private x0TriangleCoordinateElement: HTMLInputElement;
    private y0TriangleCoordinateElement: HTMLInputElement;
    private x1TriangleCoordinateElement: HTMLInputElement;
    private y1TriangleCoordinateElement: HTMLInputElement;
    private x2TriangleCoordinateElement: HTMLInputElement;
    private y2TriangleCoordinateElement: HTMLInputElement;

    private shapeInfoElement: HTMLElement;

    constructor() {
        this.currentShape = 0;

        this.canvas = this.getCanvas("canvas");

        this.initHtmlElements();
        this.hideElements();
        let shapeInfoRectangle = this.getInputValuesOfRectangle();
        let shapeInfoTriangle = this.getInputValuesOfTriangle();
        let shapeInfoCircle = this.getInputValuesOfCircle();

        this.shape = [new CRectangle(new Point(shapeInfoRectangle[0], shapeInfoRectangle[1]),
                                new Point(shapeInfoRectangle[2], shapeInfoRectangle[3]),
                                this.getInputValuesOfColor()[0], this.getInputValuesOfColor()[1]),
                      new CTriangle(new Point(shapeInfoTriangle[0], shapeInfoTriangle[1]),
                                new Point(shapeInfoTriangle[2], shapeInfoTriangle[3]),
                                new Point(shapeInfoTriangle[4], shapeInfoTriangle[5]),
                                this.getInputValuesOfColor()[0], this.getInputValuesOfColor()[1]),
                      new CCircle(new Point(shapeInfoCircle[0], shapeInfoCircle[1]),
                                200,
                                this.getInputValuesOfColor()[0], this.getInputValuesOfColor()[1]),
                      ];
        this.setShapeSelectOnchange();
        this.setMenuSelectOnchange();
    }

    private getCanvas(id: string): CCanvasControl {
        let canvas: HTMLCanvasElement = <HTMLCanvasElement> document.getElementById(id);
        let context: CanvasRenderingContext2D = canvas.getContext("2d");
        return new CCanvasControl(context, new Point(canvas.width, canvas.height));
    }

    private initHtmlElements(): void {
        this.shapeSelectElement = <HTMLInputElement> document.getElementById("shape-select");

        this.colorParametersElement = document.getElementById("color-parameters");
        this.fillColorElement = <HTMLInputElement> document.getElementById("fill-color");
        this.outlineColorElement = <HTMLInputElement> document.getElementById("border-color");

        this.rectangleParametersElement = document.getElementById("rectangle-parameters");
        this.xRectangleCoordinateElement = <HTMLInputElement> document.getElementById("rectangle-x");
        this.yRectangleCoordinateElement = <HTMLInputElement> document.getElementById("rectangle-y");
        this.widthRectangleElement = <HTMLInputElement> document.getElementById("rectangle-width");
        this.heightRectangleElement = <HTMLInputElement> document.getElementById("rectangle-height");

        this.triangleParametersElement = document.getElementById("triangle-parameters");
        this.x0TriangleCoordinateElement = <HTMLInputElement> document.getElementById("first-x");
        this.y0TriangleCoordinateElement = <HTMLInputElement> document.getElementById("first-y");
        this.x1TriangleCoordinateElement = <HTMLInputElement> document.getElementById("second-x");
        this.y1TriangleCoordinateElement = <HTMLInputElement> document.getElementById("second-y");
        this.x2TriangleCoordinateElement = <HTMLInputElement> document.getElementById("third-x");
        this.y2TriangleCoordinateElement = <HTMLInputElement> document.getElementById("third-y");

        this.circleParametersElement = document.getElementById("circle-parameters");
        this.xCircleCoordinateElement = <HTMLInputElement> document.getElementById("circle-x");
        this.yCircleCoordinateElement = <HTMLInputElement> document.getElementById("circle-y");
        this.circleRadiusElement = <HTMLInputElement> document.getElementById("circle-radius");

        this.shapeInfoElement = <HTMLElement> document.getElementById("shape-info");
    }

    private hideElements(): void {
        this.colorParametersElement.style.display = "none";
        this.rectangleParametersElement.style.display = "none";
        this.triangleParametersElement.style.display = "none";
        this.circleParametersElement.style.display = "none";
    }

    private setShapeSelectOnchange(): void {
        this.shapeSelectElement.addEventListener("change", (event: Event) => {
            let selectedShape: string = this.shapeSelectElement.value;
            this.onchangeShapeRefresh(this.stringToShapeType(selectedShape));
        });
    }

    private setMenuSelectOnchange(): void {
        this.fillColorElement.addEventListener("change", (event: Event) => {
            for (let i = 0; i <= this.shape.length - 1; i++) {
                this.shape[i].setFillColor(this.fillColorElement.value);
            }
            this.redraw();
        });
        this.outlineColorElement.addEventListener("change", (event: Event) => {
            for (let i = 0; i <= this.shape.length - 1; i++) {
                this.shape[i].setOutlineColor(this.fillColorElement.value);
            }
            this.redraw();
        });
        this.xRectangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[0].setX(<number> <any> this.xRectangleCoordinateElement.value);
            this.redraw();
        });
        this.yRectangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[0].setY(<number> <any> this.xRectangleCoordinateElement.value);
            this.redraw();
        });
        this.widthRectangleElement.addEventListener("change", (event: Event) => {
            this.shape[0].setWidth(<number> <any> this.widthRectangleElement.value);
            this.redraw();
        });
        this.heightRectangleElement.addEventListener("change", (event: Event) => {
            this.shape[0].setHeight(<number> <any> this.heightRectangleElement.value);
            this.redraw();
        });
        this.x0TriangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[1].setVertex(new Point(<number> <any> this.x0TriangleCoordinateElement.value,
                                            <number> <any> this.y0TriangleCoordinateElement.value), 0);
            this.redraw();
        });
        this.y0TriangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[1].setVertex(new Point(<number> <any> this.x0TriangleCoordinateElement.value,
                                             <number> <any> this.y0TriangleCoordinateElement.value), 0);
            this.redraw();
        });
        this.x1TriangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[1].setVertex(new Point(<number> <any> this.x1TriangleCoordinateElement.value,
                                            <number> <any> this.x1TriangleCoordinateElement.value), 1);
            this.redraw();
        });
        this.y1TriangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[1].setVertex(new Point(<number> <any> this.x1TriangleCoordinateElement.value,
                                            <number> <any> this.y1TriangleCoordinateElement.value), 1);
            this.redraw();
        });
        this.x2TriangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[1].setVertex(new Point(<number> <any> this.x2TriangleCoordinateElement.value,
                                            <number> <any> this.x2TriangleCoordinateElement.value), 2);
            this.redraw();
        });
        this.y2TriangleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[1].setVertex(new Point(<number> <any> this.x2TriangleCoordinateElement.value,
                                            <number> <any> this.y2TriangleCoordinateElement.value), 2);
            this.redraw();
        });
        this.xCircleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[2].setX(<number> <any> this.xCircleCoordinateElement.value);
            this.redraw();
        });
        this.yCircleCoordinateElement.addEventListener("change", (event: Event) => {
            this.shape[2].setY(<number> <any> this.yCircleCoordinateElement.value);
            this.redraw();
        });
        this.circleRadiusElement.addEventListener("change", (event: Event) => {
            this.shape[2].setRadius(<number> <any> this.circleRadiusElement.value);
            this.redraw();
        });
    }

    private redraw(): void {
        this.canvas.clear();
        this.canvas.setFillStyle(this.shape[this.currentShape].getFillColor());
        this.canvas.setStrokeStyle(this.shape[this.currentShape].getOutlineColor());
        this.shape[this.currentShape].draw(this.canvas);
        this.shapeInfoElement.innerHTML = "I am shape with area: " + this.shape[this.currentShape].getArea() +
                                        "<br>and perimeter: " + this.shape[this.currentShape].getPerimeter();
    }

    private stringToShapeType(value: string): ShapeType {
        switch (value) {
            case ("rectangle"):
            {
                return ShapeType.Rectangle;
            }
            case ("triangle"):
            {
                return ShapeType.Triangle;
            }
            case ("circle"):
            {
                return ShapeType.Circle;
            }
            default:
            {
                throw ("Bad shape type!");
            }
        }
    }

    private onchangeShapeRefresh(shapeType: ShapeType): void {
        switch (shapeType) {
                case ShapeType.Rectangle:
                    {
                        this.currentShape = 0;
                        this.redraw();
                        this.hideElements();
                        this.colorParametersElement.style.display = "block";
                        this.rectangleParametersElement.style.display = "block";
                    }
                    break;
                case ShapeType.Triangle:
                    {
                        this.currentShape = 1;
                        this.redraw();
                        this.hideElements();
                        this.colorParametersElement.style.display = "block";
                        this.triangleParametersElement.style.display = "block";
                    }
                    break;
                case ShapeType.Circle:
                    {
                        this.currentShape = 2;
                        this.redraw();
                        this.hideElements();
                        this.colorParametersElement.style.display = "block";
                        this.circleParametersElement.style.display = "block";
                    }
                    break;
                default:
                    break;
            }
    }

    private getInputValuesOfColor(): string[] {
        return [this.outlineColorElement.value, this.fillColorElement.value];
    }

    private getInputValuesOfRectangle(): number[] {
        return [parseInt(this.xRectangleCoordinateElement.value, 10),
                parseInt(this.yRectangleCoordinateElement.value, 10),
                parseInt(this.widthRectangleElement.value, 10),
                parseInt(this.heightRectangleElement.value, 10)];
    }

    private getInputValuesOfTriangle(): number[] {
        return [parseInt(this.x0TriangleCoordinateElement.value, 10),
                parseInt(this.y0TriangleCoordinateElement.value, 10),
                parseInt(this.x1TriangleCoordinateElement.value, 10),
                parseInt(this.y1TriangleCoordinateElement.value, 10),
                parseInt(this.x2TriangleCoordinateElement.value, 10),
                parseInt(this.y2TriangleCoordinateElement.value, 10)];
    }

    private getInputValuesOfCircle(): number[] {
        return [parseInt(this.xCircleCoordinateElement.value, 10),
                parseInt(this.yCircleCoordinateElement.value, 10),
                parseInt(this.circleRadiusElement.value, 10)];
    }
}
