import { canvas } from "./app";
import Point from "./classes/Point";
import Polygon from "./classes/Polygon";
import { dynamicConvexHull } from "./utils/convexHull";
import { clear, drawPoints, drawPolygon } from "./utils/draw";

const main = () => {
    const points = [];
    let ch = [];
    canvas.addEventListener('click', ({
        offsetX: x,
        offsetY: y
    }) => {
        points.push(new Point(x, y));
        clear();
        drawPoints(points, 8);
        ch = dynamicConvexHull(ch, points[points.length - 1]);
        drawPoints(ch, 8, true);
        drawPolygon(new Polygon(ch));
    });
};

export default main;