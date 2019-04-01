export default class {
  constructor(points) {
    this.points = points;
    this.closedPoints = [ ...points, points[0] ];
  }
}