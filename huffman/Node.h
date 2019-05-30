//
// Created by root on 24/05/19.
//

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H


class Node {

private:
    long frequency;

private:
    Node* right ;
    Node* left;

public:
    long getFrequency() const;

    void setFrequency(long frequency);

    Node *getRight() const;

    void setRight(Node *right);

    Node *getLeft() const;

    void setLeft(Node *left);

};


#endif //HUFFMAN_NODE_H
