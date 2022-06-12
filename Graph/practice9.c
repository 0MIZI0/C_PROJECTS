#pragma once
#define MAX_ELEMENT 100

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} heapType;

heapType* createHeap(void);
void insertHeap(heapType* h, int item);
int deleteHeap(heapType* h);
void printHeap(heapType* h);

heapType* createHeap(void){
    heapType* h = (heapType*)malloc(sizeof(heapType));
    h->heap_size = 0;
    return h;
}

void insertHeap(heapType* h, element item){
    h->heap_size++;
    int i = h->heap_size;
    while( (i != 1) && (item > h->heap[i/2])){
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

int deleteHeap(heapType* h){
    int parent = 1, child = 2;
    element item = h->heap[1], tmp = h->heap[h->heap_size];

    h->heap_size--;
    while( child <= h->heap_size ) {
        
    }


}