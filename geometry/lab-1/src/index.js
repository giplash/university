import * as PIXI from 'pixi.js';

//Create a Pixi Application
let app = new PIXI.Application({
    width: 600,
    height: 600,
    antialias: true,
    transparent: false,
    resolution: 1,
});

const polygon = new PIXI.Graphics();
polygon.lineStyle(2, 0xFFFFFF, 1);

let path = [
    10, 100,
    500, 500,
    200, 200,
    10, 100,
  ];
  
polygon.drawPolygon(path);


app.stage.addChild(polygon);
document.body.appendChild(app.view);