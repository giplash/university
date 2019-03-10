import * as PIXI from "pixi.js";
import math from "mathjs";
import { WIDTH, HEIGHT } from "../app";

export const formMatrix = (p1, p2, p3) => {
  return math.matrix([
    [ p3.x - p2.x, p3.y - p2.y ],
    [ p1.x - p2.x, p1.y - p2.y ]
  ]);
};

export const isIntersecting = (startPoint1, endPoint1, startPoint2, endPoint2) => {
  const det1 = math.det(formMatrix(startPoint1, startPoint2, endPoint2));
  const det2 = math.det(formMatrix(endPoint1, startPoint2, endPoint2));
  const det3 = math.det(formMatrix(startPoint2, startPoint1, endPoint1));
  const det4 = math.det(formMatrix(endPoint2, startPoint1, endPoint1));
  return (det1 * det2 <= 0 && det3 * det4 <= 0);
};

export const isCoincide = (startPoint1, endPoint1, startPoint2, endPoint2) => {
  const det1 = math.det(formMatrix(startPoint1, startPoint2, endPoint2));
  const det2 = math.det(formMatrix(endPoint1, startPoint2, endPoint2));
  const det3 = math.det(formMatrix(startPoint2, startPoint1, endPoint1));
  const det4 = math.det(formMatrix(endPoint2, startPoint1, endPoint1));
  return det1 === det2 && det3 === det4 && det2 === det3 && det1 === 0;
};

export const pointsWithoutDuplicates = points => {
  return points.filter((item, index, self) => self.indexOf(item) === index);
};

export const getRandomPoint = () => {
  return new PIXI.Point(Math.random() * WIDTH, Math.random() * HEIGHT);
};

export const getRandomPoints = n => {
  return Array(n).fill(null).map(item => new PIXI.Point(Math.random() * WIDTH, Math.random() * HEIGHT));
};

export const getSegmentToRightBorderFromPoint = point => {
  return [
    point,
    new PIXI.Point(WIDTH, point.y)
  ]
};

export const isPointToTheRightOfLine = (point, p1, p2) => {
  return math.det(formMatrix(point, p1, p2)) > 0;
};

export const isPointToTheLeftOfLine = (point, p1, p2) => {
  return math.det(formMatrix(point, p1, p2)) < 0;
};
