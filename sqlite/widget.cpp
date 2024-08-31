#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("localhost");
    db.setDatabaseName("user");
    db.setUserName("root");
    db.setPassword("root");
    if(db.open()){
        QMessageBox::information(this,"打开成功","连接成功");

        ui->table->hide();
        m = new QSqlTableModel;
        m->setTable("student");
        ui->table->setModel(m);
    }else{
        QMessageBox::warning(this,"warning","失败");
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_insert_clicked()
{
    QString name = ui->id->text();
    QString id = ui->name->text();
    QString classid = ui->classid->text();

    QString sql = QString("insert into student values ('%1',%2,%3)").arg(name).arg(id).arg(classid);

    QSqlQuery query;
    if(query.exec(sql)){
        QMessageBox::information(this,"ok","插入成功");
    }else{
        QMessageBox::warning(this,"warning","失败");
    }
}

void Widget::on_search_clicked()
{
    // 查询方法1
    /*QSqlQuery query;
    QString sql = QString("select * from student;");

    query.exec(sql);
    while(query.next()){
        qDebug() << query.value(0);
        qDebug() << query.value(1);
        qDebug() << query.value(2);
    }*/
    // 查询方法2
    ui->table->show();
    ui->id->hide();
    ui->name->hide();
    ui->classid->hide();
    m->select();
}
