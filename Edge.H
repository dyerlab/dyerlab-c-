#ifndef EDGE_H
#define EDGE_H

#include <QRectF>
#include <QGraphicsItem>

class Node;

class Edge : public QGraphicsItem
{
public:
    Edge(Node node1, Node node2, double weight=1.0, QGraphicsItem *parent=0);


    void adjust();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    Node *m_node1;
    Node *m_node2;
    double m_weight;

};

#endif // EDGE_H
