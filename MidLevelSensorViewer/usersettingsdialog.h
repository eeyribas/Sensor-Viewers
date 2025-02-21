#ifndef USERSETTINGSDIALOG_H
#define USERSETTINGSDIALOG_H

#include <QDialog>
#include <QFontDatabase>

namespace Ui {
class UserSettingsDialog;
}

class UserSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettingsDialog(QWidget *parent = nullptr);
    ~UserSettingsDialog();

signals:
    void atUserSettingsDialog();

private slots:
    void on_pushButton_clicked();

private:
    void SelectionType1();
    void SelectionType2();

    Ui::UserSettingsDialog *ui;
};

#endif // USERSETTINGSDIALOG_H
