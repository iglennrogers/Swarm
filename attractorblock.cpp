#include "attractorblock.h"

#include <QPen>
#include <QtDebug>
#include <cmath>


AttractorBlock::AttractorBlock() :
    GravitationalObject()
{
}


void AttractorBlock::setup_paint(const Status status)
{
    switch (status)
    {
    case Active:
    case Active2:
        setBrush(Qt::cyan);
        setPen(QPen(Qt::green));
        break;
    default:
        setBrush(Qt::green);
        setPen(QPen(Qt::cyan));
        break;
    }
}


QPointF AttractorBlock::acceleration_between(const GravitationalObject& other)
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
        qreal acc = -s_grav_constant/(ball_radius()*ball_radius()*inner_radius()*inner_radius());
        return QPointF(acc*gap);
    }
    return QPointF();
}


qint32 AttractorBlock::ball_radius() const
{
    return 15;
}


qint32 AttractorBlock::outer_radius() const
{
    return 5;
}


qint32 AttractorBlock::inner_radius() const
{
    return 1;
}
