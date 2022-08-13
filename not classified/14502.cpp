void downHeap(HeapType* H){
    int item = H->heap[1];
    int parent = 1, child = 2;

    while(child <= H->heapSize){
        if((child < H->heapSize) && (H->heap[child] < H->heap[child+1])
            child++;
        if(item >= H->heap[child])
            break;

        H->heap[child] = H->heap[parent];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = item;
}

void heapSort(HeapType* H){
    int n = H->heapSize;

    for(int i=1; i<=n; i++){
        int item = H->heap[1];
        H->heap[1] = H->heap[heapSize];
        H->heap[heapSize] = item;

        H->heapSize--;
        downHeap(&H);
    }
}

void upHeap(HeapType* H){
    int item = H->heap[heapSize];
    int i = H->heapSize;
    while((i != 1) && item > H->heap[i/2]){
        H->heap[i] = H->heap[]
    }
}