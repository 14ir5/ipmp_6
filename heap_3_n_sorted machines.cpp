/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//sort numbers on different machines 
// Each machine contains some numbers in sorted form.
#include <iostream>

using namespace std;
struct node{
    int data;
    struct node *next;
};
struct minheap{
    node* head;
};
node* head[100];
minheap **s=new minheap*[100];
int size=0,n;//size of minheap //n is the no.of machines
void swap(struct minheap** a,struct minheap** b)
{
    struct minheap* t = *a;
     *a = *b;
    * b = t;
}
minheap* newnode(){
    struct minheap *newnode =(struct minheap*)malloc(sizeof(struct minheap));
    return newnode;
}
void minHeapify(int idx)
  
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
  
    if (left < size && s[left]->head->data < s[smallest]->head->data)
        smallest = left;
  
    if (right < size && s[right]->head->data < s[smallest]->head->data)
        smallest = right;
  
    if (smallest != idx) {
        swap(s[smallest], s[idx]);
        minHeapify(smallest);
    }
}
  
node* extractMin(){
    if(size==0)
    return NULL;
    struct node *temp = s[0]->head;
 
  
    // Replace root either with next node of the same list.
    if( temp->next )
        s[0]->head = temp->next;
    else // If list empty, then reduce heap size
    {
        s[0] = s[ size - 1 ];
        size--;
    }

    minHeapify(0);
 
    return temp;
}
void buildMinHeap()
{
    int i, k;
    k = size-1;
    for( i = (k - 1) / 2; i >= 0; --i )
        minHeapify(i);
}
void populateMinHeap()
{
    
    for( int i = 0; i < n; ++i ){
        s[size]=newnode();
         s[size++]->head = head[i];
    }
      
  
    buildMinHeap();
}
void sort(){
   
    populateMinHeap();
  
    while ( size!=0 )
    {
        node* temp = extractMin();
        printf( "%d ",temp->data );
    }
}
int main()
{
    int n1;
    struct node*x=NULL;
    cout<<"enter no.of machines"<<endl;
    cin>>n;
    for(int j=0;j<n;j++){
        cout<<"enter no.of elements in list "<<j+1<<endl;
        cin>>n1;
        cout<<"enter elements in acsending order"<<endl;
        for(int i=0;i<n1;i++){
            cout<<"enter data"<<endl;
            struct node *newnode=(struct node*)malloc(sizeof(struct node));
            cin>>newnode->data;
            newnode->next=NULL;
            if(head[j]==NULL){
                head[j]=newnode;
                x=head[j];
            }
            else{
                x->next=newnode;
                x=x->next;
            }
        }
    }
    
    sort();

    return 0;
}
