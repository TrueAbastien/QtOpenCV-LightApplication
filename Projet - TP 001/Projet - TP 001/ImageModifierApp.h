#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageModifierApp.h"

#include "ImageOpenCV.h"

class ToolboxOpenCV;


/**
 * \class ImageModifierApp
 * \brief Application principale
 * \author Bastien LEGOY
 * \version 1.0.0
 * \date $Date: 2020/04/09 $
 *
 * Couvre l'application principale.
 */
class ImageModifierApp : public QMainWindow
{
	Q_OBJECT

public:

	/**
	* \brief Constructeur par défaut
	* \param parent Widget parent de l'application principale
	*
	* Connecte la totalité du menu.
	* Charge les images OpenCV sur l'application.
	*/
	explicit ImageModifierApp(QWidget *parent = Q_NULLPTR);

	/**
	* \brief Déstructeur par défaut
	*
	* Supprime la totalité des pointeurs initialisés.
	*/
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

	QSize imageMaximumWidth;

	/**
	* \brief Mise à jour à la réinitialisation
	* \param val Nouvel état du contenu à changer
	*
	* Active ou désactive les Actions/Widgets en attente.
	*/
	void releaseOnReset(bool val);

public slots:

	/**
	* \brief Réinitialise l'image actuelle
	* \param force Force la réinitialisation
	*
	* Applique l'image originale sur l'image transformée.
	*/
	void ResetImage(bool force = false);

	/**
	* \brief Charge une nouvelle image originale
	*
	* Charge une image à l'aide d'un sélecteur de fichier.
	*/
	void LoadImage();

	/**
	* \brief Sauvegarde l'image transformée
	*
	* Sauvegarde l'image à l'aide d'un sélecteur de fichier.
	* L'utilisateur choisi le nom et l'emplacement.
	* Si l'extension n'est pas spécifiée, le format par défaut sera le PNG.
	*/
	void SaveImage();
};
