//
// Created by root on 24/05/19.
//

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H


class Node {

private:
    long frequency;

private:
    Node *rigth;
    Node *left;

public:
    long getFrequency() const;

    void setFrequency(long frequency);

    Node *getRigth() const;

    void setRigth(Node *rigth);

    Node *getLeft() const;

    void setLeft(Node *left);

};


#endif //HUFFMAN_NODE_H
