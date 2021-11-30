/**
 *  Auther : Mohammed Hewedy 
 *  Email  : mohammed_a_hewedy@hotmail.com
 *  Date   : 21 October 2010
 *  Lincence: Waqf Public Licence
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCompleter>
#include <exefinder.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:// fucntions:
    void position();
    void setupTryIcon();
    void setTextCompleter();
    void registerSignalsAndSlots();
    void loadData();
private:
    Ui::MainWindow *ui;
    ExeFinder exeFinder;
    QSystemTrayIcon tIcon;
    QCompleter *completer;
    void closeEvent(QCloseEvent *evt);
private slots:
    void on_lineEdit_returnPressed();
    void tryIconActivated(QSystemTrayIcon::ActivationReason);
};

#endif // MAINWINDOW_H
