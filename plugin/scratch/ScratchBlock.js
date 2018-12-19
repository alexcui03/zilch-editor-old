// ScratchBlockPrototype.js
// Zilch Editor JavaScript Plugin API

import ScratchBlockPrototype from 'ScratchBlockPrototype'

'use strict';

class ScratchBlock {
    /**
     * Constructor
     * @param {ScratchBlockPrototype} blockprototype Prototype of this block
     * @param {ScratchBlock} lastblock Last block
     * @param {ScratchBlock} nextblock Next block
     */
    constructor(blockprototype, lastblock = null, nextblock = null) {
        this.blockprototype = blockprototype;
        this.lastblock = lastblock;
        this.nextblock = nextblock;
        this.x = 0;
        this.y = 0;
    }
}

export default ScratchBlock