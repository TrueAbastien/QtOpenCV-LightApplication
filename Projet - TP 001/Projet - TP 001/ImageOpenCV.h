#pragma once
#include <QObject>
#include <QLabel>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/videoio.hpp"


/**
* \class ImageOpenCV
* \brief Objet-widget couvrant un QLabel en tant qu'image OpenCV
* \author Bastien LEGOY
* \version 1.0.0
* \date $Date: 2020/04/09 $
*
* Image OpenCV (cv::mat) appliquée sur un QLabel à l'aide la Pixmap.
*/
class ImageOpenCV : public QObject
{
	Q_OBJECT

public:

	/**
	* \brief Constructeur par défaut
	* \param lab Label sur lequel appliqué l'image
	*
	* Instantie l'image en sauvegardant le Label en membre.
	*/
	explicit ImageOpenCV(QLabel* lab);


	/**
	* \brief Accesseur sur l'image OpenCV sauvegardée
	* \return Image sauvegardée
	*
	* Récupère l'image sauvegardée en tant que membre de l'instance.
	*/
	cv::Mat getImage() const;

	/**
	* \brief Vérifie la présence d'une image
	* \return Résultat de la vérification
	*
	* Est Vrai si l'instance possède une image cv::Mat en mémoire.
	*/
	bool exists() const;


	/**
	* \brief Transforme l'image en noir et blanc
	* \param update Force l'update sur l'image si nécessaire
	*
	* Transforme manuellement l'image en noir et blanc pour faciliter le traitement d'erosion et de dilation.
	*/
	void BlackAndWhite(bool update = true);

	/**
	* \brief Applique l'effet de Flou sur l'image
	* \param radius Radius du Kernel de l'application du Flou
	* \param update Force l'update sur l'image si nécessaire
	*
	* Floute l'image sur sa totalité en appliquant par pixel la moyenne des pixels environnants selon le radius.
	*/
	void Blur(int radius = 2, bool update = true);

	/**
	* \brief Applique l'effet d´Érosion sur l'image
	* \param radius Radius du Kernel de l'application de l'Érosion
	* \param update Force l'update sur l'image si nécessaire
	*
	* Erode l'image actuelle en prennant la valeure maximale des pixels environnants à un pixel donné.
	*/
	void Erode(int radius = 2, bool update = true);

	/**
	* \brief Applique l'effet de Dilatation sur l'image
	* \param radius Radius du Kernel de l'application de la Dilatation
	* \param update Force l'update sur l'image si nécessaire
	*
	* Dilate l'image actuelle en prennant la valeure minimale des pixels environnants à un pixel donné.
	*/
	void Dilate(int radius = 2, bool update = true);

	/**
	* \brief Applique l'effet d'Ouverture sur l'image
	* \param radius Radius du Kernel de l'application de l'Ouverture
	* \param update Force l'update sur l'image si nécessaire
	*
	* Ouvre l'image en appliquant consécutivement l'Érosion puis la Dilatation.
	*/
	void Open(int radius = 2, bool update = true);

	/**
	* \brief Applique l'effet de Fermeture sur l'image
	* \param radius Radius du Kernel de l'application de la Fermeture
	* \param update Force l'update sur l'image si nécessaire
	*
	* Ferme l'image en appliquant consécutivement la Dilatation puis l'Érosion.
	*/
	void Close(int radius = 2, bool update = true);

	/**
	* \brief Sort le résultat du Filtre de Canny sur l'image
	* \param lowThreshold Seuil minimum
	* \param highThreshold Seuil maximum
	* \param update Force l'update sur l'image si nécessaire
	*
	* Applique le Filtre de Canny puis l'affiche sur l'image actuelle.
	*/
	void CannyFilter(int lowThreshold, int highThreshold, bool update = true);

	/**
	* \brief Affiche le résultat du Filtre Laplacian
	* \param update Force l'update sur l'image si nécessaire
	*
	* Applique puis affiche le Filtre Laplacian de l'image à fort contraste.
	*/
	void EdgeDetection(bool update = true);

	/**
	* \brief Affiche les coins trouvés par la fonction GoodFeaturesToTrack.
	* \param update Force l'update sur l'image si nécessaire
	*
	* Recherche puis affiche en bleu les coins trouvés sur l'image.
	*/
	void VertexDetection(bool update = true);

	/**
	* \brief Cherche les objets sur l'image
	* \param lowThreshold Seuil minimale
	* \param highThreshold Seuil maximale
	* \param minArea Aire minimum du rectangle circonscrit à l'objet
	* \param boxMaxRatio Multiplicateur maximale entre la largeur et la longueur de l'entourage
	* \param update Force l'update sur l'image si nécessaire
	*
	* Cherche les contours puis encadre les objets trouvés par l'algorithme.
	*/
	void ObjectDetection(int lowThreshold, int highThreshold, double minArea = 250, double boxMaxRatio = 4.0, bool update = true);

private:

	QLabel* content;
	cv::Mat image;

public slots:

	/**
	* \brief Change l'image actuelle par celle spécifiée
	* \param img Image spécifiée
	*
	* Utilisé dans la réinitialisation d'image pour cloner une image déja présente sur l'écran.
	*/
	void setImage(cv::Mat img);

	/**
	* \brief Met à jour l'affichage de l'image actuelle.
	*
	* Applique sur la Pixmap du QLabel l'image actuellement stockée en membre de l'instance, modifié ou non.
	*/
	void Update();
};