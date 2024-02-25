#pragma once


#include <QDialog>
#include <QObject>
#include <QWidget>


class GesusAbout : public QDialog
{
	Q_OBJECT

public:
	explicit GesusAbout(QWidget * parent = nullptr);
	~GesusAbout(void);

private:
};
