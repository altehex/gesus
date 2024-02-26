#include "stash.hpp"


#include "style.hpp"

#include <QDir>
#include <QFileInfo>
#include <QIcon>
#include <QString>


TileItem::
TileItem(const QString & tilePath)
	: tile(tilePath)
	
{
	// QIcon * tileIcon;

	// tileIcon = new QIcon (tileImage);
	
	// this->setIcon(&tileIcon);
	// this->setIconSize();
}


TileStash::
TileStash(const QWidget * parent)
{
	load_tiles_from_directory();

	setup_table();
	
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
		if (!tileFile.exists())
			break;
		
		tileItem = new TileItem(tileFile.filePath());
	    tiles.push_back(tileItem);
	}
}


void TileStash::
setup_table()
{
	
}


void TileStash::
slot_receive_from_editor()
{
	
}
