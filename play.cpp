#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include"pokerlogic.cpp"


using namespace std;


void deal_preflop()
{
    int seed=time(NULL),i=0,j=0;
    card temp;
    srand(seed);

    for(i=0; i<no_of_players; i++)
    {
        for(j=0; j<2; j++)
         {
             temp.suit=rand()%4;
             temp.value=rand()%13;
             p[i].c[j]=temp;
         }
    }
}

void set_in_hand (card temp, int j)
{
     int i;
     for(i=0; i<no_of_players; i++)
        {
                p[i].c[j]=temp;
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
        cout<<"\n\n\t\t\t";
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

void set_status ()
{
    if(round<no_of_players)
    {
    p[(round%no_of_players)-1].status="Dealer";
    p[round%no_of_players].status="Small-Blind";
    p[(round+1)%no_of_players].status="Big-Blind";
    }
    else if (round==no_of_players)
    {p[no_of_players-1].status="Dealer";
    p[0].status="Small-Blind";
    p[1].status="Big-Blind";}
    else {}
}
void erase_status ()
{
    for (int i=0; i<no_of_players; i++)
        p[i].status="               ";
}
void play()
{
    int n=no_of_players;
    char choice;

    while(n-->0)
    {
    cout << "\n\n\t\t\tROUND "<<round<<"\n";

    set_status();
    deal_preflop();           // defined in play.cpp
    display_players(2);      // defined in play.cpp
    place_bet(0);
    deal_flop();
    display_players(5);
    place_bet(2);
    deal_turn();
    display_players(6);
    place_bet(2);
    deal_river();
    cout<<"\n\n\t\t Final card hands of all players are as follows : \n\n\t";
    display_players(7);
    place_bet(2);
    find_winner();
    p[i].credit+=pot;
    cout<<"\n\n\tPLAY ANOTHER ROUND, Enter 'y' for YES and 'n' for NO : ";
    cin>>choice;
    if(choice=='n')
        break;
    round++;
    erase_status();
    clr_scrn();
    }

}

