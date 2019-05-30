#include <iostream>
#include "tree/Node.h"

using namespace std;

int main() {
    Node* nl = new Node();
    nl->setFrequency(1234);

    Node* nr = new Node();
    nr->setFrequency(12345);

    Node* root = new Node();
    root->setLeft(nr);
    root->setRight(nl);
    root->setLeft(nr);

    cout << root->getLeft()->getFrequency() << endl;

    return 0;
}
