#include "CVView.h"
#include "CVScene.h"

#include <QWidget>


CVView::CVView(CVScene* scene, QWidget* owner)
    : QGraphicsView(scene, owner)
{

}

CVView::CVView(QWidget* owner)
    : QGraphicsView(owner)
{

}

CVView::~CVView()
{

}