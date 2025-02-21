#include "advsettingsdialog.h"
#include "ui_advsettingsdialog.h"

AdvSettingsDialog::AdvSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdvSettingsDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");

    lang_dialog = new LanguageDialog(this);
    lang_dialog->setWindowModality(Qt::ApplicationModal);
    lang_dialog->move(255, 165);

    user_set_dialog = new UserSettingsDialog(this);
    user_set_dialog->setWindowModality(Qt::ApplicationModal);
    user_set_dialog->move(150, 190);
    connect(user_set_dialog, SIGNAL(atUserSettingsDialog()),
            this, SLOT(onClose()));
}

AdvSettingsDialog::~AdvSettingsDialog()
{
    if (lang_dialog)
        delete lang_dialog;

    if (user_set_dialog)
        delete user_set_dialog;

    delete ui;
}

void AdvSettingsDialog::Initialize(QString user_set_text, QString language)
{
    ui->pushButton->setText(user_set_text);
    ui->pushButton_2->setText(language);
}

void AdvSettingsDialog::onClose()
{
    close();
}

void AdvSettingsDialog::on_pushButton_clicked()
{
    user_set_dialog->show();
}

void AdvSettingsDialog::on_pushButton_2_clicked()
{
    lang_dialog->SelectionLangType("TR");
    lang_dialog->show();
}

void AdvSettingsDialog::on_pushButton_3_clicked()
{
    close();
}
