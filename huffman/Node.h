//
// Created by root on 24/05/19.
//

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H


class Node {

private:
    long frequency;

private:
    Node rigth;
    Node left;

public:
    const Node &getLeft() const;

    void setLeft(const Node &left);

    const Node &getRigth() const;

    void setRigth(const Node &rigth);

    long getFrequency() const;

    void setFrequency(long frequency);



};


#endif //HUFFMAN_NODE_H
