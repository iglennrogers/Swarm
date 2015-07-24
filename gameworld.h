#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <QtWidgets/QGraphicsScene>

class GameWorld : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameWorld(QObject *parent = 0);
    void init_backdrop();
    void init();
    bool advance();

signals:

public slots:

};

#endif // GAMEWORLD_H
