#ifndef GENERALTAB_H
#define GENERALTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QColorDialog;
class QPushButton;
QT_END_NAMESPACE

class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    GeneralTab(QWidget *parent = nullptr);

private slots:
    void chooseBackgroundColor();
    void chooseModelColor();

private:
    QPushButton *backgroundColorButton;
    QPushButton *modelColorButton;
    QCheckBox *askOnExitCheckBox;
    QCheckBox *showCubeCheckBox;
    QColor backgroundColor;
    QColor modelColor;
};

#endif // GENERALTAB_H

