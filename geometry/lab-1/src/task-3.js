import $ from 'jquery';
import * as PIXI from "pixi.js";
import { clearView, drawSegment, isSimplePolygon } from "./utils";

const WIDTH = 400;
const HEIGHT = 400;
const app = new PIXI.Application({
  width: WIDTH,
  height: HEIGHT,
  antialias: true,
  transparent: false,
  resolution: 1,
  backgroundColor: 0xFFFFFF
});

$('.task-3').append(app.view);

$('.task-3 .amount').change(main);

const renderInputs = (n) => {
  $('.task-3 form').html('');
  for (let i = 0; i < n; i++) {
    $('.task-3 form').append(`
      <div>
        <label>
          ${i + 1} вершина
          <input type="number" class="x${i}" value="${Math.ceil((i + 1) * Math.random() * 100)}">
          <input type="number" class="y${i}" value="${Math.ceil((i + 1) * Math.random() * 100)}">
        </label>
      </div>
    `)
  }
  $('.task-3 form').append(`
    <div>
        <button class="regenerate">Еще раз</button>
    </div>
  `);
  $('.task-3 .regenerate').click(main);
};

const getPoints = (n) => {
  const res = [];
  for (let i = 0; i < n; i++) {
    res.push([
      +$(`.task-3 .x${i}`).val(),
      +$(`.task-3 .y${i}`).val()
    ]);
  }
  return res;
};

const getEdges = points => {
  const res = [];
  for (let i = 0; i < points.length - 1; i++) {
    res.push([
      points[i],
      points[i + 1]
    ]);
  }
  res.push([
    points[points.length - 1],
    points[0]
  ]);
  return res;
};

const main = () => {
  clearView(app);
  const n = +$('.task-3 .amount').val();
  renderInputs(n);
  const points = getPoints(n);
  const edges = getEdges(points);
  edges.forEach(([ point1, point2 ]) => {
    drawSegment(app, point1[0], point1[1], point2[0], point2[1]);
  });

  const res = isSimplePolygon(edges) ? 'Простой' : 'Не простой';
  $('.task-3 .answer').text(res);
};

main();

