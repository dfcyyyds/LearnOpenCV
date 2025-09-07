#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv){
    Mat image = cv::imread("004.png");
    Mat constant_img = Mat::zeros(image.size(),CV_32FC3);
    constant_img.setTo(Scalar(0.9,0.9,0.9));
    Mat lowContrastMat,highContrastMat;
    //低对比度
    multiply(image,constant_img,lowContrastMat,1.0,CV_8U);
    //高对比度
    divide(image,constant_img,highContrastMat,1.0,CV_8U);
    //显示
    imshow("低对比度",lowContrastMat);
    waitKey(0);
    imshow("高对比度",highContrastMat);
    waitKey(0);
    return 0;
}
