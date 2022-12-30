#version 140
in vec3 position;
in vec2 texCoords;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(position.x, position.y, 0.0, 1.0); 
    TexCoords = vec2(texCoords.y, 1.0-texCoords.x);
} 