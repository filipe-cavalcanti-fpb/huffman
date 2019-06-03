#include <iostream>
#include "src/tree/Node.h"
#include "src/heap/Heap.h"

using namespace std;

int main() {
    Heap *mimHeap = new Heap();
    mimHeap->setHeapLength(10);
    mimHeap->setHeapSize(10);
    Node *n1 = new Node(4, 1l, NULL, NULL);
    Node *n2 = new Node(1, 1l, NULL, NULL);
    Node *n3 = new Node(3, 1l, NULL, NULL);
    Node *n4 = new Node(2, 1l, NULL, NULL);
    Node *n5 = new Node(16, 1l, NULL, NULL);
    Node *n6 = new Node(9, 1l, NULL, NULL);
    Node *n7 = new Node(10, 1l, NULL, NULL);
    Node *n8 = new Node(14, 1l, NULL, NULL);
    Node *n9 = new Node(8, 1l, NULL, NULL);
    Node *n10 = new Node(7, 1l, NULL, NULL);
    Node a[10] = {*n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*n10};
    mimHeap->setHeap(a);
    mimHeap->buildMinHeap();

    for(int i = 0; i < mimHeap->getHeapSize(); i++) {
        cout << mimHeap->getHeap()[i].getFrequency() << endl;
    }

    return 0;
}
