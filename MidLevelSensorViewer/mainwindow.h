#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "maincontrol.h"
#include "advsettingsdialog.h"
#include "infodialog.h"
#include "loadingdialog.h"
#include "yesnodialog.h"
#include "sensordata.h"
#include "scrollareaproperties.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
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
    void on_pushButton_8_clicked();

private:
    void Initialize();
    void ButtonsStatus(bool standard_state, bool comparison_state, bool test_state, bool up_btn_state, bool down_btn_state,
                       bool clear_btn_state, bool settings_state);
    void SetDescriptionText(QString text);
    void ShowComparison(SensorData sensor_data);
    void ShowTest(SensorData sensor_data);
    double RandomNumber();

    Ui::MainWindow *ui;
    MainControl *main_control;
    AdvSettingsDialog *adv_settings_dialog;
    LoadingDialog *loading_dialog;
    YesNoDialog *yes_no_dialog;
    InfoDialog *info_dialog;

    std::vector<SensorData> test_sensor_data;
    uint test_index;
    uint main_control_count;
};

#endif // MAINWINDOW_H
