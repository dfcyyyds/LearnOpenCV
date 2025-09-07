#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>

using namespace cv;
//显示选项菜单
int showMenu();

int main(int argc,char **argv){
    //选择读取哪张图片
    std::string src;
    std::cout << "你想读取哪张图片：";
    std::cin >> src;
    Mat image = cv::imread("../图片/" + src);
    if(image.empty()){
        std::cout<<"图像读取失败"<<std::endl;
        return -1;
    }
    //菜单导引
    int option;
    while(option = showMenu()){
        //创建一个辅助参量
        Mat constant_img = Mat::zeros(image.size(),image.type());
        int para = 0;
        std::cout<<"请输入参数"<<std::endl;
        std::cin>>para;
        constant_img.setTo(Scalar(para,para,para));
        switch(option){
        case 1:{
            Mat lightMat;
            //亮度增强
            add(image,constant_img,lightMat);
            //显示
            imshow("lightMat",lightMat);
            waitKey(0);
            break;
            }
        case 2:{
            Mat darkMat;
            //亮度降低
            subtract(image,constant_img,darkMat);
            //显示
            imshow("darkMat",darkMat);
            waitKey(0);
            break;
            }
        }
    }    
    
    return 0;
}

int showMenu(){
    int option;
    std::cout<<"你想增强亮度【1】还是降低亮度【2】或退出【0】: ";
    std::cin >> option;
    std::cout << std::endl;
    return option;
}
