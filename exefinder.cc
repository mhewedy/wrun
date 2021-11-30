
/**
 *  Auther : Mohammed Hewedy 
 *  Email  : mohammed_a_hewedy@hotmail.com
 *  Date   : 21 October 2010
 *  Lincence: Waqf Public Licence
 */

#include "exefinder.h"
#include <cstdlib>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QMapIterator>


void ExeFinder::loadExes()
{
    QString progFilesPath = getenv("ProgramFiles");
    QString winPath = getenv("windir");
    
    // start initalizing the map with key,value pairs (program name,full path)
    //putExe(progFilesPath);
    //putExe(winPath);
    
    thProgFiles = new ExeLoaderThread(this, progFilesPath);
    thProgFiles->start();
    thWin= new ExeLoaderThread(this, winPath);
    thWin->start();
}

ExeFinder::~ExeFinder()
{
    delete thProgFiles;
    delete thWin;
}

void ExeFinder::putExe(QString &_dir)
{
    QDir dir(_dir);
    dir.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Executable);
    dir.setSorting(QDir::Name);
    
    QFileInfoList list = dir.entryInfoList();
    
    for (int i = 0; i < list.size(); ++i) 
    {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.isExecutable() && fileInfo.isFile())
        {
            QString fileName = fileInfo.fileName();
            fileName = fileName.left(fileName.indexOf(".exe", 0, Qt::CaseInsensitive));
            exeMap[fileName] = dir.path();
        }else
        {
            QString dirName (fileInfo.fileName());
            QString finalDir(_dir);
            finalDir.append('\\');
            finalDir.append(dirName);
            putExe(finalDir);
        }
    }
}

QString ExeFinder::getExePath(QString &exe)
{
    return this->exeMap[exe];
}

// some utility logging function ...
void ExeFinder::logExecution(QString &line)
{
    QFile file(QString(logFileName));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;
    QTextStream stream(&file);
    QString format("dd.MM.yyyy");
    char* currDate = const_cast<char*>(QDate::currentDate().toString(format).toStdString().data());
    stream << currDate << " : " 
            << line.toStdString().data() << endl;
    file.close();
}

/**
 * Used by the QCompleter component
 */
QStringList ExeFinder::getStringListOfExeNames()
{
     QMapIterator<QString, QString> iter (exeMap);
     while (iter.hasNext())
     {
         iter.next();
         QString keyStr = iter.key();
         stringList.append(keyStr);
     }
     return stringList;
}
