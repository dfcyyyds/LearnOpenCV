#include "quickopencv.h"

void QuickDemo::colorSpace_Demo(Mat &image)
{
    Mat gray, hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("HSV", hsv);
    imshow("灰度", gray);
    imwrite("hsv.jpg", hsv);
    imwrite("gray.jpg", gray);
}

void QuickDemo::mat_creation_demo(Mat &image)
{
    // Mat m1,m2;
    // m1 = image.clone();
    // image.copyTo(m2);
    // 创建空白图像
    Mat m3 = Mat::zeros(Size(512, 512), CV_8UC3);
    std::cout << "width: " << m3.cols << std::endl;
    std::cout << "height: " << m3.rows << std::endl;
    std::cout << "channels: " << m3.channels() << std::endl;
    m3 = Scalar(127,32,177);
    
    Mat kernel = (Mat_<char>(3,3)<<0,-1,0,
                                -1,5,-1,
                                0,-1,0);
    imshow("kernel",kernel);
    waitKey(0);
}
