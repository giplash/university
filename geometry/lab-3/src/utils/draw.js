import { graphics, COLOR, WIDTH, HEIGHT, LINE_THICKNESS } from "../app";
import { getPen, getPit } from "./field";
import * as PIXI from "pixi.js";

export const drawPolygon = (polygon, bgColor = 0xffffff) => {
  graphics.beginFill(bgColor);
  graphics.drawPolygon(polygon);
  graphics.endFill();
};

export const drawPoint = (point, thickness = 4) => {
  graphics.beginFill(COLOR);
  graphics.drawCircle(point.x, point.y, thickness);
  graphics.endFill();
};

export const drawPoints = (arr, thickness = 4) => {
  arr.forEach(point => {
    graphics.beginFill(COLOR);
    graphics.drawCircle(point.x, point.y, thickness);
    graphics.endFill();
  });
};

export const drawSegment = (p1, p2) => {
  graphics.moveTo(p1.x, p1.y);
  graphics.lineTo(p2.x, p2.y);
};

export const clear = () => {
  graphics.clear();
  graphics.lineStyle(LINE_THICKNESS, COLOR);
};

export const drawField = () => {
  const polygon = getPen();
  drawPolygon(polygon);
  const pit = getPit();
  drawPolygon(pit, 0xff00ab);
};