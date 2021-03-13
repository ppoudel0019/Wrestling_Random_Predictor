#define WRESTLERS_H_INCLUDED
#include <iostream>
#include <random>
#include <iostream>
#include <ctime>

using namespace std;
class wr
{
public:
    wr(){}
    ~wr(){}
    wr(int i, int t, default_random_engine * gptr)
    {
        Tid =t;
        id = i;
    //   wins= NULL;
    //   losses = NULL;
        normal_distribution<double> wtdist(147,22);
        normal_distribution<double> adist(100,15);

        wt=86;

        while((wt<87)||(wt>285))
        {
            wt = wtdist(*gptr);
        }
        if(wt<=99)wtClass=0;
        else if(wt<=106)wtClass=1;
        else if(wt<=113)wtClass=2;
        else if(wt<=120)wtClass=3;
        else if(wt<=126)wtClass=4;
        else if(wt<=132)wtClass=5;
        else if(wt<=138)wtClass=6;
        else if(wt<=145)wtClass=7;
        else if(wt<=152)wtClass=8;
        else if(wt<=160)wtClass=9;
        else if(wt<=170)wtClass=10;
        else if(wt<=182)wtClass=11;
        else if(wt<=195)wtClass=12;
        else if(wt<=220)wtClass=13;
        else if(wt<=285)wtClass=14;
     //   cout<<"wt: "<<wt<<endl;
        ability= adist(*gptr);
       // cout<<"ability: "<<ability<<endl;
    }
    double getAbility (){return ability;}
    int getwtClass () {return wtClass;}
    void setAbility(double i){ability=i;}

   // void unload(){full = false;}
    void display()
    {
        cout<<"wrestler #"<<id<<" Team #"<<Tid<<endl;
        cout<<wt<<" pounds in wt class #"<<wtClass<<" ability score: "<<ability<<endl;
       //  if(full){cout<<" is full"<<endl;}
       // if(!full){cout<<" is empty"<<endl;}
        cout<<endl;
    }

private:
  int Tid;
    int id;
    //node * wins;
    //node * losses;
    int wt;
    int wtClass;
    double ability;
   // bool full;

};
///#endif // WRESTLERS_H_INCLUDED

