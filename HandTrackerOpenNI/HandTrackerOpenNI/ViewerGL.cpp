#include "ViewerGL.h"

ViewerGL::ViewerGL(){
	name="Default Window";
}

ViewerGL::ViewerGL(const ViewerGL& v){
	
}
ViewerGL& ViewerGL::operator=(const ViewerGL&){ 
	return this->getInstance();
}

ViewerGL& ViewerGL::getInstance(){
	static ViewerGL viewer;
	return viewer;
}
GLvoid ViewerGL::onKey(unsigned char key,GLint x,GLint y){
	switch(key){
	case GLUT_KEY_RIGHT:
		exit(0);
		break;
	case GLUT_KEY_LEFT:
		break;
	default:
		break;
	}
}
GLvoid ViewerGL::changeSizeDisplay(GLint width,GLint height){
	if(height==0)
		height=1;

	glViewport(0,0,width,height);

	ViewerGL::getInstance().viewFrustrum.SetPerspective(35.0f,float(width)/float(height),1.0f,1000.0f);
}
GLvoid ViewerGL::renderScene(GLvoid){
	//clear the window with the current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	GLfloat vRed[]={1.0f , 0.0f , 0.0f , 1.0f};
	M3DMatrix44f m;
	m3dTranslationMatrix44(m,12.0f,5.0f,0.0f);
	ViewerGL::getInstance().shaderManager.UseStockShader(GLT_SHADER_FLAT,m,vRed);
	ViewerGL::getInstance().triangleBatch.Draw();
	glutSwapBuffers();
}
GLvoid ViewerGL::initialize(){
	//blue background
	glClearColor(0.0f,0.0f,1.0f,1.0f);
	shaderManager.InitializeStockShaders();
	// Load up a triangle
	GLfloat vVerts[] = { -0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,
	0.0f, 0.5f, 0.0f };
	triangleBatch.Begin(GL_TRIANGLES,3);
	triangleBatch.CopyVertexData3f(vVerts);
	triangleBatch.End();
}

GLboolean ViewerGL::setup(int &argc,char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutCreateWindow(name);
	glutReshapeFunc(changeSizeDisplay);
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(onKey);
	

	GLenum err = glewInit();
	if(err!=GLEW_OK){
		std::cout<<"GLEW Error: "<<glewGetErrorString(err)<<std::endl;
		return false;
	}
	return true;
}

GLvoid ViewerGL::run(){
	glutMainLoop();
}