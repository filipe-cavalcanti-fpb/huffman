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

void Node::setRight(Node* right) {
    Node::right = right;
}

Node *Node::getLeft() const {
    return left;
}

void Node::setLeft(Node* left) {
    Node::left = left;
}

long Node::getPixelValue() const {
    return pixelValue;
}

void Node::setPixelValue(long pixelValue) {
    Node::pixelValue = pixelValue;
}

Node::Node(long frequency, long pixelValue, Node *right, Node *left) : frequency(frequency), pixelValue(pixelValue),
                                                                       right(right), left(left) {}

Node::Node() {}
