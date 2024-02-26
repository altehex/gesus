#pragma once


#include "genesis_color.hpp"

#include <QImage>
#include <QString>


class Tile : public QImage
{
public:
	Tile(const QString &);
};
