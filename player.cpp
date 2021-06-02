#include<iostream>
#include"card_name.cpp"
using namespace std;

struct card
{
    int suit,value;
};
class hand
{
    public :
    int credit;
    string name;
    card c[7];
};

int no_of_players,upto,i=0,s_b,b_b;
string *names=NULL;;
hand *h=NULL;;
void clr_scrn()    //function to clear screen
{
    int n=no_of_players*15;
    while(n-->0)
        cout<<"\n";
}
void display()                                   // displays intro
{
    int j=0;
    cout<<"\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\t\t\t\t\t       TEXAS HOLD\'EM POKER \n\n\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\n\t\tSelect stakes - "<<"\n\n\n\t\t\t1. 100 - 200\n\n\n\t\t\t2. 200 - 400\n\n\n\t\t\t3. 500 -1000";
    cin>>i;
    switch(i)
    {
        do
        {
            case 1: {s_b=100; b_b=200;
            j++;
            break;}
            case 2: {s_b=200; b_b=400;
            j++;
            break;}
            case 3: {s_b=500; b_b=1000;
            j++;
            break;}
            default : {cout<<"Error selection , Select again : ";
            cin>>i;}
        }while(j<1)
    }
}

void players_settings()                          // player input function
{
    int n,c,plyr=0;
    cout<<"\n\n\n\tEnter the no of players : ";
    do
   {
       cin>>no_of_players;
       c=0;
       if(no_of_players>7)
       {cout<<"\tNo. of players cannot exceed 7, Enter again : ";
        c++;}
       else if(no_of_players==1)
        {cout<<"\tPlaying alone is no fun!, need more players to start the game\n\tEnter again : ";
        c++;}
       else if(no_of_players<1)
        {cout<<"\tInvalid no. of players, Enter again : ";
       c++;}
        else
         {cout<<"\n\n\t\t\t********LET\'S BEGIN THE GAME********\n\n\t";
         c--;}
   }while(c>0);

    names=new string[no_of_players];             // storing player names

    n=no_of_players;
    while(n-->0)
    {
       cout<<endl<<"\tEnter player"<<plyr+1<<" name: ";
       cin>>names[plyr];
       plyr++;
    }

}
void display_hands(int no_of_players, string *names, int upto)
{
    int i=0,j=0;

    for(i=0; i<no_of_players; i++)
        {
            cout<<"\n\n\t\t"<<h[i].name<<" cards :\n";
            cout<<"\n\t\t\t";
            for (j=0; j<upto; j++)
                {
                    get_card_value(h[i].c[j].value);
                    cout<<" of ";
                    get_suit_name(h[i].c[j].suit);
                    cout<<"\n\t\t\t";
                }
        }
    cout<<"\n\n\n";
}
