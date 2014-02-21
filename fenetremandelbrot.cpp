#include "fenetremandelbrot.h"

fenetremandelbrot::fenetremandelbrot(QWidget *parent) :
    QWidget(parent) , pixmap(1200,1200)
{
    setFixedSize(1100,650);
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene,this);
    QPainter *p_fractale = new QPainter(&pixmap);
    //le compteur est initialisé à 0. Il va servir à l'it_max
    int a[2];
    int c[2];
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200; // On commence par le carré classique
    vector<vector<int> > mandelbrot = Mandelbrot(100, a, c); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (mandelbrot[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale->setPen(QPen(Qt::black));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (1<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<15)
        {
            p_fractale->setPen(QPen(Qt::darkBlue));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (15<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<30)
        {
            p_fractale->setPen(QPen(Qt::blue));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (30<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<45)
        {
            p_fractale->setPen(QPen(Qt::darkCyan));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        if (45<=mandelbrot[compteur][2] && mandelbrot[compteur][2]<100)
        {
            p_fractale->setPen(QPen(Qt::cyan));
            p_fractale->drawPoint(mandelbrot[compteur][0],mandelbrot[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale;
    scene->addPixmap(pixmap);
    view->move(10,10);
}



QPixmap fenetremandelbrot::getPixmap()
{
    return pixmap;
}

QGraphicsScene* fenetremandelbrot::getScene()
{
    return scene;
}

QGraphicsView* fenetremandelbrot::getView()
{
    return view;
}
