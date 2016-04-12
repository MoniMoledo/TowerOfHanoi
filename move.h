#ifndef MOVE_H
#define MOVE_H

class Move
{
private:
    int from;
    int to;
public:

    Move(int f,int t);
    Move();
    int getFrom(){return from;}
    int getTo(){ return to;}
};

#endif // MOVE_H
