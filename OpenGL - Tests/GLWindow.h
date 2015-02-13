#pragma once
#include <QtOpenGL\qglwidget>

class GLWindow : public QGLWidget
{
protected:
	void initializeGL();
	void paintGL();
public:
	GLWindow();
	~GLWindow();
};

