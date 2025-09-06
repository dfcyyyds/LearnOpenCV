#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char**argv){
    Mat src = imread("../图片/005.png",IMREAD_GRAYSCALE);
    src -= 255;
    namedWindow("输入窗口",WINDOW_FREERATIO);
    imshow("输入窗口",src);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

