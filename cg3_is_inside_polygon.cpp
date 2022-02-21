/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//is inside polygon
#include <iostream>
#include <climits>
using namespace std;
struct point{
    int x;
    int y;
};
bool onsegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
int orientation(point p, point q, point r)
{
    
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
bool intersect(point a1,point a2,point b1,point b2){
    int o1 = orientation(a1, a2, b1);
    int o2 = orientation(a1, a2, b2);
    int o3 = orientation(b1, b2, a1);
    int o4 = orientation(b1, b2, a2);
    if(o1!=o2&&o3!=o4){
        return true;
    }
    if(o1==0 && onsegment(a1,b1,a2))//if b1 collinear with a1-a2 ,checks if b1 lies on a1-a2
    return true;
    if(o2==0 && onsegment(a1,b2,a2))
    return true;
    if(o3==0 && onsegment(b1,a1,b2))
    return true; 
    if(o4==0 && onsegment(b1,a2,b2))
    return true; 
    
    return false;
}
bool isInside(point polygon[], int n, point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3) return false;
 
    // Create a point for line segment from p to infinite
    point extreme = {INT_MAX, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
    
        if (intersect(polygon[i], polygon[next], p, extreme))
        {
        
            if (orientation(polygon[i], p, polygon[next]) == 0)
            return onsegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return (count%2 == 1);
}
int main()
{
    point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    point p = {3, 3};
    isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";
    return 0;
}
