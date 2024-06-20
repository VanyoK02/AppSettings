#include "mainwindow.h"
#include "preferencesdialog.h"
#include <QMenuBar>
#include <QMessageBox>
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , translator(new QTranslator(this))
    , qtTranslator(new QTranslator(this))
{
    // Создание элементов интерфейса
    editMenu = menuBar()->addMenu(tr("&Edit"));

    preferencesAction = new QAction(tr("Preferences..."), this);
    connect(preferencesAction, &QAction::triggered, this, &MainWindow::openPreferences);
    editMenu->addAction(preferencesAction);

    switchToEnglishAction = new QAction(tr("Switch to English"), this);
    connect(switchToEnglishAction, &QAction::triggered, this, &MainWindow::switchToEnglish);
    editMenu->addAction(switchToEnglishAction);

    switchToRussianAction = new QAction(tr("Switch to Russian"), this);
    connect(switchToRussianAction, &QAction::triggered, this, &MainWindow::switchToRussian);
    editMenu->addAction(switchToRussianAction);
}

MainWindow::~MainWindow()
{
    delete translator;
    delete qtTranslator;
}

void MainWindow::openPreferences()
{
    PreferencesDialog dialog(this);

    // Связываем сигнал languageChanged с слотом changeLanguage диалога настроек
    connect(this, &MainWindow::languageChanged, &dialog, &PreferencesDialog::changeLanguage);

    dialog.exec();
}

void MainWindow::switchLanguage(const QString &languageCode)
{
    QString appTranslationFile;
    QString qtTranslationFile;

    // Определяем файлы перевода в зависимости от выбранного языка
    if (languageCode == "en_US") {
        appTranslationFile = QString(":/translations/AppSettings_en_US.qm");
        qtTranslationFile = QString(":/translations/qtbase_en.qm");
    } else if (languageCode == "ru_RU") {
        appTranslationFile = QString(":/translations/AppSettings_ru_RU.qm");
        qtTranslationFile = QString(":/translations/qtbase_ru.qm");
    }

    // Загружаем и устанавливаем файлы перевода
    loadTranslationFiles(appTranslationFile, qtTranslationFile);
}

void MainWindow::switchToEnglish()
{
    switchLanguage("en_US");
    emit languageChanged("en_US"); // Изменение сигнала
}

void MainWindow::switchToRussian()
{
    switchLanguage("ru_RU");
    emit languageChanged("ru_RU"); // Изменение сигнала
}

void MainWindow::loadTranslationFiles(const QString &appTranslationFile, const QString &qtTranslationFile)
{
    qDebug() << "Loading application translation file:" << appTranslationFile;

    // Удаляем текущие переводчики, если они были установлены
    qApp->removeTranslator(translator);
    qApp->removeTranslator(qtTranslator);

    // Загружаем перевод для приложения
    if (translator->load(appTranslationFile)) {
        qApp->installTranslator(translator);
        qDebug() << "Application translation file loaded successfully.";
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("Failed to load application translation file: %1").arg(appTranslationFile));
        qDebug() << "Failed to load application translation file:" << appTranslationFile;
    }

    // Загружаем перевод для Qt
    qDebug() << "Loading Qt translation file:" << qtTranslationFile;
    if (qtTranslator->load(qtTranslationFile)) {
        qApp->installTranslator(qtTranslator);
        qDebug() << "Qt translation file loaded successfully.";
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("Failed to load Qt translation file: %1").arg(qtTranslationFile));
        qDebug() << "Failed to load Qt translation file:" << qtTranslationFile;
    }

    retranslateUi(); // Переводим интерфейс заново
}

void MainWindow::retranslateUi()
{
    editMenu->setTitle(tr("&Edit"));
    preferencesAction->setText(tr("Preferences..."));
    switchToEnglishAction->setText(tr("Switch to English"));
    switchToRussianAction->setText(tr("Switch to Russian"));
    // Добавьте дополнительные переводы для других элементов интерфейса, если необходимо
}
