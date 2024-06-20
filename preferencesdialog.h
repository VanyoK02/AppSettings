#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog(QWidget *parent = nullptr);

public slots:
    void changeLanguage(const QString &language);

private:
    void retranslateUi();
    void updateTranslation();

    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

#endif // PREFERENCESDIALOG_H
