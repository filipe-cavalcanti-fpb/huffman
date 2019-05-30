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
