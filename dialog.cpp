#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    label1 = new QLabel(this);
    label1->setText(tr("雷区行数"));
    label2 = new QLabel(this);
    label2->setText(tr("雷区列数"));
    label3 = new QLabel(this);
    label3->setText(tr("炸弹数量"));
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    lineEdit3 = new QLineEdit(this);
    button = new QPushButton(this);
    button->setText(tr("提交"));
    QGridLayout * mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(label3,2,0);
    mainLayout->addWidget(lineEdit1,0,1);
    mainLayout->addWidget(lineEdit2,1,1);
    mainLayout->addWidget(lineEdit3,2,1);
    mainLayout->addWidget(button,3,1);
    connect(button,SIGNAL(clicked()),this,SLOT(getRowCol()));
}

Dialog::~Dialog()
{
    
}
void Dialog::getRowCol()
{
  bool ok;
  QString str;
  str = lineEdit1->text();
  ROW = str.toInt(&ok);
  str = lineEdit2->text();
  COL = str.toInt(&ok);
  str = lineEdit3->text();
  BOOMNUM = str.toInt(&ok);
  if(ROW<9&&COL<9)
  {
    QMessageBox message(QMessageBox::NoIcon, "too low", "你还想设置的比初级还要简单？不改高点我就开枪了。");
    message.setIconPixmap(QPixmap("low.png"));
    message.exec();
  }
  else
  {
    createinterface();
    this->close();
  }


}
