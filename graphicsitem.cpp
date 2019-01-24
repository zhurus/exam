#include "graphicsitem.h"
#include <QFontMetricsF>
#include <QPainter>

GraphicsItem::GraphicsItem(QString word,QPointF position)
{
    QFontMetricsF fm(QFont("Times New Roman",12));
    m_width = fm.boundingRect(word).width()+7;
    m_height = fm.boundingRect(word).height()+4;

    m_word = word;

    setPos(position);
    setFlag(QGraphicsItem::ItemIsMovable);
}

double GraphicsItem::x() const
{
    return m_x;
}

double GraphicsItem::y() const
{
    return m_y;
}

double GraphicsItem::width() const
{
    return m_width;
}

double GraphicsItem::height() const
{
    return m_height;
}

QRectF GraphicsItem::boundingRect() const
{
    return QRectF(0,0,m_width,m_height);
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    painter->setBrush(QBrush(QColor(200,200,200)));
    painter->drawRect(QRectF(0,0,m_width,m_height));
    painter->setFont(QFont("Times New Roman",12));
    painter->drawText(QPointF(2,m_height-5),m_word);

    Q_UNUSED(options);
    Q_UNUSED(widget);
}
