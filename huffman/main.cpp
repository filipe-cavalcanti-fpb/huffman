#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "src/heap/Heap.h"
#include "src/tree/Node.h"

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


    Heap *mimHeap = new Heap();
    mimHeap->setHeapLength(MAXPIXEL);
    mimHeap->setHeapSize(MAXPIXEL);
    mimHeap->setHeap(vet_frequency);
    mimHeap->buildMinHeap();

    NodeTree *nodeTree = new NodeTree[MAXPIXEL];
    for(int i=0; i < MAXPIXEL; i++){
        nodeTree[i].setFrequency(vet_frequency[i]);
        nodeTree[i].setPixelValue(i);
    }


    for(int i = 0; i < mimHeap->getHeapSize(); i++)
    {
        cout << mimHeap->getHeap()[i] << endl;
    }


    return 0;
}
