#include "lightblock.h"

#include <QPen>
#include <QtDebug>
#include <cmath>


LightBlock::LightBlock() :
    GravitationalObject()
{
}


void LightBlock::setup_paint(const Status status)
{
    switch (status)
    {
    case Active:
    case Active2:
        setBrush(Qt::blue);
        setPen(QPen(Qt::cyan));
        break;
    default:
        setBrush(Qt::cyan);
        setPen(QPen(Qt::blue));
        break;
    }
}


QPointF LightBlock::acceleration_between(const GravitationalObject& other)
{
    Status oldstatus = m_status;

    QPointF gap = other.scenePos() - scenePos();
    qreal dist2 = gap.x()*gap.x() + gap.y()*gap.y();

    qreal band = sqrt(dist2)/ball_radius();
    if (band <= inner_radius())
    {
        m_status = Active2;
    }
    else if (band <= outer_radius())
    {
        m_status = Active;
    }
    else
    {
        m_status = Inactive;
    }

    if (m_status != oldstatus)
    {
        setup_paint( m_status );
        update();
    }

    if (m_status == Active) {

        qreal acc = -s_grav_constant/dist2;
        return QPointF(acc*gap);
    }
    else if (m_status == Active2)
    {
        qreal acc = 2*s_grav_constant/dist2;//(ball_radius()*ball_radius()*inner_radius()*inner_radius());
        return QPointF(acc*gap);
    }
    return QPointF();
}


qint32 LightBlock::ball_radius() const
{
    return 15;
}


qint32 LightBlock::outer_radius() const
{
    return 5;
}


qint32 LightBlock::inner_radius() const
{
    return 2;
}
