//
// Created by root on 29/05/19.
//

#include "Heap.h"
#include <climits>

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

    better = (left <= this->heapSize and this->heap()[left] > this->heap()[node]) ? left : node;
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

    if(better != i) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[small];
        this->heap[small] = intermediate;

        minHeapify(small);
    }
}

int Heap::heapMaximum() {
    if(this->heapSize > 0) {
        return this->heap[0]
    }
    else {
        throw "HeapEnptyException";
    }
}

int Heap::heapMinimum() {
    if(this->heapSize > 0) {
        return this->heap[0]
    }
    else {
        throw "HeapEnptyException";
    }
}

int Heap::heapExtractMax() {
    return 0;
}

int Heap::heapExtractMin() {
    return 0;
}

void Heap::heapIncreaseKey(int node, int newKey) {

}

void Heap::heapDecreaseKey(int node, int newKey) {

}

void Heap::maxHeapInsert(int node) {

}

void Heap::minHeapInsert(int node) {

}

void Heap::buildMaxHeap(int *heap, int heapSize) {
    this->heapSize = heapSize;
    for(int i = 0; i < heapSize; i++) {
        this->maxHeapify(heap[i]);
    }
}

void Heap::buildMinHeap(int *heap, int heapSize) {
    this->heapSize = heapSize;
    for(int i = 0; i < heapSize; i++) {
        this->minHeapify(heap[i]);
    }
}
