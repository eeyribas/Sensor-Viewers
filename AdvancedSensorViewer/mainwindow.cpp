#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    setWindowIcon(QIcon(":/images/images/icon.ico"));
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Lato-Regular.ttf");

    srand(static_cast<unsigned int>(time(0)));
    test_sensor_data.clear();
    test_index = 0;
    main_control_count = 0;

    main_control = new MainControl(this);
    connect(main_control, SIGNAL(atMainControl(QString)),
            this, SLOT(onMainControl(QString)));
    main_control->start();

    info_dialog = new InfoDialog(this);
    info_dialog->setWindowModality(Qt::ApplicationModal);
    info_dialog->move(230, 170);

    loading_dialog = new LoadingDialog(this);
    loading_dialog->setWindowModality(Qt::ApplicationModal);
    loading_dialog->move(200, 90);

    yes_no_dialog = new YesNoDialog(this);
    yes_no_dialog->setWindowModality(Qt::ApplicationModal);
    yes_no_dialog->move(180, 140);
    connect(yes_no_dialog, SIGNAL(atYesButton()),
            this, SLOT(onClearTests()));

    Initialize();
}

MainWindow::~MainWindow()
{
    if (main_control)
        delete main_control;

    if (info_dialog)
        delete info_dialog;

    if (loading_dialog)
        delete loading_dialog;

    if (yes_no_dialog)
        delete yes_no_dialog;

    delete ui;
}

void MainWindow::onMainControl(QString time)
{
    ui->label_4->setText(time);

    main_control_count++;
    if (main_control_count == 5) {
        loading_dialog->close();
        main_control_count = 0;
    }
}

void MainWindow::onClearTests()
{
    EmptyTestLabels();
    EmptyTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29);
    EmptyTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32);
    EmptyTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35);
    EmptyTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38);
    EmptyTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41);

    test_sensor_data.clear();
    test_index = 0;
}

void MainWindow::on_pushButton_clicked()
{
    info_dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ButtonsStatus(false, false, false, false, false, false);
    EmptyComparisonLabels();
    EmptyTestLabels();
    EmptyTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29);
    EmptyTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32);
    EmptyTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35);
    EmptyTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38);
    EmptyTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41);
    ui->label_6->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));

    loading_dialog->Initialize(":/images/images/loading.gif", "Standard");
    loading_dialog->show();

    ButtonsStatus(true, true, false, true, true, true);
}

void MainWindow::on_pushButton_3_clicked()
{
    ButtonsStatus(false, false, false, false, false, false);
    EmptyTestLabels();
    EmptyTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29);
    EmptyTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32);
    EmptyTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35);
    EmptyTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38);
    EmptyTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41);

    test_sensor_data.clear();
    test_index = 0;
    comparison_sensor_data.a_value = RandomNumber();
    comparison_sensor_data.b_value = RandomNumber();
    comparison_sensor_data.c_value = RandomNumber();
    comparison_sensor_data.d_value = RandomNumber();
    comparison_sensor_data.e_value = RandomNumber();

    WriteComparisonLabels(comparison_sensor_data);
    ButtonsStatus(true, true, true, true, true, true);
}

void MainWindow::on_pushButton_4_clicked()
{
    ButtonsStatus(false, false, false, false, false, false);

    SensorData sensor_data;
    sensor_data.a_value = RandomNumber();
    sensor_data.b_value = RandomNumber();
    sensor_data.c_value = RandomNumber();
    sensor_data.d_value = RandomNumber();
    sensor_data.e_value = RandomNumber();
    sensor_data.a_diff_value = sensor_data.a_value - comparison_sensor_data.a_value;
    sensor_data.b_diff_value = sensor_data.b_value - comparison_sensor_data.b_value;
    sensor_data.c_diff_value = sensor_data.c_value - comparison_sensor_data.c_value;
    sensor_data.d_diff_value = sensor_data.d_value - comparison_sensor_data.d_value;
    sensor_data.e_diff_value = sensor_data.e_value - comparison_sensor_data.e_value;
    test_sensor_data.push_back(sensor_data);

    if (test_sensor_data.size() > 0) {
        test_index = static_cast<uint>(test_sensor_data.size() - 1);
        WriteTestLabels(test_sensor_data.at(test_index), comparison_sensor_data);
        WriteTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29,
                                  "rgb(127, 127, 127)", "rgb(255, 255, 255)",
                                  sensor_data.a_diff_value);
        WriteTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32,
                                  "rgb(34, 177, 76)", "rgb(255, 0, 0)",
                                  sensor_data.b_diff_value);
        WriteTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35,
                                  "rgb(0, 162, 232)", "rgb(255, 242, 0)",
                                  sensor_data.c_diff_value);
        WriteTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38,
                                  "rgb(255, 255, 255)", "rgb(164, 0, 221)",
                                  sensor_data.d_diff_value);
        WriteTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41,
                                  "rgb(164, 0, 221)", "rgb(127, 127, 127)",
                                  sensor_data.e_diff_value);
    }

    ButtonsStatus(true, true, true, true, true, true);
}

void MainWindow::on_pushButton_5_clicked()
{
    yes_no_dialog->Initialize("Are you sure?", "Are you sure you want to delete the tests?",
                              "Yes", "No");
    yes_no_dialog->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    if (test_sensor_data.size() > 0 && test_index > 0) {
        test_index = test_index - 1;
        WriteTestLabels(test_sensor_data.at(test_index), comparison_sensor_data);
        WriteTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29,
                                  "rgb(127, 127, 127)", "rgb(255, 255, 255)",
                                  test_sensor_data.at(test_index).a_diff_value);
        WriteTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32,
                                  "rgb(34, 177, 76)", "rgb(255, 0, 0)",
                                  test_sensor_data.at(test_index).b_diff_value);
        WriteTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35,
                                  "rgb(0, 162, 232)", "rgb(255, 242, 0)",
                                  test_sensor_data.at(test_index).c_diff_value);
        WriteTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38,
                                  "rgb(255, 255, 255)", "rgb(164, 0, 221)",
                                  test_sensor_data.at(test_index).d_diff_value);
        WriteTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41,
                                  "rgb(164, 0, 221)", "rgb(127, 127, 127)",
                                  test_sensor_data.at(test_index).e_diff_value);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if (test_sensor_data.size() > 0 && test_index < test_sensor_data.size() - 1) {
        test_index = test_index + 1;
        WriteTestLabels(test_sensor_data.at(test_index), comparison_sensor_data);
        WriteTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29,
                                  "rgb(127, 127, 127)", "rgb(255, 255, 255)",
                                  test_sensor_data.at(test_index).a_diff_value);
        WriteTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32,
                                  "rgb(34, 177, 76)", "rgb(255, 0, 0)",
                                  test_sensor_data.at(test_index).b_diff_value);
        WriteTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35,
                                  "rgb(0, 162, 232)", "rgb(255, 242, 0)",
                                  test_sensor_data.at(test_index).c_diff_value);
        WriteTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38,
                                  "rgb(255, 255, 255)", "rgb(164, 0, 221)",
                                  test_sensor_data.at(test_index).d_diff_value);
        WriteTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41,
                                  "rgb(164, 0, 221)", "rgb(127, 127, 127)",
                                  test_sensor_data.at(test_index).e_diff_value);
    }
}

void MainWindow::Initialize()
{
    ui->label_2->setStyleSheet("background: url(:/images/images/sensor_ok_img.png);");
    ui->label_6->setText("-");

    FillToolboxs();
    EmptyComparisonLabels();
    EmptyTestLabels();
    EmptyTestDifferenceLabels(ui->label_27, ui->label_28, ui->label_29);
    EmptyTestDifferenceLabels(ui->label_30, ui->label_31, ui->label_32);
    EmptyTestDifferenceLabels(ui->label_33, ui->label_34, ui->label_35);
    EmptyTestDifferenceLabels(ui->label_36, ui->label_37, ui->label_38);
    EmptyTestDifferenceLabels(ui->label_39, ui->label_40, ui->label_41);
    ButtonsStatus(true, false, false, false, false, false);
}

void MainWindow::FillToolboxs()
{
    ui->comboBox->clear();
    ui->comboBox->addItem("Value - 1");
    ui->comboBox->addItem("Value - 2");

    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("Value - 1");
    ui->comboBox_2->addItem("Value - 2");
    ui->comboBox_2->addItem("Value - 3");
    ui->comboBox_2->addItem("Value - 4");
    ui->comboBox_2->addItem("Value - 5");

    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Value - 1");
    ui->comboBox_3->addItem("Value - 2");
    ui->comboBox_3->addItem("Value - 3");
}

void MainWindow::WriteComparisonLabels(SensorData comparison_data)
{
    ui->label_17->setText(QString::number(comparison_data.a_value, 'f', 2));
    ui->label_18->setText(QString::number(comparison_data.b_value, 'f', 2));
    ui->label_19->setText(QString::number(comparison_data.c_value, 'f', 2));
    ui->label_20->setText(QString::number(comparison_data.d_value, 'f', 1));
    ui->label_21->setText(QString::number(comparison_data.e_value, 'f', 1));
}

void MainWindow::EmptyComparisonLabels()
{
    ui->label_17->setText("-");
    ui->label_18->setText("-");
    ui->label_19->setText("-");
    ui->label_20->setText("-");
    ui->label_21->setText("-");
}

void MainWindow::WriteTestLabels(SensorData test_data, SensorData comparison_data)
{
    ui->label_22->setText(QString::number(test_data.a_value, 'f', 2));
    ui->label_23->setText(QString::number(test_data.b_value, 'f', 2));
    ui->label_24->setText(QString::number(test_data.c_value, 'f', 2));
    ui->label_25->setText(QString::number(test_data.d_value, 'f', 2));
    ui->label_26->setText(QString::number(test_data.e_value, 'f', 2));

    double result = (test_data.a_value - comparison_data.a_value) +
                    (test_data.b_value - comparison_data.b_value) +
                    (test_data.c_value - comparison_data.c_value) +
                    (test_data.d_value - comparison_data.d_value) +
                    (test_data.e_value - comparison_data.e_value);
    ui->label_8->setText(QString::number(result, 'f', 2));
    ui->label_42->setText(QString::number(test_index + 1) + "/" +
                          QString::number(test_sensor_data.size()));
    ui->label_43->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
}

void MainWindow::EmptyTestLabels()
{
    ui->label_22->setText("-");
    ui->label_23->setText("-");
    ui->label_24->setText("-");
    ui->label_25->setText("-");
    ui->label_26->setText("-");

    ui->label_8->setText("-");
    ui->label_42->setText("0/0");
    ui->label_43->setText("-");
}

void MainWindow::WriteTestDifferenceLabels(QLabel *label_1, QLabel *label_2, QLabel *label_3,
                                           QString low_color, QString high_color, double diff_value)
{
    if (diff_value > 0) {
        label_1->setText(QString::number(diff_value, 'f', 2));
        label_1->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                               "font: 28px 'Lato-Bold'; color: " + high_color + ";");
        label_2->setText("▲");
        label_2->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                               "font: 25px 'Lato-Bold'; color: " + high_color + ";");
        label_3->setText("▀");
        label_3->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                               "font: 25px 'Lato-Bold'; color: " + low_color + ";");
    } else {
        label_1->setText(QString::number(diff_value, 'f', 2));
        label_1->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                               "font: 28px 'Lato-Bold'; color: " + low_color + ";");
        label_2->setText("▄");
        label_2->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                               "font: 25px 'Lato-Bold'; color: " + high_color + ";");
        label_3->setText("▼");
        label_3->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                               "font: 25px 'Lato-Bold'; color: " + low_color + ";");
    }
}

void MainWindow::EmptyTestDifferenceLabels(QLabel *label_1, QLabel *label_2, QLabel *label_3)
{
    label_1->setText("-");
    label_2->setText("-");
    label_2->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                           "font: 25px 'Lato-Bold'; color: rgb(164, 0, 221);");
    label_3->setText("-");
    label_3->setStyleSheet("background-color: rgb(100, 100, 100); image: none; "
                           "font: 25px 'Lato-Bold'; color: rgb(164, 0, 221);");
}

void MainWindow::ButtonsStatus(bool standard_state, bool comparison_state, bool test_state,
                               bool up_btn_state, bool down_btn_state,  bool clear_btn_state)
{
    ui->pushButton_2->setEnabled(standard_state);
    ui->pushButton_3->setEnabled(comparison_state);
    ui->pushButton_4->setEnabled(test_state);
    ui->pushButton_5->setEnabled(clear_btn_state);
    ui->pushButton_6->setEnabled(down_btn_state);
    ui->pushButton_7->setEnabled(up_btn_state);
}

double MainWindow::RandomNumber()
{
    double random = static_cast<double>(rand()) / RAND_MAX * 10.0;

    return random;
}
