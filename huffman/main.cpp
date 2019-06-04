#include <iostream>
#include "src/tree/Node.h"
#include "src/heap/Heap.h"
#include "src/tree/Tree.h"
#include <string>
#include <vector>

using namespace std;

int main() {
    Heap *mimHeap = new Heap();
    mimHeap->setHeapLength(10);
    mimHeap->setHeapSize(4);
    Node *n1 = new Node(4, 1l, NULL, NULL);
    Node *n2 = new Node(1, 1l, NULL, NULL);
    Node *n3 = new Node(3, 1l, NULL, NULL);
    Node *n4 = new Node(2, 1l, NULL, NULL);

    Node* nodes[10] = {n1,n2,n3,n4};

    mimHeap->setHeap(*nodes);

    mimHeap->buildMinHeap();

    mimHeap->minHeapInsert(*new Node(15,1l,n1, n2));


    Node *nt1 = new Node(3,1l,NULL, NULL);

    Node *nt2 = new Node(6, 1l, n3, nt1);

    Node *nt3 = new Node(10, 1l, n4, nt2);
    Tree *t = new Tree();

    string b = "";
    vector <char*> string_word;

    t->builderCodeWord();
    vector <char*>::iterator a;

    for(a = string_word.begin();a <string_word.end();a++){
        cout << *a<<endl;
    }

    return 0;
}
