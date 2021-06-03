#include<iostream>


int c,pot=0;

void fold ()
{}
void place_bet (int no_of_players,int t)
{
    if(round<no_of_players)
    {
    h[round%no_of_players].bet=s_b;
    h[round%no_of_players].credit-=s_b;
    pot+=s_b;
    h[(round+1)%no_of_players].status=b_b;
    h[(round+1)%no_of_players].credit-=b_b;
    pot+=b_b;
    }
    else if (round==no_of_players)
    {h[no_of_players-1].status="Dealer";
    h[0].bet=s_b;
    h[0].credit-=s_b;
    pot+=s_b;
    h[1].bet=b_b;
    h[1].credit-=b_b;
    pot+=b_b;}
    else {}

    {
        for(i=(round+2)-t; i<=no_of_players; i++)
        {
        cout<<"\n\n\t\t\t"<<h[i%no_of_players].name;
        cout<<", it's your turn : "<<"\n\n\t\t\t1. Fold ( Forfeit this round )"<<"\n\n\t\t\t2. Call ( Bet the same amount )"<<"\n\n\t\t\t3. Raise ( Enter a higher bet )\n\n\t\t\t";
        cin>>c;
        int j=0;
        do
        {switch(c)
        {case 1:{ fold();
                  j++;
                  break;}
         case 2:{ h[i%no_of_players].bet=h[(i-1)%no_of_players].bet;
                  h[i%no_of_players].credit-=h[i%no_of_players].bet;
                  j++;
                  pot+=h[i%no_of_players].bet;
                  break;}
         case 3:{ cout<<"\n\n\t\t\tRaise bet to : ";
                  cin>>h[i%no_of_players].bet;
                  h[i%no_of_players].credit-=h[i%no_of_players].bet;
                  pot+=h[i%no_of_players].bet;
                  j++;
                  break;}
         default:{ cout<<"\n\n\t\t\tError - Enter again : ";
         cin>>c;
         break;}
        }
        }while(j<1);

    }
}
}
