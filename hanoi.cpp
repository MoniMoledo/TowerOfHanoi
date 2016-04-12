#include "hanoi.h"
#include "ui_hanoi.h"
#include <QPainter>

disk*moving = NULL;
Hanoi::Hanoi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hanoi)
{
    ui->setupUi(this);
    value = 6;

    poles[0] = new pole(0, value,ui->pushButton_1);
    poles[1] = new pole(1, 0,ui->pushButton_2);
    poles[2] = new pole(2, 0,ui->pushButton_3);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(delayedAction()));
    autoplay=false;
}
void Hanoi::delayedAction(){
    if(autoplay){
        if(!schedule.empty()){
            Move autom = schedule.dequeue();
            moving = poles[autom.getFrom()]->take();
            poles[autom.getTo()]->put(moving);
            moving = NULL;
            history.push(autom);
        }else{
            autoplay = false;
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }

    }else{
        if(history.empty()){
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }else{
            on_action_Undo_triggered();
        }
    }
}
void Hanoi::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QColor baseColor(207, 165, 100);
    p.setBrush(baseColor);
    p.drawRect(60,355,180,80);
    p.drawRect(60,345,180,70);

    p.drawRect(310,355,180,80);
    p.drawRect(310,345,180,70);

    p.drawRect(560,355,180,80);
    p.drawRect(560,345,180,70);
}




Hanoi::~Hanoi()
{
    delete ui;
    for (int i=0;i<3;i++){

        delete poles[i];
    }
    moving = NULL;
    history.clear();
    schedule.clear();
}

void Hanoi::on_pushButton_clicked(pole* p){
    if(!moving){
        moving = p->take();
    }else{
        int from = moving->On()->getIndex();
        if(p->put(moving)){
            Move mov(from,p->getIndex());
            history.push(mov);
            moving = NULL;
        }else{
            moving->On()->put(moving);
            moving = NULL;
        }
    }
}


void Hanoi::CalculateAutoplay(int count, int from,  int dest, int aux){
    if(count <1){
        return;
    }else{
        CalculateAutoplay(count-1,from,aux,dest);
        schedule.enqueue(Move(from,dest));
        CalculateAutoplay(count-1,aux,dest,from);
    }

}

void Hanoi::on_pushButton_1_clicked()
{
    on_pushButton_clicked(poles[0]);

}

void Hanoi::on_pushButton_2_clicked()
{
   on_pushButton_clicked(poles[1]);
}

void Hanoi::on_pushButton_3_clicked()
{
     on_pushButton_clicked(poles[2]);
}

void Hanoi::on_action_New_triggered()
{

    for (int i=0;i<3;i++){

        delete poles[i];
    }
    if(moving){
        delete moving;
    }
    moving = NULL;
    history.clear();
    schedule.clear();

    poles[0] = new pole(0, value,ui->pushButton_1);
    poles[1] = new pole(1, 0,ui->pushButton_2);
    poles[2] = new pole(2, 0,ui->pushButton_3);

}

void Hanoi::on_action_Undo_triggered()
{
   if(!history.empty()){
    Move mUndo = history.pop();
    pole* to = NULL;
    pole* from = NULL;
    to = poles[mUndo.getTo()];
    from = poles[mUndo.getFrom()];
    if(moving){
        moving->On()->put(moving);
        moving = NULL;
    }
    moving = to->take();
    from->put(moving);
    moving = NULL;
}
}

void Hanoi::on_action_Undo_All_triggered()
{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    timer->start(100);
}

void Hanoi::on_actionAuto_Play_triggered()

{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    autoplay = true;
    on_action_New_triggered();
    CalculateAutoplay(poles[0]->getNdisks(), 0,2,1);
    timer->start(100);

}

void Hanoi::on_action_2_triggered()
{
    value = 2;
    ui->action_New->trigger();
}

void Hanoi::on_action_3_triggered()
{
    value = 3;
    ui->action_New->trigger();
}

void Hanoi::on_action_4_triggered()
{
    value = 4;
    ui->action_New->trigger();
}

void Hanoi::on_action_5_triggered()
{
    value = 5;
    ui->action_New->trigger();
}

void Hanoi::on_action_6_triggered()
{
    value = 6;
    ui->action_New->trigger();
}

void Hanoi::on_action_7_triggered()
{
    value = 7;
    ui->action_New->trigger();
}

void Hanoi::on_action_8_triggered()
{
    value = 8;
    ui->action_New->trigger();
}
