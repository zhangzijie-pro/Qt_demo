#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#define TIMEOUT 1000

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    virtual void timerEvent(QTimerEvent *event);
    ~Widget();

private slots:
    void on_startbtn_clicked();
    void timeoutslot();
    void on_stopbtn_clicked();

    void on_Singlebtn_clicked();

private:
    Ui::Widget *ui;
    int myTimeId;
    int picID;
    QTimer *timer;

};

#endif // WIDGET_H
