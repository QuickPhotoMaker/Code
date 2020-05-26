#include "viewSegmentations.h"
#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewSegmentations::ViewSegmentations(Controller& _controller)
	: View("SEGMENTATIONS D'IMAGES"), controller(_controller)
{
	controller.addObserver(this);
}

//Notification function of the view
void ViewSegmentations::notify()
{
	if (controller.getCurrentScreen() == 8)
		display();
}

//Displays the view
void ViewSegmentations::display()
{
	clear();
	View::display();

	std::cout << "1. Operations de seuillages" << std::endl << "2. Segmentation par croissance de region" << std::endl;

	int a;
	std::cin.clear();
	std::cin >> a;
	if (a == 0)
		controller.setScreen(10);

    //Operations the seuillages
	else if (a==1) 
	{
		std::cout << "Saisissez la puissance" << std::endl;
		int value;
		std::cin >> value;
		std::string selectedImage;
		std::cout << "Saisissez le type de Thresholding svp" << std::endl;
		int type;
		std::cin >> type;
		std::ifstream file("selection.txt");
		if (file.is_open()) {
			while (!file.eof()) {
				std::getline(file, selectedImage);
			}
		}
		file.close();
		cv::Mat image = cv::imread(selectedImage);
		if (image.empty())
		{
			std::cout << "Could not open or find the image" << std::endl;
			std::cin.get();
		}

		cv::Mat newimage;
		cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
		cv::threshold(image, newimage, value, 255, type);
		cv::String nameWindow = "Operations de seuillage";
		cv::namedWindow(nameWindow);
		cv::imshow(nameWindow, newimage);
		cv::waitKey(0);
		cv::destroyAllWindows();
	}

    //Segmentation par croissance de region
	else if (a == 2)
	{
        std::string selectedImage;
        std::ifstream file("selection.txt");
        if (file.is_open()) {
            while (!file.eof()) {
                std::getline(file, selectedImage);
            }
        }
        file.close();
        cv::Mat image = cv::imread(selectedImage);
        if (image.empty())
        {
            std::cout << "Could not open or find the image" << std::endl;
            std::cin.get();
        }
        for (int i = 0; i < image.rows; i++) {
            for (int j = 0; j < image.cols; j++) {
                if (image.at<cv::Vec3b>(i, j) == cv::Vec3b(255, 255, 255))
                {
                    image.at<cv::Vec3b>(i, j)[0] = 0;
                    image.at<cv::Vec3b>(i, j)[1] = 0;
                    image.at<cv::Vec3b>(i, j)[2] = 0;
                }
            }
        }
        cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
            1, 1, 1,
            1, -8, 1,
            1, 1, 1);
        cv::Mat imgLaplacian;
        filter2D(image, imgLaplacian, CV_32F, kernel);
        cv::Mat sharp;
        image.convertTo(sharp, CV_32F);
        cv::Mat imgResult = sharp - imgLaplacian;
        imgResult.convertTo(imgResult, CV_8UC3);
        imgLaplacian.convertTo(imgLaplacian, CV_8UC3);
        cv::Mat bw;
        cvtColor(imgResult, bw, cv::COLOR_BGR2GRAY);
        threshold(bw, bw, 40, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
        cv::Mat dist;
        distanceTransform(bw, dist, cv::DIST_L2, 3);
        normalize(dist, dist, 0, 1.0, cv::NORM_MINMAX);
        threshold(dist, dist, 0.4, 1.0, cv::THRESH_BINARY);
        cv::Mat kernel1 = cv::Mat::ones(3, 3, CV_8U);
        cv::dilate(dist, dist, kernel1);
        cv::Mat dist_8u;
        dist.convertTo(dist_8u, CV_8U);
        std::vector<std::vector<cv::Point> > contours;
        findContours(dist_8u, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        cv::Mat markers = cv::Mat::zeros(dist.size(), CV_32S);
        for (size_t i = 0; i < contours.size(); i++)
        {
            drawContours(markers, contours, static_cast<int>(i), cv::Scalar(static_cast<int>(i) + 1), -1);
        }
        circle(markers, cv::Point(5, 5), 3, cv::Scalar(255), -1);
        watershed(imgResult, markers);
        cv::Mat mark;
        markers.convertTo(mark, CV_8U);
        bitwise_not(mark, mark);
        std::vector<cv::Vec3b> colors;
        for (size_t i = 0; i < contours.size(); i++)
        {
            int b = cv::theRNG().uniform(0, 256);
            int g = cv::theRNG().uniform(0, 256);
            int r = cv::theRNG().uniform(0, 256);
            colors.push_back(cv::Vec3b((uchar)b, (uchar)g, (uchar)r));
        }
        cv::Mat dst = cv::Mat::zeros(markers.size(), CV_8UC3);
        for (int i = 0; i < markers.rows; i++)
        {
            for (int j = 0; j < markers.cols; j++)
            {
                int index = markers.at<int>(i, j);
                if (index > 0 && index <= static_cast<int>(contours.size()))
                {
                    dst.at<cv::Vec3b>(i, j) = colors[index - 1];
                }
            }
        }
        cv::String nameWindow = "Segmentation par croissance de region";
        cv::namedWindow(nameWindow);
        cv::imshow(nameWindow, dst);
        cv::waitKey(0);
        cv::destroyAllWindows();
	}
    controller.setScreen(10);
}