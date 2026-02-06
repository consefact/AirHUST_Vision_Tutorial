#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int main(){
    cv::Mat img = cv::imread("../data/processed_lena.jpg");
    cv::Rect roi_region_1(100,50,450,250), roi_region_2(50,300,150,339);
    cv::Mat roi_1 = img(roi_region_1), roi_2 = img(roi_region_2);
    std::vector<cv::Mat> channels_1, channels_2, channel_temp;
    cv::split(roi_1, channels_1);
    cv::split(roi_2, channels_2);
    cv::swap(channels_1[1],channels_1[2]);
    cv::swap(channels_1[1],channels_1[0]);
    cv::swap(channels_2[0],channels_2[2]);
    cv::merge(channels_1,roi_1);
    cv::merge(channels_2,roi_2);
    cv::imwrite("../result.jpg",img);
}