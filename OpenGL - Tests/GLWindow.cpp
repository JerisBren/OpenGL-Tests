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

	GLfloat verts[]
	{
		+0.0f, +0.0f, // 0                     position
		+1.0f, +0.0f, +0.0f,                 //color ( not using right now)
		+1.0f, +1.0f, // 1
		+1.0f, +0.0f, +0.0f,
		-1.0f, +1.0f, // 2
		+1.0f, +0.0f, +0.0f,
		-1.0f, -1.0f, // 3
		+1.0f, +0.0f, +0.0f,
		+1.0f, -1.0f, // 4
		+1.0f, +0.0f, +0.0f,
	};

	GLuint VertexBufferID;                         // Data ta will store an ID for the buffer
	glGenBuffers(1, &VertexBufferID);              // Creates an Buffer and store his ID/ pointer

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID); // Bind the buffer to a data type

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),    // Copy the data to the buffer, static draw because they won't be modifyed.
				 verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);                   // Give an ID to some specific data that will be use, in this case, position.

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);     // Tells OpenGL how he will interpretate the data, 2 floats makes a position
																			   // and jumps 5 floats from the beginning of each iteration to found the another one
	glEnableVertexAttribArray(1);                                              // ID for the color

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (char*)(2 * sizeof(float)));   // for the ID 1 (color) pick up 3 floats, and jumps 5 floats from the beginning of the iteration for the next and starts the first iteration after 2 floats

	GLushort indices[] = { 0,1,2, 0,3,4};					    // indices related to the position, 0 means the first vertex, 1 the second ...
	GLuint indexBufferID;									    // ID for the buffer where the indices will be allocated
		
	glGenBuffers(1, &indexBufferID);							//relating the id 1 to the buffer ID
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);		// copying data to the buffer and telling thats an element array
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		         indices, GL_STATIC_DRAW);
}

void GLWindow::paintGL()
{
	glViewport(0, 0, width(), height());							  // adjust the openGL to use all the screen
	//glDrawArrays(GL_TRIANGLES, 0, 6);                               // draws triangles from the element_array_buffer, telling him that has 6 vertex in the array
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);			  // draws triangles based on the indices in the Element_array related to the vertex in the array_buffer
}
