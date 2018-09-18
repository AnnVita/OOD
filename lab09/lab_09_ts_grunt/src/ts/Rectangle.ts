import { CCanvasControl } from "./Canvas";
import { Point } from "./Point";
import { CShape, ShapeType } from "./Shape";

export class CRectangle extends CShape {
    constructor(private position: Point,
                private size: Point,
                fillColor: string,
                outlineColor: string) {
        super(fillColor, outlineColor);
    }

    public draw(canvas: CCanvasControl): void {
        canvas.drawRectangle(this.position, this.size);
    }

    public getShapeType(): ShapeType {
        return ShapeType.Rectangle;
    }

    public setPosition(position: Point): void {
        this.position = position;
    }

    public getPosition(): Point {
        return this.position;
    }

    public setSize(size: Point): void {
        this.position = size;
    }

    public getSize(): Point {
        return this.size;
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

    public setWidth(width: number) {
        this.size.x = width;
    }

    public getWidth(): number {
        return this.size.x;
    }

    public setHeight(height: number): void {
        this.size.y = height;
    }

    public getHeight(): number {
        return this.size.y;
    }

    public getArea(): number {
        return this.size.x * this.size.y;
    }

    public getPerimeter(): number {
        return 2 * (this.size.x + this.size.y);
    }
}
