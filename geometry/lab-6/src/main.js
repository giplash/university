import { perimeter } from "./utils/polygons";
import $ from 'jquery';
import {
  getBoundsIndexesOfSector,
  getPolygonPoints,
  isPointInsideConvexPolygon,
} from "./utils/polygons";
import { drawPoints, drawPolygon } from "./utils/draw";
import { getRandomPointsInsideConvexPolygon } from "./utils/primitives";
import { convexHull } from './utils/convexHull';
import { clear } from './utils/draw';
import * as PIXI from 'pixi.js';

const SPEED = 2;
const MAX_LENGTH = 900;
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

const generatePoints = amount => {
  const points = getRandomPointsInsideConvexPolygon(POINTS_AMOUNT, mainPolygon);
  const hull = convexHull(points);
  const hullPolygon = new PIXI.Polygon(hull);
  hullPolygon.close();
  if (perimeter(hullPolygon) >= MAX_LENGTH) {
    return generatePoints(amount);
  }
  return points.map(point => {
    const alfa = Math.random() * Math.PI * 2;
    point.alfa = alfa;
    point.vector = [ SPEED * Math.cos(alfa), SPEED * Math.sin(alfa) ];
    return point;
  });
};


const points = generatePoints(POINTS_AMOUNT);

export default () => {
  const interval = setInterval(intervalFun, 32);
};

const intervalFun = () => {
  clear();
  drawPolygon(mainPolygon, 0xFAC550);
  drawPoints(points);
  const hull = convexHull(points);
  const hullPolygon = new PIXI.Polygon(hull);
  hullPolygon.close();
  drawPolygon(hullPolygon);
  const value = perimeter(hullPolygon);
  $('.value').text(value);
  updatePoints(value);
};

const updatePoints = (value) => {
  points.forEach(point => {
    const { vector } = point;
    let newVector = vector;
    const testPoint = new PIXI.Point(point.x + vector[0], point.y + vector[1]);
    if (!isPointInsideConvexPolygon(testPoint, mainPolygon)) {
      const [ p1, p2 ] = getBoundsIndexesOfSector(testPoint, mainPolygon);
      const mainPolygonPoints = getPolygonPoints(mainPolygon);
      const boundVector = [
        mainPolygonPoints[p2].x - mainPolygonPoints[p1].x, mainPolygonPoints[p2].y - mainPolygonPoints[p1].y
      ];
      const factor = 2 * (vector[0] * boundVector[0] + vector[1] * boundVector[1])
        / (boundVector[0] * boundVector[0] + boundVector[1] * boundVector[1]);
      newVector = [ boundVector[0] * factor - vector[0], boundVector[1] * factor - vector[1] ];
    }
    if (value >= MAX_LENGTH) {
      point.alfa = point.alfa + Math.PI;
      newVector = [ SPEED * Math.cos(point.alfa), SPEED * Math.sin(point.alfa) ];
    }
    point.x = point.x + newVector[0];
    point.y = point.y + newVector[1];
    point.vector = newVector;
  })
};