import { Point } from "./Point";

export class CCanvasControl {
    constructor(private context: CanvasRenderingContext2D, private size: Point) {
        this.context.lineWidth = 5;
    }

    public setFillStyle(fillStyle: string): void {
        this.context.fillStyle = fillStyle;
    }

    public setStrokeStyle(strokeStyle: string): void {
        this.context.strokeStyle = strokeStyle;
    }

    public clear(): void {
        this.context.clearRect(0, 0, this.size.x, this.size.y);
    }

    public drawRectangle(position: Point, size: Point): void {
        this.context.strokeRect(position.x, position.y, size.x, size.y);
        this.context.fillRect(position.x, position.y, size.x, size.y);
    }

    public drawTriangle(points: Point[]): void {
        this.context.beginPath();
        this.context.moveTo(points[0].x, points[0].y);
        this.context.lineTo(points[1].x, points[1].y);
        this.context.lineTo(points[2].x, points[2].y);
        this.context.lineTo(points[0].x, points[0].y);
        this.context.stroke();
        this.context.fill();
        this.context.closePath();
    }

    public drawCircle(position: Point, radius: number): void {
        this.context.beginPath();
        this.context.arc(position.x, position.y, radius, 0, 2 * Math.PI);
        this.context.stroke();
        this.context.fill();
        this.context.closePath();
    }
}
