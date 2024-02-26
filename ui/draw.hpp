#pragma once


#include "style.hpp"

#include <QPainter>
#include <QRect>
#include <Qt>
#include <QTabBar>


namespace Draw { // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
/*  Draw rectangular outline (1 px thick)
-----------------------------------------------------------------------------*/	
void draw_outline(QPainter *, const QRect &, const QColor & = GesusTheme::FRAME_COLOR);

/*  Draw rectangular outline with a thinkness of more than 1 px
-----------------------------------------------------------------------------*/
void draw_outline_thick(QPainter *, const QRect &, const int thickness = GesusTheme::FRAME_THICKNESS, const QColor & = GesusTheme::FRAME_COLOR);
	
/*  Draw outline with skewed (on 1 px) corners
-----------------------------------------------------------------------------*/
void draw_outline_skewed(QPainter *, const QRect &, const QColor & = GesusTheme::FRAME_COLOR);
	
/*  Draw outline with skewed (on 1 px) corners without bottom edge. For use with tabs (see gesus_ce_tab_bar_shape() in style.cpp)
-----------------------------------------------------------------------------*/
void draw_outline_skewed_tab(QPainter *, const QRect &, const QColor & = GesusTheme::FRAME_COLOR);
	
}; // (namespace Draw) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
