import math from 'mathjs';

function formMatrix(p1, p2, p3) {
  return [
    [p3.x - p2.x, p3.y - p2.y],
    [p1.x - p2.x, p1.y - p2.y]
  ];
}

export function length(point1, point2) {
  return ((point2.x - point1.x) ** 2 + (point2.y - point1.y) ** 2) ** 0.5;
}

export function getPosition(point, beginLine, endLine) {
  return math.det(formMatrix(point, beginLine, endLine));
}

export function isPointToTheRight(point, p1, p2) {
  return getPosition(point, p1, p2) > 0;
}

export function isIntersect(p1, p2, p3, p4) {
  const d1 =  math.det(formMatrix(p1, p3, p4));
  const d2 =  math.det(formMatrix(p2, p3, p4));
  const d3 =  math.det(formMatrix(p3, p1, p2));
  const d4 =  math.det(formMatrix(p4, p1, p2));

  return d1 * d2 <= 0 && d3 * d4 <= 0;
}