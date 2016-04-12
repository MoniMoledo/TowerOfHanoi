
#include "pole.h"
#include "disk.h"
#include <QWidget>
#include <QPainter>
pole::pole(int index, int nDisks, QWidget * parent)
{

     this->index = index;
     this->nDisks = nDisks;

     this->setParent(parent);

     for(int i=0;i<nDisks;i++){
        disk* d = new disk(nDisks - i,this,i, parent);
        stack[i] = d;
    }
     setEnabled(true);
     show();
     raise();

}


int pole::getIndex(){
    return index;
}

void pole::paintEvent(QPaintEvent *event){

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QColor poleColor(207, 162, 95);
    QColor edgePoleColor(0, 0, 0);
    p.setPen(edgePoleColor);
    p.setBrush(poleColor);
    p.drawRoundedRect(120,90,20,260-(nDisks*23),10,8);
    raise();

}


disk* pole::take(){
  disk *d = NULL;
    if(nDisks>0){
      d = stack[--nDisks];
      stack[nDisks]=NULL;
      d->Lift();
}
return d;

}

bool pole::put(disk* d){
    if(nDisks == 0){
        stack[0] = d;
        nDisks++;
        d->setPolePos(this,0);
        raise();
        return true;
    }else{
        if(stack[nDisks-1]->Size() < d->Size()){
            return false;
        }else{
            stack[nDisks] = d;
            nDisks++;
            d->setPolePos(this,nDisks-1);
            raise();
            return true;
        }
    }

}

pole::~pole(){
    setParent(NULL);
    for (int i=0;i<nDisks;i++){
        delete stack[i];
    }
}
