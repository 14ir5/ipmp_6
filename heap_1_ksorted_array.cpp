/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// A STL based C++ program to sort a nearly sorted array.
//min heap
#include <bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k)
{
	
	int size;
	size=(n==k)?k:k+1;
	priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);


	int index = 0;
	for (int i = k + 1; i < n; i++) {
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while (pq.empty() == false) {
		arr[index++] = pq.top();
		pq.pop();
	}
}
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int k = 3;
	int arr[] = { 2, 6, 3, 12, 56, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortK(arr, n, k);

	cout << "Following is sorted array" << endl;
	printArray(arr, n);

	return 0;
}

