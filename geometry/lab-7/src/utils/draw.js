import { HEIGHT, WIDTH, ctx } from '../app';

export function drawLine(point1, point2) {
  ctx.moveTo(point1.x, point1.y);
  ctx.lineTo(point2.x, point2.y);
  ctx.stroke();
}

export function drawPoint(point, width = 8){
  ctx.beginPath();
  ctx.arc(point.x, point.y, width / 2, 0, 2 * Math.PI, true);
  ctx.fill();
}

export function clear() {
  ctx.clearRect(0, 0, WIDTH, HEIGHT);
}

export function drawPolygon(polygon) {
  for (let i = 0; i < polygon.closedPoints.length - 1; i++) {
    drawLine(polygon.closedPoints[i], polygon.closedPoints[i + 1]);
  }
}

export function drawPoints(points, width = 8, flag = false) {
  points.forEach((point, i) => {
    drawPoint(point, width);
    flag && ctx.fillText(i, point.x - 10, point.y);
  })
}