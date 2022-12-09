#version 140
//430

uniform vec2 fielOfView;

uniform vec3 cameraPosition;

in vec2 screen;
in vec3 dir;
in vec2 coord;

out vec4 finalColor;

float distSphere(vec3 point)
{
  return distance(point, vec3(0, 0, -5)) - 1.0;
}

void main() {
  vec3 origin = -cameraPosition;

  vec3 color = vec3(0.0f, 0.0f, 0.0f);

  float min_dist = 1000.0;
  vec3 point = origin;
  for (int i = 0; i < 100; i++)
  {
    min_dist = 1000.0;
    float dist = distSphere(point);
    if (dist < min_dist)
    {
      min_dist = dist;
    }
    if (min_dist < 0.01)
    {
      color = vec3(1.0, 0.0, 0.0);
      break;
    }
    point += min_dist * dir;
  }

  //color = vec3(abs(dir.x), abs(dir.y), abs(dir.z));
  finalColor = vec4(color, 1.);
}
