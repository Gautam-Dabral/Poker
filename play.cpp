#include<iostream>
#include<time.h>
#include<cstdlib>
#include"E:\poker_pankaj\card_name.cpp"

using namespace std;


struct card
{
    int suit,value;
};

card *hand=NULL;

bool compare(card temp,int no_of_players)
{
    int i=0;
    while(i<no_of_players*5)
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
    for(int i=0;i<no_of_players*5;i++)
    {
        hand[i].suit=-1;
        hand[i].value=-1;
    }
}

void deal_card(int no_of_players)
{
    int seed=time(NULL);
    srand(seed);

    hand=new card[no_of_players*5];

    init(no_of_players);

    card temp;
    int i=0;
    while(i<no_of_players*5)
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


void display_hands(int no_of_players)
{
    int curr=0,j=1,loop=0,count=0;

    while(count<no_of_players*5)
    {
        if(curr<no_of_players*5)
        {
            cout<<"\t\t";
            get_card_value(hand[curr].value);
            cout<<" of ";
            get_suit_name(hand[curr].suit);
            cout<<"\t\t";
            curr+=5;
            count++;
        }
        else
        {
            curr=j;
            j++;
            cout<<endl;
        }

    }
    cout<<"\n\n\n";
}
