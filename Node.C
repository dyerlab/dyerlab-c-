#include "Node.H"

#include <QPen>
#include <QBrush>

Node::Node(QString label, double size, QGraphicsItem *parent) :
    QGrahicsItem(parent)
{
    m_label = label;
    m_size = size;
    m_color = Qt::darkRed;
    setZValue(3);
    setPos( QPointF( qrand() % 800, qrand() % 800 ));

    setFlag( QGraphicsItem::ItemIsMovable, true );
    setFlag( QGraphicsItem::ItemIsSelectable, true );
    setFlag( QGraphicsItem::ItemSendsGeometryChanges, true);

}


QRectF Node::boundingRect() const {
    return QRectF( -m_size/2, -m_size/2, m_size, m_size);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED( option );
    Q_UNUSED( widget );
    QPen pen(Qt::black );
    QBrush brush(m_color);

    painter->setPen( pen );
    painter->setBrush( brush );
    painter->drawEllipse( -m_size/2, -m_size/2, m_size, m_size );
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value) {
    switch( change ) {
    case ItemPositionChange:
        foreach( Edget *e, edges )
            e->adjust();
        break;
    default:
        break;
    }
    return QGraphicsItem::itemChange(change, value );
}

QPainterPath Node::shape() const {
    QPainterPath path;
    path.addEllipse( boundingRect() );
    return path;
}
