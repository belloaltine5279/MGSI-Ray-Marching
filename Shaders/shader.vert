#version 430


layout(location = 0) in vec3 position; // le location permet de dire de quel flux/canal on récupère la données
layout(location = 1) in vec3 color; // le location permet de dire de quel flux/canal on récupère la données
layout(location = 2) in vec2 uv; // le location permet de dire de quel flux/canal on récupère la données

uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

out vec3 out_color;
out vec2 out_uv;

void main(){
  out_color = color;
  out_uv = uv;
  gl_Position = P * V * M * vec4(position, 1.0);
}
