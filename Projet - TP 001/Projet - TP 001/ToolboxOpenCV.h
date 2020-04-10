#pragma once
#include "ImageModifierApp.h"
#include "ui_ToolWindow.h"
#include <QDialog>


/**
* \class ToolboxOpenCV
* \brief Dialogue affichant la boîte d'outils.
* \author Bastien LEGOY
* \version 1.0.0
* \date $Date: 2020/04/09 $
*
* Boîte d'outils sur une nouvelle fenêtre ne dépendant pas de l'application principale.
* Permet de réaliser la totalité des actions du Menu Outils SAUF désactiver/activer la Réinitialisation automatique.
*/
class ToolboxOpenCV : public QDialog
{
	Q_OBJECT

public:

	/**
	* \brief Constructeur par défaut
	* \param parent Application actuelle
	*
	* Connecte la totalité du boutons-outils.
	*/
	explicit ToolboxOpenCV(ImageModifierApp *parent);

private:

	Ui::Toolbox ui;
	ImageModifierApp* app;
};