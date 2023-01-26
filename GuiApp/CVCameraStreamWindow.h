#pragma once

#include "CVStreamWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVCameraStreamWindow;
}
QT_END_NAMESPACE

class CVCameraStreamWindow : public CVStreamWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(CVCameraStreamWindow)
};