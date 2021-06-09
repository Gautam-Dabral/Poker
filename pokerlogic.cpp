#include<iostream>
#include<string.h>

using namespace std;

int k=0,j=0,help;
string winner;
card c_high, c_kicker, c_rest;

void sort_by_value (int i)
{
    card temp;
    for(k=0; k<7; k++)
           {
               for(j=0; j<6; j++)
            {
                if(p[i].c[j].value>p[i].c[j+1].value)
                    {
                        temp=p[i].c[j];
                        p[i].c[j]=p[i].c[j+1];
                        p[i].c[j+1]=temp;

                    }

            }
           }
    if(p[i].c[0].value==0)                         //  checking for an Ace
            {c_high.value=13;
            c_high.suit=p[i].c[0].suit;}
    else
            {c_high.value=p[i].c[6].value;
            c_high.suit=p[i].c[6].suit;}

}

void sort_by_suit (int i)
{
    card temp;
    for(k=0; k<7; k++)
        {
            for(j=0; j<6; j++)
            {
                if(p[i].c[j].suit>p[i].c[j+1].suit)
                    {
                        temp=p[i].c[j];
                        p[i].c[j]=p[i].c[j+1];
                        p[i].c[j+1]=temp;

                    }
            }

        }
}
bool isflush (int i)
{
    sort_by_suit (i);
    for(j=1; j<7; j++)
    {
        if(p[i].c[0].suit==p[i].c[4].suit||p[i].c[1].suit==p[i].c[5].suit||p[i].c[2].suit==p[i].c[6].suit)
            {
            if(p[i].c[0].suit==p[i].c[4].suit)                            // checking  for an ace
                {c_high=p[i].c[4];}
            else if (p[i].c[1].suit==p[i].c[5].suit)
                {c_high=p[i].c[5];}
            else if (p[i].c[2].suit==p[i].c[6].suit)
                {c_high=p[i].c[6];}
            else
                {}
            return(true);
            }
    }
    if(j>=6)
    return (false);

}

bool isstraight (int i)
{
    sort_by_value (i);
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
        {
            int temp=p[i].c[j].value;
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
    if(isstraight_flush(i)&&c_high.value==0)
        return (true);
    else
        return (false);
}

bool isfour_of_a_kind (int i)
{
    sort_by_value(i);
    for(j=0; j<4; j++)
    {
        if(p[i].c[j].value==p[i].c[j+3].value)
        {
        (c_high.value==0) ? c_high.value=13 : c_high.value=p[i].c[j].value ;
        (j==3) ? (p[i].c[0].value==0) ? c_kicker.value=13 : c_kicker.value=p[i].c[2].value : c_kicker.value=p[i].c[6].value ;
        return (true);}
    }
    if(j>3)
        {return (false);}
}

bool isfull_house (int i)
{
   sort_by_value(i);

    if(p[i].c[0].value==p[i].c[2].value)//&&(p[i].c[3].value==p[i].c[4].value||p[i].c[4].value==p[i].c[5].value||p[i].c[5].value==p[i].c[6].value))
    {
        c_high=p[i].c[0];
        if(p[i].c[3].value==p[i].c[4].value)
        {c_kicker=p[i].c[3];
        return(true);}
        else if (p[i].c[4].value==p[i].c[5].value)
        {c_kicker=p[i].c[4];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {c_kicker=p[i].c[5];
        return(true);}
        else {}
    }
    else if(p[i].c[1].value==p[i].c[3].value)
    {
        c_high=p[i].c[1];
        if (p[i].c[4].value==p[i].c[5].value)
        {c_kicker=p[i].c[4];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {c_kicker=p[i].c[5];
        return(true);}
    }
    else if(p[i].c[2].value==p[i].c[4].value)
    {
        c_high=p[i].c[2];
        if (p[i].c[0].value==p[i].c[1].value)
        {c_kicker=p[i].c[0];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {c_kicker=p[i].c[5];
        return(true);}
    }
    else if(p[i].c[3].value==p[i].c[5].value)
    {
        c_high=p[i].c[3];
        if (p[i].c[0].value==p[i].c[1].value)
        {c_kicker=p[i].c[0];
        return(true);}
         if (p[i].c[1].value==p[i].c[2].value)
        {c_kicker=p[i].c[1];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {c_kicker=p[i].c[5];
        return(true);}
    }
    else if(p[i].c[4].value==p[i].c[6].value)
    {
        c_high=p[i].c[4];
        if (p[i].c[0].value==p[i].c[1].value)
        {c_kicker=p[i].c[0];
        return(true);}
         if (p[i].c[1].value==p[i].c[2].value)
        {c_kicker=p[i].c[1];
        return(true);}
        else if (p[i].c[2].value==p[i].c[3].value)
        {c_kicker=p[i].c[2];
        return(true);}
    }
    else
        return (false);

}

bool isthree_of_a_kind (int i)
{
    sort_by_value(i);
    for(j=0; j<5; j++)
    {
        if(p[i].c[j].value==p[i].c[j+2].value)
        {
        (c_high.value==0) ? c_high.value=13 : c_high.value=p[i].c[j].value ;
        (j==4) ? (p[i].c[0].value==0) ? c_kicker.value=13 : c_kicker.value=p[i].c[2].value : c_kicker.value=p[i].c[6].value ;
        return (true);}
    }
    if(j>4)
    {return (false);}
}

bool is2pair (int i)
{
    sort_by_value(i);
    for(j=0; j<6; j++)
        if(p[i].c[j].value==p[i].c[j+1].value)
        {
           if(k>0)
           {
               if(c_high.value<p[i].c[j].value)
                {p[i].c[j].value==0 ? c_high.value=13 : c_high.value=p[i].c[j].value;
                k++;}
               else
                {p[i].c[j].value==0 ? c_kicker.value=13 : c_kicker.value=p[i].c[j].value;
                k++;}
           }
            p[i].c[j].value==0 ? c_high.value=13 : c_high.value=p[i].c[j].value;
            p[i].c[j].value==0 ? c_kicker.value=13 : c_kicker.value=p[i].c[j].value;
            k++;
        }
        if(k>=2)
            return (true);
        else
            return(false);

}

bool ispair (int i)
{
    sort_by_value(i);
    for(j=0; j<6; j++)
    {
        if(p[i].c[j].value==p[i].c[j+1].value)
        {
            (c_high.value==0) ? c_high.value=13 : c_high.value=p[i].c[j].value ;
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

bool ishigh (int i)
{
    sort_by_value(i);
    if(p[i].c[0].value==0)
        {c_high=p[i].c[0];
        c_kicker=p[i].c[6];
        return(true);}
    else
        {c_high=p[i].c[6];
        c_kicker=p[i].c[5];
        return (true);}
}
int check_hand (int i, int help)
{
    {
        if(isroyal_flush(i))
            return (help);
        else if (isstraight_flush(i))
        {help+=(c_high.value+c_kicker.value-100);
        return (help);}
        else if (isfour_of_a_kind(i))
         {help+=(c_high.value+c_kicker.value-200);
        return (help);}
        else if (isfull_house(i))
        {help+=(c_high.value+c_kicker.value-300);
        return (help);}
        else if (isflush(i))
        {help+=(c_high.value+c_kicker.value-400);
        return(help);}
        else if (isstraight(i))
        {help+=(c_high.value+c_kicker.value-500);
        return(help);}
        else if (isthree_of_a_kind(i))
        {help+=(c_high.value+c_kicker.value-600);
        return(help);}
        else if (is2pair(i))
        {help+=(c_high.value+c_kicker.value-700);
        return(help);}
        else if (ispair(i))
        {help+=(c_high.value+c_kicker.value-800);
        return(help);}
        else if (ishigh(i))
        {help+=(c_high.value+c_kicker.value-900);
        return(help);}
        else
        {cout<<"\n\nError deciding winner\n\n";}

    }
}
void find_winner ()
{
    int *score;
    int k, max_score;
    score = new int[no_of_players];
    for(i=0; i<no_of_players; i++)
    {
        help=2000;
        score[i]=check_hand(i,help);
        cout<<"\n\t"<<p[i].name<<" - "<<score[i]<<endl;
    }
    max_score=score[0];
    for(i=0; i<no_of_players; i++)
    {
        if(score[i]<score[i+1])
            {max_score=score[i+1];
            winner=p[i+1].name;}
        else
            {winner=p[i].name;}
    }
    cout<<"\n\t\t\tTHE WINNER OF ROUND "<<round<<" is : ";
    cout<<"\n\n\n\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\t\t\t\t\t"<<winner<<" - "<<max_score<<" points"<<"\t\t\t\t\t";
    cout<<"\n\n\n\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
}
