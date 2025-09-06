#include"quickopencv.h"

void QuickDemo::colorSpace_Demo(Mat &image){
    Mat gray,hsv;
    cvtColor(image,hsv,COLOR_BGR2HSV);
    cvtColor(image,gray,COLOR_BGR2GRAY);
    imshow("HSV",hsv);
    imshow("灰度",gray);
    imwrite("hsv.jpg",hsv);
    imwrite("gray.jpg",gray);
}
