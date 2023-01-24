#include "CVScene.h"

#include <QObject>
#include <QRectF>


CVScene::CVScene(qreal x, qreal y, qreal width, qreal height, QObject* owner)
    : QGraphicsScene(x, y, width, height, owner)
{

}


CVScene::CVScene(const QRectF& sceneRect, QObject* owner)
    : QGraphicsScene(sceneRect, owner)
{

}

CVScene::CVScene(QObject* owner)
    : QGraphicsScene(owner)
{

}
    
CVScene::~CVScene()
{

}

