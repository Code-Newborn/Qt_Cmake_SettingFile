#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);

    // 恢复上次关闭软件时的窗口大小

    QFile file("config.ini");
    QSettings settings("config.ini", QSettings::IniFormat);
    if (file.exists())
    {
        settings.beginGroup("mainwindow");
        resize(settings.value("size").toSize());      // 恢复到上次关闭的窗口大小
        move(settings.value("pos", pos()).toPoint()); // 移动到上次关闭的位置
        settings.endGroup();

        settings.beginGroup("UI");
        auto test = settings.value("databits");
        ui->baudrateComboBox->setCurrentText(settings.value("baudrate").toString());
        ui->databitsComboBox->setCurrentIndex(settings.value("databits").toInt());
        ui->stopbitsComboBox->setCurrentIndex(settings.value("stopbits").toInt());
        ui->parityComboBox->setCurrentIndex(settings.value("parity").toInt());
        settings.endGroup();
    }
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QSettings settings("config.ini", QSettings::IniFormat);

    settings.beginGroup("UI");
    settings.setValue("baudrate", ui->baudrateComboBox->currentText());
    settings.setValue("databits", ui->databitsComboBox->currentIndex());
    settings.setValue("stopbits", ui->stopbitsComboBox->currentIndex());
    settings.setValue("parity", ui->parityComboBox->currentIndex());
    settings.endGroup();

    // 记录软件关闭前的窗口大小和位置

    settings.beginGroup("mainwindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();

    QWidget::closeEvent(e);
}
