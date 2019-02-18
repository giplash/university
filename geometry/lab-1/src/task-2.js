import $ from 'jquery';
import * as PIXI from "pixi.js";
import {drawArrow, drawPoint, clearView, isIntersecting, isCoincide} from "./utils";
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

$('.task-2').append(app.view);

$('.task-2 form').submit(e => {
  e.preventDefault();
  main();
});

const main = () => {
  clearView(app);

  const startPointX1 = +$('.task-2 .start-point-x1').val();
  const startPointY1 = +$('.task-2 .start-point-y1').val();
  const endPointX1 = +$('.task-2 .end-point-x1').val();
  const endPointY1 = +$('.task-2 .end-point-y1').val();

  const startPointX2 = +$('.task-2 .start-point-x2').val();
  const startPointY2 = +$('.task-2 .start-point-y2').val();
  const endPointX2 = +$('.task-2 .end-point-x2').val();
  const endPointY2 = +$('.task-2 .end-point-y2').val();
  drawArrow(app, startPointX1, startPointY1, endPointX1, endPointY1);
  drawArrow(app, startPointX2, startPointY2, endPointX2, endPointY2);


  const res = isIntersecting(
    startPointX1, startPointY1, endPointX1, endPointY1, startPointX2, startPointY2, endPointX2, endPointY2
  ) ? 'Пересекаются' : isCoincide(
    startPointX1, startPointY1, endPointX1, endPointY1, startPointX2, startPointY2, endPointX2, endPointY2
  ) ? 'Совпадают' : 'Не пересекаются';
  $('.task-2 .answer').text(res);
};

main();

