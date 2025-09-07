#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char** argv){
    cv::Mat src = cv::imread("002.png");
    imshow("壁纸",src);
    waitKey(0);
    destroyAllWindows();
    return 0;   
}
