#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");

    ui->label_2->setText("MFG : 114325");
    ui->label_3->setText("V : 1.0.0");
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_pushButton_clicked()
{
    close();
}
