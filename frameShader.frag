#version 140

uniform sampler2D currentFrame;  // The texture  (we'll bind to texture unit 0)
uniform sampler2D newFrame;   // The bump-map (we'll bind to texture unit 1)

uniform float keep;

out vec4 FragColor;
  
in vec2 TexCoords;

void main()
{ 
    vec4 currentColor = texture(currentFrame, TexCoords);
    vec4 newColor = texture(newFrame, TexCoords);

    FragColor = newColor * (1 - keep) + currentColor * keep;
}