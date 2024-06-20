QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    preferencesdialog.cpp \
    generaltab.cpp \
    hotkeystab.cpp

HEADERS += \
    mainwindow.h \
    preferencesdialog.h \
    generaltab.h \
    hotkeystab.h

RESOURCES += \
    AppSettings.qrc

DISTFILES += \
    translations/AppSettings_en_US.qm \
    translations/AppSettings_ru_RU.qm \
    translations/qtbase_en.qm \
    translations/qtbase_ru.qm

TRANSLATIONS += \
    translations/AppSettings_en_US.ts \
    translations/AppSettings_ru_RU.ts

