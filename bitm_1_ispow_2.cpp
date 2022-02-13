/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Bit manipulation
//num power of 2?
#include <iostream>

using namespace std;
void ispow(int n){
    if(( n & (n-1) )==0)
    cout<<"true";
    else
    cout<<"false";
}
int main()
{
    int n;
    cin>>n;
    ispow(n);
    return 0;
}
