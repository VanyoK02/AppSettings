#include "generaltab.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QColorDialog>
#include <QPushButton>

GeneralTab::GeneralTab(QWidget *parent)
    : QWidget(parent)
{
    backgroundColorButton = new QPushButton(tr("Choose Background Color"));
    connect(backgroundColorButton, &QPushButton::clicked, this, &GeneralTab::chooseBackgroundColor);

    modelColorButton = new QPushButton(tr("Choose Model Color"));
    connect(modelColorButton, &QPushButton::clicked, this, &GeneralTab::chooseModelColor);

    askOnExitCheckBox = new QCheckBox(tr("Ask on Exit"));
    showCubeCheckBox = new QCheckBox(tr("Show Cube"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(backgroundColorButton);
    mainLayout->addWidget(modelColorButton);
    mainLayout->addWidget(askOnExitCheckBox);
    mainLayout->addWidget(showCubeCheckBox);
    mainLayout->addStretch(1);

    setLayout(mainLayout);
}

void GeneralTab::chooseBackgroundColor()
{
    backgroundColor = QColorDialog::getColor(Qt::white, this, tr("Choose Background Color"));
}

void GeneralTab::chooseModelColor()
{
    modelColor = QColorDialog::getColor(Qt::white, this, tr("Choose Model Color"));
}
