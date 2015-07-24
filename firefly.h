#ifndef FIREFLY_H
#define FIREFLY_H

#include "gravitationalobject.h"


class Firefly : public GravitationalObject
{
public:
    Firefly();
    void init(const QPointF& pos);
    void set_velocity(const QPointF& vel);
    void adjust_acceleration(const QPointF& acc);
    void update(QRectF& rc);
    void setup_paint(const Status status);
    QPointF acceleration_between(const GravitationalObject& other);
    virtual qint32 ball_radius() const;
    virtual qint32 outer_radius() const;
    virtual qint32 inner_radius() const;
signals:

public slots:

private:
    QPointF m_acc;
    QPointF m_vel;
    QPointF m_pos;
};

#endif // FIREFLY_H
