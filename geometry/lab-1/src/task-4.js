import $ from 'jquery';
import * as PIXI from "pixi.js";
import { clearView, drawSegment, isSimplePolygon } from "./utils";
import math from 'mathjs';

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

$('.task-4').append(app.view);

$('.task-4 .amount').change(e => main());

const renderInputs = (n) => {
  $('.task-4 form').html('');
  for (let i = 0; i < n; i++) {
    $('.task-4 form').append(`
      <div>
        <label>
          ${i + 1} вершина
          <input type="number" class="x${i}" value="${Math.ceil((i + 1) * Math.random() * 100)}">
          <input type="number" class="y${i}" value="${Math.ceil((i + 1) * Math.random() * 100)}">
        </label>
      </div>
    `)
  }
  $('.task-4 form').append(`
    <div>
        <button class="regenerate">Еще раз</button>
    </div>
  `);
  $('.task-4 .regenerate').click(main);
};

const getPoints = (n) => {
  const res = [];
  for (let i = 0; i < n; i++) {
    res.push([
      +$(`.task-4 .x${i}`).val(),
      +$(`.task-4 .y${i}`).val()
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

const getRes = (edges) => {
  if (!isSimplePolygon(edges)) {
    return 'Впуклый';
  }
  let prevValue = null;
  for (let i = 0; i < edges.length - 1; i++) {
    const det = math.det(math.matrix([
      [edges[i][1][0] - edges[i][0][0], edges[i][1][1] - edges[i][0][1]],
      [edges[i + 1][1][0] - edges[i][0][0], edges[i + 1][1][1] - edges[i][0][1]]
    ]));
    if (det > 0 !== prevValue && prevValue !== null) {
      return 'Впуклый';
    } else {
      prevValue = det > 0;
    }
  }
  return 'Выпуклый';
};

const main = () => {
  clearView(app);
  const n = +$('.task-4 .amount').val();
  renderInputs(n);
  const points = getPoints(n);
  const edges = getEdges(points);
  edges.forEach(([ point1, point2 ]) => {
    drawSegment(app, point1[0], point1[1], point2[0], point2[1]);
  });

  const res = getRes(edges);
  $('.task-4 .answer').text(res);
};

main();

