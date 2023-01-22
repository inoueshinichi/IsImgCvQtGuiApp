#include <iostream>

#include <QApplication>

#include "StartUpWindow.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;

    QApplication app(argc, argv);

    StartUpWindow startUpWindow;
    startUpWindow.show();

    return app.exec();
}