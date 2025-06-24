#ifndef CDRAWFILEX_H
#define CDRAWFILEX_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QListWidget>

#include "cinifile.h"

#define VERTICAL_SHIFT_AFTER_ROTATION 880
#define INITIAL_SHIFT_X -200
#define INITIAL_SHIFT_Y -200

class cDrawFilex : public QObject
{
    Q_OBJECT

    //Атрибуты
    QListWidget * ListWidget;

public:
    static qreal dx;// = 0;
    static qreal dy;// = VERTICAL_SHIFT_AFTER_ROtATION;//880

    explicit cDrawFilex(QObject *parent = 0);

    //Методы
    void install(QListWidget * other);

    static QString execRotate(int angle);
    static void execRotateCW90();
    static void execRotateCCW90();
    static void scaleImage(QString, int width, int height);



signals:

public slots:
};

#endif // CDRAWFILEX_H
