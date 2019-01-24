#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "graphicsitem.h"

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
    void buttonHandler();

private:
    Ui::Widget *ui;
    QString m_text;
    QStringList m_words;
    QGraphicsScene* m_scene;
};

#endif // WIDGET_H
