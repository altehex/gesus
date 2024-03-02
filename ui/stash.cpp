#include "stash.hpp"


#include "style.hpp"

#include <QDir>
#include <QDockWidget>
#include <QFileInfo>
#include <QIcon>
#include <QMouseEvent>
#include <QString>
#include <QWidget>


TileItem::
TileItem(const QString & tilePath)
	: tile(tilePath)
	
{
	setIconSize(QSize(48, 48));
}


TileStash::
TileStash(QWidget * parent)
	: QWidget(parent)
{	
	load_tiles_from_directory();

	setup_grid();
	
	setPalette(GesusStyle::palette);
}


void TileStash::
load_tiles_from_directory(const QDir & dir)
{
	const QStringList           extensions = {"*.bmp", "*.jpg", "*.png"};
	const QFlags<QDir::Filter>  filters    = QDir::Readable     |
						 		             QDir::Writable     |
								             QDir::Files        |
								             QDir::CaseSensitive;
	QFileInfoList  tileFiles;
	TileItem *     tileItem;

	tileFiles = dir.entryInfoList(extensions, filters);
	for (const QFileInfo & tileFile : tileFiles) {
		tileItem = new TileItem(tileFile.filePath());
	    tileItems.push_back(tileItem);
	}
}


void TileStash::
setup_grid()
{
	QIcon    tileItemIcon;
	QPixmap  tileItemIconPixmap;
	
	for (const auto & tileItem : tileItems) {
		tileItemIconPixmap = tileItem->getTile().scaled(48, 48);
		tileItemIcon.addPixmap(tileItemIconPixmap);
		tileItem->setIcon(tileItemIcon);
		tileItemGrid.addWidget(tileItem);
	}

	setLayout(&tileItemGrid);
}


void TileStash::
slot_receive_from_editor()
{
	
}
