#include "viewDetection.h"
#include <iostream>
#include <fstream>

int lowThreshold = 0;
cv::Mat src, src_gray, dst, detected_edges;
/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewDetection::ViewDetection(Controller& _controller)
	: View("DETECTION DE CONTOURS"), controller(_controller)
{
	controller.addObserver(this);
}

//Notification function of the view
void ViewDetection::notify()
{
	if (controller.getCurrentScreen() == 7)
		display();
}

//Displays the view
static void CannyThreshold(int,void*)
{
	cv::blur(src_gray, detected_edges, cv::Size(3, 3));
	cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * 3, 3);
	dst = cv::Scalar::all(0);
	src.copyTo(dst, detected_edges);
	cv::imshow("Detection de contours", dst);
}
void ViewDetection::display()
{
	clear();
	View::display();

	std::cout << "Detection de contours en cours..." << std::endl;
	std::string selectedImage;
	std::ifstream file("selection.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, selectedImage);
		}
	}
	file.close();
	src = cv::imread(selectedImage);
	dst.create(src.size(), src.type());
	cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
	cv::namedWindow("Detection de contours", cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("Min Threshold:", "Detection de contours", &lowThreshold, 100, CannyThreshold);
	CannyThreshold(0, 0);
	cv::waitKey(0);
	controller.setScreen(10);
}
