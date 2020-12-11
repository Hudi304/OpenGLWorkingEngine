#define GLEW_STATIC

#include <iostream>
#include "OpenGL dev libs/include/GL/glew.h"
#include "OpenGL dev libs/include/GLFW/glfw3.h"

int glWindowWidth = 640;
int glWindowHeight = 480;

GLFWwindow* glWindow = NULL;

bool initOpenGLWindow()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return false;
	}

	glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "Hello Window", NULL, NULL);
	if (!glWindow) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(glWindow);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	return true;
}

void processEvents(){
	if (glfwGetKey(glWindow, GLFW_KEY_A)) {
		//TODO
		std::cout << "PRESSED KEY A" << "\n";
	}
}

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 1, 1.0);
}

int main(int argc, const char * argv[]) {

	initOpenGLWindow();

	while (!glfwWindowShouldClose(glWindow)) {

		renderScene();
		processEvents();
		
		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}
	//close GL context and any other GLFW resources
	glfwTerminate();

	return 0;
}
