#include "ImageOpenCV.h"
using namespace cv;
using namespace std;

#include <QMessageBox>


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

void ImageOpenCV::ObjectDetection(int lowThreshold, int highThreshold, double minArea, double boxMaxRatio, bool update)
{
	Mat imgGrayScale;
	cvtColor(image, imgGrayScale, CV_BGR2GRAY);
	threshold(imgGrayScale, imgGrayScale, lowThreshold, highThreshold, THRESH_BINARY);

	vector<vector<Point>> contours;
	findContours(imgGrayScale.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	RNG rng(0xFFFFFFFF);
	double reverseRatio = 1.0 / boxMaxRatio;
	foreach(vector<Point> form, contours)
	{
		Rect rect = boundingRect(form);
		double factor = (double)rect.width / (double)rect.height;
		if (rect.area() >= minArea && factor < boxMaxRatio && factor > reverseRatio)
			rectangle(image, rect, Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256)), 2);
	}

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
