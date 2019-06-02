//
// Created by root on 29/05/19.
//

#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H


class Heap {
private:
    int* heap;
    int heapSize;
    int heapLength;
public:
    Heap();

public:
    int getHeapLength() const;

    void setHeapLength(int heapLength);

public:
    int *getHeap() const;

    void setHeap(int *heap);

    int getHeapSize() const;

    void setHeapSize(int heapSize);

public:
    Heap(int heapSize);

public:
    int getParent(int node);

    int getLeft(int node);

    int getRight(int node);

    void maxHeapify(int nodeIndex);

    void minHeapify(int nodeIndex);

    void buildMaxHeap(int* heap);

    void buildMinHeap(int *heap);

    int heapMaximum();

    int heapMinimum();

    int heapExtractMax();

    int heapExtractMin();

    void heapIncreaseKey(int node, int newKey);

    void heapDecreaseKey(int node, int newKey);

    void maxHeapInsert(int node);

    void minHeapInsert(int node);
};


#endif //HUFFMAN_HEAP_H
