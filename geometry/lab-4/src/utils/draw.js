import * as PIXI from "pixi.js";
import { graphics, COLOR, LINE_THICKNESS, app, HEIGHT, WIDTH } from "../app";

export const drawPolygon = (polygon, bgColor = null) => {
  bgColor && graphics.beginFill(bgColor);
  graphics.drawPolygon(polygon);
  bgColor && graphics.endFill();
};

export const drawPoint = (point, thickness = 4) => {
  graphics.beginFill(COLOR);
  graphics.drawCircle(point.x, point.y, thickness);
  graphics.endFill();
};

export const drawPoints = (arr, drawIndexes = false, thickness = 4) => {
  arr.forEach((point, i) => {
    graphics.beginFill(COLOR);
    graphics.drawCircle(point.x, point.y, thickness);
    if (drawIndexes) {
      const message = new PIXI.Text(i);
      message.style = {fill: "black", fontSize: "16px"};
      message.position.set(point.x + 5, point.y - 8);
      app.stage.addChild(message);
    }
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