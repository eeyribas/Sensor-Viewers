#ifndef YESNODIALOG_H
#define YESNODIALOG_H

#include <QDialog>
#include <QFontDatabase>

namespace Ui {
class YesNoDialog;
}

class YesNoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit YesNoDialog(QWidget *parent = nullptr);
    ~YesNoDialog();

    void Initialize(std::string text_1, std::string text_2,
                    std::string yes_btn_text, std::string no_btn_text);

signals:
    void atYesButton();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::YesNoDialog *ui;
};

#endif // YESNODIALOG_H
