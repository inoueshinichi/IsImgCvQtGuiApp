#pragma once

#include "CVCameraStreamWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVMonoCamWindow;
}
QT_END_NAMESPACE

class CVMonoCamWindow : public CVCameraStreamWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(CVMonoCamWindow)
};