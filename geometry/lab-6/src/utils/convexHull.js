import { isPointToTheLeftOfLine, triangleArea, length } from "./primitives";

export const convexHull = points => {
  const [ min, max ] = getMinMax(points);
  return [...quickhull(points, min, max), ...quickhull(points, max, min)]
};

const getMinMax = points => {
  return points.reduce((acc, item) => {
    const newMin = item.x < acc[0].x ? item : acc[0];
    const newMax = item.x > acc[1].x ? item : acc[1];
    return [ newMin, newMax ];
  }, [points[0], points[0]])
};

const quickhull = (points, min, max) => {
  const leftPoints = getPointsLeftOfLine(min, max, points);
  const maxPoint = getMaxPointFromLine(min, max, leftPoints);

  if (!maxPoint) {
    return [ max ];
  }

  return [...quickhull(leftPoints, min, maxPoint), ...quickhull(leftPoints, maxPoint, max)]
};

const getPointsLeftOfLine = (start, end, points) => {
  return points.filter(point => !!isPointToTheLeftOfLine(point, start, end));
};

const getMaxPointFromLine = (start, end, points) => {
  let maxArea = 0;
  let maxPoint;

  for (const point of points) {
    if (point !== start && point !== end) {
      const area = triangleArea(start, point, end);
      if (area > maxArea) {
        maxArea = area;
        maxPoint = point;
      }
    }
  }
  return maxPoint
};