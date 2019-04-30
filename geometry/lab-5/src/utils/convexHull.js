import { drawPoints } from "./draw";
import { formMatrix, isPointToTheRightOfLine } from "./primitives";

export const convexHull = points => {
  const convexHull = [];
  // bottom right point;
  const p0 = points.reduce((acc, item) => {
    if (item.y > acc.y) {
      return item;
    }
    if (item.y === acc.y) {
      if (item.x > acc.x) {
        return item;
      }
    }
    return acc;
  });
  convexHull.push(p0);

  const p1 = points.reduce((acc, point) => {
    return isPointToTheRightOfLine(point, p0, acc) ? point : acc;
  }, points[0] === p0 ? points[1] : points[0]);
  points = points.filter(point => point !== p1);
  convexHull.push(p1);
  let lastPoint = p1;
  do {
    let index;
    const rightPoint = points.reduce((acc, point, i) => {
      if (isPointToTheRightOfLine(point, lastPoint, acc)) {
        index = i;
        return point;
      } else {
        return acc;
      }
    });
    points.splice(index, 1);
    convexHull.push(rightPoint);
    lastPoint = rightPoint;
  } while (lastPoint !== p0);
  return convexHull;
};
