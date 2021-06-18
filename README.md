1 - Installer QT5 
	
https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4

	1.1. Choisir la version 5.15 (testée pour le projet)
        1.2. Choisir MSVC 2019 x64 ainsi que UWP x64 durant l'installation de QT. Pour cela il faut prendre l'option custom et choisir les modules a installer.

2- Installer Visual Studio (Community) 2019

https://visualstudio.microsoft.com/downloads/

3- Installer l'extension Qt Vs Tools du Visual Studio Marketplace

4- Ouvrir le fichier TP_LOG2810_Qt.sln fournit.

5- Une fois ouvert, déroulez le menu Extensions->Qt Vs Tools->Qt Versions. Ajoutez votre version de Qt avec le path à qmake.exe.
	ex: C:\QT\5.15.2\mingw81_64\bin\qmake.exe

6- Ouvrez les propriétés du projet TP_LOG2810_Qt. Allez à Configuration Properties->Qt Project Setting. À Qt Installation, resélectionnez votre version Qt.
	ex: 5.15.0_msvc2019_64

7- En mode Debug, appuyer sur Local Windows Debugger pour commencer l'application.