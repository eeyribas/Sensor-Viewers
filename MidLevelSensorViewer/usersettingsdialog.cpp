#include "usersettingsdialog.h"
#include "ui_usersettingsdialog.h"

UserSettingsDialog::UserSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettingsDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");

    SelectionType1();
    SelectionType2();
}

UserSettingsDialog::~UserSettingsDialog()
{
    delete ui;
}

void UserSettingsDialog::on_pushButton_clicked()
{
    emit atUserSettingsDialog();
    close();
}

void UserSettingsDialog::SelectionType1()
{
    ui->comboBox->clear();
    ui->comboBox->addItem("Value - 1");
    ui->comboBox->addItem("Value - 2");
    ui->comboBox->addItem("Value - 3");
    ui->comboBox->setCurrentIndex(1);
}

void UserSettingsDialog::SelectionType2()
{
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("Value - 1");
    ui->comboBox_2->addItem("Value - 2");
    ui->comboBox_2->addItem("Value - 3");
    ui->comboBox_2->addItem("Value - 4");
    ui->comboBox_2->addItem("Value - 5");
    ui->comboBox_2->setCurrentIndex(2);
}
