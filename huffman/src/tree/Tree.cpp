//
// Created by root on 24/05/19.
//

#include "Tree.h"

const Node &Tree::getRoot() const {
    return root;
}

void Tree::setRoot(const Node &root) {
    Tree::root = root;
}
