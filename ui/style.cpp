#include "style.hpp"


#include "draw.hpp"

#include <QCommonStyle>
#include <QFontMetrics>
#include <QPalette>
#include <QStyle>
#include <QStyleOption>
#include <QStyleOptionTab>
#include <Qt>
#include <QtGui>
#include <QTabBar>


GesusStyle::
GesusStyle()
	: QCommonStyle()
{
}


void GesusStyle::
drawItemText(       QPainter *           painter,
			  const QRect &              rect,
			        int                  flags,
			  const QPalette &           palette,
			 		bool                 enabled,
			  const QString &            text,
			        QPalette::ColorRole  textRole) const
{
	QColor textColor;
	QRect  textRect;

	textColor = GesusTheme::TEXT_COLOR_VARIANTS[enabled];
	textRect  = rect.adjusted(GesusMetrics::TEXT_MARGIN_DEFAULT_H,
			 				  GesusMetrics::TEXT_MARGIN_DEFAULT_V, 0, 0);
	
	painter->setPen   (QPen(textColor));
	painter->setFont  (GesusTheme::DEFAULT_FONT);
	
	painter->drawText(textRect, text);
	
}


void GesusStyle::
drawControl(      QStyle::ControlElement  controlElement,
			const QStyleOption *          styleOption,
			      QPainter *              painter,
			const QWidget *               widget) const
{
	using namespace GesusMetrics;

	bool isSelected = styleOption->state & State_Selected;

	switch (controlElement) { // ============================================================
		
		case CE_MenuBarEmptyArea: {
			painter->fillRect(styleOption->rect, GesusTheme::OUTER_BG_COLOR);

			return;
		} // case CE_MenuItem: -------------------------------------------------------------
			
		case CE_MenuItem: {
			const QStyleOptionMenuItem * menuItemOption = qstyleoption_cast<const QStyleOptionMenuItem *>(styleOption);

			int     itemTextFlags;
			QRect   itemTextRect;
			QColor  itemTextColor, itemBaseColor;

			itemTextFlags = Qt::AlignLeft        |
							Qt::AlignTop         |
							Qt::TextShowMnemonic |
							Qt::TextDontClip     |
							Qt::TextSingleLine;
			itemTextRect  = menuItemOption->rect.adjusted(TEXT_MARGIN_DEFAULT_H + MENU_ITEM_MARGIN_H,
														  TEXT_MARGIN_DEFAULT_V + MENU_ITEM_MARGIN_V,
														  -TEXT_MARGIN_DEFAULT_H - MENU_ITEM_MARGIN_H,
														  -TEXT_MARGIN_DEFAULT_V - MENU_ITEM_MARGIN_V);

			itemBaseColor = GesusTheme::BG_COLOR_VARIANTS[isSelected];
			itemTextColor = GesusTheme::TEXT_COLOR_VARIANTS[isSelected];

			painter->fillRect(menuItemOption->rect, itemBaseColor);

			painter->setPen   (QPen(itemTextColor));
			painter->setFont  (GesusTheme::DEFAULT_FONT);

			painter->drawText(itemTextRect, itemTextFlags, menuItemOption->text);

			return;
		} // case CE_MenuItem: -------------------------------------------------------------
			
		case CE_TabBarTabShape: {
			const QStyleOptionTab * tabOption = qstyleoption_cast<const QStyleOptionTab *>(styleOption);

			QColor  tabColor;
			QRect   tabRect;

			tabRect  = tabOption->rect;
			tabColor = GesusTheme::BG_COLOR_VARIANTS[!isSelected];
			
			if (!isSelected) [[likely]]
				tabRect = tabRect.adjusted(0, 0, 0, -1);
			else 
				tabRect = tabRect.adjusted(1, 1, -3, 0);

			painter->fillRect(tabRect, tabColor);

			if (isSelected)
				Draw::draw_outline_skewed_tab(painter, tabRect);

			return;
		} // case CE_TabBarTabShape: -------------------------------------------------------
			
		default:
			QCommonStyle::drawControl(controlElement, styleOption, painter, widget);

	} // switch (controlElement) ============================================================
}


void GesusStyle::
drawPrimitive(      QStyle::PrimitiveElement  primitiveElement,
			  const QStyleOption *            styleOption,
			        QPainter *                painter,
			  const QWidget *                 widget) const
{	
	switch (primitiveElement) { 
		case PE_FrameMenu:
			Draw::draw_outline(painter, styleOption->rect);
		case PE_FrameFocusRect:
			return;
			
		case PE_PanelMenuBar: {
			QRect panelRect = styleOption->rect.adjusted(1, 1, -1, -1);
			painter->fillRect(panelRect, GesusTheme::BG_COLOR_VARIANTS[0]);
			return;
		}
			
		default:
			if (primitiveElement <= QSTYLE_PE_FRAME_END)
				Draw::draw_outline_skewed(painter, styleOption->rect);
			else [[likely]]
				QCommonStyle::drawPrimitive(primitiveElement, styleOption, painter, widget);
	}
}


QSize GesusStyle::
sizeFromContents(QStyle::ContentsType  contentsType,
				 const QStyleOption *  styleOption,
				 const QSize &         contentsSize,
				 const QWidget *       widget) const
{
	int width, height;
	int fontHeight;
	
	fontHeight = styleOption->fontMetrics.height();

	switch (contentsType) {
		case CT_MenuBarItem: {
			width  = qMax(contentsSize.width() + 2 * GesusMetrics::MENU_BAR_ITEM_MARGIN_H, fontHeight * 2);
			height = fontHeight + 2 * GesusMetrics::MENU_BAR_ITEM_MARGIN_V;

			return QSize(width, height);
		}

		case CT_TabBarTab: {
			width  = contentsSize.width() + 2 * GesusMetrics::TAB_BAR_TAB_MARGIN_H;
			height = fontHeight + 2 * GesusMetrics::TAB_BAR_TAB_MARGIN_V * 2;

			return QSize(width, height);
		}
			
		default: 
			return QCommonStyle::sizeFromContents(contentsType, styleOption, contentsSize, widget);
	}
}


int GesusStyle::
styleHint(      QStyle::StyleHint   styleHint,
		  const QStyleOption *      styleOption,
		  const QWidget *           widget,
				QStyleHintReturn *  returnData) const
{
	if (styleHint == QStyle::SH_Widget_Animation_Duration)
		return GesusTheme::NO_ANIMATION;

	return QCommonStyle::styleHint(styleHint, styleOption, widget, returnData);
}


QRect GesusStyle::
subElementRect(      QStyle::SubElement  subElement,
			   const QStyleOption *      styleOption,
			   const QWidget *           widget) const
{
	QRect rect = QCommonStyle::subElementRect(subElement, styleOption, widget);

	switch (subElement) {
		case SE_DockWidgetTitleBarText:
		case SE_TabBarTabText:
			return rect.adjusted(GesusMetrics::TEXT_MARGIN_DEFAULT_H, GesusMetrics::TEXT_MARGIN_DEFAULT_V, 0, 0);

		default:
			return rect;
	}	
}
