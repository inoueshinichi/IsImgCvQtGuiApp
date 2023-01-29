#include <iostream>

#include <QApplication>

#include "StartUpWindow.h"

#include "CVEngine.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;

    QApplication app(argc, argv);

    StartUpWindow startUpWindow;
    startUpWindow.show();

    CVEngine engine;
    if (engine.Initialize())
    {
        engine.Run();
    }

    return app.exec();
}