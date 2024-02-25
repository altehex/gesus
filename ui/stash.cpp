#include "stash.hpp"


#include "style.hpp"
#include "../genesis/genesis_tile.hpp"

#include <filesystem>
namespace fs = std::filesystem;

#include <QIcon>


TileItem::
TileItem(const char * tilePath)
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
	this->setPalette(GesusStyle::palette);
}


void TileStash::
load_tiles_from_directory(const char * dir)
{
	const fs::path tilePath{dir};

	TileItem * tileItem;
	
	for (auto const & tileFile : fs::directory_iterator{tilePath}) {
		if (!tileFile.exists())
			break;
		
		tileItem = new TileItem(tileFile.path()
								        .c_str());
	    tiles.push_back(tileItem);
	}
}


void TileStash::
receive_from_editor()
{
	
}
