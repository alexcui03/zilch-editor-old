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
 * @brief Scratch::ProgramRun - Run program.
 */
void Scratch::ProgramRun() {
	ScriptPart_ScriptEdit *&Edit = AppWindow->EditArea->ScriptPart->ScriptEdit;
	for (const auto &c : Edit->children()) {
		if (dynamic_cast<BlockItem*>(c)->BlockData->Block->Name == "When program start") {
			// TODO: multiprocess
			emit dynamic_cast<BlockItem*>(c)->run();
		}
	}
}

/**
 * @brief Scratch::ProgramStop - Stop program running forcefully.
 */
void Scratch::ProgramStop() {

}
