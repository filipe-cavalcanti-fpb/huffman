//
// Created by root on 29/05/19.
//

#include "Heap.h"
#include <climits>


#define HEAP_ENPTY_EXCPETION "HeapEnptyException"
#define HEAP_MAX_SIZE_EXCEPTION "HeapMaxSizeException"

int Heap::getParent(int node) {
    return node / 2;
}

int Heap::getLeft(int node) {
    return 2 * node;
}

int Heap::getRight(int node) {
    return 2 * node + 1;
}

void Heap::maxHeapify(int node) {
    int left = this->getLeft(node);
    int right = this->getRight(node);
    int better;

    better = (left <= this->heapSize and this->heap[left] > this->heap()[node]) ? left : node;
    better = (right <= this->heapSize and this->heap[right] > this->heap[better]) ? right : better;

    if(better != i) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[better];
        this->heap[better] = intermediate;

        maxHeapfy(better);
    }
}

Heap::Heap(int heapSize) : heapSize(heapSize) {
    this->heapSize = heapSize;
}

int *Heap::getHeap() const {
    return heap;
}

void Heap::setHeap(int *heap) {
    Heap::heap = heap;
}

int Heap::getHeapSize() const {
    return heapSize;
}

void Heap::setHeapSize(int heapSize) {
    Heap::heapSize = heapSize;
}

void Heap::minHeapify(int node) {
    int left = this->getLeft(node);
    int right = this->getRight(node);
    int small;

    small = (left <= this->heapSize and this->heap()[left] < this->heap()[node]) ? left : node;
    small = (right <= this->heapSize and this->heap[right] < this->heap[small]) ? right : small;

    if(small != node) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[small];
        this->heap[small] = intermediate;

        minHeapify(small);
    }
}

int Heap::heapMaximum() {
    if(this->heapSize > 0) {
        return this->heap[0];
    }
    else {
        throw HEAP_ENPTY_EXCPETION;
    }
}

int Heap::heapMinimum() {
    if(this->heapSize > 0) {
        return this->heap[0];
    }
    else {
        throw HEAP_ENPTY_EXCPETION;
    }
}

int Heap::heapExtractMax() {
    if(this->heapSize < 1) {
        throw HEAP_ENPTY_EXCPETION;
    }
    int max = this->heap[0];
    this->heap[0] = this->heap[this->heapSize - 1];

    return 0;
}

int Heap::heapExtractMin() {
    return 0;
}

void Heap::heapIncreaseKey(int node, int newKey) {
    this->heap[node] = newKey;
    while (node != 0 && this->heap[this->getParent(node)] > this->heap[node])
    {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[this->getParent(node)];
        this->heap[this->getParent(node)] = intermediate;

        node = this->getParent(node);
    }
}

void Heap::heapDecreaseKey(int node, int newKey) {
    this->heap[node] = newKey;
    while (node != 0 && this->heap[this->getParent(node)] > this->heap[node]) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[this->getParent(node)];
        this->heap[this->getParent(node)] = intermediate;

        node = this->getParent(node);
    }
}

void Heap::maxHeapInsert(int node) {
    if (this->heapSize == this->heapLength) {
        throw HEAP_MAX_SIZE_EXCEPTION;
    }

    this->heapSize++;
    int i = this->heapSize - 1;
    this->heap[i] = node;

    while (i != 0 && this->heap[this->getParent(node)] < this->heap[i]) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[this->getParent(node)];
        this->heap[this->getParent(node)] = intermediate;

        node = this->getParent(node);
    }
}

void Heap::minHeapInsert(int node) {
    if (this->heapSize == this->heapLength) {
        throw HEAP_MAX_SIZE_EXCEPTION;
    }

    this->heapSize++;
    int i = this->heapSize - 1;
    this->heap[i] = node;

    while (i != 0 && this->heap[this->getParent(node)] > this->heap[i]) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[this->getParent(node)];
        this->heap[this->getParent(node)] = intermediate;

        node = this->getParent(node);
    }

}

int Heap::getHeapLength() const {
    return heapLength;
}

void Heap::setHeapLength(int heapLength) {
    Heap::heapLength = heapLength;
}

void Heap::buildMaxHeap(int *heap) {
    this->heapSize = heapSize;
    for(int i = 0; i < heapSize; i++) {
        this->maxHeapify(heap[i]);
    }
}

void Heap::buildMinHeap(int *heap) {
    this->heapSize = heapSize;
    for(int i = 0; i < heapSize; i++) {
        this->minHeapify(heap[i]);
    }

}