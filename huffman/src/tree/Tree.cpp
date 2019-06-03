//
// Created by root on 24/05/19.
//

#include "Tree.h"
#include <iostream>
#include <cstring>

using namespace std;

/**
 * Método para construir os codeWord a partir da fila de prioridade minima
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param minHeap - fila de prioridade minima
 */
int Tree::builderCodeWord(Node *root, string codeWord, string* listCodeWords, int i) {
    if(root->getRight() == NULL && root->getRight() == NULL) {
        listCodeWords[i] = codeWord.substr(0, codeWord.size());
        return NULL;
    }
    codeWord.append("0");
    this->builderCodeWord(root->getLeft(), codeWord, listCodeWords, i++);
    codeWord.pop_back();

    codeWord.append("1");
    this->builderCodeWord(root->getRight(), codeWord, listCodeWords, i++);
    codeWord.pop_back();
}