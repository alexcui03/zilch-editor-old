#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

class Widget : public QWidget {
	Q_OBJECT
public:
	Widget(QWidget *parent = nullptr);
	~Widget() override;
	virtual void paintEvent(QPaintEvent *e) override;
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void mouseReleaseEvent(QMouseEvent *e) override;
	virtual void mouseMoveEvent(QMouseEvent *e) override;
	virtual void enterEvent(QEvent *e);
	virtual void leaveEvent(QEvent *e);
	virtual void reloadTranslation();
private slots:
	void DefMouseProc();
signals:
	void leftclicked();
	void rightclicked();
	void onmouseenter();
	void onmouseleave();
protected:
	bool LeftPressed;
	bool RightPressed;
};

#endif // WIDGET_H
