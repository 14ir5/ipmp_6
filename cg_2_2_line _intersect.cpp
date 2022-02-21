/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//2 line segments intersect?
//orientation-using slope
#include <iostream>

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
int main()
{
    point a1,a2,b1,b2;
    cout<<"line segment 1 end1 : x and y "<<endl;
    cin>>a1.x;
    cin>>a1.y; 
     cout<<"line segment 1 end2 : x and y "<<endl;
    cin>>a2.x;
    cin>>a2.y;
     cout<<"line segment 2 end1 : x and y"<<endl;
    cin>>b1.x;
    cin>>b1.y;
    cout<<"line segment 2 end2 : x and y"<<endl;
    cin>>b2.x;
    cin>>b2.y;
    if(intersect(a1,a2,b1,b2))
    cout<<"intersecting"<<endl;
    cout<<"do not intersect"<<endl;
    return 0;
}
