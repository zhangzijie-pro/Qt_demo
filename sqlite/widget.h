#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


    void on_insert_clicked();

    void on_search_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QSqlTableModel *m;
};

#endif // WIDGET_H
