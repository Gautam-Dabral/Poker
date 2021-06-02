#include<iostream>
#include<cstdlib>
#include<conio.h>
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
int no_of_players,upto;
string *names=NULL;;

void clr_scrn()    //function to clear screen
{
    int n=no_of_players*15;
    while(n-->0)
        cout<<"\n";
}


void display()                                 // displays intro
{
    cout<<"\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\t\t\t\t\t       TEXAS HOLD\'EM POKER \n\n\t\t\t\t";
    for(int i=0;i<50;i++)
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

void deal_preflop(int no_of_players, string* names)
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
void set_in_hand (card temp, int j)
{
     int i;
     for(i=0; i<no_of_players; i++)
        {
                h[i].c[j]=temp;
        }
}

void deal_flop ()
{
    card temp;
    int seed,i,j=2;
    seed=time(NULL);
    srand(seed);
    cout<<"\t To see the community cards : press any key\n\n\n\t";
    getch();
    clr_scrn();       //clear screen
    cout<<"\tThe three community cards are : ";

    for (i=0; i<3; i++)
    {
        cout<<"\n\n\n\t\t";
        temp.value=rand()%13;
        temp.suit=rand()%4;
        get_card_value(temp.value);
        cout<<" of ";
        get_suit_name(temp.suit);
        cout<<"\n\t";
        set_in_hand(temp,j);
        j++;
    }
}

void deal_turn ()
{
     card temp;
    int seed,i,j=5;
    seed=time(NULL);
    srand(seed);
    cout<<"\t To see the Turn card : press any key\n\n\n\t";
    getch();
    clr_scrn();
    cout<<"\tThe Turn card is : ";

    for (i=0; i<1; i++)
    {
        cout<<"\n\n\n\t\t";
        temp.value=rand()%13;
        temp.suit=rand()%4;
        get_card_value(temp.value);
        cout<<" of ";
        get_suit_name(temp.suit);
        cout<<"\n\t";
        set_in_hand(temp,j);
        //j++;
    }

}
void deal_river ()
{
    card temp;
    int seed,i,j=6;
    seed=time(NULL);
    srand(seed);
    cout<<"\t To see the River card : press any key\n\n\n\t";
    getch();
    clr_scrn();
    cout<<"\tThe River card is : ";
    for (i=0; i<1; i++)
    {
        cout<<"\n\n\n\t\t";
        temp.value=rand()%13;
        temp.suit=rand()%4;
        get_card_value(temp.value);
        cout<<" of ";
        get_suit_name(temp.suit);
        cout<<"\n\t";
        set_in_hand(temp,j);
        //j++;
    }

}



void play(int no_of_players)
{
    int n=no_of_players,round=1;
    char choice;

    while(n-->0)
    {
    cout << "\n\n\t\t\tROUND "<<round<<"\n";
    deal_preflop(no_of_players,names);           // defined in play.cpp
    display_hands(no_of_players,names,2);      // defined in play.cpp
    deal_flop();
    display_hands(no_of_players,names,5);
    deal_turn();
    display_hands(no_of_players,names,6);
    deal_river();
    cout<<"\n\n\t\t Final card hands of all players are as follows : \n\n\t";
    display_hands(no_of_players,names,7);
    cout<<"\n\t\t\tTHE WINNER OF ROUND "<<round<<" is: "<<"\n\n";
    cout<<"\n\n\tWANTS TO CONTINUE(y/n): ";
    cin>>choice;
    if(choice=='n')
        break;
    round++;
    clr_scrn();
    }

}



int main()
{
    display();                                  // defined in player.cpp
    players_settings();                        // defined in player.cpp
    play(no_of_players);
    return 0;
}
