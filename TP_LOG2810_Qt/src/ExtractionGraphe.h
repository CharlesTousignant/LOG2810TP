#pragma once
//#include "qdialog.h"
#include "../x64/Debug/uic/ui_extractionGraphe.h"
#include <memory>

class ExtractionGraphe : public QDialog {
	Q_OBJECT

public:
	ExtractionGraphe();
	~ExtractionGraphe() = default;

	void buttonClicked();

	void closeEvent(QCloseEvent* event) override;
signals:
	void choixCouleur(char couleur);

private:
	std::unique_ptr<Ui_DialogExtractionGraphe> uiExtraction_;
};
