
#ifndef DISK_H
#define DISK_H
#include<QWidget>
class pole;
class disk: public QWidget
{
private:

    int size;
    pole* on;
    int Size(){return size;}
    int pos; // index on pole, zero bottom;

public:
      //extern float scale;
      void setPolePos(pole*d, int p);
      void Lift();
      void paintEvent(QPaintEvent * event);
      disk(int size, pole* on,int pos, QWidget*);
      pole* On(){return on;}
      friend class pole;
     //~disk();

};

#endif // DISK_H

