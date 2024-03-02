#pragma once


#include <QCommonStyle>
#include <QFont>
#include <QtGui>
#include <QRect>
#include <QSize>
#include <QStyle>

#include <array>
using std::array;

#include <functional>
using std::function;


#define QSTYLE_PE_FRAME_END QStyle::PE_FrameTabBarBase


namespace GesusTheme { // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	const QRgb ACCENT_COLOR          = 0xFF9888C5;
	const QRgb FRAME_COLOR           = 0xFF545054;
	const QRgb FRAME_HIGHLIGHT_COLOR = 0xFF686468;
	const QRgb HIGHLIGHT_BG_COLOR    = 0xFF3F3B3F;
	
	const QRgb INNER_BG_COLOR        = 0xFF2C282C;
	const QRgb OUTER_BG_COLOR        = 0xFF191519;
   
	const QRgb BG_COLOR_VARIANTS[2] = { INNER_BG_COLOR,
										OUTER_BG_COLOR };

	const QRgb TEXT_COLOR            = 0xFFF2F1F2;
	const QRgb TEXT_HIGHLIGHT_COLOR  = 0xFFFFFFFF;

	const QRgb TEXT_COLOR_VARIANTS[2] = { TEXT_COLOR,
	                                      TEXT_HIGHLIGHT_COLOR };
	const int FRAME_THICKNESS = 1;

	const QFont DEFAULT_FONT = QFont("Helvetica");

	/*  Style hints
	 */
	const int NO_ANIMATION = 0;
}; // namespace GesusTheme >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


namespace GesusMetrics { // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	const int MENU_BAR_ITEM_MARGIN_H  = 2;
	const int MENU_BAR_ITEM_MARGIN_V  = 2;
	
	const int MENU_ITEM_MARGIN_H  = 2;
	const int MENU_ITEM_MARGIN_V  = 1;
	
	const int TAB_BAR_TAB_MARGIN_H = 2;
	const int TAB_BAR_TAB_MARGIN_V = 2;
	
	const int TEXT_MARGIN_DEFAULT_H = 2;
	const int TEXT_MARGIN_DEFAULT_V = 2;
	
}; // namespace GesusMetrics >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


class GesusStyle : public QCommonStyle
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	explicit GesusStyle(void);
	
	static inline QPalette palette = []() {
		QPalette p;

		p.setColor(QPalette::WindowText,      GesusTheme::TEXT_COLOR          );
		p.setColor(QPalette::Button,          GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::Light,           GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::Midlight,        GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::Dark,            GesusTheme::OUTER_BG_COLOR      );
		p.setColor(QPalette::Mid,             GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::Text,            GesusTheme::TEXT_COLOR          );
		p.setColor(QPalette::BrightText,      GesusTheme::TEXT_COLOR          );
		p.setColor(QPalette::ButtonText,      GesusTheme::TEXT_COLOR          );
		p.setColor(QPalette::Base,            GesusTheme::OUTER_BG_COLOR      );
		p.setColor(QPalette::Window,          GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::Shadow,          GesusTheme::OUTER_BG_COLOR      );
		p.setColor(QPalette::Highlight,       GesusTheme::HIGHLIGHT_BG_COLOR  );
		p.setColor(QPalette::HighlightedText, GesusTheme::TEXT_HIGHLIGHT_COLOR);
		p.setColor(QPalette::Link,            GesusTheme::ACCENT_COLOR        );
		p.setColor(QPalette::LinkVisited,     GesusTheme::ACCENT_COLOR        );
		p.setColor(QPalette::AlternateBase,   GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::ToolTipBase,     GesusTheme::INNER_BG_COLOR      );
		p.setColor(QPalette::ToolTipText,     GesusTheme::TEXT_COLOR          );
		p.setColor(QPalette::PlaceholderText, GesusTheme::TEXT_COLOR          );
		p.setColor(QPalette::Accent,          GesusTheme::ACCENT_COLOR        );
		
		return p;
	}();
	
	void  drawControl(QStyle::ControlElement, const QStyleOption *, QPainter *, const QWidget * = nullptr) const override;
	void  drawItemText(QPainter *, const QRect &, int, const QPalette &, bool, const QString &, QPalette::ColorRole) const override;
	void  drawPrimitive(QStyle::PrimitiveElement, const QStyleOption *, QPainter *, const QWidget * = nullptr) const override;
	QSize sizeFromContents(QStyle::ContentsType, const QStyleOption *, const QSize &, const QWidget * = nullptr) const override;
	int   styleHint(QStyle::StyleHint, const QStyleOption * = nullptr, const QWidget * = nullptr, QStyleHintReturn * = nullptr) const override;
	QRect subElementRect(QStyle::SubElement, const QStyleOption *, const QWidget * = nullptr) const override;
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
};
