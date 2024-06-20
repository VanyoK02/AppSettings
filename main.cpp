#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Переводчик для Qt
    QTranslator qtTranslator;
    QString qtTranslationsPath = "D:/Qt/6.7.2/mingw_64/translations";

    if (qtTranslator.load(QLocale(), "qt", "_", qtTranslationsPath)) {
        qDebug() << "Qt translation files loaded successfully.";
        // Далее установка переводчика в приложение
    } else {
        qDebug() << "Failed to load Qt translation files from:" << qtTranslationsPath;
    }

    // Переводчик для приложения
    QTranslator appTranslator;
    QString appTranslationPath = ":/translations/AppSettings_ru_RU.qm";

    if (appTranslator.load(appTranslationPath)) {
        qDebug() << "Application translation file loaded successfully.";
        // Далее установка переводчика в приложение
    } else {
        qDebug() << "Failed to load application translation file:" << appTranslationPath;
    }


    MainWindow w;
    w.show();

    // Обработчик события о завершении работы приложения
    QObject::connect(&app, &QApplication::aboutToQuit, [&app, &appTranslator, &qtTranslator]() {
        // Удаление установленных переводчиков перед выходом
        app.removeTranslator(&appTranslator);
        app.removeTranslator(&qtTranslator);
    });

    return app.exec();
}
