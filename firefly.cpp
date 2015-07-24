#include "firefly.h"

#include <QtWidgets/QGraphicsScene>
#include <QPen>
#include <cassert>
#include <QDebug>
#include <cmath>


Firefly::Firefly() :
    GravitationalObject(), m_acc(0,0), m_vel(0,0), m_pos(0,0)
{
}


void Firefly::init(const QPointF& pos)
{
    GravitationalObject::init(pos);
    m_pos = this->pos();
}


void Firefly::setup_paint(const Status status)
{
    setBrush(Qt::yellow);
    setPen(QPen(Qt::green));
}


void Firefly::set_velocity(const QPointF& vel)
{
    m_vel = vel;
}


QPointF Firefly::acceleration_between(const GravitationalObject& other)
{
    assert(false);
    return QPointF();
}


void Firefly::adjust_acceleration(const QPointF& acc)
{
    m_acc += acc;
}


void Firefly::update(QRectF& rc)
{
    QPointF oldpos = m_pos;
    m_vel += m_acc;
    if (m_pos.x() < rc.left())
    {
        m_vel.setX(std::abs(m_vel.x()));
    }
    else if (m_pos.x() > rc.right())
    {
        m_vel.setX(-std::abs(m_vel.x()));
    }
    if (m_pos.y() < rc.top())
    {
        m_vel.setY(std::abs(m_vel.y()));
    }
    else if (m_pos.y() > rc.bottom())
    {
        m_vel.setY(-std::abs(m_vel.y()));
    }
    m_pos += m_vel;
    setPos(m_pos);
    m_acc.setX(0);
    m_acc.setY(0);

    scene()->addLine(oldpos.x(), oldpos.y(), m_pos.x(), m_pos.y(), QPen(Qt::gray));
}


qint32 Firefly::ball_radius() const
{
    return 10;
}


qint32 Firefly::outer_radius() const
{
    return 1;
}


qint32 Firefly::inner_radius() const
{
    return 1;
}
