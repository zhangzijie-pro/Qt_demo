#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    picID = 2;

    QPixmap pix("C:\\Users\\lenovo\\Desktop\\Qt\\test\\pic\\1.png");
    ui->picture->setPixmap(pix);

    /* QTimer
    timer = new QTimer;
    QImage img;
    img.load("C:\\Users\\lenovo\\Desktop\\Qt\\test\\pic\\1.png");
    ui->picture->setPixmap(QPixmap::fromImage(img));

    connect(timer,&QTimer::timeout,this,&Widget::timeoutslot);*/
}

Widget::~Widget()
{
    delete ui;
}

// QObject  定时器

void Widget::on_startbtn_clicked()
{
    // 开启定时器,返回定时器编号
    myTimeId = this->startTimer(TIMEOUT);
    //timer->start(TIMEOUT);
}


void Widget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() != myTimeId)
    {
        return;
    }

    QString path("C:\\Users\\lenovo\\Desktop\\Qt\\test\\pic\\");
    path+=QString::number(picID);
    path+=".png";

    QPixmap pix(path);
    ui->picture->setPixmap(pix);

    /*
    QImage img;
    img.load(path);
    ui->picture->setPixmap(QPixmap::fromImage(img));
    */

    picID++;
    if(5==picID){
        picID=1;
    }

}

void Widget::on_stopbtn_clicked()
{
    this->killTimer(myTimeId);
}

void Widget::timeoutslot(){
    timer->stop();
}

void Widget::on_Singlebtn_clicked()
{
    timer->singleShot(1000,this,SLOT(timeoutslot));
}
