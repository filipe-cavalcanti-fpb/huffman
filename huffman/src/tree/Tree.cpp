//
// Created by root on 24/05/19.
//

#include "Tree.h"
#include <iostream>
#include <cstring>
#include <vector>

#define INTERMEDIATE_NODE -1

using namespace std;

/**
 * Método para construir os codeWord a partir da fila de prioridade minima
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param minHeap - fila de prioridade minima
 */
int Tree::builderCodeWord(Node *root, string codeWord, vector <char*> *listCodeWords, int i) {
    if(root->getRight() == NULL && root->getRight() == NULL) {
        char * word_aux = new char [codeWord.length()+1];
        strcpy(word_aux, codeWord.c_str());
        listCodeWords->push_back(word_aux);

        return NULL;
    }
    codeWord.append("0");
    this->builderCodeWord(root->getLeft(), codeWord, listCodeWords, i++);
    codeWord.pop_back();

    codeWord.append("1");
    this->builderCodeWord(root->getRight(), codeWord, listCodeWords, i++);
    codeWord.pop_back();
}

Tree Tree::builderHuffman(Heap minHeap) {

    for(int i = 0; i < minHeap.getHeapSize(); i++) {
        Node *intermediateNode = new Node();

        intermediateNode->setLeft(minHeap.heapExtractMin());
        intermediateNode->setRight(minHeap.heapExtractMin());

        intermediateNode->setFrequency(intermediateNode->getLeft()->getFrequency() + intermediateNode->getRight()->getFrequency());

        intermediateNode->setPixelValue(INTERMEDIATE_NODE);

        minHeap.minHeapInsert(*intermediateNode);

    }
    return Tree();
}
