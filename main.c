#include <stdio.h>
#include <math.h>
float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularPerimetro(float puntos [4][3], float *a, float *b, float *c, float *d, float *e, float *f);
float calcularArea (float a, float b, float c);
void calcularBaricentro (float puntos[4][3], float *gx, float *gy, float *gz);
void calcularAltura(float a, float b, float c, float gx, float gy, float gz, float puntos[4][3], float *altura);
float calcularVolumen(float altura, float areabase);

int main(int argc, char const *argv[])
{
    float puntos [4][3]={{0,0,0},{0,0,3},{3,0,0},{1,7,1}};
    float a, b, c, d, e ,f, gx, gy, gz, altura;
    
    float perimetro=calcularPerimetro(puntos, &a,&b,&c,&d,&e,&f);
    float areabase= calcularArea(a,b,c);
    float area1= calcularArea(a,d,e);
    float area2= calcularArea(b,d,f);
    float area3= calcularArea(c,e,f);
    calcularAltura(a, b, c, gx, gy, gz, puntos, &altura);
    float volumen= calcularVolumen(altura, areabase);
    printf("El perimetro es: %.2f \n", perimetro);
    float areatotal=areabase+area1+area2+area3;
    printf("El area del triangulo es: %.2f\n", areatotal);
    printf("El volumen es: %.2f", volumen);
    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2){
    float dist=sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
    return dist;
}
float calcularPerimetro(float puntos [4][3], float *a, float *b, float *c, float *d, float *e, float *f){
    *a=calcularDistancia (puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b=calcularDistancia (puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c=calcularDistancia (puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);

    *d=calcularDistancia (puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e=calcularDistancia (puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f=calcularDistancia (puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float perimetro= *a + *b + *c +*d+*e+*f;
    return perimetro;
}
float calcularArea (float a, float b, float c){
    float s=(a+b+c)/2;
    float area= sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
void calcularBaricentro (float puntos[4][3], float *gx, float *gy, float *gz){
    *gx=(puntos[0][0]+puntos[1][0]+puntos[2][0]+puntos[3][0])/3;
    *gy=(puntos[0][1]+puntos[1][1]+puntos[2][1]+puntos[3][1])/3;
    *gz=(puntos[0][2]+puntos[1][2]+puntos[2][2]+puntos[3][2])/3;
}
void calcularAltura(float a, float b, float c, float gx, float gy, float gz, float puntos[4][3], float *altura){
    *altura=calcularDistancia(gx, gy, gz, puntos[3][0], puntos[3][1], puntos[3][2]);
}

float calcularVolumen(float altura, float areabase){

    float volumen= (areabase*altura)/3;
    return volumen;
}