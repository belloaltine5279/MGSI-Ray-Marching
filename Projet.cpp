#include <GL/glew.h>
#include <glm/glm.hpp>

#include <iostream>
#include <SDL/SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

using namespace std;
using namespace glm;

#include "Scene.h"
#include "Renderer.h"
#include "Camera.h"

#include "Material.h"

#include "Objects/Sphere.h"

int WIDTH = 800;
int HEIGHT = 600;

int main(int argc, char** argv)
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);


    Renderer renderer(WIDTH, HEIGHT, "shader");
    Camera camera(vec3(0.0f, 0.0f, 0.0f), vec3(0.0f,0.0f,0.0f), vec2(90.0f, 90.0f));

    Scene scene();
    Material material(vec3(1.0f,0.0f,0.0f), 0.7f, 20.0f, 0.0f);
    Sphere sphere(vec3(0.0f, 0.0f, -10.0f), 1.0f, material);

    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
                case SDL_QUIT:
                    done = true;
                    break;

                    // check for keypresses
                case SDL_KEYDOWN:

                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                    // check for keypresses
                /*
                case SDL_MOUSEBUTTONDOWN:
                    mouse(event.button.button,SDL_MOUSEBUTTONDOWN, event.button.x,event.button.y) ;
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouse(event.button.button,SDL_MOUSEBUTTONUP, event.button.x,event.button.y) ;
                    break;
                case SDL_MOUSEMOTION:
                    mousemotion(event.button.x,event.button.y) ;
                    break;
                */
            } // end switch
        } // end of message processing

        renderer.draw(camera);
        //On echange les buffers
        SDL_GL_SwapBuffers();
    }
}