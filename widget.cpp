#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(10,10,300,200);
    connect(ui->button,SIGNAL(clicked()),
        this,SLOT(buttonHandler()));

    ui->view->setScene(m_scene);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonHandler()
{
    m_scene->clear();

    m_text = ui->textEdit->toPlainText();

    m_words = m_text.split(QRegExp("[\x0020+\t+\r+\n+]"));

    QFontMetricsF fm(QFont("Times New Roman",12));
    double x = 0;
    double y = 0;

    for(int i = 0;i<m_words.length();++i)
    {
        if(m_words[i]!="")
        {
            if(x + fm.boundingRect(m_words[i]).width() >
                m_scene->width())
            {
                y += fm.boundingRect(m_words[i]).height()+7;
                x = 0;
            }

            m_scene->addItem(
                new GraphicsItem(m_words[i],QPointF(x,y)));

            x += fm.boundingRect(m_words[i]).width() + 10;
        }
    }
}
