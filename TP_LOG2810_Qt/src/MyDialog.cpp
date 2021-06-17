#include "MyDialog.h"
#include <iostream>

using namespace std;

MyDialog::MyDialog() {
    Ui_Dialog myDialog;
    myDialog.setupUi(this);
    connect(this->buttonSuggestion, &QPushButton::clicked, this, &MyDialog::buttonClicked);
}

void MyDialog::show() {
    this->exec();
}

void MyDialog::buttonClicked(QPushButton* button) {
    cout << button->accessibleName().toStdString();
}
