#include "Thread.h"

Thread::Thread(std::function<void()> Function) {
	this->Function = Function;
}

void Thread::run() {
	Function();
}
