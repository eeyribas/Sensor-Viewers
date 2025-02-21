#include "yesnodialog.h"
#include "ui_yesnodialog.h"

YesNoDialog::YesNoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YesNoDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");
}

YesNoDialog::~YesNoDialog()
{
    delete ui;
}

void YesNoDialog::Initialize(std::string text_1, std::string text_2, std::string yes_btn_text, std::string no_btn_text)
{
    ui->label->setText(QString::fromStdString(text_1));
    ui->label_2->setText(QString::fromStdString(text_2));
    ui->pushButton->setText(QString::fromStdString(yes_btn_text));
    ui->pushButton_2->setText(QString::fromStdString(no_btn_text));
}

void YesNoDialog::on_pushButton_clicked()
{
    emit atYesButton();
    close();
}

void YesNoDialog::on_pushButton_2_clicked()
{
    close();
}
