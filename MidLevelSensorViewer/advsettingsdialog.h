#ifndef ADVSETTINGSDIALOG_H
#define ADVSETTINGSDIALOG_H

#include <QDialog>
#include <QFontDatabase>
#include "languagedialog.h"
#include "usersettingsdialog.h"

namespace Ui {
class AdvSettingsDialog;
}

class AdvSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdvSettingsDialog(QWidget *parent = nullptr);
    ~AdvSettingsDialog();

    void Initialize(QString user_set_text, QString language);

public slots:
    void onClose();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::AdvSettingsDialog *ui;
    LanguageDialog *lang_dialog;
    UserSettingsDialog *user_set_dialog;
};

#endif // ADVSETTINGSDIALOG_H
