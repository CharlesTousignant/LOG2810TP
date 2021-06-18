#include "ExtractionGraphe.h"

using namespace std;

ExtractionGraphe::ExtractionGraphe() {
    uiExtraction_ = make_unique<Ui_Dialog_Extraction>();
    uiExtraction_->setupUi(this);

    connect(uiExtraction_->r, &QPushButton::clicked, this, &ExtractionGraphe::buttonClicked);
    connect(uiExtraction_->b, &QPushButton::clicked, this, &ExtractionGraphe::buttonClicked);
    connect(uiExtraction_->v, &QPushButton::clicked, this, &ExtractionGraphe::buttonClicked);
    connect(uiExtraction_->j, &QPushButton::clicked, this, &ExtractionGraphe::buttonClicked);

    connect(uiExtraction_->continuer, &QPushButton::clicked, this, &ExtractionGraphe::buttonClicked);
}

void ExtractionGraphe::buttonClicked() {
    string buttonName = QObject::sender()->objectName().toStdString();

    if (buttonName.length() == 1) {
        emit(choixCouleur(buttonName[0]));
    }

    this->accept();
}

void ExtractionGraphe::closeEvent(QCloseEvent* event) {
    // do nothing
}