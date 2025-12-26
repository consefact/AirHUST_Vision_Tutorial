#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("../test.jpg");
    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}