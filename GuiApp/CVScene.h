#pragma once

#include <QGraphicsScene>
#include <QRectF>

class CVScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CVScene(qreal x, qreal y, qreal width, qreal height, class QObject* owner = nullptr);
    CVScene(const QRectF& sceneRect, class QObject* owner = nullptr);
    CVScene(class QObject* owner = nullptr);
    virtual ~CVScene();
};