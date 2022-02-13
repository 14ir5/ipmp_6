/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Bit manipulation
//show  bits
#include <iostream>

using namespace std;

/*void printbits(int n){
    
    if(n>=1)
    printbits(n>>1);
    
    int k=n&1;
    cout<<k;
}*/

void printbits(int n){
    long i=1<<31;
    while(i){
        int k=n&i;
        if(k==0)
        cout<<"0";
        else
        cout<<"1";
        i=i/2;
    }
    
}
int main()
{
    int n;
    cin>>n;
    
    printbits(n);
    
    return 0;
}
