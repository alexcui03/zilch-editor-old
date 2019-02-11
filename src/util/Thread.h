#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread {
public:
	Thread(std::function<void()> Function);
	void run();
private:
	std::function<void()> Function;
};

#endif // THREAD_H
