#version 430


in vec3 out_color;
in vec2 out_uv;

out vec4 finalColor;

float psin(float x)
{
  return sin(x) * 0.5f + 0.5f;
}
float pcos(float x)
{
  return cos(x) * 0.5f + 0.5f;
}

float mandelbrot(vec2 pos)
{
float scale = 1.5f;
//definition de la zone où on dessine
float x = pos.x * 5 - 2.5f;
float y = pos.y * 5 - 2.5f;
float x0 = pos.x * (scale * 2.0f) - scale;
float y0 = pos.y * (scale * 2.0f) - scale;


float x2 = 0.0f;
float y2 = 0.0f;
float w = 0.0f;
  for (int i = 0; i < 1000; i++)
  {
    x= x2 - y2 + x0;
    y= w - x2 - y2 + y0;
    x2= x * x;
    y2= y * y;
    w = (x + y) * (x + y);
    //x2 + y2 = z
    if (x2 + y2 >= 2 * 2)
    //dessine pas
      return 0.0f;
  }
  //dessine
  return 1.0f;
}



//equation d'un rectangle avec (a,b) et (c,d) => sqrt((a-x)(x-c)) * sqrt((b-y)(y-d)) =0 (x,y) le point qu'on cherche a tester
/*float intersectionRectangle(vec2 pos){
  float scale = 1.5f;
float x = pos.x * 5 - 2.5f;
float y = pos.y * 5 - 2.5f;
float x0 = pos.x * (scale * 2.0f) - scale;
float y0 = pos.y * (scale * 2.0f) - scale;
float x2 = 0.0f;
float y2 = 0.0f;
float w = 0.0f;
  for (int i = 0; i < 1000; i++)
  {
    x= x2 - y2 + x0;
    y= w - x2 - y2 + y0;
    x2= x * x;
    y2= y * y;
    w = (x + y) * (x + y);
    if (x2 + y2 >= 2 * 2)
      return 0.0f;
  }
  return 1.0f;
}





}*/

void main() {
  //vec3 color = vec3(psin(out_uv.x * 18.0f), pcos(out_uv.y * 18.0f), 1.0f); //* out_color;

  vec3 color = vec3(1.0f, 1.0f, 1.0f) * mandelbrot(out_uv);
  finalColor = vec4(color, 1.);
}
