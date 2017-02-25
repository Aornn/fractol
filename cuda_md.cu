// This is the REAL "hello world" for CUDA!
// It takes the string "Hello ", prints it, then passes it to CUDA with an array
// of offsets. Then the offsets are added in parallel to produce the string "World!"
// By Ingemar Ragnemalm 2010
 
#include "fract.h"
__global__
void mandelbrot(t_mbrot *mbrot)
{
  int color = 0x01FEDC;
  mbrot->x = 0;

  while(mbrot->x < mbrot->image_x)
  {
    mbrot->y = 0;
    while(mbrot->y < mbrot->image_y)
    {
      mbrot->cr = mbrot->x / mbrot->zoom_x + mbrot->x1;
      mbrot->ci = mbrot->y / mbrot->zoom_y + mbrot->y1;
      mbrot->zr = 0;
      mbrot->zi = 0;
      mbrot->i = 0;
      while (mbrot->zr*mbrot->zr + mbrot->zi*mbrot->zi < 4 && mbrot->i < mbrot->itemax)
      {
        mbrot->tmp = mbrot->zr;
        mbrot->zr = mbrot->zr * mbrot->zr - mbrot->zi * mbrot->zi + mbrot->cr;
        mbrot->zi = 2*mbrot->zi*mbrot->tmp+mbrot->ci;
        mbrot->i ++;
      }
      if (mbrot->i != mbrot->itemax)
      { 
        mlx_put_pixel_image(mbrot->x, mbrot->y, mbrot, (color * mbrot->i + 499 / 10) / mbrot->itemax);
      }
      //else
      //  mlx_put_pixel_image(mbrot->x, mbrot->y, mbrot, color);//(color * 49 + mbrot->x) / mbrot->itemax);
      mbrot->y++;
    }
    mbrot->x++;
  }
}