#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]){
    cv::Mat img = cv::imread(argv[1]);
    cv::imshow("this is a name", img);
    cv::waitKey(0);
    if(cv::imwrite(argv[2],img)) std::cout<<"done!";
}