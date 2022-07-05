#include<stdio.h>
#include<stdlib.h>
struct BHeap
{
    int* A;
    int size;
    int length;
};
struct BHeap* createHeap(int size)
{
    struct BHeap* heap = (struct BHeap*)malloc(sizeof(struct BHeap));
    heap->A = (int*)malloc(sizeof(int)*size);
    heap->size = size;
    heap->length = 0;
    return heap;
}
void insertElementsInHeap(struct BHeap* heap, int data){
    int i=heap->length;
    heap->A[i] =data;
    int child = i;
    int parent = (child-1)/2;
    while(child!=0 && heap->A[parent]<heap->A[child])
    {
        int temp = heap->A[parent];
        heap->A[parent] = heap->A[child];
        heap->A[child] = temp;
        child = parent;
        parent = (child-1)/2;
    }
    heap->length++;
}
int extractMax(struct BHeap* heap)
{
    int delete = heap->A[0];
    heap->A[0] = heap->A[heap->length-1];
    heap->length--;
    int parent = 0;
    while(1)
    {
    int lc = 2*parent+1,rc = 2*parent+2;
    int child;
    if(lc<heap->length && rc<heap->length)
    {
        child = heap->A[lc]>heap->A[rc]?lc:rc;
    }
    else if(lc<heap->length)
    {
        child = lc;
    }
    else
    {
        return delete;
    }
    if(heap->A[parent]<heap->A[child])
    {
        int temp = heap->A[parent];
        heap->A[parent] = heap->A[child];
        heap->A[child] = temp;
        parent = child;
    }
    else{
        return delete;
    }
    }
}
void heapSort(struct BHeap* heap)
{
    int n = heap->length;
    for(int i=0;i<n;i++)
    {
        int curr = extractMax(heap);
        heap->A[heap->length] = curr;
    }
    heap->length = n;
}
void heapify(struct BHeap* heap)
{
    int n = heap->length;
    int choose = n-1;
    while(choose>=0)
    {
        int parent = choose;
        while(1)
        {
            int lc = 2*parent+1;
            int rc = 2*parent+2;
            int child;
            if(lc<n && rc<n)
            {
                child = heap->A[lc]>heap->A[rc]?lc:rc;
            }
            else if(lc<n)
            {
                child = lc;
            }
            else
            {
                break;
            }
            if(heap->A[parent]<heap->A[child])
            {
                int temp = heap->A[parent];
                heap->A[parent] = heap->A[child];
                heap->A[child] = temp;
                parent = child;
            }
            else{
                break;
            }
        }
        choose--;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    struct BHeap* heap = createHeap(n);
    int data;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        heap->A[heap->length] = data;
        heap->length++;
    }
   heapify(heap);
    for(int i=0;i<heap->length;i++)
    {
        printf("%d ",heap->A[i]);
    }
}