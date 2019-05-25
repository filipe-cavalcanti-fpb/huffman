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

Node *Node::getRigth() const {
    return rigth;
}

void Node::setRigth(Node *rigth) {
    Node::rigth = rigth;
}

Node *Node::getLeft() const {
    return left;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}
