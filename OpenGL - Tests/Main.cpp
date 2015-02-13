// OpenGL - Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GLWindow.h>

int _tmain(int argc, char* argv[])
{
	QApplication app(argc, argv);
	GLWindow meWindow;
	meWindow.show();
	return app.exec();
}

