import * as PIXI from "pixi.js";
import { getRandomPoint } from "./primitives";
import {
  getBoundsIndexesOfSector,
  getPolygonPoints,
  isPointInsideConvexPolygon,
  isPointInsidePolygon
} from "./polygons";

export const getPit = () => {
  const polygon = new PIXI.Polygon([
    new PIXI.Point(300, 200),
    new PIXI.Point(150, 220),
    new PIXI.Point(200, 300),
    new PIXI.Point(400, 300),
    new PIXI.Point(300, 250)
  ]);
  polygon.close();
  return polygon;
};

export const getPen = () => {
  const polygon = new PIXI.Polygon([
    new PIXI.Point(100, 50),
    new PIXI.Point(50, 100),
    new PIXI.Point(50, 150),
    new PIXI.Point(80, 550),
    new PIXI.Point(550, 500),
    new PIXI.Point(545, 450),
    new PIXI.Point(250, 50)
  ]);
  polygon.close();
  return polygon;
};

export const PEN = getPen();
export const PIT = getPit();
export const SPEED = 3;

export const generatePointInsidePen = () => {
  const point = getRandomPoint();
  if (isPointInsideConvexPolygon(point, PEN) && !isPointInsidePolygon(point, PIT)) {
    return point;
  }
  return generatePointInsidePen();
};

export const generateSheeps = n => {
  const res = Array(n).fill(null).map(item => {
    const point = generatePointInsidePen();
    const alfa = Math.random() * Math.PI * 2;
    return {
      point,
      vector: [ SPEED * Math.cos(alfa), SPEED * Math.sin(alfa) ]
    }
  });
  return res;
};

export const updateSheeps = sheeps => {
  return sheeps
    .map(sheep => {
      const { point, vector } = sheep;
      const newPoint = new PIXI.Point(point.x + vector[0], point.y + vector[1]);
      let newVector = vector;
      if (!isPointInsideConvexPolygon(newPoint, PEN)) {
        const [ p1, p2 ] = getBoundsIndexesOfSector(newPoint, PEN);
        const penPoints = getPolygonPoints(PEN);
        const boundVector = [ penPoints[p2].x - penPoints[p1].x, penPoints[p2].y - penPoints[p1].y ];
        const factor = 2 * (vector[0] * boundVector[0] + vector[1] * boundVector[1])
          / (boundVector[0] * boundVector[0] + boundVector[1] * boundVector[1]);
        newVector = [ boundVector[0] * factor - vector[0], boundVector[1] * factor - vector[1] ];
        newPoint.x = point.x + newVector[0];
        newPoint.y = point.y + newVector[1];
      }
      return {
        point: newPoint,
        vector: newVector
      }
    })
    .filter(sheep => {
      const { point } = sheep;
      return !isPointInsidePolygon(point, PIT);
    });
};