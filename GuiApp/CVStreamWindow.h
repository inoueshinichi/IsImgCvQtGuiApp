#pragma once

#include "CVWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVWindow;
}
QT_END_NAMESPACE

class CVStreamWindow : public CVWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(CVStreamWindow)
};