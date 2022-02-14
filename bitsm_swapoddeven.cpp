/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// to swap even and
// odd bits of a given number
#include <bits/stdc++.h>
using namespace std;


unsigned int swapBits(int x)
{
	// Get all even bits of x
	 int even_bits = x & 0xAAAAAAAA;

	// Get all odd bits of x
	int odd_bits = x & 0x55555555;

	even_bits >>= 1; // Right shift even bits
	odd_bits <<= 1; // Left shift odd bits

	return (even_bits | odd_bits); // Combine even and odd bits
}

// Driver code
int main()
{
    int n;
    cin>>n;
    int k=swapBits(n);
    cout<<k;
	return 0;
}



