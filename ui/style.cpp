#include "style.hpp"


#include "draw.hpp"

#include <QCommonStyle>
#include <QFontMetrics>
#include <QPalette>
#include <QStyle>
#include <QStyleOption>
#include <QStyleOptionTab>
#include <QtGui>
#include <QTabBar>


GesusStyle::
GesusStyle()
	: QCommonStyle()
{
}


void GesusStyle::
drawItemText(       QPainter *          painter,
			  const QRect &             rect,
			        int                 flags,
			  const QPalette &          palette,
			 		bool                enabled,
			  const QString &           text,
			        QPalette::ColorRole textRole) const
{
	QColor textColor;
	QRect  textRect;

	textColor = enabled ? GesusTheme::TEXT_HIGHLIGHT_COLOR :
		                  GesusTheme::TEXT_COLOR;
	textRect  = rect.adjusted(GesusMetrics::TEXT_MARGIN_DEFAULT_H,
			 				  GesusMetrics::TEXT_MARGIN_DEFAULT_V, 0, 0);
	
	painter->setPen  (QPen(textColor));
	painter->setFont (GesusTheme::DEFAULT_FONT);
	
	painter->drawText(textRect, text);
	
}


void GesusStyle::
drawControl(      QStyle::ControlElement controlElement,
			const QStyleOption *         styleOption,
			      QPainter *             painter,
			const QWidget *              widget) const
{
	DrawFunction draw_function = customDrawControlFunctions[controlElement];
		
	if (draw_function) [[unlikely]]
		draw_function(styleOption, painter, widget);
	else
		QCommonStyle::drawControl(controlElement, styleOption, painter, widget);
}


void GesusStyle::
gesus_ce_tab_bar_shape(const QStyleOption * styleOption,
					         QPainter *     painter,
					   const QWidget *      widget)
{
	const QStyleOptionTab * tabOption = qstyleoption_cast<const QStyleOptionTab *>(styleOption);

	QColor tabColor;
	QRect  tabRect;

	bool isSelected;

    tabRect = tabOption->rect;

	isSelected = tabOption->state & State_Selected;
	
	if (!isSelected) [[likely]] {
		tabColor = GesusTheme::OUTER_BG_COLOR;
		tabRect  = tabRect.adjusted(0, 0, 0, -1);
	}
	else {
		tabColor = GesusTheme::INNER_BG_COLOR;
		tabRect  = tabRect.adjusted(1, 1, -3, 0);
	}
	
	painter->fillRect(tabRect, tabColor);
	
	if (isSelected)
		Draw::draw_outline_skewed_tab(painter, tabRect);
}


void GesusStyle::
gesus_ce_menu_bar_empty_area(const QStyleOption * styleOption,
					               QPainter *     painter,
					         const QWidget *      widget)
{
	painter->fillRect(styleOption->rect, GesusTheme::OUTER_BG_COLOR);
}


void GesusStyle::
drawPrimitive(      QStyle::PrimitiveElement primitiveElement,
			  const QStyleOption *           styleOption,
			        QPainter *               painter,
			  const QWidget *                widget) const
{
	DrawFunction draw_function = customDrawPrimitiveFunctions[primitiveElement];
		
	if (draw_function)
		draw_function(styleOption, painter, widget);
	else
		QCommonStyle::drawPrimitive(primitiveElement, styleOption, painter, widget);
}


//  0. Generic frame
void GesusStyle::
gesus_pe_frame(const QStyleOption * styleOption,
			         QPainter *     painter,
			   const QWidget *      widget)
{
	Draw::draw_outline_skewed(painter,
						        styleOption->rect);
}


//  3. Generic focus indicator
void GesusStyle::
gesus_pe_frame_focus_rect(const QStyleOption * styleOption,
								QPainter *     painter,
						  const QWidget *      widget)
{
	/* Draw nothing */
}


void GesusStyle::
gesus_pe_panel_menu_bar(const QStyleOption * styleOption,
					    	  QPainter *     painter,
    					const QWidget *      widget)
{
	QRect panelRect = styleOption->rect.adjusted(1, 1, -1, -1);
	painter->fillRect(panelRect, GesusTheme::OUTER_BG_COLOR);
}


QSize GesusStyle::
sizeFromContents(QStyle::ContentsType contentsType,
				 const QStyleOption * styleOption,
				 const QSize &        contentsSize,
				 const QWidget *      widget) const
{
	SizeFunction size_function = customContentSizeFunctions[contentsType];
		
	if (size_function) [[unlikely]]
		return size_function(styleOption, contentsSize, widget);

	return QCommonStyle::sizeFromContents(contentsType, styleOption, contentsSize, widget);
}


QSize GesusStyle::
gesus_ct_menu_bar_item(const QStyleOption * styleOption,
				       const QSize &        contentsSize,
				       const QWidget *      widget)
{
	const int minWidth = QFontMetrics(GesusTheme::DEFAULT_FONT).height() * 2;
	
	int width, height;
	int fontHeight;
	
	fontHeight = styleOption->fontMetrics.height();
	
	width  = qMax(contentsSize.width() + 2 * GesusMetrics::MENU_BAR_ITEM_MARGIN_H, minWidth);
	height = fontHeight + 2 * GesusMetrics::MENU_BAR_ITEM_MARGIN_V;
	
	return QSize(width, height);
}


QSize GesusStyle::
gesus_ct_menu_item(const QStyleOption * styleOption,
				   const QSize &        contentsSize,
			       const QWidget *      widget)
{
	// int width, height;
	// int fontMetrics;
	
	// width  = ;
	// height = contentsSize.height() + ;
	
	// return QSize(width, height);
}


QSize GesusStyle::
gesus_ct_tab_bar_tab(const QStyleOption * styleOption,
				     const QSize &        contentsSize,
			         const QWidget *      widget)
{
	int width, height;
	int fontHeight;

	fontHeight = styleOption->fontMetrics.height();
	
	width  = contentsSize.width() + 2 * GesusMetrics::TAB_BAR_TAB_MARGIN_H;
	height = fontHeight + 2 * GesusMetrics::TAB_BAR_TAB_MARGIN_V * 2;
	
	return QSize(width, height);
}


int GesusStyle::
styleHint(      QStyle::StyleHint  styleHint,
		  const QStyleOption *     styleOption,
		  const QWidget *          widget,
				QStyleHintReturn * returnData) const
{
	if (styleHint == QStyle::SH_Widget_Animation_Duration) [[unlikely]]
		return GesusTheme::NO_ANIMATION;

	return QCommonStyle::styleHint(styleHint, styleOption, widget, returnData);
}


QRect GesusStyle::
subElementRect(      QStyle::SubElement subElement,
			   const QStyleOption *     styleOption,
			   const QWidget *          widget) const
{
	RectFunction rect_function = customSubElementRectFunctions[subElement];
	QRect        rect          = QCommonStyle::subElementRect(subElement, styleOption, widget);
	
	if (rect_function) [[unlikely]]
		return rect_function(rect, styleOption, widget);
	
	return rect;
}


QRect GesusStyle::
gesus_se_default_text(const QRect &        rect,
					  const QStyleOption * styleOption,
			          const QWidget *      widget)
{
	return rect.adjusted(GesusMetrics::TEXT_MARGIN_DEFAULT_H, GesusMetrics::TEXT_MARGIN_DEFAULT_V, 0, 0);
}
