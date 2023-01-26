#pragma once

#include "CGWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CGWindow;
}
QT_END_NAMESPACE

class CGMainWindow : public CGWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(CGMainWindow)
};