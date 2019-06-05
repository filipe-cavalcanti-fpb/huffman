//
// Created by root on 29/05/19.
//

#include "Heap.h"
#include <climits>


#define HEAP_ENPTY_EXCPETION "HeapEnptyException"
#define HEAP_MAX_SIZE_EXCEPTION "HeapMaxSizeException"
#define ROOT 1

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

    better = (left <= this->heapSize and this->heap[left-1]->getFrequency() > this->heap[nodeIndex-1]->getFrequency()) ? left : nodeIndex;
    better = (right <= this->heapSize and this->heap[right-1]->getFrequency() > this->heap[better-1]->getFrequency()) ? right : better;

     if(better != nodeIndex) {
        Node* intermediate = this->heap[nodeIndex-1];
        this->heap[nodeIndex-1] = this->heap[better-1];
        this->heap[better-1] = intermediate;

        this->maxHeapify(better);
    }
}

Heap::Heap(int heapSize) : heapSize(heapSize) {
    this->heapSize = heapSize;
}

vector<Node *> Heap::getHeap() const {
    return heap;
}

void Heap::setHeap(vector<Node *> heapp) {
    for(int i = 0; i < this->heapLength; i++){
        this->heap.push_back(heapp[i]);
    }
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

    small = (left <= this->heapSize and this->heap[left-1]->getFrequency() < this->heap[nodeIndex-1]->getFrequency()) ? left : nodeIndex;
    small = (right <= this->heapSize and this->heap[right-1]->getFrequency() < this->heap[small-1]->getFrequency()) ? right : small;

    if(small != nodeIndex) {
        Node *intermediate = this->heap[nodeIndex-1];
        this->heap[nodeIndex-1] = this->heap[small-1];
        this->heap[small-1] = intermediate;
        intermediate = nullptr;

        minHeapify(small);
    }
}

/**
 * Método para visualizar a raiz do heap máximo
 * @author filipe.cazuza@ifpb.edu.br
 * @return - a raiz do heap maximo
 */
Node Heap::heapMaximum() {
    if(this->heapSize > 0) {
        return *this->heap[0];
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
Node Heap::heapMinimum() {
    if(this->heapSize > 0) {
        return *this->heap[0];
    }
    else {
        throw HEAP_ENPTY_EXCPETION;
    }
}

/**
 * Método para extrair o maior valor em um heap máximo
 * @author filipe.cazuza@ifpb.edu.br
 * @throw HEAP_ENPTY_EXCPETION
 * @return - Maior valor do heap maximo
 */
Node Heap::heapExtractMax() {
    if(this->heapSize < 1) {
        throw HEAP_ENPTY_EXCPETION;
    }
    Node *max = this->heap[ROOT - 1];
    this->heap[ROOT -1] = this->heap[this->heapSize - 1];
    this->heapSize--;
    this->maxHeapify(ROOT);
    return *max;
}

/**
 * Método para extrair o menor valor de um heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @return - Menor valor do heap minimo
 */
Node* Heap::heapExtractMin() {
    if(this->heapSize < 1) {
        return nullptr;
    }
    Node *small = this->heap[0];
    this->heap[ROOT - 1] = this->heap[this->heapSize - 1];
    this->heapSize--;
    this->minHeapify(ROOT);
    return small;
}

/**
 * Método para incrementar o valor de um nó
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param nodeIndex - nó a ser incrementado
 * @param newKey - novo valor do nó
 */
void Heap::heapIncreaseKey(int nodeIndex, int newKey) {
    this->heap[nodeIndex-1]->setFrequency(newKey);
    while (nodeIndex != 0 && this->heap[this->getParent(nodeIndex)-1]->getFrequency() < this->heap[nodeIndex-1]->getFrequency())
    {
        Node *intermediate = this->heap[nodeIndex - 1];
        this->heap[nodeIndex - 1] = this->heap[this->getParent(nodeIndex) - 1];
        this->heap[this->getParent(nodeIndex) - 1] = intermediate;

        nodeIndex = this->getParent(nodeIndex);
    }
}


/**
 * Método para decrementar o valor de um no
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param nodeIndex - nó a ser decrementado
 * @param newKey - novo valor do nó
 */
void Heap::heapDecreaseKey(int nodeIndex, int newKey) {
    this->heap[nodeIndex - 1]->setFrequency(newKey);
    while (nodeIndex != 1 && this->heap[this->getParent(nodeIndex) - 1]->getFrequency() > this->heap[nodeIndex - 1]->getFrequency()) {
        Node *intermediate = this->heap[nodeIndex - 1];
        this->heap[nodeIndex - 1] = this->heap[this->getParent(nodeIndex) - 1];
        this->heap[this->getParent(nodeIndex) - 1] = intermediate;

        nodeIndex = this->getParent(nodeIndex);
    }
}

/**
 * Método para inserir um elemento no heap maximo
 * @author filipe.cazuza@ifpb.edu.br
 * @param node - node a ser inserido no heap
 */
void Heap::maxHeapInsert(Node node) {
    if (this->heapSize == this->heapLength) {
        throw HEAP_MAX_SIZE_EXCEPTION;
    }

    this->heapSize++;
    int i = this->heapSize - 1;
    this->heap[i] = &node;

    while (i != 0 && this->heap[this->getParent(i)]->getFrequency() < this->heap[i]->getFrequency()) {
        Node *intermediate = this->heap[i];
        this->heap[i] = this->heap[this->getParent(i)];
        this->heap[this->getParent(i)] = intermediate;

        i = this->getParent(i);
    }
}

/**
 * Método para inserir um elemento no heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @param node - node a ser inserido no heap
 */
void Heap::minHeapInsert(Node* node){
    if (this->heapSize == this->heapLength) {
        throw HEAP_MAX_SIZE_EXCEPTION;
    }

    this->heapSize++;
    int i = this->heapSize - 1;
    this->heap[i] = node;

    while (i != 0 && this->heap[this->getParent(i)]->getFrequency() > this->heap[i]->getFrequency()) {
        Node *intermediate = this->heap[i];
        this->heap[i] = this->heap[this->getParent(i)];
        this->heap[this->getParent(i)] = intermediate;

        i = this->getParent(i);
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
    this->heap[Heap::heapLength];

}

/**
 * Método para construir um heap maximo
 * @author filipe.cazuza@ifpb.edu.br
 * @param heap - Array para o a construção do Heap minimo
 */
void Heap::buildMaxHeap() {
    for(int i = heapSize/2; i >= 1 ; i--) {
        this->maxHeapify(i);
    }
}

/**
 * Método para construir um heap minimo
 * @author filipe.cazuza@ifpb.edu.br
 * @param heap - Array para o a construção do Heap minimo
 */
void Heap::buildMinHeap() {
    this->heapSize = heapSize;
    for(int i = heapSize / 2; i >= 1; i--) {
        this->minHeapify(i);
    }
}

Heap::Heap() {}

int Heap::getReference() const {
    return reference;
}

void Heap::increaseReference() {
    Heap::reference += 1;
}
