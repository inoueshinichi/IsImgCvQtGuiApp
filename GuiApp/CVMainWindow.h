#pragma once

#include "CVWindow.h"

#include "CVEngine.h"

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
};