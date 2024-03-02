#include "genesis_tile.hpp"


#include <QImage>
#include <QString>


Tile::
Tile(const QString & path)
	: QPixmap(path)
{
}
