#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

class Widget : public QWidget {
	Q_OBJECT
public:
	Widget(QWidget *parent = nullptr);
	void paintEvent(QPaintEvent *e) override;
	void mousePressEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
	void enterEvent(QEvent *e) override;
	void leaveEvent(QEvent *e) override;
private slots:
	void DefMouseProc();
	void ReloadTranslation();
signals:
	void leftclicked();
	void rightclicked();
	void onmouseenter();
	void onmouseleave();
	void reloadtranslation();
protected:
	bool LeftPressed;
	bool RightPressed;
};

#endif // WIDGET_H
