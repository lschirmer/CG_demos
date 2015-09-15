//Problem 4807 ACM-ICPC Live Archive - Cocircular Points
//Leonardo Quatrin Campagnolo
//Solved using Cocircular Points formula
//http://en.wikipedia.org/wiki/Circumscribed_circle

#include <vector>
#include <cstdio>
#include <cmath>

typedef struct POINT
{
    double x;
    double y;

}Point;


int main()
{

    int n;
    scanf("%d",&n);
    while(n != 0)
    {
        std::vector<Point> points;
        int maxPoints = std::min(2,n);
        int a,b;
        for(int i = 0 ; i < n ; i++)
        {
            Point p;
            scanf("%d %d", &a, &b);
            p.x = (double)a;
            p.y = (double)b;
            points.push_back(p);
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                for(int k = j+1 ; k < n ; k++)
                {
                    Point A=points[i];
                    Point B=points[j];
                    Point C=points[k];

                    Point mcenter;
                    double D = 2.0 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
                    if(D != 0.0){
                        mcenter.x = ((A.y*A.y + A.x*A.x) * (B.y - C.y) + (B.y*B.y + B.x*B.x) * (C.y - A.y) + (C.y*C.y + C.x*C.x) * (A.y - B.y))/D;
                        mcenter.y = ((A.y*A.y + A.x*A.x) * (C.x - B.x) + (B.y*B.y + B.x*B.x) * (A.x - C.x) + (C.y*C.y + C.x*C.x) * (B.x - A.x))/D;
                    }else{
                        continue;
                    }
                    double r = ((mcenter.x - A.x)*(mcenter.x - A.x)) + ((mcenter.y - A.y)*(mcenter.y - A.y));
                    int pfound = 3;
                    for(int z = 0 ; z < n ; z++)
                    {
                        if(z != i && z != j && z != k){
                            double rf = ((mcenter.x - points[z].x)*(mcenter.x - points[z].x)) + ((mcenter.y - points[z].y)*(mcenter.y - points[z].y));
                            if(rf == r) {pfound++;}
                        }
                    }
                    maxPoints = std::max(maxPoints,pfound);
                }
            }
        }
        printf("%d\n",maxPoints);
        scanf("%d",&n);
    }
    return 0;
}
