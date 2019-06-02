//
// Created by root on 24/05/19.
//

#include "Node.h"


long Node::getFrequency() const {
    return frequency;
}

void Node::setFrequency(long frequency) {
    Node::frequency = frequency;
}

Node *Node::getRight() const {
    return right;
}

void Node::setRight(Node *right) {
    Node::right = right;
}

Node *Node::getLeft() const {
    return left;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}