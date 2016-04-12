
#ifndef POLE_H
#define POLE_H

#include <QWidget>
const int MAX_DISKS = 8;
class disk;
class pole : public QWidget
{
private:
    int index;
    int nDisks;
    disk* stack[MAX_DISKS];

public:
    pole(int,int, QWidget*);
    int getIndex();
    ~pole();
    disk* take(); //return the top disk on the pole, otherwise NULL
    bool put(disk* d);// false means size is wrong or pointer NULL. put the disk on the pole, true success.
    int getNdisks(){return nDisks;};
    void paintEvent(QPaintEvent *event);
};

#endif // POLE_H
