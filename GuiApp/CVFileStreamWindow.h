#pragma once

#include "CVStreamWindow.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVFileStreamWindow;
}
QT_END_NAMESPACE

class CVFileStreamWindow : public CVStreamWindow
{
    Q_OBJECT
public:

    CV_DISABLE_COPY_AND_ASSIGN(CVFileStreamWindow)
};