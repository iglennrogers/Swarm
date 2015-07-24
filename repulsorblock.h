#ifndef REPULSORBLOCK_H
#define REPULSORBLOCK_H

#include "gravitationalobject.h"


class RepulsorBlock : public GravitationalObject
{
public:
    RepulsorBlock();
    void setup_paint(Status status);
    QPointF acceleration_between(const GravitationalObject& other);
    virtual qint32 ball_radius() const;
    virtual qint32 outer_radius() const;
    virtual qint32 inner_radius() const;

signals:

public slots:

};

#endif // REPULSORBLOCK_H
