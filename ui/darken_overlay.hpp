/*
 *  Adapted from: https://github.com/KubaO/stackoverflown/tree/master/questions/overlay-widget-19362455
 */

#pragma once


#include "stash.hpp"

#include <QDockWidget>
#include <QEvent>
#include <QGraphicsScene>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QResizeEvent>
#include <Qt>


#include <iostream>
class DarkenOverlay : public QWidget
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	explicit
	DarkenOverlay(QDockWidget *  trackableDock,
				  QWidget *      parent)
	   : QWidget(parent)
	{
		dock = trackableDock;
		
		parent->installEventFilter(this);
		trackableDock->installEventFilter(this);

		setAttribute(Qt::WA_TranslucentBackground);
		setAttribute(Qt::WA_TransparentForMouseEvents);

		hide();
	}

	
	bool
	eventFilter(QObject *  object,
				QEvent *   event) override
	{
		QEvent::Type eventType = event->type();
		
		if (object == parent()) {			
			if      (eventType == QEvent::Resize)      resize(static_cast<QResizeEvent *>(event)->size());
			else if (eventType == QEvent::ChildAdded)  raise();
		}
		else if (object == dock) {
			if      (eventType == QEvent::MouseButtonPress)    show();
			else if (eventType == QEvent::MouseButtonRelease)  hide();
		}
			
		return QWidget::eventFilter(object, event);
	}


	void
	paintEvent(QPaintEvent *) override
	{
		QPainter  p{this};
		QRect     rect = this->rect();

		p.setOpacity(0.5);
		p.fillRect(rect, Qt::black);
	}

private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	QDockWidget * dock;
};
