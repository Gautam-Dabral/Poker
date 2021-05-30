#include<iostream>
#include<time.h>
#include<cstdlib>
#include"card_name.cpp"

using namespace std;


struct card
{
    int suit,value;
};

card *hand=NULL;

bool compare(card temp,int no_of_players)
{
    int i=0;
    while(i<no_of_players*7)
    {
        if(hand[i].suit<0)
            break;
        else
        {
            if(hand[i].suit==temp.suit && hand[i].value==temp.value)
                return true;
            i++;
        }
    }
    return false;
}

void init(int no_of_players)
{
    for(int i=0;i<no_of_players*7;i++)
    {
        hand[i].suit=-1;
        hand[i].value=-1;
    }
}

void deal_card(int no_of_players)
{
    int seed=time(NULL);
    srand(seed);

    hand=new card[no_of_players*7];

    init(no_of_players);

    card temp;
    int i=0;
    while(i<no_of_players*7)
    {
        temp.suit=rand()%4;
        temp.value=rand()%13;
        if(!compare(temp,no_of_players))
        {
           hand[i]=temp;
           i++;
        }
    }
}


void display_hands(int no_of_players, string *names)
{
    int i=0,j=0;

    while(i<no_of_players*7)
    {
        if(i%7==0)
        {
           cout<<"\n\n\t\t"<<names[j]<<" cards:\n";
            j++;
        }

        cout<<"\n\t\t\t";
        get_card_value(hand[i].value);             // defined in card_name.cpp
        cout<<" of ";
        get_suit_name(hand[i].suit);               // defined in card_name.cpp
        i++;

    }
    cout<<"\n\n\n";
}
