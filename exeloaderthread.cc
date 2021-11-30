#include "exeloaderthread.h"
#include <exefinder.h>

void ExeLoaderThread::run()
{
    setPriority(HighestPriority);
    ExeFinder *afinder = static_cast<ExeFinder*>(finder);
    afinder->putExe(this->path);
    exec();
}

ExeLoaderThread::ExeLoaderThread(void *finder, QString path){
    this->finder = finder;
    this->path = path;
}
