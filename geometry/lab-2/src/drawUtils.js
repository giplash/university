import { graphics, COLOR } from "./app";

export const drawPolygon = polygon => {
  graphics.drawPolygon(polygon);
};

export const drawPoint = (point, thickness = 4) => {
  graphics.beginFill(COLOR);
  graphics.drawCircle(point.x, point.y, thickness);
  graphics.endFill();
};

export const drawSegment = (p1, p2) => {
  graphics.moveTo(p1.x, p1.y);
  graphics.lineTo(p2.x, p2.y);
};