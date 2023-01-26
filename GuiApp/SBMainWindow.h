
#pragma once

#include "SBWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class SBMainWindow;
}
QT_END_NAMESPACE

class SBMainWindow : public SBWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(SBMainWindow)
};