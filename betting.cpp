#include<iostream>
#include<string.h>

int c,pot=0;
void set_status ()
{
    int i;
    if(round<no_of_players)
    {
        i=(round-1)%no_of_players;
        strcpy(p[i].status,"Dealer");
        strcpy(p[i+1].status,"Small-Blind");
        strcpy(p[i+2].status,"Big-Blind");
    }
    else if (round==no_of_players)
    {
        strcpy(p[no_of_players-1].status,"Dealer");
        strcpy(p[0].status,"Small-Blind");
        strcpy(p[1].status,"Big-Blind");}
    else {}
}
void erase_status ()
{
    for (i=0; i<no_of_players; i++)
        strcpy(p[i].status,"                   ");
}

void bet_innit ()
{
    for (i=0; i<no_of_players; i++)
    {p[i].bet=0;}
}

void set_bet ()
{
        for(i=0; i<no_of_players; i++)
        if(!strncmp(p[i%no_of_players].status,"Small",5))
           {
               p[i%no_of_players].bet=s_b;
               p[i%no_of_players].credit-=s_b;
               pot+=s_b;}
        else if (!strncmp(p[i%no_of_players].status,"Big",3))
            {
                p[i%no_of_players].bet=b_b;
                p[i%no_of_players].credit-=b_b;
                pot+=b_b;}
        else
            {}
}

int check_bet ()
{
    for(i=0; i<=no_of_players-1; i++)
    {
        if(p[(i+1)%no_of_players].bet==p[(i)%no_of_players].bet)
            return(1);
        else
            return (0);
    }
}


void call_bet(int i)
{
    p[i%no_of_players].bet=p[i%(no_of_players-1)].bet;
    p[i%no_of_players].credit-=p[i%no_of_players].bet;
    pot+=p[i%no_of_players].bet;
}

void raise_bet (int i)
{
    int help=0;
    int j=0;
    cout<<"\n\tRaise bet to - ";
    do
    {cin>>help;
    if(p[i%(no_of_players-1)].bet<help)
    {p[i%no_of_players].bet=help;
    j++;}
    else
    {cout<<"Amount entered should be bigger than the previous bet : ";}
    }while(j<1);
}

void fold (int i)
{
    int j;
    if(!strncmp(p[i%no_of_players].status,"folded",6))
    {
        for(j=0; j<7; j++)
        p[i%no_of_players].c[j].value=-1;
    }

}

void place_bet ()
{
    int i,j;
    bet_innit();
    set_bet();
    i=round+2;
    while(1-check_bet())
    {
            if(p[i%(no_of_players)].c[0].value>=0)
           {
            cout<<p[i%(no_of_players)].name;
            cout<<", it's your turn : "<<"\n\n\t\t\t1. Fold ( Forfeit this round )"<<"\n\n\t\t\t2. Call ( Bet the same amount )"<<"\n\n\t\t\t3. Raise ( Enter a higher bet )\n\n\t\t\t";
            j=0;
            do
            {cin>>c;
            if(c==1)
                {
                    strcpy(p[i%(no_of_players)].status,"folded");
                    fold(i%(no_of_players));
                    j++;
                }
            else if (c==2)
                {
                    call_bet(i%(no_of_players));
                    j++;
                }
            else if (c==3)
                {
                    raise_bet(i%(no_of_players));
                    j++;
                }
            else
                {
                    cout<<"Error : Enter a valid choice - ";
                }
            }while(j<1);

           }
           i++;
    }

}






