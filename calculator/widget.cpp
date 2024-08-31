#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(193,292);
    this->setMinimumSize(193,292);

    this->setWindowTitle("计算机");

    // 修改字体
    QFont f(" 仿宋",10);
    ui->result->setFont(f);

    // 添加图片
    QIcon con("C:\\Users\\lenovo\\Desktop\\Qt\\calculator\\back.png");
    ui->delbtn->setIcon(con);

    // 修改背景颜色
    ui->dengyubtn->setStyleSheet("background:blue");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_onebtn_clicked()
{
    expression+="1";
    ui->result->setText(expression);
}

void Widget::on_twobtn_clicked()
{
    expression+="2";
    ui->result->setText(expression);
}

void Widget::on_threebtn_clicked()
{
    expression+="3";
    ui->result->setText(expression);
}


void Widget::on_leftbtn_clicked()
{
    expression+="(";
    ui->result->setText(expression);
}

void Widget::on_zerobtn_clicked()
{
    expression+="0";
    ui->result->setText(expression);
}

void Widget::on_rightbtn_clicked()
{
    expression+=")";
    ui->result->setText(expression);
}

void Widget::on_fourbtn_clicked()
{
    expression+="4";
    ui->result->setText(expression);
}

void Widget::on_fivebtn_clicked()
{
    expression+="5";
    ui->result->setText(expression);
}

void Widget::on_sixbtn_clicked()
{
    expression+="6";
    ui->result->setText(expression);
}

void Widget::on_chubtn_clicked()
{
    expression+="/";
    ui->result->setText(expression);
}

void Widget::on_chengbtn_clicked()
{
    expression+="*";
    ui->result->setText(expression);
}

void Widget::on_ninebtn_clicked()
{
    expression+="9";
    ui->result->setText(expression);
}

void Widget::on_eightbtn_clicked()
{
    expression+="8";
    ui->result->setText(expression);
}

void Widget::on_sevenbtn_clicked()
{
    expression+="7";
    ui->result->setText(expression);
}

void Widget::on_plusbtn_clicked()
{
    expression+="+";
    ui->result->setText(expression);
}

void Widget::on_losebtn_clicked()
{
    expression+="-";
    ui->result->setText(expression);
}

void Widget::on_clearbtn_clicked()
{
    expression.clear();
    ui->result->clear();
}

void Widget::on_delbtn_clicked()
{
    expression.chop(1);
    ui->result->setText(expression);
}

void Widget::on_dengyubtn_clicked()
{
    QStack<int> s_opt,s_num;

    char opt[128]={0};
    int i=0,temp=0,num1,num2;

    QByteArray ba;
    ba.append(expression);
    strcpy(opt,ba.data());

    while(opt[i]!='\0' || s_opt.empty()!=true){
        if(opt[i]>='\0' && opt[i]<='9')
        {
            temp = temp*10+opt[i]-'0';
            i++;
            if(opt[i]<'0'||opt[i]>'9'){
                s_num.push(temp);
                temp = 0;
            }
        }
        else{
            if(s_opt.empty() == true ||Priority(opt[i])>Priority(s_opt.top()) ||
                    (s_opt.top()=='('&&opt[i]!=')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }

            if(s_opt.top() == '(' && opt[i]==')')
            {
                s_opt.pop();
                i++;
                continue;
            }

            if(Priority(opt[i])<=Priority(s_opt.pop())||
               (opt[i]==')'&&s_opt.top() !='(')||
                    (opt[i]=='\0'&&s_opt.empty()!=true))
            {
                char ch=s_opt.top();
                s_opt.pop();
                switch (ch) {
                    case '+':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1+num2);
                    break;
                    case '-':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2-num1);
                    break;
                    case '*':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1*num2);
                    break;
                    case '/':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2/num1);
                    break;
                }
            }
        }
    }
    ui->result->setText(QString::number(s_num.top()));
    expression.clear();
}

int Widget::Priority(char ch){
    switch (ch) {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
