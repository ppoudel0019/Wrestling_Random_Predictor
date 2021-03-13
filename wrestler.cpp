#include <iostream>
#include <random>
#include <ctime>
#include "wrestler.h"
///make 2 teams and have the best players go against each other in 1 tournament
using namespace std;

double bout(wr * w1, wr * w2, default_random_engine *gptr);

int main()
{

    default_random_engine * gptr;
    gptr=new default_random_engine(time(NULL));

///make 2 teams and have the best players go against each other in 1 tournament

    wr * Team1[15];

for (int i=0; i<1; i++)
    {
    for(int i=0; i<16; i++){Team1[i]=NULL;}

    wr * tptr1=NULL;
    int Num, T1;
    cout<<"How many wrestlers?"<<endl;
    cin>>Num;
    cout<<"generate arriving wrestlers"<<endl;
    for(int i=0; i<Num; i++)
    { ///make a wrestler and display
     tptr1 = new wr(i,1,gptr);
     tptr1->display();
     ///get the type of stuff being delivered
     T1 = tptr1->getwtClass();
     ///no one is there..park it
     if(Team1[T1]==NULL){Team1[T1] = tptr1;}
     ///if a wrestler is there and the new wrestler has higher priority
     else{if(Team1[T1]->getAbility()<tptr1->getAbility())
            {
                delete Team1[T1];
                Team1[T1]=tptr1;
            }
     }
    }

    cout<<"Team1 wrestlers"<<endl;
    ///display the team
    for(int i=0; i<15; i++)
    {   cout<<"Match class #"<<i + 1<<": ";
        if(Team1[i]!=NULL)Team1[i]->display();
        else{cout<<"currently empty"<<endl;}
    }
    }


wr * Team2[15];

for (int i=0; i<1; i++)
    {
    for(int i=0; i<16; i++){Team2[i]=NULL;}

    wr * tptr2=NULL;
    int Num, T2;
    cout<<"How many wrestlers?"<<endl;
    cin>>Num;
    cout<<"generate arriving wrestlers"<<endl;
    for(int i=0; i<Num; i++)
    {///make a wrestler and display
     tptr2 = new wr(i,2,gptr);
     tptr2->display();
     ///get the type of stuff being delivered
     T2 = tptr2->getwtClass();
     ///no one is there..park it
     if(Team2[T2]==NULL){Team2[T2] = tptr2;}
     ///if a wrestler is there and the new wrestler has higher priority
     else{if(Team2[T2]->getAbility()<tptr2->getAbility())
            {
                delete Team2[T2];
                Team2[T2]=tptr2;
            }
     }
    }

    cout<<"Team2 wrestlers"<<endl;
    ///display the team
    for(int i=0; i<15; i++)
    {   cout<<"Match class #"<<i + 1<<": ";
        if(Team2[i]!=NULL)Team2[i]->display();
        else{cout<<"currently empty"<<endl;}
    }
    }

cout<<"Wrestle!!!!"<<endl;


cout<<"*************************"<<endl;
    int teamS1=0;
    int teamS2=0;
    double diff=0;
    for(int i=0; i<14; i++)
    {
        diff=bout(Team1[i], Team2[i], gptr);
        cout<<"Diff = "<<diff<<endl;
        if(diff>0)
        {
            if(diff>17){teamS1=teamS1+6;}
            else if(diff>15){teamS1=teamS1+5;}
            else if(diff>8) {teamS1-teamS1+4;}
            else if(diff>1) {teamS1-teamS1+3;}
        }
        else
        {
            diff=abs(diff);
            if(diff>15){teamS2=teamS2+6;}
            else if(diff>15){teamS2=teamS2+5;}
            else if(diff>8) {teamS2-teamS2+4;}
            else if(diff>1) {teamS2-teamS2+3;}
        }
        }

    cout<<"Team 1's Scores: "<<teamS1<<endl;
    cout<<"Team 2's Scores: "<<teamS2<<endl;



    return 0;
}


double bout( wr * w1, wr * w2, default_random_engine * gptr)
{
    double s1;
    double s2;
    double diff=0;

    if((w1==NULL)&&(w2==NULL)){return 0;}
    else if((w1!=NULL)&&(w2==NULL)){return 16;}
    else if((w1==NULL&&w2!=NULL)){return -16;}
    else{
    double a1;
    a1 = w1->getAbility();
    double a2;
    a2 = w2->getAbility();

    normal_distribution<double> a1dist(a1, 15);
    normal_distribution<double> a2dist(a2, 15);

    s1 = a1dist(*gptr);
    s2 = a2dist(*gptr);
    w1->display();
    cout<<"  versus "<<endl;
    w2->display();
    diff=s1-s2;
    if(s1>s2){cout<<"team 1 victorious "<<s1<<" to "<<s2<<endl;}
    else if(s2>s1){cout<<"team 2 victorious "<<s2<<" to "<<s1<<endl;}

    return diff;
    }
}


