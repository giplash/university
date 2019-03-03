import { generateSheeps, updateSheeps } from './utils/field';
import { drawPoint, drawField, clear } from './utils/draw';

const UPDATE_TIME  = 16;
const SHEEPS_AMOUNT = 10;

export default () => {
  setInterval(intervalFun, UPDATE_TIME);
}

let sheeps = generateSheeps(SHEEPS_AMOUNT);

const intervalFun = () =>  {
  clear();
  drawField();
  sheeps.forEach(item => drawPoint(item.point));
  sheeps = updateSheeps(sheeps);
};