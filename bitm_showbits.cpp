/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Bit manipulation
//reverse bits
#include <iostream>

using namespace std;

void printbits(int n){
    
    if(n>1)
    printbits(n>>1);
    
    int k=n&1;
    cout<<k;
}
void rev(int num){
    int tmp=0;
    while(num){
        tmp=tmp<<1;
        tmp=tmp|(num & 1);
        int k=tmp & 1;
        cout<<k;
        num=num>>1;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"b4 reversal"<<endl;
    printbits(n);
    cout<<endl;
    rev(n);
    
    return 0;
}
