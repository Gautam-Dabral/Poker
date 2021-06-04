#include<iostream>
#include<cstdbool>

using namespace std;
card c_high;

void sort_by_value ()
{
    int j,temp;
    for(i=0; i<no_of_players; i++)
        {
            for(j=0; j<no_of_players-1; j++)
            {
                if(p[i].c[j].value>p[i].c[j+1].value)
                    {
                        temp=p[i].c[j].value;
                        p[i].c[j].value=p[i].c[j+1].value;
                        p[i].c[j+1].value=temp;

                    }

            }
           if(p[i].c[0].value==0)
            {c_high.value=13;
            c_high.suit=p[i].c[6].suit;}
            else
            {c_high.value=p[i].c[6].value;
            c_high.suit=p[i].c[6].suit;}
        }
}
void sort_by_suit ()
{
    int j,temp;
    for(i=0; i<no_of_players; i++)
        {
            for(j=0; j<no_of_players-1; j++)
            {
                if(p[i].c[j].suit>p[i].c[j+1].suit)
                    {
                        temp=p[i].c[j].suit;
                        p[i].c[j].suit=p[i].c[j+1].suit;
                        p[i].c[j+1].suit=temp;

                    }
            }

        }
}
bool isflush (int i)                  // i being the player
{
    int k=0;
    sort_by_suit ();
    for(j=1; j<7; j++)
    {
        if(p[i].c[0].suit==p[i].c[6].suit)
            {
            if(p[i].c[0].value==0)        // when a player's hand has an ace
                {c_high.value=13;
                c_high.suit=p[i].c[0].suit;}
            else
                {c_high.value=p[i].c[6].value;
                c_high.suit=p[i].c[6].suit;}
            return(true);
            }
        else
        return (false);
    }

}

bool isstraight (int i)
{
    int k=0;
    sort_by_value ();
    if(p[i].c[0].value==0)
    {
        if(p[i].c[4].value==4)
        {c_high.value=4;
        c_high.suit=p[i].c[4].suit;
        return(true);}
        else if (p[i].c[3].value==9)
        {c_high.value=13;
        c_high.suit=p[i].c[0].suit;
        return (true);}
        else
        {}
    }
    else if (p[i].c[0].value+4==p[i].c[4].value)
    {
        c_high.value=p[i].c[4].value;
        c_high.suit=p[i].c[4].suit;
        return (true);
    }
    else
        return (false);

}

bool isstraight_flush (int i)
{
    if(isstraight(i)&&isflush(i))
    {return(true);}
    else
    {return(false);}
}
bool ispair (int i)
{
    int k=0;
    sort_by_value();
    for(j=0; j<6; j++)
    {
        if(p[i].c[j].value==p[i].c[j+1].value)
        {c_high.value=p[i].c[j].value;
        k++;}

        else
        {}
    }
    if(k>0)
        {
            if(p[i].c[0].value==0)        // when a player's hand has an ace
                {c_high.value=13;}
            else
                {};
            return(true);
        }
    else
        return (false);
}
