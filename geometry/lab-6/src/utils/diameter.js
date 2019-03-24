import { convexHull } from "./convexHull";
import { length } from './primitives';
import math from 'mathjs';

// export const diameter = (points, isConvexHull = false) => {
//   const hull = isConvexHull ? points.reverse() : convexHull(points);
//   hull.pop();
//   drawPoints(hull, 0xFF0000, true);
//
//   const getPoint = i => {
//     if (i === hull.length) {
//       return hull[0];
//     } if (i > hull.length ) {
//       throw new Error("???????");
//     }
//     return hull[i];
//   };
//
//   const area = (i, j, k) => {
//
//     const point1 = getPoint(i);
//     const point2 = getPoint(j);
//     const point3 = getPoint(k);
//
//     return Math.abs(
//       0.5 * ((point1.x - point3.x) * (point2.y - point3.y) - (point1.y - point3.y) * (point2.x - point3.x))
//     );
//   };
//
//   const getLength = (i, j) => length(getPoint(i), getPoint(j));
//
//   let maxLength = 0;
//   let pair;
//
//   const n = hull.length;
//   let i0 = n;
//   let i = 0;
//   let j = i+1;
//   let j0;
//   while (area(i,i+1,j+1) > area(i,i+1,j)) {
//     j = j+1;
//     j0 = j;
//   }
//   while (j !== i0) {
//     i = i+1;
//     // yield i,j
//
//     console.log([i, j]);
//     if (getLength(i, j) > maxLength) {
//       maxLength = getLength(i, j);
//       pair = [i, j];
//     }
//     while (area(i,i+1,j+1) > area(i,i+1,j)) {
//       j=j+1;
//       if (i !== j0 && j !== i0) {
//         // yield i,j
//         console.log([i, j]);
//         if (getLength(i, j) > maxLength) {
//           maxLength = getLength(i, j);
//           pair = [i, j];
//         }
//       } else {
//         // return;
//         return {
//           value: maxLength,
//           points: [ getPoint(pair[0]), getPoint(pair[1]) ]
//         }
//       }
//     }
//     if (area(j,i+1,j+1) === area(i,i+1,j))
//       if (i !== j0 && j !== i0) {
//         // yield i,j+1
//
//         console.log([i, j + 1]);
//         if (getLength(i, j + 1) > maxLength) {
//           maxLength = getLength(i, j + 1);
//           pair = [i, j + 1];
//         }
//       }
//       else {
//         // yield i+1,j
//
//         console.log([i + 1, j]);
//         if (getLength(i + 1, j) > maxLength) {
//           maxLength = getLength(i + 1, j);
//           pair = [i + 1, j];
//         }
//       }
//   }
//
//   return {
//     value: maxLength,
//     points: [ getPoint(pair[0]), getPoint(pair[1]) ]
//   }
//
//
// };

// export const diameter = (points, isConvexHull = false) => {
//   const hull = isConvexHull ? points.reverse() : convexHull(points);
//   hull.pop();
//   // drawPoints(hull, 0xFF0000, true);
//
//   const getPoint = i => {
//     if (i === hull.length) {
//       return hull[0];
//     } if (i > hull.length ) {
//       // throw new Error("???????");
//       return hull[i - hull.length + 1]
//     }
//     return hull[i];
//   };
//
//   const getLength = (i, j) => Math.abs(length(getPoint(i), getPoint(j)));
//
//   const angle = (n, m) => {
//     const vector1 = [ getPoint(m + 1).x - getPoint(m).x, getPoint(m + 1).y - getPoint(m).y ];
//     const vector2 = [ getPoint(n + 1).x - getPoint(n).x, getPoint(n + 1).y - getPoint(n).y ];
//     const cos = (vector1[0] * vector2[0] + vector1[1] * vector2[1])
//       / (((vector1[0] ** 2 + vector1[1] ** 2) ** 0.5) * ((vector2[0] ** 2 + vector2[1] ** 2) ** 0.5));
//     return Math.acos(cos);
//   };
//
//   let maxLength = 0;
//   let pair;
//
//   let i = 0;
//   let j = 1;
//
//   while (angle(i, j) > Math.PI)
//     j++
//
//   // yield i,j
//   if (getLength(i, j) > maxLength) {
//     maxLength = getLength(i, j);
//     pair = [i, j];
//   }
//
//   let current = i;
//
//   while (j !== hull.length - 1) {
//     if (angle(current, i+1) <= angle(current, j+1)) {
//       j++;
//       current = j;
//     } else {
//       i++;
//       current = i
//     }
//     if (getLength(i, j) > maxLength) {
//       maxLength = getLength(i, j);
//       pair = [i, j];
//     }
//     if (angle(current, i+1) === angle(current, j+1)) {
//       if (getLength(i + 1, j) > maxLength) {
//         maxLength = getLength(i + 1, j);
//         pair = [i + 1, j];
//       }
//       if (getLength(i, j + 1) > maxLength) {
//         maxLength = getLength(i, j + 1);
//         pair = [i, j + 1];
//       }
//       if (getLength(i + 1, j + 1) > maxLength) {
//         maxLength = getLength(i + 1, j + 1);
//         pair = [i + 1, j + 1];
//       }
//
//       if (current === i) {
//         j++
//       }
//       else {
//         i++
//       }
//     }
//
//   }
//
//   return {
//     value: maxLength,
//     points: [ getPoint(pair[0]), getPoint(pair[1]) ]
//   }
//
//
// };

export const diameter2 = (points, isConvexHull = false) => {
  const hull = isConvexHull ? points : convexHull(points);
  hull.pop();
  const getPoint = index => hull[index];
  let resPair;
  let maxLength = 0;
  for (let i = 0; i < hull.length; i++) {
    for (let j = i + 1; j < hull.length; j++) {
      if (length(getPoint(i), getPoint(j)) > maxLength) {
        maxLength = length(getPoint(i), getPoint(j));
        resPair = [i, j];
      }
    }
  }

  return {
    value: maxLength,
    points: [ getPoint(resPair[0]), getPoint(resPair[1]) ]
  }
};