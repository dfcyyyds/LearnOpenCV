#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat img = cv::imread("001.png");  // 替换成你本地的一张图片
    if (img.empty()) {
        std::cout << "无法加载图像！" << std::endl;
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    std::cout << "图像大小: " << img.cols << "x" << img.rows << std::endl;
    return 0;
}

