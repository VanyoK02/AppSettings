#include "preferencesdialog.h"
#include "generaltab.h"
#include "hotkeystab.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QCoreApplication> // Для доступа к qApp
#include <QLocale> // Добавлено для QLocale
#include <QTranslator> // Добавлено для QTranslator

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
{
    tabWidget = new QTabWidget;
    tabWidget->addTab(new GeneralTab, tr("General"));
    tabWidget->addTab(new HotkeysTab, tr("Hotkeys"));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Preferences"));

    // Подключаем сигнал aboutToQuit к слоту updateTranslation
    connect(QCoreApplication::instance(), &QCoreApplication::aboutToQuit, this, &PreferencesDialog::updateTranslation);
}

void PreferencesDialog::updateTranslation()
{
    retranslateUi(); // Переводим UI заново
}

void PreferencesDialog::retranslateUi()
{
    setWindowTitle(tr("Preferences"));
    tabWidget->setTabText(0, tr("General"));
    tabWidget->setTabText(1, tr("Hotkeys"));
    buttonBox->button(QDialogButtonBox::Ok)->setText(tr("OK"));
    buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));
}

void PreferencesDialog::changeLanguage(const QString &language)
{
    // Установка локали для перевода
    QLocale locale(language);
    QLocale::setDefault(locale);

    qDebug() << "Retranslating UI";

    setWindowTitle(tr("Preferences"));
    qDebug() << "WindowTitle:" << windowTitle();

    tabWidget->setTabText(0, tr("General"));
    qDebug() << "Tab 0 text:" << tabWidget->tabText(0);

    tabWidget->setTabText(1, tr("Hotkeys"));
    qDebug() << "Tab 1 text:" << tabWidget->tabText(1);

    buttonBox->button(QDialogButtonBox::Ok)->setText(tr("OK"));
    qDebug() << "OK button text:" << buttonBox->button(QDialogButtonBox::Ok)->text();

    buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));
    qDebug() << "Cancel button text:" << buttonBox->button(QDialogButtonBox::Cancel)->text();
}
