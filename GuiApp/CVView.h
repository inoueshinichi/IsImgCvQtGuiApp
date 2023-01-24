#pragma once

#include <QGraphicsView>

class CVView : public QGraphicsView
{
    Q_OBJECT
public:
    CVView(class CVScene* scene, class QWidget* owner = nullptr);
    CVView(class QWidget* owner = nullptr);
    virtual ~CVView();
};