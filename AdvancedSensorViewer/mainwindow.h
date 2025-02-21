#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QDateTime>
#include <QLabel>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "maincontrol.h"
#include "infodialog.h"
#include "loadingdialog.h"
#include "yesnodialog.h"
#include "sensordata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onMainControl(QString time);
    void onClearTests();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    void Initialize();
    void FillToolboxs();
    void WriteComparisonLabels(SensorData comparison_data);
    void EmptyComparisonLabels();
    void WriteTestLabels(SensorData test_data, SensorData comparison_data);
    void EmptyTestLabels();
    void WriteTestDifferenceLabels(QLabel *label_1, QLabel *label_2, QLabel *label_3, QString low_color,
                                   QString high_color, double diff_value);
    void EmptyTestDifferenceLabels(QLabel *label_1, QLabel *label_2, QLabel *label_3);
    void ButtonsStatus(bool standard_state, bool comparison_state, bool test_state, bool up_btn_state,
                       bool down_btn_state,  bool clear_btn_state);
    double RandomNumber();

    Ui::MainWindow *ui;
    MainControl *main_control;
    InfoDialog *info_dialog;
    LoadingDialog *loading_dialog;
    YesNoDialog *yes_no_dialog;

    std::vector<SensorData> test_sensor_data;
    SensorData comparison_sensor_data;
    uint test_index;
    uint main_control_count;
};
#endif // MAINWINDOW_H
