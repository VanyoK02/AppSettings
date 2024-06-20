#ifndef HOTKEYSTAB_H
#define HOTKEYSTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class HotkeysTab : public QWidget
{
    Q_OBJECT

public:
    HotkeysTab(QWidget *parent = nullptr);

private:
    QLineEdit *importStepLineEdit;
    QLineEdit *exportStepLineEdit;
    QLineEdit *exitLineEdit;
};

#endif // HOTKEYSTAB_H
