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
    m3 = Scalar(127, 32, 177);
    // Mat kernel = (Mat_<char>(3,3)<<0,-1,0,
    //                             -1,5,-1,
    //                             0,-1,0);
    // imshow("kernel", kernel);
    waitKey(0);
}

void QuickDemo::pixel_visit_demo(Mat &image)
{
    int w = image.cols;
    int h = image.rows;
    int dims = image.channels();
    // for (int row = 0; row < h; row++)
    // {
    //     for (int col = 0; col < w; col++)
    //     {
    //         if (dims == 1)
    //         {
    //             int pv = image.at<uchar>(row, col);
    //             image.at<uchar>(row, col) = 255 - pv;
    //         }
    //         if (dims == 3)
    //         {
    //             Vec3b bgr = image.at<Vec3b>(row, col);
    //             image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
    //             image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
    //             image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
    //         }
    //     }
    // }

    for (int row = 0; row < h; row++)
    {
        uchar *current_row = image.ptr<uchar>(row);
        for (int col = 0; col < w; col++)
        {
            if (dims == 1)
            {
                int pv = *current_row;
                *current_row = 255 - pv;
            }
            if (dims == 3)
            {
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
            }
        }
    }
    imshow("像素读写演示", image);
}
void QuickDemo::operators_demo(Mat &image)
{
    Mat dst = Mat::zeros(image.size(), image.type());
    Mat m = Mat::zeros(image.size(), image.type());
    m = Scalar(50, 50, 50);
    int w = image.cols;
    int h = image.rows;
    int dims = image.channels();
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            Vec3b p1 = image.at<Vec3b>(row, col);
            Vec3b p2 = m.at<Vec3b>(row, col);
            dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
            dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
            dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
        }
    }
    imshow("add",dst);
}

static void on_lightness(int b,void* userdata){
    Mat image = *((Mat*)userdata);
    Mat dst = Mat::zeros(image.size(),image.type());
    Mat m = Mat::zeros(image.size(),image.type());
    m = Scalar(b,b,b);
    addWeighted(image,1.0,m,0,b,dst);
    imshow("亮度调整",dst);
}

static void on_contrast(int b,void* userdata){
    Mat image = *((Mat*)userdata);
    Mat dst = Mat::zeros(image.size(),image.type());
    Mat m = Mat::zeros(image.size(),image.type());
    double contrast = b/100.0;
    addWeighted(image,contrast,m,0.0,0,dst);
    imshow("亮度调整",dst);
}

void QuickDemo::tracking_bar_demo(Mat &image){
    namedWindow("亮度与对比度调整",WINDOW_AUTOSIZE);
    int lightness = 50;
    int max_value = 100;
    int contrast_value = 100;

    createTrackbar("Value Bar:","亮度与对比度调整",&lightness,max_value,on_lightness,(void*)(&image));
    createTrackbar("Contrast Bar:","亮度与对比度调整",&contrast_value,200,on_contrast,(void*)(&image));
    on_lightness(50,&image);
}