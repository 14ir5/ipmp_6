/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
void rightset(int n){
    int k=log (n & ~(n-1));
    cout<<k+1;
}
int main()
{
    int n;
    cin>>n;
    rightset(n);

    return 0;
}
