#include "maincontrol.h"

MainControl::MainControl(QObject * parent, bool b) : QThread(parent), Stop(b)
{

}

MainControl::~MainControl()
{

}

void MainControl::run()
{
    for (;;) {
       QMutex mutex;
       mutex.lock();

       if (this->Stop)
           break;

       QDateTime currentDateTime = QDateTime::currentDateTime();
       emit atMainControl(currentDateTime.toString("yyyy-MM-dd HH:mm:ss"));
       this->sleep(1);

       mutex.unlock();
    }
}
