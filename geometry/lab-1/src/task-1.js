import $ from 'jquery';
import * as PIXI from "pixi.js";
import { drawArrow, drawPoint, clearView } from "./utils";
import math from 'mathjs';

const WIDTH = 400;
const HEIGHT = 400;
const app = new PIXI.Application({
  width: WIDTH,
  height: HEIGHT,
  antialias: true,
  transparent: false,
  resolution: 1,
  backgroundColor: 0xFFFFFF
});

$('.task-1').append(app.view);

$('.task-1 form').submit(e => {
  e.preventDefault();
  main();
});

const main = () => {
  clearView(app);

  const startPointX = +$('.task-1 .start-point-x').val();
  const startPointY = +$('.task-1 .start-point-y').val();
  const endPointX = +$('.task-1 .end-point-x').val();
  const endPointY = +$('.task-1 .end-point-y').val();
  const otherPointX = +$('.task-1 .other-point-x').val();
  const otherPointY = +$('.task-1 .other-point-y').val();
  drawArrow(app, startPointX, startPointY, endPointX, endPointY);
  drawPoint(app, otherPointX, otherPointY);

  const matrix = math.matrix([
    [endPointX - startPointX, endPointY - startPointY],
    [otherPointX - startPointX, otherPointY - startPointY]
  ]);
  const det = math.det(matrix);
  const res = det > 0 ? 'Лежит правее' : det < 0 ? 'Лежит левее' : 'Лежит на прямой';
  $('.task-1 .answer').text(res);
};

main();

