#version 140

uniform sampler2D u_texture;  // The texture  (we'll bind to texture unit 0)

out vec4 FragColor;
  
in vec2 TexCoords;

void main()
{ 
    FragColor = texture(u_texture, TexCoords);
}