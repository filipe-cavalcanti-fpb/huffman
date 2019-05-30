//
// Created by root on 24/05/19.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H


#include "Node.h"

class Tree {
private:
    Node root;
public:
    const Node &getRoot() const;

    void setRoot(const Node &root);

};


#endif //HUFFMAN_TREE_H
