#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("rsz_mandobannereutrigger_zps371729a7.jpg");
    ui->picture->setPixmap(pix);
    this->setWindowTitle("2142 Launcher");
    loadSettings();


}

void MainWindow::loadSettings()
{
    QSettings setting("Mando75","2142CusLaunch");
    setting.beginGroup("MainWindow");
    QRect myrect = setting.value("position","100x200").toRect();
    setGeometry(myrect);
    QString fileloc = setting.value("loc","").toString();
    ui->lineEdit_3->setText(fileloc);
    bool wides = setting.value("wides","").toBool();
    ui->widescreenb->setChecked(wides);
    bool fulls = setting.value("fulls","").toBool();
    ui->fullscreenb->setChecked(fulls);
    QString widths = setting.value("width","").toString();
    ui->lineEdit->setText(widths);
    QString height = setting.value("height","").toString();
    ui->lineEdit_2->setText(height);
    setting.endGroup();
    qDebug() << "Loaded";
}

void MainWindow::saveSettings()
{
    QSettings setting("Mando75","2142CusLaunch");
    setting.beginGroup("MainWindow");
    setting.setValue("position", this->geometry());
    setting.setValue("loc",ui->lineEdit_3->text());
    setting.setValue("wides",ui->widescreenb->isChecked());
    setting.setValue("fulls", ui->fullscreenb->isChecked());
    setting.setValue("width",ui->lineEdit->text());
    setting.setValue("height", ui->lineEdit_2->text());

    setting.endGroup();
    qDebug()<<"Saved";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "Executable Files (*.exe)"
                );
    ui->lineEdit_3->setText(filename);
}

void MainWindow::on_pushButton_2_clicked()
{
    saveSettings();
    QStringList arg;
    arg.append(" +menu 1");
    qDebug() << "adding to arg";
    if(ui->fullscreenb->isChecked())
    {
        arg.append(" +fullscreen 1");
        qDebug() << "added fullscreen";
    }
    if(ui->widescreenb->isChecked())
    {
        arg.append(" +widescreen 1");
        qDebug() << "added widescreen";
    }

    arg.append(" +szx ");
    arg.append(ui->lineEdit->text());
    arg.append(" +szy ");
    arg.append(ui->lineEdit_2->text());
    QFile bat("launch.bat");
    bat.open(QIODevice::WriteOnly |
             QIODevice::Text);
    QTextStream out(&bat);
    out <<"@echo off\n" << "start " << '"' << '"' << " ";
    out << '"' << ui->lineEdit_3->text() << '"';
    for (int i = 0; i < arg.size(); i++)
    {
        out << arg[i];
    }
    bat.close();

    QProcess p;
    p.startDetached("launch.bat");
    p.waitForFinished();
    qDebug() << "Program finished";

}


void MainWindow::on_pushButton_3_clicked()
{
    exit(1);
}
