// EventSystem.js
// Zilch Editor JavaScript Plugin API

'use strict';

const EventSystem = {
    // Program Event
    on_program_start: 0x00,
    on_program_crash: 0x01,
    on_program_exit: 0x02,
    pre_program_start: 0x10,
    pre_program_exit: 0x12,
    // Project Event
    on_project_run: 0x20,
    on_project_stop: 0x21,
    pre_project_run: 0x30,
    pre_project_stop: 0x31,
    // Block Event
    on_block_drag: 0x40,
    on_block_move: 0x41,
    on_block_release: 0x42,
    on_block_copy: 0x43,
    pre_block_copy: 0x53
}

export default EventSystem;