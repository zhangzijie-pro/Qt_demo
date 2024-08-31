#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *k);       // 键盘事件
    void mousePressEvent(QMouseEvent *m);   // 鼠标事件

private slots:
    void NewActionSlot();
    void OpenActionSlot();
    void SaveActionSlot();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
