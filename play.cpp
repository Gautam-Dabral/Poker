#include<iostream>
#include<time.h>
#include<cstdlib>
#include"card_name.cpp"

using namespace std;


struct card
{
    int suit,value;
};

card *moves=NULL;

bool compare(card temp,int no_of_players)
{
    int i=0;
    while(i<no_of_players*5)
    {
        if(moves[i].suit<0)
            break;
        else
        {
            if(moves[i].suit==temp.suit && moves[i].value==temp.value)
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
        moves[i].suit=-1;
        moves[i].value=-1;
    }
}


void play(int no_of_players)
{
    int seed=time(NULL);
    srand(seed);

    moves=new card[no_of_players*5];

    init(no_of_players);

    card temp;
    int i=0;
    while(i<no_of_players*5)
    {
        temp.suit=rand()%4;
        temp.value=rand()%13;
        if(!compare(temp,no_of_players))
        {
           moves[i]=temp;
           i++;
        }
    }
}


void display_moves(int no_of_players)
{
    int curr=0,j=1,loop=0,count=0;

    while(count<no_of_players*5)
    {
        if(curr<no_of_players*5)
        {
            cout<<"\t\t";
            get_card_value(moves[curr].value);
            cout<<" of ";
            get_suit_name(moves[curr].suit);
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
