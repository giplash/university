export default class {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  equalsTo(point) {
    return this.x === point.x && this.y === point.y;
  }
}