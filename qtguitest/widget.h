#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void receiveFromQml();

private:
    Ui::Widget *ui;
    QPushButton *m_pButton;
};

#endif // WIDGET_H
