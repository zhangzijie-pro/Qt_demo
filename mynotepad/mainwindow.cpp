#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->NewAction,&QAction::triggered,this,&MainWindow::NewActionSlot);
    connect(ui->OpenAction,&QAction::triggered,this,&MainWindow::OpenActionSlot);
    connect(ui->OpenAction,&QAction::triggered,this,&MainWindow::SaveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NewActionSlot(){
    ui->textBrowser->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::OpenActionSlot(){
    QString filename = QFileDialog::getOpenFileName(this,"打开文件",QCoreApplication::applicationFilePath(),"*.cpp");
    if(filename.isEmpty())
    {
        QMessageBox::warning(this,"warning","没有选择打开文件");
    }else{
        qDebug() << filename;
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textBrowser->setText(QString(ba));
        file.close();
    }
}

void MainWindow::SaveActionSlot(){
    QString filename = QFileDialog::getSaveFileName(this,"保存文件",QCoreApplication::applicationFilePath());
    if(filename.isEmpty()){
        QMessageBox::warning(this,"warning","保存失败");
    }else {
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        QByteArray ba;
        ba.append(ui->textBrowser->toPlainText());
        file.write(ba,ba.length());
        file.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_S)
    {
        SaveActionSlot();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m)
{
    QPoint pt = m->pos();
    qDebug() << pt ;
    if(m->button() == Qt::LeftButton){
        qDebug() << "Left Button Pressed!";
    }else if(m->button() == Qt::RightButton){
        qDebug() << "Right Button Pressed!";
    }
}
