import $ from 'jquery';
import * as PIXI from "pixi.js";
import math from 'mathjs';

const app = new PIXI.Application({
  width: 600,
  height: 600,
  antialias: true,
  transparent: false,
  resolution: 1,
  backgroundColor: 0xFFFFFF
});

const line = new PIXI.Graphics();
line.lineStyle(2, 0x000000, 1);

const circle = new PIXI.Graphics();

$('.task-1 form').submit(e => {
  e.preventDefault();

  const startPointX = +$('.task-1 .start-point-x').val();
  const startPointY = +$('.task-1 .start-point-y').val();
  const endPointX = +$('.task-1 .end-point-x').val();
  const endPointY = +$('.task-1 .end-point-y').val();
  const otherPointX = +$('.task-1 .other-point-x').val();
  const otherPointY = +$('.task-1 .other-point-y').val();

  line.moveTo(startPointX, startPointY);
  line.lineTo(endPointX, endPointY);
  app.stage.addChild(line);

  circle.beginFill(0xff0000);
  circle.drawCircle(otherPointX, otherPointY, 4);
  circle.endFill();
  app.stage.addChild(circle);

  $('.task-1').append(app.view);

  const matrix = math.matrix([
    [endPointX - startPointX, endPointY - startPointY],
    [otherPointX - startPointX, otherPointY - startPointY]]);
  const det = math.det(matrix);
  let res;
  if (det > 0) {
    res = 'Лежит правее';
  } else if (det < 0) {
    res = 'Лежит левее';
  } else {
    res = 'Лежит на прямой';
  }
  $('.task-1 .answer').text(res);
});