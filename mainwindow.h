#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief  MainWindow       构造函数
     * @param  parent           父窗口指针
     */
    MainWindow( QWidget* parent = nullptr );

    /**
     * @brief  ~MainWindow      析构函数
     */
    ~MainWindow();

    /**
     * @brief  showEvent       重写显示事件
     * @param  e               显示事件
     */
    void showEvent( QShowEvent* e );

    /**
     * @brief  closeEvent      重写关闭事件
     * @param  e               关闭事件
     */
    void closeEvent( QCloseEvent* e );

private:
    Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
