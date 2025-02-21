#ifndef MAIN_CONTROL_H
#define MAIN_CONTROL_H

#include <QThread>
#include <QMutex>
#include <QDateTime>

class MainControl : public QThread
{
    Q_OBJECT

public:
    explicit MainControl(QObject *parent = 0, bool b = false);
    ~MainControl();

    void run();
    bool Stop;

signals:
    void atMainControl(QString time);
};

#endif // MAIN_CONTROL_H
