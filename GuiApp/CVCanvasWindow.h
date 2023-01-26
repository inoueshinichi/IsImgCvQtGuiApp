#pragma once

#include "CVWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVCanvasWindow;
}
QT_END_NAMESPACE

class CVCanvasWindow : public CVWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(CVCanvasWindow)
};