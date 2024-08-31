#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
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
    void on_onebtn_clicked();

    void on_twobtn_clicked();

    void on_threebtn_clicked();

    void on_leftbtn_clicked();

    void on_zerobtn_clicked();

    void on_rightbtn_clicked();

    void on_fourbtn_clicked();

    void on_fivebtn_clicked();

    void on_sixbtn_clicked();

    void on_chubtn_clicked();

    void on_chengbtn_clicked();

    void on_ninebtn_clicked();

    void on_eightbtn_clicked();

    void on_sevenbtn_clicked();

    void on_plusbtn_clicked();

    void on_losebtn_clicked();

    void on_clearbtn_clicked();

    void on_delbtn_clicked();

    void on_dengyubtn_clicked();

private:
    Ui::Widget *ui;
    QString expression;
    int Priority(char ch);
};

#endif // WIDGET_H
