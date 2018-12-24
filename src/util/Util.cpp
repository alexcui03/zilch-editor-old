#include "Util.h"

#include <string>

QColor operator*(const QColor &Color, const double &&Number) {
	int r, g, b, a;
	Color.getRgb(&r, &g, &b, &a);
	return QColor(static_cast<int>(r * Number), static_cast<int>(g * Number), static_cast<int>(b * Number), a);
}
