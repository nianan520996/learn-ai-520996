#include <iostream>
#include<opencv2/opencv.hpp>
#include<vector>

int main()
{
    cv::Mat src = cv::imread("../assets/lena.jpg");
    if (src.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    int rows = src.rows;
    int cols = src.cols;
    int channels = src.channels();
    int step = src.step;
    std::cout << "rows:" << rows << ", cols:" << cols << ", channels:" << channels << ", step:" << step << std::endl;
    cv::Rect rect=cv::Rect(200,180,220,240);
    cv::Mat ROI = src(rect).clone();
    cv::rectangle(src, rect, cv::Scalar(0, 255, 0), 2);
    cv::imshow("src", src);
    cv::imshow("dst", ROI);
    cv::waitKey(0);
    cv::imwrite("../results/src.jpg", src);
    cv::imwrite("../results/ROI.jpg", ROI);
    cv::Mat roi= ROI.clone();
    ROI.at<cv::Vec3b>(0, 0) = cv::Vec3b(0, 0, 255);
    std::cout << roi.at<cv::Vec3b>(0, 0) << std::endl;
    cv::imread("../assets/coin.png");
    cv::Mat coin = cv::imread("../assets/coins.png");
    if (coin.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    cv::Mat coin_gray;
    cv::cvtColor(coin, coin_gray, cv::COLOR_BGR2GRAY);
    cv::Mat coin_binary;
    cv::threshold(coin_gray, coin_binary, 135, 255, cv::THRESH_BINARY );
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(coin_binary.clone(), contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    int count=0;
    double min_area=250;
    double max_area=4000;
    for (size_t i = 0; i < contours.size(); i++)
    {
        
        double area= cv::contourArea(contours[i]);
        if (area >= min_area && area <= max_area)
        {
            count++;
            cv::Rect box = cv::boundingRect(contours[i]);
            cv::rectangle(coin, box, cv::Scalar(0, 255, 0), 2);
            cv::putText(coin, std::to_string(count), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
        }
    }
    cv::imshow("coin_binary", coin_binary);
    cv::imshow("coin", coin);
    cv::waitKey(0);
    cv::imwrite("../results/coin_binary.png", coin_binary);
    cv::imwrite("../results/coins.png", coin);
    std::cout <<count<<std::endl;


    cv::Mat sudu=cv::imread("../assets/sudoku.png");
    std::vector<cv::Point2f> from = {
        {74,85},{490,70},{520,520},{36,516}
    };
    std::vector<cv::Point2f> to={
        {0,0},{449,0},{449,449},{0,449}
    };
    cv::Mat H= cv::getPerspectiveTransform(from,to);
    cv::Mat corrected;
    cv::warpPerspective(sudu,corrected,H,cv::Size(450,450));
    std::vector<cv::Point>points={
        cv::Point(74,85),cv::Point(490,70),cv::Point(520,520),cv::Point(36,516)
    };
    for(auto p : points)
    {
        cv::circle(sudu,p,2,cv::Scalar(0,0,255),-1);
        
    };

    cv::imshow("sudoku",sudu);
    cv::imshow("corrected",corrected);
    cv::waitKey(0);
    cv::imwrite( "../results/sudo.png",sudu);
    cv::imwrite( "../results/corrected.png",corrected);
    return 0;
}