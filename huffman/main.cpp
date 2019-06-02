#include <iostream>
#include "Node.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

#define MAXPIXEL 256

int main() {
    Mat img1;

    img1 = imread("../img/LEFT_4k3d_2160p24_010512.tif",cv::IMREAD_GRAYSCALE);

    int vet_frequency[MAXPIXEL] = {0};

    if(!img1.data)// Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl;
        return -1;
    }
    int freq_aux=0;
    for(int x = img1.rows-1; x < (img1.rows); x++)
    {
        for(int y = 0; y < (img1.cols); y++)
        {
            freq_aux = (int) img1.at<uchar>(x, y);
           vet_frequency[freq_aux]+=1;

        }
    }

    for(int i=0;i<256;i++){

        cout << vet_frequency[i]<<"\n";

    }

   // namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display
    //imshow( "Display window", m );// Show our image inside it.
    //waitKey(0);// Wait for a keystroke in the window
    return 0;}