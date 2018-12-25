#include "Scratch.h"
#include "../widget/MainWindow.h"
#include "../widget/ScriptPart.h"
#include "../widget/StageView.h"

/**
 * @brief Scratch::Scratch - Constructor.
 */
Scratch::Scratch() {	
	//Test code, it will be written into plugin in release.
	BlockCategory.push_back(new ScratchBlockCategory("Motion", 0x4C97FF));
	BlockCategory.push_back(new ScratchBlockCategory("Event", 0xFDD200));

	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "add 10 to x", ScratchBlockType::BODY_BLOCK, []()->void {
		auto &Sprite = AppWindow->StageArea->StageView->TestSprite;
		Sprite->move(Sprite->x() + 10, Sprite->y());
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "add 10 to y", ScratchBlockType::BODY_BLOCK, []()->void {
		auto &Sprite = AppWindow->StageArea->StageView->TestSprite;
		Sprite->move(Sprite->x(), Sprite->y() + 10);
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "sub 10 to x", ScratchBlockType::BODY_BLOCK, []()->void {
		auto &Sprite = AppWindow->StageArea->StageView->TestSprite;
		Sprite->move(Sprite->x() - 10, Sprite->y());
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[0], "sub 10 to y", ScratchBlockType::BODY_BLOCK, []()->void {
		auto &Sprite = AppWindow->StageArea->StageView->TestSprite;
		Sprite->move(Sprite->x(), Sprite->y() - 10);
	}));
	Block.push_back(new ScratchBlockPrototype(BlockCategory[1], "When program start", ScratchBlockType::HEAD_BLOCK, []()->void {

	}));

	Stage.Sprite.push_back(new ScratchSprite("Sprite A"));
}

/**
 * @brief Scratch::~Scratch - Destructor.
 */
Scratch::~Scratch() {
	for (size_t i = 0; i < BlockCategory.size(); i++) {
		delete BlockCategory[i];
	}
	BlockCategory.clear();
	for (size_t i = 0; i < Block.size(); i++) {
		delete Block[i];
	}
	Block.clear();
}

/**
 * @brief Scratch::ProgramRun - Run program.
 */
void Scratch::ProgramRun() {
	///TODO: Muiltiprocess
	for (const auto &c : this->Stage.Blocks) {
		if (c->Block->Name == "When program start") {
			c->Run();
		}
	}
}

/**
 * @brief Scratch::ProgramStop - Stop program running forcefully.
 */
void Scratch::ProgramStop() {

}
