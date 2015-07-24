#ifndef LIGHTBLOCK_H
#define LIGHTBLOCK_H

#include "gravitationalobject.h"


class LightBlock : public GravitationalObject
{
public:
    LightBlock();
    void setup_paint(const Status status);
    QPointF acceleration_between(const GravitationalObject& other);
    virtual qint32 ball_radius() const;
    virtual qint32 outer_radius() const;
    virtual qint32 inner_radius() const;

signals:

public slots:

};

#endif // LIGHTBLOCK_H
