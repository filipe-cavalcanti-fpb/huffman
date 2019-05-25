#include <iostream>
#include "Node.h"

int main() {
    Node* nl = new Node();
    nl->setFrequency(1234l);
    Node* nr = new Node();
    Node* root = new Node();
    root->setRigth(nl);
    root->setFrequency(123123);
    std::cout << root->getRigth()->getFrequency() << std::endl;
    return 0;
}
