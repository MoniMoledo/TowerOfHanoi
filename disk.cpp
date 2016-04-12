#include "pole.h"
#include "disk.h"
#include <QPainter>

disk::disk(int size, pole* pole,int pos, QWidget* par)
{
  this->size = size;
  this->on = pole;
  this->pos = pos;
  this->setParent(par);
  show();


}
void disk::Lift(){
    pos=12;
    repaint();
}


void disk::setPolePos(pole*d, int p){

     if(On() != d){
       on = d;
       setParent(d->parentWidget());
       show();
     }
     pos = p;
     repaint();
}
void disk::paintEvent(QPaintEvent *event){

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QColor edgeDiskColor(0, 0, 0);
    p.setPen(edgeDiskColor);


    //x = pole.x + 10 - disk.width/2
    //y = pole.y + pole.height - disk.height -5 ---pole.y=160+260-25*pole->getNDisks()-5
    //width = size
    //height = 25
    int width = (size*3)+60;

    QColor colors[] = {QColor(0,0,255),QColor(255,0,0),QColor(255,255,0),  QColor(0,255,255), QColor(160,32,240), QColor(52, 76, 18), QColor(190,96,74), QColor(0,255,0) };
    QColor diskTop = colors[size-1];
    QColor diskShadow = diskTop.darker(200);
    p.setBrush(diskShadow);
    p.drawEllipse(QPointF(130,(100 + 260 - 5)-23*(pos+1)),width,25);

    p.setBrush(diskTop);
    p.drawEllipse(QPointF(130,(100 + 250 - 5)-23*(pos+1)),width,25);

    QColor baseColor(100,100,100);
    p.setBrush(edgeDiskColor);
    p.drawEllipse(QPointF(130,(100 + 250 - 5)-23*(pos+1)),width/4,8);

}

