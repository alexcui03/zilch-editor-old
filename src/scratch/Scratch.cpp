#include "Scratch.h"

Scratch::Scratch() {
	BlockCategory.push_back(new ScratchBlockCategory("Motion", 0x4C97FF));
	BlockCategory.push_back(new ScratchBlockCategory("Event", 0xFDD200));

	Block.push_back(new ScratchBlock(BlockCategory[0], "set x to 0", ScratchBlockType::BODY_BLOCK));
	Block.push_back(new ScratchBlock(BlockCategory[0], "update stage", ScratchBlockType::BODY_BLOCK));
	Block.push_back(new ScratchBlock(BlockCategory[1], "event a", ScratchBlockType::HEAD_BLOCK));
	Block.push_back(new ScratchBlock(BlockCategory[1], "stop all", ScratchBlockType::TAIL_BLOCK));
}
