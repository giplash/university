import { getRandomPoints } from "./utils/primitives";
import { grahamScan } from './utils/grahamScan';

export default () => {
  const points = getRandomPoints(20);
  grahamScan(points);
};