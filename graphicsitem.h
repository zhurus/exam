#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>

class GraphicsItem: public QGraphicsItem
{
public:
    GraphicsItem(QString word, QPointF position);
    double x()const;
    double y()const;
    double width()const;
    double height()const;

private:
    QRectF boundingRect()const;
    void paint(QPainter* painter,
        const QStyleOptionGraphicsItem* options,QWidget* widget);
    QString m_word;
    double m_x;
    double m_y;
    double m_width;
    double m_height;
};

#endif // GRAPHICSITEM_H
