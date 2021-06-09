#include<iostream>
#include<cstdio>
#include"card_name.cpp"

using namespace std;

class card
{
    public :
    int suit,value;
    card ()
    {suit=-1; value=-1;}           // card values and suits initialized to -1
    card (card &temp)             // copy constructor for card type values
    {
        suit=temp.suit;
        value=temp.value;
    }
};
class players
{
    public :
    int credit, bet=0;
    string name;
    char status[15];
    card c[7];
};

int no_of_players, upto, i=0, s_b, b_b, round=1;
players *p=NULL;;


void clr_scrn()    //function to clear screen
{
    int n=no_of_players*15;
    while(n-->0)
        cout<<"\n";
}
void display()                                   // displays intro
{
    int c,j=0;
    cout<<"\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\t\t\t\t\t       TEXAS HOLD\'EM POKER \n\n\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\n\t\tSelect stakes - "<<"\n\n\n\t\t\t1. 100 - 200\n\n\n\t\t\t2. 200 - 400\n\n\n\t\t\t3. 500 - 1000\n\n\t\t";
    cin>>c;
    switch(c)
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
            cin>>c;}
        }while(j<1);
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
       if(no_of_players>9)
       {cout<<"\tNo. of players cannot exceed 8, Enter again : ";
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

    p=new players[no_of_players];

    n=no_of_players;
    for(i=0; i<no_of_players; i++)
    {
       cout<<endl<<"\tEnter player"<<plyr+1<<" name: ";
       cin>>p[i].name;
       plyr++;
       p[i].credit=10000;
    }

}

void display_players(int upto)
{
    int i=0,j=0;

    for(i=0; i<no_of_players; i++)
        {
            cout<<"\n\n\t\t"<<p[i].name;
            printf("\t\t%s",p[i].status);
            cout<<"\n\n\t\tCredit : "<<p[i].credit<<" Points";
            cout<<"\n\n\t\tCards : ";
            cout<<"\n\t\t\t";
            for (j=0; j<upto; j++)
                {
                    get_card_value(p[i].c[j].value);
                    get_suit_name(p[i].c[j].suit);
                    cout<<"\n\t\t\t";
                }
        }
    cout<<"\n\n\n";
}

