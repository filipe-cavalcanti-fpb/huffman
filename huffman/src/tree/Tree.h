//
// Created by root on 24/05/19.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H


#include "Node.h"
#include "../heap/Heap.h"
#include <string>
#include <vector>

using namespace std;

class Tree {

private:
    Node root;
public:
    Tree(const Node *root);

public:
    Tree();

    const Node &getRoot() const;

    void setRoot(Node* root);

private:
    int builderCodeWord_(Node *root, string codeWord, vector <char*> *listCodeWords);

public:
    Tree* builderHuffman(Heap *minHeap);

    vector <char*> builderCodeWord();

};


#endif //HUFFMAN_TREE_H
