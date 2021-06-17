#pragma once
#include "ui_choix.h"
#include <qbuttongroup.h>

enum possibleGameState {
	suggest,
	correct,
	suggestCorrect
};

class MyDialog : QDialog, Ui_Dialog {
	Q_OBJECT
public:
	MyDialog();
	
	void buttonClicked(QPushButton* buttonGroup);
	void show();

};