#ifndef EXELOADERTHREAD_H
#define EXELOADERTHREAD_H

#include <QThread>
#include <QString>

class ExeLoaderThread : public QThread
{
    QString path;
    void *finder;
public:
    ExeLoaderThread(void *finder, QString path);
    void run();
};

#endif // EXELOADERTHREAD_H
