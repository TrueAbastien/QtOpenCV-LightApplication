# QtOpenCV - LightApplication

Projet préparatif en traitement d'images avec OpenCV développé sur Qt en C++.

## Installation

### Utilisateur

Télécharger puis exécuter l'installateur.
Les instructions propres à l'installation seront explicités au travers du déploiement.

### Développeur

Afin de pouvoir développer le projet source, suivez les étapes suivantes:

1. Téléchargez [OpenCV 3.4.3](https://github.com/opencv/opencv/archive/3.4.3.zip), puis extrayez le sur votre disque dur.
2. Téléchargez [Qt5](https://www.qt.io/download-thank-you?hsLang=en), puis installer la **version 5.12.7 (64x)** pour **Microsoft Visual Studio 2015** (msvc2015_64).
3. Implicitement, télécharger [Microsoft Visual Studio 2015](https://my.visualstudio.com/Downloads?q=visual%20studio%202015&wt.mc_id=o~msft~vscom~older-downloads) puis, à partir de l'IDE, télécharger **l'extension Qt** puis redémarrer Microsoft VS 2015.
4. Dans l'IDE, précisez l'emplacement de  Qt en cliquant sur **Qt VS Tools > Qt Options** et en ajoutant le chemin de votre version (ex: *C:\Qt\5.12.7\msvc2015_64*). Idéalement, nommez la version **msvc2015-64**.
5. Clonez ou téléchargez le projet source sur votre disque dur.
6. Ouvrez la solution puis changez, dans les propriétés de la solution, la version de Qt sous **Qt Project Settings > Qt Installation** par **msvc2015-64** (pensez à être en version **x64** et en **_All Configurations_**).
7. Changez dans le **Property Manager**, à l'intérieur des fichiers **'Debug OpenCV.props'** et **'Release OpenCV.props'**, en cliquant dans l'onglet **User Macros**, le chemin d'accès du **build OpenCV** (ex: *C:\OpenCV\opencv\build*).
8. Après avoir compiler votre application en **Debug et Release**, chercher dans le dossier *build* précédent, sous **_\.\build\x64\vc14\bin_**, les fichiers **'opencv_world343.dll' (Release)** et **'opencv_world343d.dll' (Debug)** et copier-coller les aux emplacements des exécutables du projet (**_\.\Projet - TP 001\x64\\[Debug][Release]_**).

L'installation est désormais terminé mais il vous sera surement nécessaire de redémarrer **Microsoft Visual Studio 2015** et/ou **rescanner la solution** pour faire disparaître les erreurs.