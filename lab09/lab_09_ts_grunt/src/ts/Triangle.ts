import { CCanvasControl } from "./Canvas";
import { Point } from "./Point";
import { CShape, ShapeType } from "./Shape";

export class CTriangle extends CShape {
    private points: Point[];
    constructor(point0: Point,
                point1: Point,
                point2: Point,
                fillColor: string, outlineColor: string) {
        super(fillColor, outlineColor);
        this.points = [point0, point1, point2];
    }

    public getVertex(vertexNum: number): Point {
        return this.points[vertexNum];
    }

    public setVertex(point: Point, vertexNum: number): void {
        this.points[vertexNum] = point;
    }

    public getArea(): number {
        return 0.5 * Math.abs((this.points[0].x - this.points[2].x) *
        (this.points[1].y - this.points[2].y) - (this.points[1].x - this.points[2].x) *
        (this.points[0].y - this.points[2].y));
    }

    public getPerimeter(): number {
        return this.getVectorLength(this.points[0], this.points[1]) +
               this.getVectorLength(this.points[1], this.points[2]) +
               this.getVectorLength(this.points[2], this.points[0]);
    }

    public draw(canvas: CCanvasControl): void {
        canvas.drawTriangle(this.points);
    }

    public getShapeType(): ShapeType {
        return ShapeType.Triangle;
    }
    private getVectorLength(vertex1: Point, vertex2: Point): number {
        return Math.sqrt((vertex2.x - vertex1.x) * (vertex2.x - vertex1.x)
                        + (vertex2.y - vertex1.y) * (vertex2.y - vertex1.y));
    }

}
