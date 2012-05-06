#ifndef EXTENDEDQLABEL_H
#define EXTENDEDQLABEL_H

#include <QLabel>
#include <QtCore/QDebug>

class ExtendedQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ExtendedQLabel( const QString& text ="", QWidget * parent = 0 );
    ~ExtendedQLabel();

signals:
    void clicked();
    void hover();

protected:
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // EXTENDEDQLABEL_H
