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

void Heap::maxHeapify(int nodeIndex) {
    int left = this->getLeft(nodeIndex);
    int right = this->getRight(nodeIndex);
    int better;

    better = (left <= this->heapSize and this->heap[left-1] > this->heap[nodeIndex-1]) ? left : nodeIndex;
    better = (right <= this->heapSize and this->heap[right-1] > this->heap[better-1]) ? right : better;

     if(better != nodeIndex) {
        int intermediate = this->heap[nodeIndex-1];
        this->heap[nodeIndex-1] = this->heap[better-1];
        this->heap[better-1] = intermediate;

        this->maxHeapify(better);
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

void Heap::minHeapify(int nodeIndex) {
    int left = this->getLeft(nodeIndex);
    int right = this->getRight(nodeIndex);
    int small;

    small = (left <= this->heapSize and this->heap[left-1] < this->heap[nodeIndex-1]) ? left : nodeIndex;
    small = (right <= this->heapSize and this->heap[right-1] < this->heap[small-1]) ? right : small;

    if(small != nodeIndex) {
        int intermediate = this->heap[nodeIndex-1];
        this->heap[nodeIndex-1] = this->heap[small-1];
        this->heap[small-1] = intermediate;

        minHeapify(small);
    }
}

/**
 * Método para visualizar a raiz do heap máximo
 * @author filipe.cazuza@ifpb.edu.br
 * @return - a raiz do heap maximo
 */
int Heap::heapMaximum() {
    if(this->heapSize > 0) {
        return this->heap[0];
    }
    else {
        throw HEAP_ENPTY_EXCPETION;
    }
}

/**
 * Método para visualizar a raiz do heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @return - a raiz do heap minimo
 */
int Heap::heapMinimum() {
    if(this->heapSize > 0) {
        return this->heap[0];
    }
    else {
        throw HEAP_ENPTY_EXCPETION;
    }
}

/**
 * Método para extrair o maior valor em um heap máximo
 * @author filipe.cazuza@ifpb.edu.br
 * @return - Maior valor do heap maximo
 */
int Heap::heapExtractMax() {
    if(this->heapSize < 1) {
        throw HEAP_ENPTY_EXCPETION;
    }
    int max = this->heap[0];
    this->heap[0] = this->heap[this->heapSize - 1];

    return 0;
}

/**
 * Método para extrair o menor valor de um heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @return - Menor valor do heap minimo
 */
int Heap::heapExtractMin() {
    return 0;
}

/**
 * Método para incrementar o valor de um nó
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param node - nó a ser incrementado
 * @param newKey - novo valor do nó
 */
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


/**
 * Método para decrementar o valor de um no
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param node - nó a ser decrementado
 * @param newKey - novo valor do nó
 */
void Heap::heapDecreaseKey(int node, int newKey) {
    this->heap[node] = newKey;
    while (node != 0 && this->heap[this->getParent(node)] > this->heap[node]) {
        int intermediate = this->heap[node];
        this->heap[node] = this->heap[this->getParent(node)];
        this->heap[this->getParent(node)] = intermediate;

        node = this->getParent(node);
    }
}

/**
 * Método para inserir um elemento no heap maximo
 * @author filipe.cazuza@ifpb.edu.br
 * @param node - node a ser inserido no heap
 */
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

/**
 * Método para inserir um elemento no heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @param node - node a ser inserido no heap
 */
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

/**
 * @author filipe.cazuza@ifpb.edu.br
 * @param heapLength
 */
void Heap::setHeapLength(int heapLength) {
    Heap::heapLength = heapLength;
}

/**
 * Método para construir um heap maximo
 * @author filipe.cazuza@ifpb.edu.br
 * @param heap - Array para o a construção do Heap minimo
 */
void Heap::buildMaxHeap(int *heap) {
    for(int i = heapSize/2; i >= 1 ; i--) {
        this->maxHeapify(i);
    }
}

/**
 * Método para construir um heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @param heap - Array para o a construção do Heap minimo
 */
void Heap::buildMinHeap(int *heap) {
    this->heapSize = heapSize;
    for(int i = heapSize / 2; i >= 1; i--) {
        this->minHeapify(i);
    }
}

Heap::Heap() {}
