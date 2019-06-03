#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "src/heap/Heap.h"
#include "src/tree/Node.h"
#include "src/tree/Tree.h"
#include <string>
#include <vector>

typedef Node NodeTree;
using namespace cv;
using namespace std;

#define MAXPIXEL 256

int main() {
    Mat img1;
    img1 = imread("../img/LEFT_4k3d_2160p24_010512.tif",cv::IMREAD_GRAYSCALE);

    int vet_frequency[MAXPIXEL] = {0};

    if(!img1.data) //Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl;
        return -1;
    }


    for(int x = 0; x < (img1.rows); x++)
    {
        for(int y = 0; y < (img1.cols); y++)
        {
            vet_frequency[(int) img1.at<uchar>(x, y)]+=1;
        }
    }

    vector <NodeTree*> nodeTree;
    for(int i=0; i < MAXPIXEL; i++) {
        NodeTree *node = new NodeTree(vet_frequency[i], i, NULL, NULL);
        nodeTree.push_back(node);
    }

    Heap *mimHeap = new Heap();
    mimHeap->setHeapLength(MAXPIXEL);
    mimHeap->setHeapSize(MAXPIXEL);



   /* mimHeap->setHeapLength(10);
    mimHeap->setHeapSize(10);
    Node *n1 = new Node(4, 1l, NULL, NULL);
    Node *n2 = new Node(1, 1l, NULL, NULL);
    Node *n3 = new Node(3, 1l, NULL, NULL);
    Node *n4 = new Node(2, 1l, NULL, NULL);


    Node *nt1 = new Node(3,1l,n1, n2);

    Node *nt2 = new Node(6, 1l, n3, nt1);

    Node *nt3 = new Node(10, 1l, n4, nt2);*/

    Tree *t = new Tree();

    string b = "";
    vector <char*> string_word;

    t->builderCodeWord(nt3, b, &string_word, 0);
    vector <char*>::iterator a;

    for(a = string_word.begin();a <string_word.end();a++){
        cout << *a<<endl;
    }


    return 0;
}
