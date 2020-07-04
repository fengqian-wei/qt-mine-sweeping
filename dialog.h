#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
class Dialog;
#include <mainwindow.h>
extern   void   createinterface();
extern int ROW,COL,BOOMNUM;


class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QLabel *label1,*label2,*label3;
    QLineEdit * lineEdit1,*lineEdit2,*lineEdit3;
    QPushButton *button;
private slots:
    void getRowCol();
};


#endif // DIALOG_H
