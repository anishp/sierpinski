#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPointF p1 = QPointF(320.0f, 50.0f);
    qreal size = 400.0f;
    sierpinski(10, p1, size);
}

void Dialog::drawTriangle(QPointF p1, qreal size)
{
    qreal height = size * qSqrt(3)/2.0f;

    QPointF p2 = QPointF(p1.x()-size/2.0f, p1.y()+height);
    QPointF p3 = QPointF(p1.x()+size/2.0f, p1.y()+height);

    QPainter myPainter(this);

    myPainter.drawLine(p1, p2);
    myPainter.drawLine(p1, p3);
    myPainter.drawLine(p2, p3);
}

void Dialog::sierpinski(int level, QPointF p1, qreal size)
{

    if(level==1)
        drawTriangle(p1, size);

    else
    {
        drawTriangle(p1, size);


        qreal height = size * qSqrt(3)/4.0f;

        QPointF p2 = QPointF((p1.x() - size/4), height+p1.y());
        QPointF p3 = QPointF((p1.x() + size/4), height+p1.y());

        //drawTriangle(p1, UP, size/2.0f);
        sierpinski(level-1, p1, size/2);

        //drawTriangle(p2, UP, size/2.0f);
        sierpinski(level-1, p2, size/2);

        //drawTriangle(p3, UP, size/2.0f);
        sierpinski(level-1, p3, size/2);
    }
}
