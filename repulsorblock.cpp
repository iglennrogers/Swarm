#include "repulsorblock.h"

#include <QPen>
#include <QtDebug>
#include <cmath>


RepulsorBlock::RepulsorBlock() :
    GravitationalObject()
{
}


void RepulsorBlock::setup_paint(const Status status)
{
    switch (status)
    {
    case Active:
    case Active2:
        setBrush(Qt::red);
        setPen(QPen(Qt::magenta));
        break;
    default:
        setBrush(Qt::magenta);
        setPen(QPen(Qt::red));
        break;
    }
}


QPointF RepulsorBlock::acceleration_between(const GravitationalObject& other)
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

        qreal acc = s_grav_constant/dist2;
        return QPointF(acc*gap);
    }
    else if (m_status == Active2)
    {
        qreal acc = s_grav_constant/(ball_radius()*ball_radius()*inner_radius()*inner_radius());
        return QPointF(acc*gap);
    }
    return QPointF();
}


qint32 RepulsorBlock::ball_radius() const
{
    return 15;
}


qint32 RepulsorBlock::outer_radius() const
{
    return 5;
}


qint32 RepulsorBlock::inner_radius() const
{
    return 1;
}
