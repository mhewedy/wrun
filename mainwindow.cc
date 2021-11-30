/**
 *  Auther : Mohammed Hewedy 
 *  Email  : mohammed_a_hewedy@hotmail.com
 *  Date   : 21 October 2010
 *  Lincence: Waqf Public Licence
 */

#include <QApplication>
#include <QDesktopWidget>
#include <QProcess>
#include <QCloseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadData();
    position();
    setupTryIcon();
    setTextCompleter();
    registerSignalsAndSlots();
}

void MainWindow::position()
{
    QDesktopWidget *dwid = QApplication::desktop();
    this->setGeometry(dwid->screenGeometry().width()/2.0 - this->geometry().width()/4.0 , 20, 0, 0);
    delete dwid;
    
}

void MainWindow::setupTryIcon()
{
    ui->setupUi(this);
    tIcon.setIcon(QIcon(":/rc/WRun.bmp"));
    tIcon.show();    
}

void MainWindow::loadData()
{
    this->exeFinder.loadExes();
}

void MainWindow::setTextCompleter()
{
    try
    {
        QStringList wordList = exeFinder.getStringListOfExeNames();
        completer = new QCompleter(wordList);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setMaxVisibleItems(10);
        this->ui->lineEdit->setCompleter(completer);   
    }catch(...)
    {
        
    }
}
void MainWindow::registerSignalsAndSlots()
{
    connect(&tIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), 
            this, SLOT(tryIconActivated(QSystemTrayIcon::ActivationReason)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete completer;
}

void MainWindow::tryIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    this->showNormal();
    this->activateWindow();
}

// TODO : show complete list as small-case & allow execute commands case-instensively...
void MainWindow::on_lineEdit_returnPressed()
{
    QString exe = ui->lineEdit->text();
    QString path = exeFinder.getExePath(exe);
    if (path != NULL && path.length() > 0)
    {
        path.append("/").append(exe).append(".exe");
        QProcess::startDetached("\"" + path + "\"");
        ExeFinder::logExecution(path);
        this->ui->lineEdit->clear();
        this->hide();
        
    }else
    {
        QString msg(exe + " not found!");
        QString title("WRun");
        this->tIcon.showMessage(title, msg);
    }
    
}
void MainWindow::closeEvent(QCloseEvent *evt)
{
    //evt->ignore();
    //this->hide();
}
