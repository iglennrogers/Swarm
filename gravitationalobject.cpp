#include "gravitationalobject.h"

#include <QPen>


GravitationalObject::GravitationalObject() :
    QGraphicsEllipseItem(0), m_status(Unknown)
{
}


void GravitationalObject::init(const QPointF& pos)
{
    const qint32 r = ball_radius();
    setPos(pos.x(), pos.y());
    setRect(-r, -r, 2*r, 2*r);
    setup_paint(Unknown);
}


qint32 GravitationalObject::inner_radius() const
{
    return outer_radius();
}
