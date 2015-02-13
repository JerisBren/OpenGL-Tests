#include "stdafx.h"
#include <GL\glew.h>
#include "GLWindow.h"


GLWindow::GLWindow()
{
}


GLWindow::~GLWindow()
{
}

void GLWindow::initializeGL()
{
	glewInit();
}

void GLWindow::paintGL()
{

}
