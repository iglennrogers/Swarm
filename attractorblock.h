#ifndef ATTRACTORBLOCK_H
#define ATTRACTORBLOCK_H

#include "gravitationalobject.h"


class AttractorBlock : public GravitationalObject
{
public:
    AttractorBlock();
    void setup_paint(const Status status);
    QPointF acceleration_between(const GravitationalObject& other);
    virtual qint32 ball_radius() const;
    virtual qint32 outer_radius() const;
    virtual qint32 inner_radius() const;

signals:

public slots:

};

#endif // ATTRACTORBLOCK_H
