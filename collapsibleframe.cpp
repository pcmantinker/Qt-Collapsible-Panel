#include "collapsibleframe.h"

CollapsibleFrame::CollapsibleFrame()
{
    m_frameState = CLOSED;
    determineIcon();
    m_headerArea = new QWidget;
    m_widgetArea = new QWidget;
    icon = new ExtendedQLabel;
    icon->setPixmap(m_collapseIcon);
    connect(icon, SIGNAL(clicked()), this, SLOT(changeState()));
    QLabel* headerTextLabel = new QLabel;
    headerTextLabel->setText(m_headerText);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QVBoxLayout* widgetLayout = new QVBoxLayout;
    m_widgetArea->setLayout(widgetLayout);
    m_widgetArea->show();
    QHBoxLayout* headerLayout = new QHBoxLayout;
    headerLayout->addWidget(icon);
    headerLayout->addWidget(headerTextLabel);
    m_headerArea->setLayout(headerLayout);
    m_headerArea->show();
    mainLayout->addWidget(m_headerArea);
    //mainLayout->addLayout(headerLayout);
    mainLayout->addWidget(m_widgetArea);
    setLayout(mainLayout);
    show();
}

CollapsibleFrame::CollapsibleFrame(QString headerText)
{
    m_headerText = headerText;
    m_frameState = CLOSED;

    m_headerArea = new QWidget;
    m_widgetArea = new QWidget;
    icon = new ExtendedQLabel;
    icon->setMaximumSize(13, 13);
    icon->setPixmap(m_collapseIcon);
    connect(icon, SIGNAL(clicked()), this, SLOT(changeState()));
    headerTextLabel = new QLabel;
    headerTextLabel->setText(m_headerText);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    widgetLayout = new QVBoxLayout;
    ExtendedQLabel* test = new ExtendedQLabel;
    test->setText("Testing");
    test->setMaximumSize(50,30);
    widgetLayout->addWidget(test);
    m_widgetArea->setLayout(widgetLayout);
    QHBoxLayout* headerLayout = new QHBoxLayout;
    headerLayout->addWidget(icon);
    headerLayout->addWidget(headerTextLabel);
    m_headerArea->setLayout(headerLayout);
    m_headerArea->show();
    mainLayout->addWidget(m_headerArea);
    mainLayout->addWidget(m_widgetArea);
    setLayout(mainLayout);
    show();
    determineIcon();
}

CollapsibleFrame::~CollapsibleFrame()
{
    delete m_headerArea;
    delete m_widgetArea;
}

void CollapsibleFrame::determineIcon()
{
    if(m_frameState == OPEN)
    {
        icon->setStyleSheet("QLabel { image: url(:/open.png) no-repeat; } QLabel:hover { image: url(:/open_hover.png) no-repeat; }");
        icon->setToolTip("Close");
        m_widgetArea->show();
    }
    else
    {
        icon->setStyleSheet("QLabel { image: url(:/closed.png) no-repeat; } QLabel:hover { image: url(:/closed_hover.png) no-repeat; }");
        icon->setToolTip("Open");
        m_widgetArea->hide();
    }
}

void CollapsibleFrame::changeState()
{
    if(m_frameState == OPEN)
    {
        m_frameState = CLOSED;
        headerTextLabel->setText("Closed");
        m_widgetArea->hide();
    }
    else
    {
        m_frameState = OPEN;
        headerTextLabel->setText("Open");
        m_widgetArea->show();
    }
    determineIcon();
}

void CollapsibleFrame::addWidget(QWidget * widget)
{
    widgetLayout->addWidget(widget);
}

void CollapsibleFrame::addLayout(QLayout *layout)
{
    widgetLayout->addLayout(layout);
}

