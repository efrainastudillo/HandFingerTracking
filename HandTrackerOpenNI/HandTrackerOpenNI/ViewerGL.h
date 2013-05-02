#ifndef VIEWER_GL_H
#define VIEWER_GL_H
#pragma once
#include "libraries.h"
#include <GLTools\GLTools.h>
#include <GLTools\GLShaderManager.h>
#include <GLFrustum.h>
#ifdef __APPLE__
#include <glut/glut.h> // OS X version of GLUT
#else
#define FREEGLUT_STATIC
#include <GL\glut.h>// Windows FreeGlut equivalent
#endif

class ViewerGL{
public:
	static ViewerGL& getInstance();
	/*ViewerGL();*/
	/*ViewerGL(char *name);*/
	GLboolean setup(int &argc,char* argv[]);
	static GLvoid renderScene(GLvoid);
	static GLvoid changeSizeDisplay(GLint,GLint);
	static GLvoid onKey(unsigned char,int,int);
	GLvoid initialize(GLvoid);
	GLvoid run();

	//void setName(char *name);
private:
	ViewerGL();
	ViewerGL(const ViewerGL&);
	ViewerGL& operator=(const ViewerGL&);
	GLBatch triangleBatch;
	GLShaderManager shaderManager;
	GLFrustum viewFrustrum;
	char *name;
};
#endif