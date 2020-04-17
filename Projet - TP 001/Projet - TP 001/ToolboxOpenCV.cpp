#include "ToolboxOpenCV.h"

ToolboxOpenCV::ToolboxOpenCV(ImageModifierApp *parent)
	: QDialog(Q_NULLPTR)
{
	ui.setupUi(this);
	app = parent;

	connect(ui.toolBtnReset, &QPushButton::pressed, [this]() { app->ResetImage(true); });
	connect(ui.toolBtnBlur, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->Blur(); });
	connect(ui.toolBtnBlackWhite, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->BlackAndWhite(); });
	connect(ui.toolBtnErode, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->Erode(); });
	connect(ui.toolBtnDilate, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->Dilate(); });
	connect(ui.toolBtnOpen, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->Open(); });
	connect(ui.toolBtnClose, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->Close(); });
	connect(ui.toolBtnCannyFilter, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->CannyFilter(app->lowThreshold, app->highThreshold); });
	connect(ui.toolBtnDetectEdge, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->EdgeDetection(); });
	connect(ui.toolBtnDetectVertex, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->VertexDetection(); });
	connect(ui.toolBtnDetectObject, &QPushButton::pressed, [this]() { app->ResetImage(); app->transformed->ObjectDetection(app->lowThreshold, app->highThreshold); });

	app->waitingWidgetOnReset.append({ ui.toolBtnBlackWhite, ui.toolBtnCannyFilter, ui.toolBtnDetectEdge, ui.toolBtnDetectVertex, ui.toolBtnDetectObject });
}