#pragma once
#include "ui_choixModesJeux.h"
#include "qevent.h"
#include <qbuttongroup.h>
#include <memory>

enum possibleGameState {
	suggest,
	correct,
	suggestCorrect,
	shouldExit
};

class ChoixModesJeux :public QDialog, public Ui_Dialog {
	Q_OBJECT
public:
	ChoixModesJeux();
	
	void buttonClicked();
	void show();
	void closeEvent(QCloseEvent* event) override;

	void afficherErreur(std::string erreur);

signals:
	void choiceLexique(std::string fileName);
	void choiceSelected(possibleGameState selectedState);
	void windowClosed(QCloseEvent* event);

private:
	std::unique_ptr<Ui_Dialog> uiDialog;
};