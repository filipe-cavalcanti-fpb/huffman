//
// Created by root on 29/05/19.
//

#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H


#include "../tree/Node.h"
#include <vector>

using namespace std;

class Heap {
private:
    vector<Node *> heap;
    int heapSize;
    int heapLength;
    int reference = 0;
public:
    int getReference() const;

    void increaseReference();

public:
    Heap();

public:
    int getHeapLength() const;

    void setHeapLength(int heapLength);

public:
    vector<Node *> getHeap() const;

    void setHeap(vector<Node *> heap);

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

    void buildMaxHeap();

    void buildMinHeap();

    Node heapMaximum();

    Node heapMinimum();

    Node heapExtractMax();

    Node* heapExtractMin();

    void heapIncreaseKey(int nodeIndex, int newKey);

    void heapDecreaseKey(int nodeIndex, int newKey);

    void maxHeapInsert(Node node);

    void minHeapInsert(Node* node);
};


#endif //HUFFMAN_HEAP_H
