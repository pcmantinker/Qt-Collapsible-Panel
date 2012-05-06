#include "extendedqlabel.h"

ExtendedQLabel::ExtendedQLabel(const QString& text, QWidget * parent):
    QLabel(parent)

{
    this->setText(text);
}

ExtendedQLabel::~ExtendedQLabel()
{

}

void ExtendedQLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked();
}

void ExtendedQLabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit hover();
}
