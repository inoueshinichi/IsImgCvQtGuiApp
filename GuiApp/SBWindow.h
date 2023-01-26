#pragma once

#include <QMainWindow>

#include "CVDefs.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class SBWindow;
}
QT_END_NAMESPACE

class SBWindow : public QMainWindow
{
    Q_OBJECT
public:
    CV_DISABLE_COPY_AND_ASSIGN(SBWindow)
};