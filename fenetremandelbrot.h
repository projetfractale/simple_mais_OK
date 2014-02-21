#ifndef FENETREMANDELBROT_H
#define FENETREMANDELBROT_H

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

class fenetremandelbrot : public QWidget
{
    Q_OBJECT
public:
    explicit fenetremandelbrot(QWidget *parent = 0);
    QGraphicsView* getView();
    QGraphicsScene* getScene();
    QPixmap getPixmap();

signals:

public slots:

protected:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap pixmap;

};

#endif // FENETREMANDELBROT_H
