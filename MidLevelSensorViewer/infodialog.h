#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QIcon>
#include <QFontDatabase>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
