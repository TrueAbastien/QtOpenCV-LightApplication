#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageModifierApp.h"

#include "ImageOpenCV.h"

class ToolboxOpenCV;

class ImageModifierApp : public QMainWindow
{
	Q_OBJECT

public:
	ImageModifierApp(QWidget *parent = Q_NULLPTR);
	~ImageModifierApp();

	ImageOpenCV *original, *transformed;

	QList<QAction*> waitingActionOnReset;
	QList<QWidget*> waitingWidgetOnReset;

	const int
		lowThreshold = 100,
		highThreshold = 255;

private:
	Ui::ImageModifierAppClass ui;
	ToolboxOpenCV* toolBox;

	void releaseOnReset(bool val);

public slots:
	void ResetImage(bool force = false);
	void LoadImage();
	void SaveImage();
};
