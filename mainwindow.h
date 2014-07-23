#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCore>
#include <QDebug>
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    void processError(QProcess::ProcessError err);
    void loadSettings();
    void saveSettings();

};

#endif // MAINWINDOW_H
