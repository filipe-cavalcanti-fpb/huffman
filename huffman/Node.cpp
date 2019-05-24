//
// Created by root on 24/05/19.
//

#include "Node.h"

const Node &Node::getLeft() const {
    return left;
}

void Node::setLeft(const Node &left) {
    Node::left = left;
}

const Node &Node::getRigth() const {
    return rigth;
}

void Node::setRigth(const Node &rigth) {
    Node::rigth = rigth;
}

long Node::getFrequency() const {
    return frequency;
}

void Node::setFrequency(long frequency) {
    Node::frequency = frequency;
}
