#include "widget.h"
#include "ui_widget.h"
#include <QQuickWidget>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QQuickWidget *m_quickWidget=new QQuickWidget();
    QUrl source("qrc:/main.qml");

    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView );
    m_quickWidget->setSource(source);
//    m_quickWidget->show();

    m_pButton = new QPushButton(this);
        m_pButton->setText("Qt Widgets...");

        QVBoxLayout *pLayout = new QVBoxLayout();
        pLayout->addWidget(m_quickWidget);
        pLayout->addWidget(m_pButton);
        pLayout->setSpacing(10);
        pLayout->setContentsMargins(10, 10, 10, 10);
        setLayout(pLayout);

        // QML 与 Qt Widgets 通信
        // QObject *pRoot = (QObject*)pView->rootObject();
        QObject *pRoot = (QObject*)m_quickWidget->rootObject();
        if (pRoot != NULL) {
            connect(pRoot, SIGNAL(qmlSignal()), this, SLOT(receiveFromQml()));
            connect(m_pButton, SIGNAL(clicked(bool)), pRoot, SIGNAL(cSignal()));
        }
    }

Widget::~Widget()
{
    delete ui;
}

void Widget::receiveFromQml()
{
    m_pButton->setText("Call the C++ slot");
}
