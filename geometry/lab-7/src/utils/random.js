import { HEIGHT, WIDTH } from "../app";
import Point from "../classes/Point";

export const getRandomPoint = () => {
  return new Point(
    Math.ceil(Math.random() * WIDTH),
    Math.ceil(Math.random() * HEIGHT)
  );
};