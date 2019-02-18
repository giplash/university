import * as PIXI from "pixi.js";
import math from "mathjs";

export const drawArrow = (context, fromx, fromy, tox, toy, color = 0x000000, thickness = 2) => {
  const line = new PIXI.Graphics();
  line.lineStyle(thickness, color, 1);
  const headlen = 10;
  const angle = Math.atan2(toy - fromy, tox - fromx);
  line.moveTo(fromx, fromy);
  line.lineTo(tox, toy);
  line.lineTo(tox-headlen*Math.cos(angle-Math.PI/6),toy-headlen*Math.sin(angle-Math.PI/6));
  line.moveTo(tox, toy);
  line.lineTo(tox-headlen*Math.cos(angle+Math.PI/6),toy-headlen*Math.sin(angle+Math.PI/6));
  context.stage.addChild(line);
};

export const drawSegment = (context, fromx, fromy, tox, toy, color = 0x000000, thickness = 2) => {
  const line = new PIXI.Graphics();
  line.lineStyle(thickness, color, 1);
  line.moveTo(fromx, fromy);
  line.lineTo(tox, toy);
  line.moveTo(tox, toy);
  context.stage.addChild(line);
};

export const drawPoint = (context, x, y, color = 0xff0000, thickness = 4) => {
  const circle = new PIXI.Graphics();
  circle.beginFill(color);
  circle.drawCircle(x, y, thickness);
  circle.endFill();
  context.stage.addChild(circle);
};

export const clearView = context => {
  const rectangle = new PIXI.Graphics();
  rectangle.beginFill(0xFFFFFF);
  rectangle.drawRect(0, 0, context.view.width, context.view.height);
  rectangle.endFill();
  context.stage.addChild(rectangle);
};

export const isIntersecting = (
  startPointX1, startPointY1, endPointX1, endPointY1, startPointX2, startPointY2, endPointX2, endPointY2
) => {
  const matrix1 = math.matrix([
    [endPointX1 - startPointX1, endPointY1 - startPointY1],
    [startPointX2 - startPointX1, startPointY2 - startPointY1]
  ]);
  const matrix2 = math.matrix([
    [endPointX1 - startPointX1, endPointY1 - startPointY1],
    [endPointX2 - startPointX1, endPointY2 - startPointY1]
  ]);
  const matrix3 = math.matrix([
    [endPointX2 - startPointX2, endPointY2 - startPointY2],
    [startPointX1 - startPointX2, startPointY1 - startPointY2]
  ]);
  const matrix4 = math.matrix([
    [endPointX2 - startPointX2, endPointY2 - startPointY2],
    [endPointX1 - startPointX2, endPointY1 - startPointY2]
  ]);
  const det1 = math.det(matrix1);
  const det2 = math.det(matrix2);
  const det3 = math.det(matrix3);
  const det4 = math.det(matrix4);
  return Math.sign(det1) !== Math.sign(det2) && Math.sign(det3) !== Math.sign(det4);
};

export const isCoincide = (
  startPointX1, startPointY1, endPointX1, endPointY1, startPointX2, startPointY2, endPointX2, endPointY2
) => {
  const matrix1 = math.matrix([
    [endPointX1 - startPointX1, endPointY1 - startPointY1],
    [startPointX2 - startPointX1, startPointY2 - startPointY1]
  ]);
  const matrix2 = math.matrix([
    [endPointX1 - startPointX1, endPointY1 - startPointY1],
    [endPointX2 - startPointX1, endPointY2 - startPointY1]
  ]);
  const matrix3 = math.matrix([
    [endPointX2 - startPointX2, endPointY2 - startPointY2],
    [startPointX1 - startPointX2, startPointY1 - startPointY2]
  ]);
  const matrix4 = math.matrix([
    [endPointX2 - startPointX2, endPointY2 - startPointY2],
    [endPointX1 - startPointX2, endPointY1 - startPointY2]
  ]);
  const det1 = math.det(matrix1);
  const det2 = math.det(matrix2);
  const det3 = math.det(matrix3);
  const det4 = math.det(matrix4);
  return det1 === det2 && det3 === det4 && det2 === det3 && det1 === 0;
};

const getNotTouchingEdges = (edges, i) => {
  const nextEdge = edges[i + 1] || edges[0];
  const prevEdge = edges[i - 1] || edges[edges.length - 1];
  return edges.filter(item => item !== nextEdge && item !== prevEdge && item !== edges[i]);
};

export const isSimplePolygon = edges => {
  return edges.every((edge, i) => {
    return getNotTouchingEdges(edges, i).every(item => {
      return isIntersecting(item[0][0], item[0][1], item[1][0], item[1][1], edge[0][0], edge[0][1], edge[1][0], edge[1][1]) === false;
    })
  });
};