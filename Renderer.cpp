#include <GL/glew.h>
#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include "Renderer.h"

using namespace glm;

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

Renderer::Renderer(int width, int height, std::string shaderBaseName){
  screenWidth = width;
  screenHeight = height;

  // create a new window
  window = SDL_SetVideoMode(width, height, 16, SDL_OPENGL | SDL_DOUBLEBUF);
  if (!window)
  {
    printf("Unable to set %i, %i video: %s\n", width, height, SDL_GetError());
    return;
  }
  // ATTENTION ne pas oublier l'initialisation de GLEW
  GLenum err = glewInit();

  //info version oenGL / GLSL :
  //info version oenGL / GLSL :
  std::cout << std::endl<< "***** Info GPU *****" << std::endl;
  std::cout << "Fabricant : " << glGetString (GL_VENDOR) << std::endl;
  std::cout << "Carte graphique: " << glGetString (GL_RENDERER) << std::endl;
  std::cout << "Version : " << glGetString (GL_VERSION) << std::endl;

  initOpenGL(shaderBaseName);
}
Renderer::~Renderer(){
  glDeleteProgram(programID);
  programID = -1;
}

void Renderer::initOpenGL(std::string shaderBaseName){
  string vert = "./Shaders/" + shaderBaseName + ".vert";
  string frag = "./Shaders/" + shaderBaseName + ".frag";
  programID = LoadShaders(vert.c_str(), frag.c_str());

  //recupere id
  locCameraPosition = glGetUniformLocation(programID, "cameraPosition");
  locCameraRotation = glGetUniformLocation(programID, "cameraRotation");
  locFieldOfView = glGetUniformLocation(programID, "fieldOfView");
  locScreenSize = glGetUniformLocation(programID, "screen_size");
  //locMatrixIDObject = glGetUniformLocation(programID, "Object");

  glGenVertexArrays(1, &vao);
  
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);  
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vec3), &vertices[0], GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
  
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderer::draw(Camera& camera, Scene& scene){
	glUseProgram(programID);
	glViewport(0,0,screenWidth,screenHeight);

	mat4 rotation = camera.getRotationMatrix();
	glUniformMatrix4fv(locCameraRotation, 1, GL_FALSE, &rotation[0][0]);
	glUniform3f(locCameraPosition,camera.getPosition().x,camera.getPosition().y,camera.getPosition().z);
	glUniform2f(locFieldOfView, camera.getFieldOfView().x, camera.getFieldOfView().y);
	glUniform2f(locScreenSize, (float)screenWidth, (float)screenHeight);
	//glUniformMatrix4fv(locMatrixIDObject, 1, GL_FALSE, &Object[0][0]);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	/*CODE POUR ENVOYER LES INFOS DE LA SCENE AU SHADER A FAIRE ICI
	L'objectif est d'envoyer des listes de donnees au shader
	Pour se faire, il faudra decommenter cette partie :
	//
	vector<mat4> objectMatrices;
	vector<Material> objectMaterials;
	vector<int> objectTypes;
	vector<float> objectDatas;
	vector<int> csg_type;
	vector<float> csg_value;
	scene.getInfos(objectMatrices, objectMaterials, objectTypes, objectDatas, csg_type, csg_value);
	
	//
	les parametres sont note comme ca car il faut les creer avant la fonction et les passer dedans pour qu'elle les initialise
	
	les donnees a envoyer (uniform ou buffer), devront respecter ce format

	objectMatrices, array de mat4
	objectMaterials, array de float, avec pour chaque Material 8 float en taille (vec4 couleur, plus 4 floats des proprietes), 
		c'est important de connaitre sa taille exacte en unite pour les arrays qui convertissent un type
	objectTypes, array de int, pourrait meme etre des unsigned char tellement il n'y aura pas beaucoup de types
	objectDatas, array de float

	*/

	glUseProgram(0);
}




GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}else{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::string Line = "";
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}



	GLint Result = GL_FALSE;
	int InfoLogLength;



	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}



	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}



	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}
