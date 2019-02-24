import * as PIXI from "pixi.js";
import math from "mathjs";
import { uniqBy } from 'lodash';
import { WIDTH, HEIGHT } from "./app";

export const formMatrix = (p1, p2, p3) => {
  return math.matrix([
    [p3.x - p2.x, p3.y - p2.y],
    [p1.x - p2.x, p1.y - p2.y]
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

export const getPolygonPoints = polygon => {
  const points = polygon.points;
  return Array(points.length / 2)
    .fill(null)
    .map((item, i) => new PIXI.Point(points[i * 2], points[i * 2 + 1]));
};

export const pointsWithoutDuplicates = points => {
  return points.filter((item, index, self) => self.indexOf(item) === index);
};

export const isSimplePolygon = points => {
  points = uniqBy(points, 'x', 'y');
  for (let i = 0; i < points.length; i++) {
    for (let j = 0; j < points.length; j++) {
      const p1 = points[i];
      const p2 = points[i + 1] || points[0];
      const p3 = points[j];
      const p4 = points[j + 1] || points[0];

      if (p1 === p3 || p2 === p4 || p1 === p4 || p2 === p3) {
        continue;
      }

      if (isIntersecting(p1, p2, p3, p4)) {
        return false;
      }
    }
  }
  return true;
};

export const getRandomSimplePolygon = n => {
  const points = Array(n)
    .fill(null)
    .map(item => new PIXI.Point(Math.random() * WIDTH, Math.random() * HEIGHT));

  const polygon = new PIXI.Polygon(points);
  polygon.close();

  return isSimplePolygon(getPolygonPoints(polygon)) ? polygon : getRandomSimplePolygon(n);
};

export const getRandomPoint = () => {
  return new PIXI.Point(Math.random() * WIDTH, Math.random() * HEIGHT);
};

export const getSegmentToRightBorderFromPoint = point => {
  return [
    point,
    new PIXI.Point(WIDTH, point.y)
  ]
};

export const isPointInsidePolygon = (point, polygon) => {
  const segmentPoints = getSegmentToRightBorderFromPoint(point);
  const polygonPoints = getPolygonPoints(polygon);
  let res = 0;
  for (let i = 0; i < polygonPoints.length - 1; i++) {
    const p1 = polygonPoints[i];
    const p2 = polygonPoints[i + 1];
    if (isIntersecting(p1, p2, segmentPoints[0], segmentPoints[1])) {
      res++;
    }
  }

  return res % 2 === 1;
};