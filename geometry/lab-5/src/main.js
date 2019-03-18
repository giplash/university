import { diameter2 } from "./utils/diameter";
import $ from 'jquery';
import {
  getBoundsIndexesOfSector,
  getPolygonPoints,
  isPointInsideConvexPolygon,
} from "./utils/polygons";
import { drawPoints, drawPolygon, drawSegment } from "./utils/draw";
import { getRandomPointsInsideConvexPolygon } from "./utils/primitives";
import { convexHull } from './utils/convexHull';
import { clear } from './utils/draw';
import * as PIXI from 'pixi.js';

const SPEED = 2;
const MAX_LENGTH = 400;
const POINTS_AMOUNT = 6;

const mainPolygon = new PIXI.Polygon([
  new PIXI.Point(300, 50),
  new PIXI.Point(50, 200),
  new PIXI.Point(50, 400),
  new PIXI.Point(300, 500),
  new PIXI.Point(500, 400),
  new PIXI.Point(500, 200),
  new PIXI.Point(300, 50),
]);


let points = getRandomPointsInsideConvexPolygon(POINTS_AMOUNT, mainPolygon).map(point => {
  const alfa = Math.random() * Math.PI * 2;
  point.vector = [ SPEED * Math.cos(alfa), SPEED * Math.sin(alfa) ];
  return point;
});

let interval;

export default () => {
  interval = setInterval(intervalFun, 32);
};

const intervalFun = () => {
  clear();
  drawPolygon(mainPolygon, 0xFAC550);
  drawPoints(points);
  const hull = convexHull(points);
  drawPolygon(new PIXI.Polygon(hull));
  const { value, points: resPoints } = diameter2(hull, true);
  $('.value').text(value);
  drawSegment(resPoints[0], resPoints[1], 0xFF0000);
  if (value > MAX_LENGTH) {
    clearInterval(interval);
    return;
  }
  updatePoints();
};

const updatePoints = () => {
  points.forEach(point => {
    const { vector } = point;
    const newPoint = new PIXI.Point(point.x + vector[0], point.y + vector[1]);
    let newVector = vector;
    if (!isPointInsideConvexPolygon(newPoint, mainPolygon)) {
      const [ p1, p2 ] = getBoundsIndexesOfSector(newPoint, mainPolygon);
      const mainPolygonPoints = getPolygonPoints(mainPolygon);
      const boundVector = [
        mainPolygonPoints[p2].x - mainPolygonPoints[p1].x, mainPolygonPoints[p2].y - mainPolygonPoints[p1].y
      ];
      const factor = 2 * (vector[0] * boundVector[0] + vector[1] * boundVector[1])
        / (boundVector[0] * boundVector[0] + boundVector[1] * boundVector[1]);
      newVector = [ boundVector[0] * factor - vector[0], boundVector[1] * factor - vector[1] ];
      newPoint.x = point.x + newVector[0];
      newPoint.y = point.y + newVector[1];
    }
    point.x = newPoint.x;
    point.y = newPoint.y;
    point.vector = newVector;
  })
};