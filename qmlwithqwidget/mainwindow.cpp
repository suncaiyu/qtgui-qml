#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickWidget>
#include <QQuickView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*

      If you are using a recent version of Qt, QWidget::createWindoContainer is depricated.
    Create a QQuickWidget instead, and use it a a normal QWidget.


//    */
//        QQuickWidget *pWidget = new QQuickWidget();
//        pWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
//        pWidget->setSource(QUrl("qrc:/ui/qml.qml"));

    QQuickWidget *m_quickWidget=new QQuickWidget();
    QUrl source("qrc:/ui/dynamic.qml");

    m_quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView );
    m_quickWidget->setSource(source);

    ui->dynamicQmlEmber->addWidget(m_quickWidget);

//    QQuickWidget *view = new QQuickWidget;
//    view->setSource(QUrl("qrc:/ui/test.qml"));
//    view->show();

    //这个方式被弃用了
//     QQuickView *pView = new QQuickView();
//        QWidget *pWidget = QWidget::createWindowContainer(pView, this);
//        pView->setResizeMode(QQuickView::SizeRootObjectToView);
//        pView->setSource(QUrl("qrc:/ui/test.qml"));



//    m_quickWidget->setParent( );

}

MainWindow::~MainWindow()
{
    delete ui;
}
