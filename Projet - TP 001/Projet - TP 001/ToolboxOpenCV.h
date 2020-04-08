#pragma once
#include "ImageModifierApp.h"
#include "ui_ToolWindow.h"
#include <QDialog>

class ToolboxOpenCV : public QDialog
{
	Q_OBJECT

public:
	ToolboxOpenCV(ImageModifierApp *parent);

private:
	Ui::Toolbox ui;
	ImageModifierApp* app;
};