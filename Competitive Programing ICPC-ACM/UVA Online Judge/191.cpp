//Problem 378 UVA ONLINE - Intersection Lines
//Leonardo Quatrin Campagnolo
//Using intersection functions

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
#define SMALL_NUM 0.01f

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


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
    {
        Point l1 = Point();
        Point l2 = Point();
        float xleft, xright;
        float ytop, ybottom;
        scanf("%f%f", &l1.x, &l1.y);
        scanf("%f%f", &l2.x, &l2.y);
        scanf("%f%f", &xleft, &ytop);
        scanf("%f%f", &xright, &ybottom);

        bool achou = false;

        Point p1 = Point(xleft, ybottom, 0.f);
        Point p2 = Point(xright, ybottom, 0.f);
        if(intersection(l1.x,l1.y,l2.x,l2.y,p1.x,p1.y,p2.x,p2.y))
        {
            achou = true;
        }
        p1 = Point(xleft, ytop, 0.f);
        p2 = Point(xright, ytop, 0.f);
        if(intersection(l1.x,l1.y,l2.x,l2.y,p1.x,p1.y,p2.x,p2.y))
        {
            achou = true;
        }
        p1 = Point(xleft, ytop, 0.f);
        p2 = Point(xleft, ybottom, 0.f);
        if(intersection(l1.x,l1.y,l2.x,l2.y,p1.x,p1.y,p2.x,p2.y))
        {
            achou = true;
        }
        p1 = Point(xright, ytop, 0.f);
        p2 = Point(xright, ybottom, 0.f);
        if(intersection(l1.x,l1.y,l2.x,l2.y,p1.x,p1.y,p2.x,p2.y))
        {
            achou = true;
        }

        if(achou)
        {
            printf("T\n");
        }else{
            printf("F\n");
        }
    }
    return 0;
}
