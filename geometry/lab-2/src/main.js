import { getRandomSimplePolygon, getRandomPoint, isPointInsidePolygon } from './utils';
import { drawPoint, drawPolygon } from './drawUtils';
import $ from 'jquery';

export default () => {
  const polygon = getRandomSimplePolygon(10);
  drawPolygon(polygon);
  const point = getRandomPoint();
  drawPoint(point);
  const textResult = isPointInsidePolygon(point, polygon) ?
    'Точка лежит внутри многоугольника'
    : 'Точка не лежит внутри многоугольника';
  $('.answer').text(textResult);
}