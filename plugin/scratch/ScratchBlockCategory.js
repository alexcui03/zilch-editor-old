// ScratchBlockCategory.js
// Zilch Editor JavaScript Plugin API

'use strict';

class ScratchBlockCategory {
    constructor(name, color) {
        this.name = name;
        this.color = color;
        this.blocks = [];
    }
}

export default ScratchBlockCategory;