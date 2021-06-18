#pragma once
#include "qdialog.h"
#include "ui_extractionGraphe.h"
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
	std::unique_ptr<Ui_Dialog_Extraction> uiExtraction_;
};