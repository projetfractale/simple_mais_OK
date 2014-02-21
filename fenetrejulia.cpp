#include "fenetrejulia.h"

fenetrejulia::fenetrejulia(int c_x,int c_y,QWidget *parent) :
    QWidget(parent) , pixmap(1200,1200)
{

    x = c_x;
    y = c_y;

    setFixedSize(1100,650);


    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene,this);


    QPainter *p_fractale = new QPainter(&pixmap);
    //le compteur est initialisé à 0. Il va servir à l'it_max
    int a[2];
    int c[2];
    int b[2];
    a[0]=0;
    a[1]=0;
    c[0]=1200;
    c[1]=1200; // On commence par le carré classique
    b[0]=x;
    b[1]=y; //On démarre avec un choix par défaut qui correspond à ce point ci (0,0)
    vector<vector<int> > julia = Julia(100, a, c, b); //ici l'iteration max est 100.
    int compteur = 0;
    while (compteur<1200*1200)
    {
        if (julia[compteur][2]==100) //100 est l'iteration max ici
        {
            p_fractale->setPen(QPen(Qt::black));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (1<=julia[compteur][2] && julia[compteur][2]<15)
        {
            p_fractale->setPen(QPen(Qt::darkBlue));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (15<=julia[compteur][2] && julia[compteur][2]<30)
        {
            p_fractale->setPen(QPen(Qt::blue));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (30<=julia[compteur][2] && julia[compteur][2]<45)
        {
            p_fractale->setPen(QPen(Qt::darkCyan));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        if (45<=julia[compteur][2] && julia[compteur][2]<100)
        {
            p_fractale->setPen(QPen(Qt::cyan));
            p_fractale->drawPoint(julia[compteur][0],julia[compteur][1]);
        }
        compteur++;
    }
    delete p_fractale;
    scene->addPixmap(pixmap);
}



QPixmap fenetrejulia::getPixmap()
{
    return pixmap;
}

QGraphicsScene* fenetrejulia::getScene()
{
    return scene;
}

QGraphicsView* fenetrejulia::getView()
{
    return view;
}

