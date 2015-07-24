#include "gameworld.h"
#include "firefly.h"
#include "lightblock.h"
#include "repulsorblock.h"
#include "attractorblock.h"

#include <ctime>
#include <cstdlib>


int rnd(const int l, const int h )
{
    const int width = h - l;
    double x = static_cast<double>(qrand())/RAND_MAX*width;
    return qRound(x) + l;
}


QPointF rand_pos()
{
    qint16 x = rnd(1, 15)*50;
    qint16 y = rnd(1, 11)*50;
    return QPointF(x, y);
}


GameWorld::GameWorld(QObject *parent) :
    QGraphicsScene(0, 0, 800, 600, parent)
{
    srand((unsigned)time(0));
}


void GameWorld::init_backdrop()
{
    for (int i = 0; i <= 800; i += 50)
    {
        addLine(i, 0, i, 600, QPen(Qt::gray));
    }
    for (int j = 0; j <= 600; j += 50)
    {
        addLine(0, j, 800, j, QPen(Qt::gray));
    }
}


void GameWorld::init()
{
    init_backdrop();

    qint16 x = 0;
    qint16 y = rnd(1,11)*50;
    Firefly* curr = new Firefly();
    curr->init(QPointF(x, y));
    curr->set_velocity(QPointF(10, rnd(0, 10) - 5));
    addItem(curr);

    for (int i = 0; i < 3; i++ ){
        QPointF pos = rand_pos();
        LightBlock* block = new LightBlock();
        block->init(pos);
        addItem(block);

        const qint32 r = block->ball_radius();
        const qint32 inr = block->inner_radius()*r;
        const qint32 outr = block->outer_radius()*r;
        addEllipse(pos.x() - inr, pos.y() - inr, 2*inr, 2*inr, QPen(Qt::red));
        addEllipse(pos.x() - outr, pos.y() - outr, 2*outr, 2*outr, QPen(Qt::blue));
    }
    for (int i = 0; i < 3; i++ ){
        QPointF pos = rand_pos();
        RepulsorBlock* block = new RepulsorBlock();
        block->init(pos);
        addItem(block);

        const qint32 r = block->ball_radius();
        const qint32 outr = block->outer_radius()*r;
        addEllipse(pos.x() - outr, pos.y() - outr, 2*outr, 2*outr, QPen(Qt::red));
    }
    for (int i = 0; i < 3; i++ ){
        QPointF pos = rand_pos();
        AttractorBlock* block = new AttractorBlock();
        block->init(pos);
        addItem(block);

        const qint32 r = block->ball_radius();
        const qint32 outr = block->outer_radius()*r;
        addEllipse(pos.x() - outr, pos.y() - outr, 2*outr, 2*outr, QPen(Qt::green));
    }
}


bool GameWorld::advance()
{
    QList<QGraphicsItem*> objlist = items();
    foreach(QGraphicsItem* curr, objlist)
    {
        Firefly* firefly = dynamic_cast<Firefly*>(curr);
        if (firefly == NULL) continue;

        foreach(QGraphicsItem* others, objlist)
        {
            GravitationalObject* other = dynamic_cast<GravitationalObject*>(others);
            if (other == NULL) continue;
            if (other == firefly) continue;

            QPointF acc = other->acceleration_between(*firefly);
            firefly->adjust_acceleration(acc);
        }
    }

    QRectF rc(sceneRect());
    foreach(QGraphicsItem* curr, objlist)
    {
        Firefly* firefly = dynamic_cast<Firefly*>(curr);
        if (firefly != NULL)
        {
            firefly->update(rc);
        }
    }
    return true;
}

