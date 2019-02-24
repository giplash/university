import * as PIXI from 'pixi.js';

export const WIDTH = 400;
export const HEIGHT = 400;

export const COLOR = 0x000000;
export const BG_COLOR = 0xFFFFFF;

export const LINE_THICKNESS = 2;

export const app = new PIXI.Application({
  width: WIDTH,
  height: HEIGHT,
  antialias: true,
  transparent: false,
  resolution: 1,
  backgroundColor: BG_COLOR
});

export const graphics = new PIXI.Graphics();

graphics.lineStyle(LINE_THICKNESS, COLOR);

app.stage.addChild(graphics);
