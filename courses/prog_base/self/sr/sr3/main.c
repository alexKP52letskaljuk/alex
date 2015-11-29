#include <stdio.h>
#include <stdlib.h>
struct zentr_radiys1{
float x;
float y;
float z;
} rol, rol2;

int main(){
    float a, b, c, d, e, g;
//struct zentr_radius1 rol;
//struct zentr_radius1 rol2;

printf("Vedit koordunatu zentra 1 kola x, y: ");
scanf("%f, %f", &a, &b);
printf("Vedit radius 1 kola: ");
scanf("%f", &c);
rol.x = a;
rol.y = b;
rol.z = c;
printf("Vedit koordunatu zentra 2 kola x, y: ");
scanf("%f, %f", &d, &e);
printf("Vedit radius 2 kola: ");
scanf("%f", &g);
rol2.x = d;
rol2.y = e;
rol2.z = g;
if(sqrt ((rol.x - rol2.x)*(rol.x - rol2.x) + (rol.y - rol2.y)*(rol.y - rol2.y)) < (rol.z+rol2.z))
    {
        printf("Peretunaytsa \n");
        return 0;
    }
else
    return 1;
}
