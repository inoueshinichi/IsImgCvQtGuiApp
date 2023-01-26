#pragma once

#include "CVWindow.h"

#include "CVEngine.h"

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVMainWindow;
}
QT_END_NAMESPACE

class CVMainWindow : public CVWindow
{
    Q_OBJECT

public:
    CVMainWindow(class CVWindow* owner = nullptr);
    ~CVMainWindow();
private:
    CVEngine mCvEngine;

    CV_DISABLE_COPY_AND_ASSIGN(CVMainWindow)
};