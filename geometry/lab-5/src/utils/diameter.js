import { convexHull } from "./convexHull";
import { length } from './primitives';

export const diameter = (points, isConvexHull = false) => {
  const hull = isConvexHull ? points : convexHull(points);

  const area = (i, j, k) => {

    const point1 = hull[i];
    const point2 = hull[j];
    const point3 = hull[k];

    return Math.abs(
      0.5 * ((point1.x - point3.x) * (point2.y - point3.y) - (point1.y - point3.y) * (point2.x - point3.x))
    );
  };

  let result = [];
  let max = -1;
  let k = hull.length - 1;
  let i = 1;
  let temp = 0;

  while (area(k - 1, 0, i + 1) > area(k - 1, 0, i)) {
    i = i + 1;
  }

  let start = i;
  let j = 0;

  while (temp < k) {
    temp = start;
    while (area(j, j + 1 , temp + 1) >= area(j, j + 1, temp)) {
      temp = temp + 1;
      if (temp >= k) {
        break;
      }
    }
    let end = temp;
    for (let a = start; a < end + 1; a++) {
      if (length(hull[a], hull[j]) > max) {
        max = length(hull[a], hull[j]);
        result = [a, j];
      }
    }
    j = j + 1;

    start = end
  }

  return [ hull[result[0]], hull[result[1]] ];

};

export const slowDiameter = (points, isConvexHull = false) => {
  const hull = isConvexHull ? points : convexHull(points);
  let resPair;
  let maxLength = 0;
  for (let i = 0; i < hull.length; i++) {
    for (let j = i + 1; j < hull.length; j++) {
      if (length(hull[i], hull[j]) > maxLength) {
        maxLength = length(hull[i], hull[j]);
        resPair = [i, j];
      }
    }
  }

  return [ hull[resPair[0]], hull[resPair[1]] ];
};
