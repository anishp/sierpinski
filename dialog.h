#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QPointF>
#include <qmath.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

protected:
    void paintEvent(QPaintEvent *);
    void drawTriangle(QPointF p1, int orientation, float size);
};

#endif // DIALOG_H
