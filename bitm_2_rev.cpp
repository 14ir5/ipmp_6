/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Bit manipulation
//count set bits
//2 meth
#include <iostream>

using namespace std;

void printbits(int n){
    
    if(n>1)
    printbits(n>>1);
    
    int k=n&1;
    cout<<k;
}
/*void nsetb(int n){
    int cnt=0;
    while(n){
        
        if(n&1==1)
        cnt++;
        n=n>>1;
    }
    cout<<"count="<<cnt;
}*/
void nsetb(int num){
    int cnt=0;
    while(num){
        num=num&(num-1);
        cnt++;
    }
    cout<<"count="<<cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<"the num in bits is :"<<endl;
    printbits(n);
    cout<<endl;
    nsetb(n);
    
    return 0;
}
