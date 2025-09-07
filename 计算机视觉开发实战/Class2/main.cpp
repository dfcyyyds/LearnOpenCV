#include<opencv2/opencv.hpp>
#include"quickopencv.h"
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char**argv){
    Mat src = imread("../图片/007.png");
    if(src.empty()){
        cout<<"读取图片失败"<<endl;
        return -1;
    }
    namedWindow("输入窗口",WINDOW_FREERATIO);
    imshow("输入窗口",src);
    QuickDemo qd;
    qd.operators_demo(src);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

