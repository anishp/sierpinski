#include "dialog.h"
#include "ui_dialog.h"

#define UP 1
#define DOWN -1

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
    float size = 400.0f;

    drawTriangle(p1, UP, size);

}

void Dialog::drawTriangle(QPointF p1, int orientation, float size)
{
    float height = p1.y() + orientation * size * qSqrt(3)/2.0f;

    QPointF p2 = QPointF(p1.x()-size/2.0f, p1.y()+height);
    QPointF p3 = QPointF(p1.x()+size/2.0f, p1.y()+height);

    QPainter myPainter(this);

    myPainter.drawLine(p1, p2);
    myPainter.drawLine(p1, p3);
    myPainter.drawLine(p2, p3);
}
