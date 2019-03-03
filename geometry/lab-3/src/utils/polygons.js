import {drawPoint} from "./draw";
import {
  getSegmentToRightBorderFromPoint,
  isIntersecting,
  isPointToTheLeftOfLine,
  isPointToTheRightOfLine
} from "./primitives";
import * as PIXI from "pixi.js";
import { HEIGHT, WIDTH } from "../app";
import { uniqBy } from "lodash";

export const isSimplePolygon = polygon => {
  const points = uniqBy(getPolygonPoints(polygon), 'x', 'y');
  for (let i = 0; i < points.length; i++) {
    for (let j = 0; j < points.length; j++) {
      const p1 = points[i];
      const p2 = points[i + 1] || points[0];
      const p3 = points[j];
      const p4 = points[j + 1] || points[0];

      if (p1 === p3 || p2 === p4 || p1 === p4 || p2 === p3) {
        continue;
      }

      if (isIntersecting(p1, p2, p3, p4)) {
        return false;
      }
    }
  }
  return true;
};

export const isPointInsidePolygon = (point, polygon) => {
  const segmentPoints = getSegmentToRightBorderFromPoint(point);
  const polygonPoints = getPolygonPoints(polygon);
  let res = 0;
  let lastIndex = null;
  let isInteresectFirstEdge = false;
  for (let i = 0; i < polygonPoints.length - 1; i++) {
    const p1 = polygonPoints[i];
    const p2 = polygonPoints[i + 1];
    if (isIntersecting(p1, p2, segmentPoints[0], segmentPoints[1])) {
      if (i === 0) {
        isInteresectFirstEdge = true;
      }
      if (lastIndex !== null && (i - 1 === lastIndex)) {
        if (isPointToTheLeftOfLine(p2, segmentPoints[0], segmentPoints[1])
          !== isPointToTheLeftOfLine(polygonPoints[lastIndex], segmentPoints[0], segmentPoints[1])) {
          res--;
        }
      }
      if (i + 1 === polygonPoints.length && isInteresectFirstEdge) {
        if (isPointToTheLeftOfLine(p1, segmentPoints[0], segmentPoints[1])
          !== isPointToTheLeftOfLine(polygonPoints[1], segmentPoints[0], segmentPoints[1])) {
          res--;
        }
      }
      lastIndex = i;
      res++;
    }
  }

  return res % 2 === 1;
};

export const getPolygonPoints = polygon => {
  const points = polygon.points;
  return Array(points.length / 2)
    .fill(null)
    .map((item, i) => new PIXI.Point(points[i * 2], points[i * 2 + 1]));
};

export const getRandomSimplePolygon = n => {
  const points = Array(n)
    .fill(null)
    .map(item => new PIXI.Point(Math.random() * WIDTH, Math.random() * HEIGHT));

  const polygon = new PIXI.Polygon(points);
  polygon.close();

  return isSimplePolygon(getPolygonPoints(polygon)) ? polygon : getRandomSimplePolygon(n);
};

export const getBoundsIndexesOfSector = (point, polygon) => {
  const points = getPolygonPoints(polygon);
  let p = 0;
  let r = points.length - 1;
  let q;
  while (r - p > 1) {
    q = Math.ceil((p + r) / 2);
    if (isPointToTheLeftOfLine(point, points[0], points[q])) {
      p = q;
    } else {
      r = q;
    }
  }
  return [ p, r ];
};

export const isPointInsideConvexPolygon = (point, polygon) => {
  const points = getPolygonPoints(polygon);
  const firstEdge = [ points[0], points[1] ];
  const lastEdge = [ points[points.length - 1], points[0] ];
  if (isPointToTheRightOfLine(point, firstEdge[0], firstEdge[1])
    || isPointToTheRightOfLine(point, lastEdge[0], lastEdge[1])) {
    return false;
  }
  const [ p1, p2 ] = getBoundsIndexesOfSector(point, polygon);
  return !isIntersecting(point, points[0], points[p1], points[p2]);
};

