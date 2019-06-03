//
// Created by root on 24/05/19.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H


#include "Node.h"
#include "../heap/Heap.h"
#include <string>

using namespace std;

class Tree {
public:

    int builderCodeWord(Node *root, string codeWord, string* listCodeWords);

};


#endif //HUFFMAN_TREE_H
