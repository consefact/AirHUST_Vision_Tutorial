#include <opencv2/opencv.hpp>
#include <cmath>
#include <vector>

#define PI 3.14159

int main(int argc, char* argv[]){
    cv::Mat img = cv::imread(argv[1]), result;
    double angle_d = atoi(argv[3]), scale = atoi(argv[4]);
    cv::Point2f center(img.cols / 2, img.rows / 2);
    cv::Mat rot_mat = cv::getRotationMatrix2D(center,angle_d,scale);

    //源图像顶点
    std::vector<cv::Point2f> corners = {
        cv::Point2f(0, 0),
        cv::Point2f(img.cols, 0),
        cv::Point2f(0, img.rows),
        cv::Point2f(img.cols, img.rows)
    };

    //将顶点旋转(绕源图中心)
    std::vector<cv::Point2f> rotated_corners;
    cv::transform(corners, rotated_corners, rot_mat);

    cv::Rect bbox = cv::boundingRect(rotated_corners);
    
    rot_mat.at<double>(0, 2) += bbox.width/2 - center.x;
    rot_mat.at<double>(1, 2) += bbox.height/2 - center.y;

    cv::warpAffine(img, result, rot_mat, bbox.size());
    cv::imwrite(argv[2],result);

}