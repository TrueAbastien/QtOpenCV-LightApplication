#include "ImageModifierApp.h"
#include <QFileDialog>

#include "ToolboxOpenCV.h"


ImageModifierApp::ImageModifierApp(QWidget *parent)
	: QMainWindow(parent), toolBox(new ToolboxOpenCV(this))
{
	ui.setupUi(this);
	original = new ImageOpenCV(ui.imgOriginal);
	transformed = new ImageOpenCV(ui.imgTransformed);

	// File
	connect(ui.actionLoad, SIGNAL(triggered()), this, SLOT(LoadImage()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(SaveImage()));

	// Tools
	ui.menuTransform->setEnabled(false);
	connect(ui.actionReset, &QAction::triggered, [this]() { ResetImage(true); });
	connect(ui.actionBlur, &QAction::triggered, [this]() { ResetImage(); transformed->Blur(); });
	connect(ui.actionErode, &QAction::triggered, [this]() { ResetImage(); transformed->Erode(); });
	connect(ui.actionDilate, &QAction::triggered, [this]() { ResetImage(); transformed->Dilate(); });
	connect(ui.actionOpening, &QAction::triggered, [this]() { ResetImage(); transformed->Open(); });
	connect(ui.actionClosing, &QAction::triggered, [this]() { ResetImage(); transformed->Close(); });
	connect(ui.actionCannyFilter, &QAction::triggered, [this]() { ResetImage(); transformed->CannyFilter(lowThreshold, highThreshold); });
	connect(ui.actionDetectEdges, &QAction::triggered, [this]() { ResetImage(); transformed->EdgeDetection(); });
	connect(ui.actionDetectVertices, &QAction::triggered, [this]() { ResetImage(); transformed->VertexDetection(); });
	connect(ui.actionDetectObjects, &QAction::triggered, [this]() { ResetImage(); transformed->ObjectDetection(lowThreshold, highThreshold); });
	connect(ui.actionOpenToolbox, &QAction::triggered, [this]() { toolBox->open(); toolBox->raise(); });

	waitingActionOnReset.append({ ui.actionCannyFilter, ui.actionDetectEdges, ui.actionDetectVertices, ui.actionDetectObjects });
}

ImageModifierApp::~ImageModifierApp()
{
	delete original;
	delete transformed;

	delete toolBox;
}

void ImageModifierApp::ResetImage(bool force)
{
	if (ui.actionReset->isChecked() || force)
	{
		transformed->setImage(original->getImage());
		releaseOnReset(true);
	}
	else releaseOnReset(false);
}

void ImageModifierApp::releaseOnReset(bool val)
{
	foreach(QAction* a, waitingActionOnReset)
		a->setEnabled(val);
	foreach(QWidget* w, waitingWidgetOnReset)
		w->setEnabled(val);
}

void ImageModifierApp::LoadImage()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg * .jpeg *.bmp)"));
	if (!fileName.isEmpty())
	{
		original->setImage(cv::imread(fileName.toStdString()));
		ui.menuTransform->setEnabled(true);
		ResetImage(true);

		if (isMaximized())
		{
			showMaximized();
		}
	}
}

void ImageModifierApp::SaveImage()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Image Files (*.png *.jpg * .jpeg *.bmp)"));
	if (!fileName.isEmpty() && transformed->exists())
		cv::imwrite(fileName.toStdString(), transformed->getImage());
}