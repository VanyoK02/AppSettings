#include "hotkeystab.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

HotkeysTab::HotkeysTab(QWidget *parent)
    : QWidget(parent)
{
    QLabel *importStepLabel = new QLabel(tr("Import from STEP"));
    importStepLineEdit = new QLineEdit;

    QLabel *exportStepLabel = new QLabel(tr("Export to STEP"));
    exportStepLineEdit = new QLineEdit;

    QLabel *exitLabel = new QLabel(tr("Exit"));
    exitLineEdit = new QLineEdit;

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(importStepLabel);
    mainLayout->addWidget(importStepLineEdit);
    mainLayout->addWidget(exportStepLabel);
    mainLayout->addWidget(exportStepLineEdit);
    mainLayout->addWidget(exitLabel);
    mainLayout->addWidget(exitLineEdit);
    mainLayout->addStretch(1);

    setLayout(mainLayout);
}
