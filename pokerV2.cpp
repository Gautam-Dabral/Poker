#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

struct card
{
    int suit,value;
};
class hand
{
    public :
    string name;
    card c[7];
};
hand *h=NULL;;
int no_of_players;
string *names=NULL;;

void display()                                 // displays intro
{
    cout<<"\t\t\t\t";
    for(int i=0;i<38;i++)
        cout<<"*";
    cout<<"\n\n \t\t\t\t\t\tTEXAS HOLD\'EM POKER\n\n\t\t\t\t";
    for(int i=0;i<38;i++)
        cout<<"*";
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
         {cout<<"\n\n\t\t\t********LET\'S BEGIN THE GAME********";
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
void get_card_value(int p)
    {
        switch(p)
        {
        case 0 :
            {cout<<"Ace";
            break;}
        case 1:
            {cout<<"Two";
            break;}
        case 2 :
            {cout<<"Three";
            break;}
        case 3 :
            {cout<<"Four";
            break;}
        case 4 :
            {cout<<"Five";
            break;}
        case 5 :
            {cout<<"Six";
            break;}
        case 6 :
            {cout<<"Seven";
            break;}
        case 7 :
            {cout<<"Eight";
            break;}
        case 8 :
            {cout<<"Nine";
            break;}
        case 9 :
            {cout<<"Ten";
            break;}
        case 10 :
            {cout<<"Jack";
            break;}
        case 11 :
            {cout<<"Queen";
            break;}
        case 12 :
            {cout<<"King";
            break;}
        default :
            {cout<<"error"<<endl;}
        }
}
void get_suit_name(int q)
{

    switch (q)
        {
        case 00 :
            {cout<<"Spades";
            break;}
        case 01 :
            {cout<<"Hearts";
            break;}
        case 02 :
            {cout<<"Diamond";
            break;}
        case 03 :
            {cout<<"Clubs";
            break;}

        }
}

void deal_card(int no_of_players, string* names)
{
    int seed=time(NULL),i=0,j=0;
    card temp;
    srand(seed);

    h=new hand[no_of_players];           // hand has no_of_players players having 7 card type values each


    for(i=0; i<no_of_players; i++)
    {
        h[i].name=names[i];
        for(j=0; j<2; j++)
         {
             temp.suit=rand()%4;
             temp.value=rand()%13;
             h[i].c[j]=temp;
         }
    }
}

void display_hands(int no_of_players, string *names)
{
    int i=0,j=0;

    for(i=0; i<no_of_players; i++)
        {
            cout<<"\n\n\t\t"<<h[i].name<<" cards :\n";
            cout<<"\n\t\t\t";
            for (j=0; j<2; j++)
                {
                    get_card_value(h[i].c[j].value);
                    cout<<" of ";
                    get_suit_name(h[i].c[j].suit);
                    cout<<"\n\t\t\t";
                }
        }
    cout<<"\n\n\n";
}

int main()
{
    display();                                // defined in player.cpp
    players_settings();                      // defined in player.cpp
    deal_card(no_of_players,names);               // defined in play.cpp
    display_hands(no_of_players,names);    // defined in play.cpp
    return 0;
}
