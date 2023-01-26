#pragma once

#include <QGraphicsView>

#include "CVDefs.h"

class CVView : public QGraphicsView
{
    Q_OBJECT
public:
    CVView(class CVScene* scene, class QWidget* owner = nullptr);
    CVView(class QWidget* owner = nullptr);
    virtual ~CVView();

    CV_DISABLE_COPY_AND_ASSIGN(CVView)
};