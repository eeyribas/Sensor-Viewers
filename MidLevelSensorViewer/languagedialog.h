#ifndef LANGUAGEDIALOG_H
#define LANGUAGEDIALOG_H

#include <QDialog>
#include <QFontDatabase>

namespace Ui {
class LanguageDialog;
}

class LanguageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LanguageDialog(QWidget *parent = nullptr);
    ~LanguageDialog();

    void SelectionLangType(QString language);

signals:
    void atLangType(QString language);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::LanguageDialog *ui;
};

#endif // LANGUAGEDIALOG_H
