#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QRectF>
#include <QColor>
#include <QPainter>
#include <QGraphicsItem>

class Edge;

class Node : QGraphicsItem {
public:
    Node(QString label = QString("Node"), double size=5.0, QGraphicsItem *parent=0);

    inline void addEdge(Edge *e)    { m_edges.append( e ); }
    inline Edge* getEdge( int idx)  { return m_edges.at(idx); }
    inline int degree()             { return m_edges.count(); }


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QPainterPath shape() const;

private:
    QString m_label;
    QColor m_color;
    double m_size;

    QList<Edge*> m_edges;


};

#endif // NODE_H
