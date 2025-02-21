#include "loadingdialog.h"
#include "ui_loadingdialog.h"

LoadingDialog::LoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");

    movie = new QMovie();
}

LoadingDialog::~LoadingDialog()
{
    if (movie)
        delete movie;

    delete ui;
}

void LoadingDialog::Initialize(QString file_name, std::string text)
{
    movie->setFileName(file_name);
    ui->label->setMovie(movie);
    movie->start();
    ui->label_2->setText(QString::fromStdString(text));
}
