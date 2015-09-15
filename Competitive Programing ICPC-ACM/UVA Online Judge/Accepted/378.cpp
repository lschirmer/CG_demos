//Problem 378 UVA ONLINE - Intersection Lines
//Leonardo Quatrin Campagnolo
//Using intersection functions

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define SMALL_NUM 0.0001
using namespace std;
class Point {
public:
   float x, y, z;

   Point() {
      x = y = z = 0;
   }

   Point(float x1, float y1, float z1) {
      x = x1;
      y = y1;
      z = z1;
   }

   Point operator - (Point a) {
      return Point(x - a.x, y - a.y, z - a.z);
   }

   Point operator + (Point a) {
      return Point (x + a.x, y + a.y, z + a.z);
   }

   Point operator / (float a) {
      return Point (x / a, y / a, z / a);
   }

   Point operator * (float a) {
      return Point (x * a, y * a, z * a);
   }
};

float dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
float norma(Point a) {
	return sqrt(dot(a, a));
}

bool linesCoincident(Point p1, Point p2, Point p3, Point p4)
{
    float nominator_ua = ((p4.x - p3.x)*(p1.y - p3.y)) - ((p4.y - p3.y)*(p1.x - p3.x));
    float denominator_ua = ((p4.y - p3.y)*(p2.x - p1.x)) - ((p4.x - p3.x)*(p2.y - p1.y));
    float nominator_ub = ((p2.x - p1.x)*(p1.y - p3.y)) - ((p2.y - p1.y)*(p1.x - p3.x));
    float denominator_ub = ((p4.y - p3.y)*(p2.x - p1.x)) - ((p4.x - p3.x)*(p2.y - p1.y));
    //Se os nominadores e denominadores para ua e ub forem 0, então as linhas são
    //coincidentes.
    //se apenas os denominadores forem iguais a zero, então as retas são paralelas.
    if(nominator_ua == 0.f && denominator_ua == 0.f
       && nominator_ub == 0.f && denominator_ub == 0.f)
       {
        return true;
       }
    return false;
}

Point* intersection(Point p1, Point p2, Point p3, Point p4) {
    // Store the values for fast access and easy
    // equations-to-code conversion
    float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
    float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;

    float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    // If d is zero, there is no intersection
    if (d == 0)
    {
        return NULL;
    }

    // Get the x and y
    float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
    float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
    float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

    // Checa se as coordenadas do ponto então entre os dois segmentos
    //OBS: Se for linhas, esse código deve ser comentado, pois essa
    //parte do código é apenas quando se lida com SEGMENTOS de reta.
    /*if ( x < min(x1, x2) || x > max(x1, x2) ||
        x < min(x3, x4) || x > max(x3, x4) ) return NULL;
    if ( y < min(y1, y2) || y > max(y1, y2) ||
        y < min(y3, y4) || y > max(y3, y4) ) return NULL;*/

    // Retorna o ponto da intersecção
    Point* ret = new Point();
    ret->x = x;
    ret->y = y;
    return ret;
}


int main()
{
    int n;
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    for(int i = 0 ; i < n ; i++)
    {
        Point p1 = Point();
        Point p2 = Point();
        Point p3 = Point();
        Point p4 = Point();
        scanf("%f%f", &p1.x, &p1.y);
        scanf("%f%f", &p2.x, &p2.y);
        scanf("%f%f", &p3.x, &p3.y);
        scanf("%f%f", &p4.x, &p4.y);
        p1.z = p2.z = p3.z = p4.z = 0.f;
        Point *t = intersection(p1,p2,p3,p4);
        if(t == NULL)
        {
            if(linesCoincident(p1,p2,p3,p4)){
                printf("LINE\n");
            }
            else
            {
                printf("NONE\n");
            }
        }else{
            printf("POINT %.2f %.2f\n", t->x, t->y );
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
