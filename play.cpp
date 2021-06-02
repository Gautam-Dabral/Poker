#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>

using namespace std;


void deal_preflop(int no_of_players)
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

void set_status (int no_of_players)
{
    if(round<no_of_players)
    {
    h[(round%no_of_players)-1].status="Dealer";
    h[round%no_of_players].status="Small-Blind";
    h[(round+1)%no_of_players].status="Big-Blind";
    }
    else if (round==no_of_players)
    {h[no_of_players-1].status="Dealer";
    h[0].status="Small-Blind";
    h[1].status="Big-Blind";}
    else {}
}
void erase_status (int no_of_players)
{
    for (int i=0; i<no_of_players; i++)
        h[i].status="               ";
}
void play(int no_of_players)
{
    int n=no_of_players;
    char choice;

    while(n-->0)
    {
    cout << "\n\n\t\t\tROUND "<<round<<"\n";

    set_status(no_of_players);
    deal_preflop(no_of_players);           // defined in play.cpp
    display_hands(no_of_players,h,2);      // defined in play.cpp
    deal_flop();
    display_hands(no_of_players,h,5);
    deal_turn();
    display_hands(no_of_players,h,6);
    deal_river();
    cout<<"\n\n\t\t Final card hands of all players are as follows : \n\n\t";
    display_hands(no_of_players,h,7);
    cout<<"\n\t\t\tTHE WINNER OF ROUND "<<round<<" is: "<<"\n\n";
    cout<<"\n\n\tWANTS TO CONTINUE(y/n): ";
    cin>>choice;
    if(choice=='n')
        break;
    round++;
    erase_status(no_of_players);
    clr_scrn();
    }

}

