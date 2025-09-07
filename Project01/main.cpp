#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    Mat src1,src2,dst;
    src1 = imread("001.png");
    src2 = imread("003.png");
    addWeighted(src1,0.5,src2,0.5,0.0,dst);
    imshow("混合后的图片",dst);
    waitKey(0);
    return 0;
} 
