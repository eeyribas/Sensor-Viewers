#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H

#include <QDialog>
#include <QIcon>
#include <QMovie>
#include <QFontDatabase>

namespace Ui {
class LoadingDialog;
}

class LoadingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingDialog(QWidget *parent = nullptr);
    ~LoadingDialog();

    void Initialize(QString file_name, std::string text);

private:
    Ui::LoadingDialog *ui;
    QMovie *movie;
};

#endif // LOADINGDIALOG_H
