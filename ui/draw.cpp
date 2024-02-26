#include "draw.hpp"


#include "style.hpp"

#include <QPainter>
#include <QRect>
#include <Qt>


void Draw::
draw_outline(      QPainter *  painter,
			 const QRect &     rect,
			 const QColor &    color)
{
	int x, y, w, h;

	rect.getRect(&x, &y, &w, &h);
	w -= 1;  h -= 1;
	
	painter->setPen(color);
	
	painter->drawLine(x,     y,     x + w, y    ); // Top
	painter->drawLine(x,     y + h, x + w, y + h); // Bottom
	painter->drawLine(x,     y,     x,     y + h); // Left
	painter->drawLine(x + w, y,     x + w, y + h); // Right
}


void Draw::
draw_outline_thick(      QPainter *  painter,
				   const QRect &     rect,
				   const int         thickness,
				   const QColor &    color)
{
	int x, y, w, h;

	rect.getRect(&x, &y, &w, &h);
	
	QRect rectTop   (x,     y,     w,         thickness);
	QRect rectBottom(x,     y + h, w,         thickness);
	QRect rectLeft  (x,     y,     thickness, h);
	QRect rectRight (x + w, y,     thickness, h);

	painter->fillRect(rectTop,    color);
	painter->fillRect(rectBottom, color);
	painter->fillRect(rectLeft,   color);
	painter->fillRect(rectRight,  color);
}


void Draw::
draw_outline_skewed(      QPainter *  painter, 
					const QRect &     rect,
					const QColor &    color)
{
	int x, y, w, h;

	rect.getRect(&x, &y, &w, &h);
	x += 1;      y += 1;
	w -= 2 + 1;  h -= 2 + 1;
	
	painter->setPen(color);
	
	painter->drawLine(x + 2, y,     x + w - 2, y        ); // Top
	painter->drawLine(x + 2, y + h, x + w - 2, y + h    ); // Bottom
	painter->drawLine(x,     y + 2, x,         y + h - 2); // Left
	painter->drawLine(x + w, y + 2, x + w,     y + h - 2); // Right

	painter->drawPoint(x + 1,     y + 1    ); // Top left
	painter->drawPoint(x + 1,     y + h - 1); // Bottom left
	painter->drawPoint(x + w - 1, y + 1    ); // Top right
	painter->drawPoint(x + w - 1, y + h - 1); // Bottom right
}


void Draw::
draw_outline_skewed_tab(      QPainter *  painter, 
						const QRect &     rect,
					    const QColor &    color)
{
	int x, y, w, h;
	
	rect.getRect(&x, &y, &w, &h);
	
	painter->setPen(color);
	
	painter->drawLine(x + 2, y,     x + w - 2, y    ); // Top
	painter->drawLine(x,     y + 2, x,         y + h); // Left
	painter->drawLine(x + w, y + 2, x + w,     y + h); // Right

	painter->drawPoint(x + 1,     y + 1    ); // Top left
	painter->drawPoint(x + w - 1, y + 1    ); // Top right	
}
