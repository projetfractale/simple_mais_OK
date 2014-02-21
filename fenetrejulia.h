#ifndef FENETREJULIA_H
#define FENETREJULIA_H

#include <QLCDNumber>
#include <QSlider>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QEvent>
#include <QPoint>


#include "math.h"

#include <QGraphicsPixmapItem>

class fenetrejulia : public QWidget
{
    Q_OBJECT
public:
    explicit fenetrejulia(int, int, QWidget *parent = 0);
    QGraphicsView* getView();
    QGraphicsScene* getScene();
    QPixmap getPixmap();

signals:

public slots:

protected:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap pixmap;
    int x;
    int y;

};

#endif // FENETREJULIA_H
