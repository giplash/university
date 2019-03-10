import * as PIXI from 'pixi.js';
import { clear, drawPoints, drawPolygon } from './draw';
import { formMatrix, isPointToTheLeftOfLine } from "./primitives";
import math from 'mathjs';

const copy = obj => JSON.parse(JSON.stringify(obj));

const changes = [];

const drawChanges = (points) => {
  let index = 0;
  const intervalFun = () => {
    if (index > changes.length) {
      clearInterval(interval);
      return;
    }
    clear();
    drawPoints(points);
    const polygon = new PIXI.Polygon((changes[index] || changes[index - 1])
      .map(point => new PIXI.Point(point.x, point.y)));
    if (index === changes.length) {
      polygon.close();
    }
    drawPolygon(polygon);
    index++;
  };
  const interval = setInterval(intervalFun, 500);
};

export const grahamScan = points => {
  drawPoints(points);
  const topPoint = points.reduce((acc, item) => item.y < acc.y ? item : acc);
  const pointsWithoutTop = points.filter(item => item !== topPoint);
  const sortedPointsWithoutTop = pointsWithoutTop.sort((a, b) => {
    return math.det(formMatrix(topPoint, a, b)) - math.det(formMatrix(topPoint, b, a));
  });
  const P = [ topPoint, ...sortedPointsWithoutTop ];
  const S = [ P[0], P[1] ];
  const nextToTop = () => S[S.length - 2] || top();
  const top = () => S[S.length - 1];
  changes.push(copy(S));
  for (let i = 1; i < sortedPointsWithoutTop.length; i++) {
    while (isPointToTheLeftOfLine(top(), nextToTop(), sortedPointsWithoutTop[i])) {
      S.push(sortedPointsWithoutTop[i]);
      changes.push(copy(S));
      S.pop();
      changes.push(copy(S));
      S.pop();
      changes.push(copy(S));
    }
    S.push(sortedPointsWithoutTop[i]);
    changes.push(copy(S));
  }
  drawChanges(points);
};