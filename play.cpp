#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>

using namespace std;


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

