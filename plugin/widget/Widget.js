// Widget.js
// Zilch Editor JavaScript Plugin API

'use strict';

class Widget {
    constructor(objname, parent = null) {
        this.objname = objname;
        this.parent = parent;
        this.children = [];
        this.x = 0;
        this.y = 0;
        this.width = 0;
        this.height = 0;
    }
    toString() {
        return `(Widget)[objname:${this.objname}, x:${this.x}, y:${this.y}, ` +
            `width: ${this.width}, height:${this.height}]`;
    }
}

export default Widget;