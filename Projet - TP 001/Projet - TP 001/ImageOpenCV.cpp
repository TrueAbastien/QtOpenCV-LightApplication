#include "ImageOpenCV.h"
using namespace cv;
using namespace std;

ImageOpenCV::ImageOpenCV(QLabel* lab)
	: content(lab)
{
}

void ImageOpenCV::setImage(cv::Mat img)
{
	img.copyTo(image);
	content->setText("");
	Update();
}

cv::Mat ImageOpenCV::getImage() const
{
	return image;
}

bool ImageOpenCV::exists() const
{
	return !image.empty();
}

void ImageOpenCV::Blur(int radius, bool update)
{
	blur(image, image, Size(radius * 2 - 1, radius * 2 - 1));
	if (update) Update();
}

void ImageOpenCV::Erode(int radius, bool update)
{
	erode(image, image, getStructuringElement(MORPH_RECT, Size(radius * 2 - 1, radius * 2 - 1)));
	if (update) Update();
}

void ImageOpenCV::Dilate(int radius, bool update)
{
	dilate(image, image, getStructuringElement(MORPH_RECT, Size(radius * 2 - 1, radius * 2 - 1)));
	if (update) Update();
}

void ImageOpenCV::Open(int radius, bool update)
{
	morphologyEx(image, image, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(radius * 2 - 1, radius * 2 - 1)));
	if (update) Update();
}

void ImageOpenCV::Close(int radius, bool update)
{
	morphologyEx(image, image, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(radius * 2 - 1, radius * 2 - 1)));
	if (update) Update();
}

void ImageOpenCV::CannyFilter(int lowThreshold, int highThreshold, bool update)
{
	cvtColor(image, image, COLOR_RGB2GRAY);
	GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Canny(image, image, lowThreshold, highThreshold);

	if (update) Update();
}

void ImageOpenCV::EdgeDetection(bool update)
{
	GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(image, image, CV_BGR2GRAY);
	Laplacian(image, image, CV_8U);
	image.convertTo(image, -1, 4, 0);

	if (update) Update();
}

void ImageOpenCV::VertexDetection(bool update)
{
	Mat savedImg = image;
	cvtColor(image, image, COLOR_RGB2GRAY);

	vector<Point2f> corners;
	goodFeaturesToTrack(image, corners, 100, 0.01, 25);

	for (int i = 0; i < corners.size(); i++)
		circle(savedImg, corners[i], 2, Scalar(255), 2, 8, 0);
	savedImg.copyTo(image);

	if (update) Update();
}

void ImageOpenCV::ObjectDetection(bool update)
{
	/*for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			if (image.at<Vec3b>(i, j) == Vec3b(255, 255, 255))
			{
				image.at<Vec3b>(i, j)[0] = 0;
				image.at<Vec3b>(i, j)[1] = 0;
				image.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}

	Mat kernel = (Mat_<float>(3, 3) <<
		1, 1, 1,
		1, -8, 1,
		1, 1, 1);
	Mat imgLaplacian;
	filter2D(image, imgLaplacian, CV_32F, kernel);
	Mat sharp;
	image.convertTo(sharp, CV_32F);
	image = sharp - imgLaplacian;
	image.convertTo(image, CV_8UC3);
	Mat sharpen = image;

	cvtColor(image, image, COLOR_BGR2GRAY);
	threshold(image, image, 40, 255, THRESH_BINARY | THRESH_OTSU);

	distanceTransform(image, image, DIST_L2, 3);
	normalize(image, image, 0, 1.0, NORM_MINMAX);

	threshold(image, image, 0.4, 1.0, THRESH_BINARY);
	Mat kernel1 = Mat::ones(3, 3, CV_8U);
	dilate(image, image, kernel1);

	image.convertTo(image, CV_8U);
	vector<vector<Point>> contours;
	findContours(image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	Mat markers = Mat::zeros(image.size(), CV_32S);
	for (size_t i = 0; i < contours.size(); i++)
		drawContours(markers, contours, static_cast<int>(i), Scalar(static_cast<int>(i) + 1), -1);
	circle(markers, Point(5, 5), 3, Scalar(255), -1);

	watershed(sharpen, markers);
	Mat mark;
	markers.convertTo(mark, CV_8U);
	bitwise_not(mark, mark);
	vector<Vec3b> colors;
	for (size_t i = 0; i < contours.size(); i++)
	{
		int b = theRNG().uniform(0, 256);
		int g = theRNG().uniform(0, 256);
		int r = theRNG().uniform(0, 256);
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}
	image = Mat::zeros(markers.size(), CV_8UC3);
	for (int i = 0; i < markers.rows; i++)
	{
		for (int j = 0; j < markers.cols; j++)
		{
			int index = markers.at<int>(i, j);
			if (index > 0 && index <= static_cast<int>(contours.size()))
			{
				image.at<Vec3b>(i, j) = colors[index - 1];
			}
		}
	}*/

	Mat imgGrayScale, tresh_binary;
	cvtColor(image, imgGrayScale, CV_BGR2GRAY);
	threshold(imgGrayScale, tresh_binary, 220, 255, THRESH_BINARY);
	//Canny(imgGrayScale, imgGrayScale, 128, 255);

	vector<vector<Point>> contours;
	findContours(imgGrayScale.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	vector<Point> pupil;
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		Rect rect = boundingRect(contours[i]);
		int radius = rect.width / 2;
		if (area >= 30 && abs(1 - ((double)rect.width / (double)rect.height)) <= 0.2)
		{
			pupil = contours[i];
		}
	}
	Rect region_of_interest = boundingRect(pupil);
	Mat small_region = imgGrayScale(region_of_interest);
	Mat small_mask = tresh_binary(region_of_interest);
	image = small_region & (small_mask * 255);

	/*vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgGrayScale, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	for (size_t i = 0; i < contours.size(); i++)
		drawContours(image, contours, (int)i, Scalar(0, 0, 255), 1, LINE_8, hierarchy, 0);*/

	if (update) Update();
}

void ImageOpenCV::Update()
{
	if (image.cols*image.rows)
	{
		Mat rgb;
		QPixmap p;
		cvtColor(image, rgb, (-2 * image.channels() + 10));
		p.convertFromImage(QImage(rgb.data, rgb.cols, rgb.rows, QImage::Format_RGB888));
		content->setPixmap(p);
	}
}
