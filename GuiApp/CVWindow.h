#pragma once

#include <QMainWindow>

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CVWindow;
}
QT_END_NAMESPACE

class CVWindow : public QMainWindow
{
    Q_OBJECT

public:
    CVWindow(QMainWindow* owner = nullptr);
    virtual ~CVWindow();

    CV_DISABLE_COPY_AND_ASSIGN(CVWindow)
};

