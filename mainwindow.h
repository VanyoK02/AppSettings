#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QTranslator>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void switchToEnglish();
    void switchToRussian();

signals:
    void languageChanged(const QString &language);

private slots:
    void openPreferences();
    void switchLanguage(const QString &languageCode);

private:
    void loadTranslationFiles(const QString &appTranslationFile, const QString &qtTranslationFile);
    void retranslateUi();

    QMenu *editMenu;
    QAction *preferencesAction;
    QAction *switchToEnglishAction;
    QAction *switchToRussianAction;

    QTranslator *translator;
    QTranslator *qtTranslator;

};

#endif // MAINWINDOW_H
