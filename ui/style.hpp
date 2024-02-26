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


namespace GesusTheme { // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	const QColor ACCENT_COLOR          = QColor(152, 116, 192);
	const QColor FRAME_COLOR           = QColor( 84,  80,  84);
	const QColor FRAME_HIGHLIGHT_COLOR = QColor(104, 100, 104);
	const QColor HIGHLIGHT_BG_COLOR    = QColor( 63,  59,  63);
	const QColor INNER_BG_COLOR        = QColor( 44,  40,  44);
	const QColor OUTER_BG_COLOR        = QColor( 25,  21,  25);
	const QColor TEXT_COLOR            = QColor(242, 241, 242);
	const QColor TEXT_HIGHLIGHT_COLOR  = QColor(255, 255, 255);
	
	const int FRAME_THICKNESS = 1;

	const QFont DEFAULT_FONT = QFont("Helvetica");

	/*  Style hints
	 */
	const int NO_ANIMATION = 0;
}; // namespace GesusTheme >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


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

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
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
	
	void  drawControl(QStyle::ControlElement, const QStyleOption *, QPainter *, const QWidget * = nullptr) const;
	void  drawItemText(QPainter *, const QRect &, int, const QPalette &, bool, const QString &, QPalette::ColorRole) const;
	void  drawPrimitive(QStyle::PrimitiveElement, const QStyleOption *, QPainter *, const QWidget * = nullptr) const;
	QSize sizeFromContents(QStyle::ContentsType, const QStyleOption *, const QSize &, const QWidget * = nullptr) const;
	int   styleHint(QStyle::StyleHint, const QStyleOption * = nullptr, const QWidget * = nullptr, QStyleHintReturn * = nullptr) const;
	QRect subElementRect(QStyle::SubElement, const QStyleOption *, const QWidget * = nullptr) const;
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
#define QSTYLE_CE_MAX       QStyle::CE_ShapedFrame + 1
#define QSTYLE_CT_MAX       QStyle::CT_ItemViewItem + 1
#define QSTYLE_PE_MAX       QStyle::PE_IndicatorTabTearRight + 1
#define QSTYLE_SE_MAX       QStyle::SE_PushButtonBevel + 1
#define QSTYLE_PE_FRAME_END QStyle::PE_FrameTabBarBase
	
#define DRAW_SIGNATURE  const QStyleOption *, QPainter *, const QWidget *
#define RECT_SIGNATURE  const QRect &, const QStyleOption *, const QWidget *
#define SIZE_SIGNATURE  const QStyleOption *, const QSize &, const QWidget *
	
	typedef function<void(DRAW_SIGNATURE)>  DrawFunction;
	typedef function<QRect(RECT_SIGNATURE)> RectFunction;
	typedef function<QSize(SIZE_SIGNATURE)> SizeFunction;

	static void gesus_ce_menu_bar_empty_area(DRAW_SIGNATURE);
	static void gesus_ce_menu_item(DRAW_SIGNATURE);
	static void gesus_ce_tab_bar_shape(DRAW_SIGNATURE);
	
	array<DrawFunction, QSTYLE_CE_MAX> customDrawControlFunctions = []() {
		array<DrawFunction, QSTYLE_CE_MAX> a{};
		
		a[QStyle::CE_MenuBarEmptyArea] = gesus_ce_menu_bar_empty_area;

		a[QStyle::CE_MenuItem] = gesus_ce_menu_item;

		a[QStyle::CE_TabBarTabShape] = gesus_ce_tab_bar_shape;
		
		return a;
	}();

	static void gesus_pe_frame(DRAW_SIGNATURE);
	static void gesus_pe_frame_focus_rect(DRAW_SIGNATURE);
	static void gesus_pe_frame_not_skewed(DRAW_SIGNATURE);
	static void gesus_pe_panel_menu_bar(DRAW_SIGNATURE);
	
	array<DrawFunction, QSTYLE_PE_MAX> customDrawPrimitiveFunctions = []() {
		array<DrawFunction, QSTYLE_PE_MAX> a{};

		for (int i = 0; i <= QSTYLE_PE_FRAME_END; a[i++] = gesus_pe_frame);
		
		a[QStyle::PE_FrameFocusRect] = gesus_pe_frame_focus_rect;

		a[QStyle::PE_FrameMenu] = gesus_pe_frame_not_skewed;
		
		a[QStyle::PE_PanelMenuBar] = gesus_pe_panel_menu_bar;
		
		return a;
	}();

	static QSize gesus_ct_menu_bar_item(SIZE_SIGNATURE);
	static QSize gesus_ct_menu_item(SIZE_SIGNATURE);
	static QSize gesus_ct_tab_bar_tab(SIZE_SIGNATURE);
	
	array<SizeFunction, QSTYLE_CT_MAX> customContentSizeFunctions = []() {
		array<SizeFunction, QSTYLE_CT_MAX> a{};

		a[QStyle::CT_MenuBarItem] = gesus_ct_menu_bar_item;

		// a[QStyle::CT_MenuItem] = gesus_ct_menu_item;

		a[QStyle::CT_TabBarTab] = gesus_ct_tab_bar_tab;
		
		return a;
	}();

	static QRect gesus_se_default_text(RECT_SIGNATURE);
	
	array<RectFunction, QSTYLE_SE_MAX> customSubElementRectFunctions = []() {
		array<RectFunction, QSTYLE_SE_MAX> a{};

		a[QStyle::SE_DockWidgetTitleBarText] = gesus_se_default_text;
		
	    a[QStyle::SE_TabBarTabText] = gesus_se_default_text;
		
		return a;
	}();
};
