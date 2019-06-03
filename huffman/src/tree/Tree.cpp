//
// Created by root on 24/05/19.
//

#include "Tree.h"
#include <iostream>

using namespace std;

/**
 * Método para construir os codeWord a partir da fila de prioridade minima
 * @author filipe.cazuza@academico.ifpb.edu.br
 * @param minHeap - fila de prioridade minima
 */
int Tree::builderCodeWord(Node *root, string codeWord, string* listCodeWords) {
    if(root->getRight() == NULL && root->getRight() == NULL) {
        cout << codeWord << endl;
        return NULL;
    }
    codeWord.append("0");
    this->builderCodeWord(root->getLeft(), codeWord, listCodeWords);
    codeWord.pop_back();

    codeWord.append("1");
    this->builderCodeWord(root->getRight(), codeWord, listCodeWords);
    codeWord.pop_back();
}