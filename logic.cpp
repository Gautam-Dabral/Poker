#include<iostream>
#include<cstdbool>

using namespace std;
card c_high; c_kicker;
int k=0;

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
    sort_by_value ();
    if(p[i].c[0].value==0)
    {
        if(p[i].c[1].value==1&&p[i].c[2].value==2&&p[i].c[3].value==3&&p[i].c[4].value==4)
           {c_high.value=4;
            return (true);}
        else if(p[i].c[3].value==9&&p[i].c[4].value==10&&p[i].c[5].value==11&&p[i].c[6].value==12)
            {c_high.value=13;
            return (true);}
        else
            {return (false);}
    }
    else
    {
        for(j=0; j<3; j++)
        {int temp=p[i].c[j].value;
        if(p[i].c[j+1].value==temp+1&&p[i].c[j+2].value==temp+2&&p[i].c[j+3].value==temp+3&&p[i].c[j+4].value==temp+4)
        {c_high.value=p[i].c[j+4].value;
        return (true);}
        else
        {return (false);}
        }

    }

}

bool isstraight_flush (int i)
{
    if(isstraight(i)&&isflush(i))
    {return(true);}
    else
    {return(false);}
}
bool isroyal_flush (int i)
{
    if(isstraight_flush(int i)&&c_high.value==0)
        return (true);
    else
        return (false);
}
bool isfour_of_a_kind (int i)
{
    sort_by_value();
    for(j=0; j<4; j++)
    {
        if(p[i].c[j].value==p[i].c[j+3].value)
        {c_high.value=p[i].c[j].value;
        (c_high.value==0) ? c_high.value=13 : ;
        (j==3) ? (p[i].c[0]==0) ? c_kicker.value=13 : c_kicker.value=p[i].c[2].value : c_kicker.value=p[i].c[6].value ;
        return (true);}
    }
    if(j>3)
        {return (false);}
}

bool isthree_of_a_kind (int i)
{
    sort_by_value();
    for(j=0; j<5; j++)
    {
        if(p[i].c[j].value==p[i].c[j+2].value)
        {c_high.value=p[i].c[j].value;
        (c_high.value==0) ? c_high.value=13 : ;
        (j==4) ? (p[i].c[0]==0) ? c_kicker.value=13 : c_kicker.value=p[i].c[2].value : c_kicker.value=p[i].c[6].value ;
        return (true);}
    }
    if(j>4)
    {return (false);}
}
bool ispair (int i)
{
    sort_by_value();
    for(j=0; j<6; j++)
    {
        if(p[i].c[j].value==p[i].c[j+1].value)
        {
            c_high.value=p[i].c[j].value;
            (c_high.value==0) ? c_high.value=13 : ;
        if(j<5)
        (p[i].c[0].value==0) ? c_kicker.value=13 : c_kicker.value=p[i].c[6].value ;
        else
        (p[i].c[0].value==0) ? c_kicker.value=13 : c_kicker.value=p[i].c[4].value ;

        return (true);
        }
    }
    if(j>=5)
        return(false);
}

