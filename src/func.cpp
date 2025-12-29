#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

/**
 * @brief 从纯数字文本文件读取图像数据到cv::Mat
 * @param filename 文本文件路径
 * @param width 图像宽度（像素）
 * @param height 图像高度（像素）
 * @param channels 图像通道数（1=灰度，3=RGB）
 * @return 包含图像数据的cv::Mat（8位无符号整数）
 */
cv::Mat readImageFromTxt(const std::string& filename,
                         int width, 
                         int height, 
                         int channels = 1) {
    
    // 验证输入参数
    if (width <= 0 || height <= 0) {
        std::cerr << "错误：无效的图像尺寸 " << width << "x" << height << std::endl;
        return cv::Mat();
    }
    
    if (channels != 1 && channels != 3) {
        std::cerr << "错误：通道数必须是1或3，当前为" << channels << std::endl;
        return cv::Mat();
    }
    
    // 打开文件
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "错误：无法打开文件 " << filename << std::endl;
        return cv::Mat();
    }
    
    // 创建结果矩阵
    cv::Mat result(height, width, CV_8UC(channels));
    
    // 计算总像素值数
    int totalValues = width * height * channels;
    std::vector<int> allValues;
    allValues.reserve(totalValues);
    
    // 读取文件中的所有数字
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int value;
        
        while (iss >> value) {
            allValues.push_back(value);
        }
    }
    
    file.close();
    
    // 检查是否读取了足够的数据
    if (static_cast<int>(allValues.size()) < totalValues) {
        std::cerr << "错误：文件数据不足，需要" << totalValues 
                  << "个值，但只读取了" << allValues.size() << "个" << std::endl;
        return cv::Mat();
    }
    
    // 将数据填充到cv::Mat中
    if (channels == 1) {
        // 单通道图像（灰度图）
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                int idx = row * width + col;
                int value = allValues[idx];
                
                // 限制值在0-255范围内
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                
                result.at<uchar>(row, col) = static_cast<uchar>(value);
            }
        }
    } else if (channels == 3) {
        // 三通道图像（BGR格式）
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                int idx = (row * width + col) * 3;
                
                cv::Vec3b pixel;
                for (int c = 0; c < 3; c++) {
                    int value = allValues[idx + c];
                    
                    // 限制值在0-255范围内
                    if (value < 0) value = 0;
                    if (value > 255) value = 255;
                    
                    pixel[c] = static_cast<uchar>(value);
                }
                
                result.at<cv::Vec3b>(row, col) = pixel;
            }
        }
    }
    
    return result;
}


int main(int argc, char* argv[]){
    cv::Mat image = readImageFromTxt(argv[3], atoi(argv[1]), atoi(argv[2]), 1);
    for(int i = 0; i < atoi(argv[1]); i++){
        for(int j = 0; j < atoi(argv[2]); j++){
            if(image.at<uchar>(j,i) == 1){
                image.at<uchar>(j,i) = 255;
            }
        }
    }
    cv::imshow("image",image);
    cv::waitKey(0);

    if(cv::imwrite("output_2.png",image)){
        std::cout<<"save OK";
    }
}