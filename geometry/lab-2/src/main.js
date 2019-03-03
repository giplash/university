import { getRandomSimplePolygon, getRandomPoint, isPointInsidePolygon } from './utils';
import { drawPoint, drawPolygon } from './drawUtils';
import * as PIXI from 'pixi.js';
import $ from 'jquery';

export default () => {
  // const polygon = getRandomSimplePolygon(10);
  const polygon = new PIXI.Polygon([
    new PIXI.Point(100, 100),
    new PIXI.Point(200, 200),
    new PIXI.Point(100, 300),
    new PIXI.Point(100, 100),
  ]);
  drawPolygon(polygon);
  // const point = getRandomPoint();
  const point = new PIXI.Point(150, 200);
  // const point = new PIXI.Point(50, 100);
  drawPoint(point);
  const textResult = isPointInsidePolygon(point, polygon) ?
    'Точка лежит внутри многоугольника'
    : 'Точка не лежит внутри многоугольника';
  $('.answer').text(textResult);
}