//
// Created by root on 29/05/19.
//

#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H


class Heap {
private:
    int* heap;
    int heapSize;
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

    void maxHeapify(int node);

};


#endif //HUFFMAN_HEAP_H
