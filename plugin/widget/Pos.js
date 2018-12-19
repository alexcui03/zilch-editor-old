// Widget.js
// Zilch Editor JavaScript Plugin API

import { sqrt } from 'Math';

'use strict';

class Pos {
    /**
     * Constructor
     * @param {Number} [x = 0] X pos
     * @param {Number} [y = 0] Y pos
     */
    constructor(x = 0, y = 0) {
        this.x = x;
        this.y = y;
    }

    /**
     * Calculate the distance between two points
     * @param {Pos} pos Another pos.
     */
    Distance(pos) {
        return sqrt((pos.x - this.x) ** 2 + (pos.y - this.y) ** 2);
    }

    toString() {
        return `(Pos)[x:${this.x}, y:${this.y}]`;
    }
}

/**
 * Calculate the distance between two points
 * @param {Number} x0 X of point
 * @param {Number} y0 Y of point
 * @param {Number} x1 X of another point
 * @param {Number} y1 Y of another point
 * @returns {Number}
 */
function Distance(x0, y0, x1, y1) {
    return sqrt((x1 - x0) ** 2 + (y1 - y0) ** 2);
}

export default Pos;
export {
    Distance
};