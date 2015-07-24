#ifndef GRAVITATIONALOBJECT_H
#define GRAVITATIONALOBJECT_H

#include <QtWidgets/QGraphicsEllipseItem>


class GravitationalObject : public QGraphicsEllipseItem
{
protected:
    enum Status
    {
        Unknown,
        Active,
        Active2,
        Inactive,
        Disabled
    };

public:
    GravitationalObject();
    virtual void init(const QPointF& pos);

    virtual void setup_paint(const Status status) = 0;
    virtual QPointF acceleration_between(const GravitationalObject& other) = 0;
    virtual qint32 ball_radius() const = 0;
    virtual qint32 outer_radius() const = 0;
    virtual qint32 inner_radius() const;

    static const qint32 s_grav_constant = 50;

protected:
    Status m_status;

signals:

public slots:

};

#endif // GRAVITATIONALOBJECT_H
