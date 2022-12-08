#version 140
//430

in vec2 screen;
in vec2 dir;

out vec4 finalColor;

float psin(float x)
{
  return sin(x) * 0.5f + 0.5f;
}
float pcos(float x)
{
  return cos(x) * 0.5f + 0.5f;
}

void main() {
  float times = 3.0;
  vec3 color = vec3(pcos(dir.x * 3.141 * 2.0 * times), 1.0f, psin(dir.y * 3.141 * 2.0 * times));
  finalColor = vec4(color, 1.);
}
