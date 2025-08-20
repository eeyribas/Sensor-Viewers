#include "languagedialog.h"
#include "ui_languagedialog.h"

LanguageDialog::LanguageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanguageDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");

    SelectionLangType("TR");
}

LanguageDialog::~LanguageDialog()
{
    delete ui;
}

void LanguageDialog::SelectionLangType(QString language)
{
    if (language == "TR")
    {
        ui->pushButton->setStyleSheet("QPushButton { border: 0px; image: "
                                      "url(:/images/images/turkey_active.png); }");
        ui->pushButton_2->setStyleSheet("QPushButton { border: 0px; image: "
                                        "url(:/images/images/USA_passive.png); }"
                                        "QPushButton:hover{ border: 0px; image: "
                                        "url(:/images/images/USA_active.png); }");
    } else if (language == "EN") {
        ui->pushButton->setStyleSheet("QPushButton { border: 0px; image: "
                                      "url(:/images/images/turkey_passive.png); }"
                                      "QPushButton:hover{ border: 0px; image: "
                                      "url(:/images/images/turkey_active.png); }");
        ui->pushButton_2->setStyleSheet("QPushButton { border: 0px; image: "
                                        "url(:/images/images/USA_active.png); }");
    }
}

void LanguageDialog::on_pushButton_clicked()
{
    emit atLangType("TR");
    close();
}

void LanguageDialog::on_pushButton_2_clicked()
{
    emit atLangType("EN");
    close();
}

void LanguageDialog::on_pushButton_3_clicked()
{
    emit atLangType("EN");
    close();
}
