#pragma once

#include "CVCameraStreamWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVSteCamWindow;
}
QT_END_NAMESPACE

class CVSteCamWindow : public CVCameraStreamWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(CVSteCamWindow)
};