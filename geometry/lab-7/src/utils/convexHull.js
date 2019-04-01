import { isPointToTheRight } from "./helpers";

export const dynamicConvexHull = (existedCH, newPoint) => {
  if (!existedCH.length) {
    return [ newPoint ];
  }
  if (existedCH.length === 1) {
    return [ existedCH[0], newPoint ];
  }
  if (existedCH.length === 2) {
    if (isPointToTheRight(newPoint, existedCH[0], existedCH[1])) {
      return [ newPoint, existedCH[1], existedCH[0] ];
    } else {
      return [ ...existedCH, newPoint ];
    }
  }
  const [ firstPoint, secondPoint ] = existedCH;
  const lastPoint = existedCH[existedCH.length - 1];
  const closedExistedCH = [ ...existedCH, firstPoint ];

  if (isPointToTheRight(newPoint, firstPoint, secondPoint)
      && isPointToTheRight(newPoint, lastPoint, firstPoint)) {
    let i = closedExistedCH.length - 1;
    while (isPointToTheRight(newPoint, closedExistedCH[i - 1], closedExistedCH[i])) {
      i--;
    }
    let k = 0;
    while (isPointToTheRight(newPoint, closedExistedCH[k], closedExistedCH[k + 1])) {
      k++;
    }
    return [ newPoint, ...closedExistedCH.slice(k, i + 1)];
  }
  for (let i = 0; i < closedExistedCH.length - 1; i++) {
    if (isPointToTheRight(newPoint, closedExistedCH[i], closedExistedCH[i + 1])) {
      let k = i + 1;
      if (i !== closedExistedCH.length - 2) {
        while (k < closedExistedCH.length - 1 && isPointToTheRight(newPoint, closedExistedCH[k], closedExistedCH[k + 1])) {
          k++;
        }
      }
      return [ ...closedExistedCH.slice(0, i + 1), newPoint, ...closedExistedCH.slice(k, -1) ]
    }
  }
  return closedExistedCH.slice(0, -1);
};