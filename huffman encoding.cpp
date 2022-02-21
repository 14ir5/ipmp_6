/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//huffman coding
//priority queue using array can be unsigned
//we are using pq using heap
//ch[] = { ‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘f’ }, freq[] = { 5, 9, 12, 13, 16, 45 } 
#include <iostream>

using namespace std;
struct node{
    
    char ch;
    int f;
    struct node*left=NULL,*right=NULL;
};
int size=0,n;
node **s=new node*[100];
void swap(struct node** a,struct node** b)
{
    struct node* t = *a;
     *a = *b;
    * b = t;
}
node* newnode(char a,int b,node *left,node *right){
    struct node *newnode =(struct node*)malloc(sizeof(struct node));
    return newnode;
}
void insert(char a,int b,node *left,node *right){
    size++;
    s[size-1]=newnode(a,b,left,right);
    s[size-1]->ch=a;
    s[size-1]->f=b;
    s[size-1]->left=left;
    s[size-1]->right=right;
    int i = size - 1;
  
    while (i && s[i]->f < s[(i - 1) / 2]->f) {
        
        node *temp=s[i];
        s[i]=s[(i-1)/2];
        s[(i-1)/2]=temp;
        //swap(s[i],s[(i-1)/2]);
        i = (i - 1) / 2;
    }

}
void minHeapify(int idx)
  
{
  
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
  
    if (left < size && s[left]->f < s[smallest]->f)
        smallest = left;
  
    if (right < size && s[right]->f < s[smallest]->f)
        smallest = right;
  
    if (smallest != idx) {
        swap(s[smallest], s[idx]);
        minHeapify(smallest);
    }
}
  
node* extractmin(){
    struct node *temp = s[0];
    s[0] =s[size - 1];
  
    size--;
    minHeapify(0);
    cout<<"hi"<<endl;
    cout<<temp->f<<endl;
    
    return temp;
}

node* huffmancoding(){
    struct node *left, *right, *top;
    
    while (size>1) {
  
        left = extractmin();
        right = extractmin();
        cout<<left->f;
        insert('$',left->f+right->f,left,right);
    }
    
    return extractmin();
}
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
  
    printf("\n");
}
void printCodes(struct node* root, int arr[],int top)
  
{
    if (root->left) {
  
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
  
    if (root->right) {
  
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
  
    if (root->left==NULL&&root->right==NULL) {
  
        printf("%c: ", root->ch);
        printArr(arr, top);
    }
}
int main()
{
   char a;
   int b;
    cout<<"enter no.of distinct characters in the string"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"character :"<<i+1<<endl;
        cout<<"enter character"<<endl;
        cin>>a;
        cout<<"enter freq"<<endl;
        cin>>b;
        insert(a,b,NULL,NULL);
    }
    
   
    int arr[1000];
   node*hfc=huffmancoding();
    printCodes(hfc,arr,0);
    return 0;
}

