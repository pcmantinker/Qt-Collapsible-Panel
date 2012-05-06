/*
   Copyright 2012 Cameron Tinker

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
    QObject* m_parent;

public:
    ~CollapsibleFrame();
    CollapsibleFrame(QObject *parent, QString headerText);
    void addWidget(QWidget *widget);
    void addLayout(QLayout *layout);
    enum { OPEN, CLOSED };

private slots:
    void changeState();
};

#endif // COLLAPSIBLEFRAME_H
