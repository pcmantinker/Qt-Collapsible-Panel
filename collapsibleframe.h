#ifndef COLLAPSIBLEFRAME_H
#define COLLAPSIBLEFRAME_H
#include <QtGui>
#include "extendedqlabel.h"
#include "extendedqlabel.h"

class CollapsibleFrame : public QWidget
{
    Q_OBJECT
private:
    QWidget* m_headerArea;
    QPixmap m_collapseIcon;
    QString m_headerText;
    QWidget* m_widgetArea;
    ExtendedQLabel* icon;
    QLabel* headerTextLabel;
    QVBoxLayout* widgetLayout;
    int m_frameState;
    void determineIcon();

public:
    CollapsibleFrame();
    ~CollapsibleFrame();
    CollapsibleFrame(QString headerText);
    void addWidget(QWidget *widget);
    void addLayout(QLayout *layout);
    enum { OPEN, CLOSED };

private slots:
    void changeState();
};

#endif // COLLAPSIBLEFRAME_H
