#pragma once
#include <QtOpenGL\qglwidget>

class GLWindow : public QGLWidget
{
protected:
	void initializeGL();
	void paintGL();
	//void sendDataToOpenGL();
	//void installShaders();
/*public:
	GLWindow();
	~GLWindow();*/
};

