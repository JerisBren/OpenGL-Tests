#include "stdafx.h"

const char* vertexShaderCode =
"#version 140\r\n"
""
"in layout(location=0) vec2 position;" // location = 0 - > refer to the VertexAttribArray = 0, generally position, vec2 -> 2 floats
"in layout(location=1) vec3 vertexColor;"
""
"out vec3 theColor;"
""
"void main()"
"{"
"	gl_position = vec4(position, 0.0, 1.0);" // gl_position its a vec4 attribute, then we need to transform the position that its a vec2 in a vec4;
"	theColor = vertexColor;"
"}";

const char* fragmentShaderCode =
"#version 140\r\n"
""
"out vec4 gl_FragColor;"
"in vec3 theColor;"
""
"void main()"
"{"
"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
"}";