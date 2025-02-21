#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    adv_settings_dialog = new AdvSettingsDialog(this);
    adv_settings_dialog->setWindowModality(Qt::ApplicationModal);
    adv_settings_dialog->move(145, 190);

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

    if (adv_settings_dialog)
        delete adv_settings_dialog;

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
    ui->label_3->setText(time);
    ui->label_4->setStyleSheet("background: url(:/images/images/sensor_ok.png);");

    main_control_count++;
    if (main_control_count == 5) {
        loading_dialog->close();
        main_control_count = 0;
    }
}

void MainWindow::onClearTests()
{
    test_sensor_data.clear();
    test_index = 0;
    ui->label_11->setText("0");

    QWidget *widget_1 = new QWidget();
    widget_1->setStyleSheet("background-color: rgb(84, 40, 72);");
    ui->scrollArea_2->setWidget(widget_1);

    QWidget *widget_2 = new QWidget();
    widget_2->setStyleSheet("background-color: rgb(84, 40, 72);");
    ui->scrollArea_3->setWidget(widget_2);

    QWidget *widget_3 = new QWidget();
    widget_3->setStyleSheet("background-color: rgb(84, 40, 72);");
    ui->scrollArea_4->setWidget(widget_3);

    QWidget *widget_4 = new QWidget();
    widget_4->setStyleSheet("background-color: rgb(84, 40, 72);");
    ui->scrollArea_5->setWidget(widget_4);

    ui->label_14->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    adv_settings_dialog->Initialize("User Settings", "Language");
    adv_settings_dialog->show();
    ButtonsStatus(true, false, false, false, false, false, true);
}

void MainWindow::on_pushButton_2_clicked()
{
    info_dialog->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    yes_no_dialog->Initialize("Are you sure?", "Are you sure you want to delete the tests?", "Yes", "No");
    yes_no_dialog->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    if (test_sensor_data.size() > 0 && test_index < test_sensor_data.size() - 1) {
        test_index = test_index + 1;
        ui->label_11->setText(QString::number(test_index + 1));
        ShowTest(test_sensor_data.at(test_index));
        ui->label_14->setText(QString::number(test_index + 1));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if (test_sensor_data.size() > 0 && test_index > 0) {
        test_index = test_index - 1;
        ui->label_11->setText(QString::number(test_index + 1));
        ShowTest(test_sensor_data.at(test_index));
        ui->label_14->setText(QString::number(test_index + 1));
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    ButtonsStatus(false, false, false, false, false, false, false);
    main_control_count = 0;
    loading_dialog->Initialize(":/images/images/loading.gif", "Standard");
    loading_dialog->show();
    ButtonsStatus(true, true, false, true, true, true, true);
}

void MainWindow::on_pushButton_7_clicked()
{
    ButtonsStatus(false, false, false, false, false, false, false);
    main_control_count = 0;
    loading_dialog->Initialize(":/images/images/loading.gif", "Comparison");
    loading_dialog->show();

    SensorData sensor_data;
    sensor_data.a_value = RandomNumber();
    sensor_data.b_value = RandomNumber();
    sensor_data.c_value = RandomNumber();
    sensor_data.d_value = RandomNumber();
    sensor_data.e_value = RandomNumber();

    ShowComparison(sensor_data);
    ButtonsStatus(true, true, true, true, true, true, true);
}

void MainWindow::on_pushButton_8_clicked()
{
    ButtonsStatus(false, false, false, false, false, false, false);

    SensorData sensor_data;
    sensor_data.a_value = RandomNumber();
    sensor_data.b_value = RandomNumber();
    sensor_data.c_value = RandomNumber();
    sensor_data.d_value = RandomNumber();
    sensor_data.e_value = RandomNumber();
    sensor_data.f_value = RandomNumber();
    sensor_data.g_value = RandomNumber();
    sensor_data.h_value = RandomNumber();
    sensor_data.i_value = RandomNumber();
    sensor_data.j_value = RandomNumber();
    sensor_data.k_value = RandomNumber();
    sensor_data.l_value = RandomNumber();
    sensor_data.m_value = RandomNumber();
    sensor_data.text = "Test - " + QString::number(test_index + 2);

    test_sensor_data.push_back(sensor_data);
    if (test_sensor_data.size() > 0) {
        test_index = static_cast<uint>(test_sensor_data.size() - 1);
        ui->label_11->setText(QString::number(test_index + 1));
        ShowTest(test_sensor_data.at(test_index));
        ui->label_14->setText(QString::number(test_index + 1));
    }

    ButtonsStatus(true, true, true, true, true, true, true);
}

void MainWindow::Initialize()
{
    ui->label->setText("Sensor Meas");
    ui->label_11->setText("0");
    ButtonsStatus(true, false, false, false, false, false, true);
    SetDescriptionText("Measurement");
    onClearTests();
}

void MainWindow::ButtonsStatus(bool standard_state, bool comparison_state, bool test_state, bool up_btn_state, bool down_btn_state,
                               bool clear_btn_state, bool settings_state)
{
    ui->pushButton->setEnabled(settings_state);
    ui->pushButton_3->setEnabled(clear_btn_state);
    ui->pushButton_4->setEnabled(up_btn_state);
    ui->pushButton_5->setEnabled(down_btn_state);
    ui->pushButton_6->setEnabled(standard_state);
    ui->pushButton_7->setEnabled(comparison_state);
    ui->pushButton_8->setEnabled(test_state);
}

void MainWindow::SetDescriptionText(QString text)
{
    ui->label_2->setText(text);
    ui->label_13->setText("Description");
    ButtonsStatus(true, false, false, true, true, true, true);
}

void MainWindow::ShowComparison(SensorData sensor_data)
{
    ScrollAreaProperties sca_prop;

    QWidget *widget = new QWidget();
    widget->setStyleSheet("background-color: rgb(84, 40, 72);");
    widget->setContentsMargins(0, 0, 0, 0);

    QFormLayout *qform_layout = new QFormLayout();
    qform_layout->setContentsMargins(0, 0, 0, 0);
    qform_layout->setSpacing(0);

    QHBoxLayout *first_hbox_layout = sca_prop.CreateQHBoxLayout("a *", "b *", "c *", "d *", "e *", 98, 38,
                                                                "QLabel { background-color: rgb(255, 255, 255); color: rgb(84, 40, 72); "
                                                                "qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                "font: 28px 'Lato-Bold'; }");
    qform_layout->addRow(first_hbox_layout);

    QHBoxLayout *second_hbox_layout = sca_prop.CreateQHBoxLayout(QString::number(sensor_data.a_value, 'f', 2), QString::number(sensor_data.b_value, 'f', 2),
                                                                 QString::number(sensor_data.c_value, 'f', 2), QString::number(sensor_data.d_value, 'f', 2),
                                                                 QString::number(sensor_data.e_value, 'f', 2), 98, 38, "QLabel { background-color: rgba(255, 255, 255, 0%); "
                                                                 "color: rgb(255, 255, 255); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                 "font: 28px 'Lato-Bold'; }");
    qform_layout->addRow(second_hbox_layout);

    widget->setLayout(qform_layout);
    ui->scrollArea->setContentsMargins(0, 0, 0, 0);
    ui->scrollArea->setWidget(widget);
}

void MainWindow::ShowTest(SensorData sensor_data)
{
    ScrollAreaProperties sca_prop;

    QWidget *widget_1 = new QWidget();
    widget_1->setStyleSheet("background-color: rgb(84, 40, 72);");
    widget_1->setContentsMargins(0, 0, 0, 0);
    QFormLayout *qform_layout_1 = new QFormLayout();
    qform_layout_1->setContentsMargins(0, 0, 0, 0);
    qform_layout_1->setSpacing(0);
    QHBoxLayout *first_hbox_layout = sca_prop.CreateQHBoxLayout("a *", "b *", "c *", "d *", "e *", 98, 38, "QLabel { background-color: rgb(255, 255, 255); "
                                                                "color: rgb(84, 40, 72); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                "font: 28px 'Lato-Bold'; }");
    qform_layout_1->addRow(first_hbox_layout);
    QHBoxLayout *second_hbox_layout = sca_prop.CreateQHBoxLayout(QString::number(sensor_data.a_value, 'f', 2), QString::number(sensor_data.b_value, 'f', 2),
                                                                 QString::number(sensor_data.c_value, 'f', 2), QString::number(sensor_data.d_value, 'f', 2),
                                                                 QString::number(sensor_data.e_value, 'f', 2), 98, 38, "QLabel { background-color: rgba(255, 255, 255, 0%); "
                                                                 "color: rgb(255, 255, 255); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                 "font: 28px 'Lato-Bold'; }");
    qform_layout_1->addRow(second_hbox_layout);
    widget_1->setLayout(qform_layout_1);
    ui->scrollArea_2->setContentsMargins(0, 0, 0, 0);
    ui->scrollArea_2->setWidget(widget_1);

    QWidget *widget_2 = new QWidget();
    widget_2->setStyleSheet("background-color: rgb(84, 40, 72);");
    widget_2->setContentsMargins(0, 0, 0, 0);
    QFormLayout *qform_layout_2 = new QFormLayout();
    qform_layout_2->setContentsMargins(0, 0, 0, 0);
    qform_layout_2->setSpacing(0);
    QHBoxLayout *third_hbox_layout = sca_prop.CreateQHBoxLayout("f *", "g *", "h *", "i *", "j *", 98, 38, "QLabel { background-color: rgb(255, 255, 255); "
                                                                "color: rgb(84, 40, 72); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                "font: 28px 'Lato-Bold'; }");
    qform_layout_2->addRow(third_hbox_layout);
    QHBoxLayout *fourth_hbox_layout = sca_prop.CreateQHBoxLayout(QString::number(sensor_data.f_value, 'f', 2), QString::number(sensor_data.g_value, 'f', 2),
                                                                 QString::number(sensor_data.h_value, 'f', 2), QString::number(sensor_data.i_value, 'f', 2),
                                                                 QString::number(sensor_data.j_value, 'f', 2), 98, 38, "QLabel { background-color: rgba(255, 255, 255, 0%); "
                                                                 "color: rgb(255, 255, 255); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                 "font: 28px 'Lato-Bold'; }");
    qform_layout_2->addRow(fourth_hbox_layout);
    widget_2->setLayout(qform_layout_2);
    ui->scrollArea_3->setContentsMargins(0, 0, 0, 0);
    ui->scrollArea_3->setWidget(widget_2);

    QWidget *widget_3 = new QWidget();
    widget_3->setStyleSheet("background-color: rgb(84, 40, 72);");
    widget_3->setContentsMargins(0, 0, 0, 0);
    QFormLayout *qform_layout_3 = new QFormLayout();
    qform_layout_3->setContentsMargins(0, 0, 0, 0);
    qform_layout_3->setSpacing(0);
    QHBoxLayout *fifth_hbox_layout = sca_prop.CreateQHBoxLayout("k *", "l *", "m *", 98, 38, "QLabel { background-color: rgb(255, 255, 255); "
                                                                "color: rgb(84, 40, 72); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                "font: 25px 'Lato-Bold'; }");
    qform_layout_3->addRow(fifth_hbox_layout);
    QHBoxLayout *sixth_hbox_layout = sca_prop.CreateQHBoxLayout(QString::number(sensor_data.k_value, 'f', 2), QString::number(sensor_data.l_value, 'f', 2),
                                                                QString::number(sensor_data.m_value, 'f', 2), 98, 38, "QLabel { background-color: rgba(255, 255, 255, 0%); "
                                                                                "color: rgb(255, 255, 255); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                                "font: 28px 'Lato-Bold'; }");
    qform_layout_3->addRow(sixth_hbox_layout);
    widget_3->setLayout(qform_layout_3);
    ui->scrollArea_4->setContentsMargins(0, 0, 0, 0);
    ui->scrollArea_4->setWidget(widget_3);

    QWidget *widget_4 = new QWidget();
    widget_4->setStyleSheet("background-color: rgb(84, 40, 72);");
    widget_4->setContentsMargins(0, 0, 0, 0);
    QFormLayout *qform_layout_4 = new QFormLayout();
    qform_layout_4->setContentsMargins(0, 0, 0, 0);
    qform_layout_4->setSpacing(0);
    QHBoxLayout *seventh_hbox_layout = sca_prop.CreateQHBoxLayout(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"), 195, 38,
                                                                  "QLabel { background-color: rgb(255, 255, 255); color: rgb(84, 40, 72); "
                                                                  "qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                  "font: 18px 'Lato-Bold'; }");
    qform_layout_4->addRow(seventh_hbox_layout);
    QHBoxLayout *eigthth_hbox_layout = sca_prop.CreateQHBoxLayout(sensor_data.text, 195, 38, "QLabel { background-color: rgba(255, 255, 255, 0%); "
                                                                  "color: rgb(255, 255, 255); qproperty-alignment: AlignCenter; border: 1px solid white; "
                                                                  "font: 20px 'Lato-Bold'; }");
    qform_layout_4->addRow(eigthth_hbox_layout);
    widget_4->setLayout(qform_layout_4);
    ui->scrollArea_5->setContentsMargins(0, 0, 0, 0);
    ui->scrollArea_5->setWidget(widget_4);
}

double MainWindow::RandomNumber()
{
    double random = static_cast<double>(rand()) / RAND_MAX * 10.0;

    return random;
}
