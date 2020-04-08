#pragma once
#include <QObject>
#include <QLabel>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/videoio.hpp"


class ImageOpenCV : public QObject
{
	Q_OBJECT

public:
	explicit ImageOpenCV(QLabel* lab);

	cv::Mat getImage() const;
	bool exists() const;

	void Blur(int radius = 2, bool update = true);
	void Erode(int radius = 2, bool update = true);
	void Dilate(int radius = 2, bool update = true);
	void Open(int radius = 2, bool update = true);
	void Close(int radius = 2, bool update = true);
	void CannyFilter(int lowThreshold, int highThreshold, bool update = true);
	void EdgeDetection(bool update = true);
	void VertexDetection(bool update = true);
	void ObjectDetection(bool update = true);

private:
	QLabel* content;
	cv::Mat image;

public slots:
	void setImage(cv::Mat img);
	void Update();
};