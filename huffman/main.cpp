#include <iostream>
#include "src/tree/Node.h"
#include "src/heap/Heap.h"

using namespace std;

int main() {
    Heap *mimHeap = new Heap();
    mimHeap->setHeapLength(10);
    mimHeap->setHeapSize(10);
    int a[10] = {4,1,3,2,16,9,10,14,8,7};
    mimHeap->setHeap(a);
    mimHeap->buildMinHeap(a);

    for(int i = 0; i < mimHeap->getHeapSize(); i++) {
        cout << mimHeap->getHeap()[i] << endl;
    }

    return 0;
}
