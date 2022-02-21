/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//point inside triangle or not
#include <iostream>

using namespace std;
struct point{
    int x;
    int y;
};
float area(point a,point b,point c){
    return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y))/2.0);
}
bool isinside(point p[],point a){
    float A = area (p[0] ,p[1], p[2]);
  
   float A1 = area (p[0] ,p[1], a);
   float A2 = area (p[0] ,p[2], a);
   float A3 = area (p[2] ,p[1], a);
   return (A == A1 + A2 + A3);
}
int main()
{
    point p[]={{0,0},{20,0},{10,30}};
    point a;
    cout<<"enter x and y coordinates of point "<<endl;
    cin>>a.x;
    cin>>a.y;
    if(isinside(p,a))
    cout<<"inside"<<endl;
    else
    cout<<"outside";
    return 0;
}
