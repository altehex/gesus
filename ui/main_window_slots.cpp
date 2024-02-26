#include "main_window.hpp"


#include <QKeySequence>
#include <QTabBar>
#include <QTabWidget>


void GesusMainWindow::
slot_close_selected_tab(int index)
{
	QTabBar *  gesusTabBar = gesusEditorTabs->tabBar();
	gesusTabBar->removeTab(index);
}


void GesusMainWindow::
slot_select_adjacent_tab(const QKeySequence & seq)
{
	int iter, currentIndex;

	iter = seq.matches(scLeftTab.key()) ? -1 : 1;

	currentIndex = gesusEditorTabs->currentIndex() + iter;
	
	if (currentIndex >= gesusEditorTabs->count())
		return;
	if (currentIndex < 0)
		return;
	
	gesusEditorTabs->setCurrentIndex(currentIndex);
}


void GesusMainWindow::
slot_toggle_fullscreen()
{
	if (this->isFullScreen())
		this->showNormal();
	else
		this->showFullScreen();
}
