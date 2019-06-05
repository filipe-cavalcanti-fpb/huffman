#include <iostream>
#include "src/tree/Node.h"
#include "src/heap/Heap.h"
#include "src/tree/Tree.h"
#include <string>
#include <vector>

using namespace std;

int main() {
    Heap *mimHeap = new Heap();
    mimHeap->setHeapLength(11);
    mimHeap->setHeapSize(11);
    Node *n1 = new Node(4, 1l, nullptr, nullptr);
    Node *n2 = new Node(1, 1l, nullptr, nullptr);
    Node *n3 = new Node(3, 1l, nullptr, nullptr);
    Node *n4 = new Node(2, 1l, nullptr, nullptr);
    Node *n5 = new Node(7, 1l, nullptr, nullptr);
    Node *n6 = new Node(9, 1l, nullptr, nullptr);
    Node *n7 = new Node(8, 1l, nullptr, nullptr);
    Node *n8 = new Node(10, 1l, nullptr, nullptr);
    Node *n9 = new Node(9, 1l, nullptr, nullptr);
    Node *n10 = new Node(10, 1l, nullptr, nullptr);
    Node *n11 = new Node(16, 1l, nullptr, nullptr);
    n1->setRight(n2);
    n1->setLeft(n3);
    vector<Node *> nodes{n1,n2,n3,n4,n5, n6, n7, n8, n9, n10, n11};

    mimHeap->setHeap(nodes);

    mimHeap->buildMinHeap();

    Tree *t = new Tree();

    t->builderHuffman(mimHeap);

    string b = "";
    vector <char*> string_word;

    t->builderCodeWord();
    vector <char*>::iterator a;

    for(a = string_word.begin();a <string_word.end();a++){
        cout << *a<<endl;
    }

    return 0;
}
