#version 140
//430


//layout(location = 0) in vec3 position; // le location permet de dire de quel flux/canal on récupère la données
//layout(location = 1) in vec3 color; // le location permet de dire de quel flux/canal on récupère la données
//layout(location = 1) in vec2 uv; // le location permet de dire de quel flux/canal on récupère la données

uniform vec3 cameraPosition;
uniform vec3 cameraRotation;
uniform vec2 fielOfView;

in vec3 position;

uniform vec2 screen_size;

//out vec3 out_color;
out vec2 screen;
out vec2 dir;

void main(){
  //out_color = color;
  //out_uv = uv;
  //gl_Position = P * V * M * vec4(position, 1.0);
  gl_Position = vec4(position, 1.0f);
  dir = vec2((gl_Position.x + 1.0f) / 2.0f, (-gl_Position.y + 1.0f) / 2.0f);
  screen.x = dir.x * screen_size.x;
  screen.y = dir.y * screen_size.y;
}
