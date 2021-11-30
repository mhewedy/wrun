/**
 *  Auther : Mohammed Hewedy 
 *  Email  : mohammed_a_hewedy@hotmail.com
 *  Date   : 21 October 2010
 *  Lincence: Waqf Public Licence
 */

#ifndef EXEFINDER_H
#define EXEFINDER_H

#include <QMap>
#include <QString>
#include <QStringList>
#include <exeloaderthread.h>

#define logFileName "wrun.log"

class ExeFinder
{
private:
    QMap<QString, QString> exeMap;
    QStringList stringList;
    ExeLoaderThread *thProgFiles;
    ExeLoaderThread *thWin;
public:
    ~ExeFinder();
    void loadExes();
    void putExe(QString &_dir);
    QString getExePath(QString&);
    static void logExecution(QString&);
    QStringList getStringListOfExeNames();
};

#endif // EXEFINDER_H
