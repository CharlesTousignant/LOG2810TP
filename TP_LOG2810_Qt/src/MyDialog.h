#pragma once
#include "ui_choixModesJeux.h"
#include <qbuttongroup.h>
#include <memory>

enum possibleGameState {
	suggest,
	correct,
	suggestCorrect,
	shouldExit
};

class MyDialog :public QDialog, public Ui_Dialog {
	Q_OBJECT
public:
	MyDialog();
	
	void buttonClicked();
	void show();

signals:
	void choiceLexique(std::string fileName);
	void choiceSelected(possibleGameState selectedState);

private:
	std::unique_ptr<Ui_Dialog> uiDialog;
};