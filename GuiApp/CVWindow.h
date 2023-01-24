#pragma once

#include <QMainWindow>

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
};

