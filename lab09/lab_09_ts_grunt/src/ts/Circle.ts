import { CCanvasControl } from "./Canvas";
import { Point } from "./Point";
import { CShape, ShapeType } from "./Shape";

export class CCircle extends CShape {
    constructor(private position: Point, private radius: number, fillColor: string, outlineColor: string) {
        super(fillColor, outlineColor);
    }

    public getShapeType(): ShapeType {
        return ShapeType.Circle;
    }

    public setX(x: number): void {
        this.position.x = x;
    }

    public getX(): number {
        return this.position.x;
    }

    public setY(y: number): void {
        this.position.y = y;
    }

    public getY(): number {
        return this.position.y;
    }

    public setRadius(radius: number): void {
        this.radius = radius;
    }

    public getRadius(): number {
        return this.radius;
    }

    public getArea(): number {
        return Math.PI * this.radius * this.radius;
    }

    public getPerimeter(): number {
        return 2 * Math.PI * this.radius;
    }

    public draw(canvas: CCanvasControl): void {
        canvas.drawCircle(this.position, this.radius);
    }
}
