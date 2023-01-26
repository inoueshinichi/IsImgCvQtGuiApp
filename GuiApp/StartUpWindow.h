#pragma once

#include <QMainWindow>

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class StartUpWindow;
}
QT_END_NAMESPACE

class StartUpWindow : public QMainWindow
{
    Q_OBJECT
public:
    StartUpWindow(QWidget* owner = nullptr);
    ~StartUpWindow() {}

    CV_DISABLE_COPY_AND_ASSIGN(StartUpWindow)
};