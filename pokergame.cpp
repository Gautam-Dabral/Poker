#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<string.h>


using namespace std;

class card
{
    public :
    int suit,value;
    card ()
    {suit=-1; value=-1;}           // card values and suits initialized to -1
    card (card &temp)             // copy constructor for card type values
    {
        suit=temp.suit;
        value=temp.value;
    }
};

class players
{
    public :
    int credit, bet;
    string name;
    char status[15];
    card c[7], c_high, c_kicker;
};


int    no_of_players, upto, s_b, b_b, round=1;
int    c, help;
int    i=0, j=0, k=0, pot=0;
string winner;

//------------------------display section---------------------------

void clr_scrn()                                   //function to clear screen
{
    int n=no_of_players*15;
    while(n-->0)
        cout<<"\n";
}

void get_card_value(int p)
    {
        switch(p)
        {
        case 0 :
            {cout<<"Ace";
            break;}
        case 1:
            {cout<<"Two";
            break;}
        case 2 :
            {cout<<"Three";
            break;}
        case 3 :
            {cout<<"Four";
            break;}
        case 4 :
            {cout<<"Five";
            break;}
        case 5 :
            {cout<<"Six";
            break;}
        case 6 :
            {cout<<"Seven";
            break;}
        case 7 :
            {cout<<"Eight";
            break;}
        case 8 :
            {cout<<"Nine";
            break;}
        case 9 :
            {cout<<"Ten";
            break;}
        case 10 :
            {cout<<"Jack";
            break;}
        case 11 :
            {cout<<"Queen";
            break;}
        case 12 :
            {cout<<"King";
            break;}
        default :
            {cout<<" "<<endl;}
        }
}

void get_suit_name(int q)
{

    switch (q)
        {
        case 0:
            {cout<<" of Spades";
            break;}
        case 1 :
            {cout<<" of Hearts";
            break;}
        case 2 :
            {cout<<" of Diamonds";
            break;}
        case 3 :
            {cout<<" of Clubs";
            break;}
        default :
            cout<<" "<<endl;
        }
}

void display()                                   // displays intro
{
    int c,j=0;
    cout<<"\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\t\t\t\t\t       TEXAS HOLD\'EM POKER \n\n\t\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n\n\t\tSelect stakes - "<<"\n\n\n\t\t\t1. 100 - 200\n\n\n\t\t\t2. 200 - 400\n\n\n\t\t\t3. 500 - 1000\n\n\t\t";
    cin>>c;
    switch(c)
    {
        do
        {
            case 1: {s_b=100; b_b=200;
            j++;
            break;}
            case 2: {s_b=200; b_b=400;
            j++;
            break;}
            case 3: {s_b=500; b_b=1000;
            j++;
            break;}
            default : {cout<<"Error selection , Select again : ";
            cin>>c;}
        }while(j<1);
    }
    cout<<"\n\n\n\tEnter the no of players : ";
    do
   {
       cin>>no_of_players;
       c=0;
       if(no_of_players>9)
       {cout<<"\tNo. of players cannot exceed 8, Enter again : ";
        c++;}
       else if(no_of_players==1)
        {cout<<"\tPlaying alone is no fun!, need more players to start the game\n\tEnter again : ";
        c++;}
       else if(no_of_players<1)
        {cout<<"\tInvalid no. of players, Enter again : ";
       c++;}
        else
         {cout<<"\n\n\t\t\t********LET\'S BEGIN THE GAME********\n\n\t";
         c--;}
   }while(c>0);
}

players * p = new players[no_of_players];

void players_settings()                          // player input function
{
    int n,plyr=0;

    n=no_of_players;

    for(i=0; i<no_of_players; i++)
    {
       cout<<endl<<"\tEnter player"<<plyr+1<<" name: ";
       cin>>p[i].name;
       plyr++;
       if (s_b==100)
       p[i].credit=10000;
       else if (s_b==200)
       p[i].credit=20000;
       else if (s_b==500)
       p[i].credit=50000;
       else
       {}
    }

}

void display_players(int upto)                   // displays card hands of players
{
    int i=0,j=0;

    for(i=0; i<no_of_players; i++)
        {
            cout<<"\n\n\t\t"<<p[i].name;
            printf("\t\t%s",p[i].status);
            cout<<"\n\n\t\tCredit : "<<p[i].credit<<" Points";
            cout<<"\n\n\t\tCards : ";
            cout<<"\n\t\t\t";
            for (j=0; j<upto; j++)
                {
                    get_card_value(p[i].c[j].value);
                    get_suit_name(p[i].c[j].suit);
                    cout<<"\n\t\t\t";
                }
        }
    cout<<"\n\n\n";
}

// -------------------card dealing section------------------------

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
        strcpy(p[i].status,"            ");
}


// ----------------------------betting section-------------------------


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

bool check_bet (int i)
{
  {
        if(p[(i-1)%no_of_players].bet>p[i%no_of_players].bet)
        return (true);
        else
        return (false);
  }
}

bool check_credit (int i)
{
    int j=0;
    if(p[i%no_of_players].credit==0)
    {
       strcpy(p[i%no_of_players].status, "is out of credit");
       p[i%no_of_players].bet=p[(i-1)%no_of_players].bet;
       for (j=0; j<7; j++)
       {p[i%no_of_players].c[j].value=-1;
       p[i%no_of_players].c[j].suit=-1;}
       return (false);
    }
    else if (p[i%no_of_players].credit<p[(i-1)%no_of_players].bet && p[i%no_of_players].credit>0)
    {
        strcpy(p[i%no_of_players].status, "is all in");
        p[i%no_of_players].bet=p[i%no_of_players].credit;
        p[i%no_of_players].credit-=p[i%no_of_players].bet;
        pot+=p[i%no_of_players].bet;
        return (false);
    }
    else
    {
        return (true);
    }
}

void call_bet(int i)
{
    if(check_credit(i))
    {p[i%no_of_players].bet=p[(i-1)%no_of_players].bet;
    p[i%no_of_players].credit-=p[i%no_of_players].bet;
    pot+=p[i%no_of_players].bet;}
}

void raise_bet (int i)
{
    int help=0;
    int j=0;
    cout<<"\n\tRaise bet to - ";
    do
    {cin>>help;
    if(p[i%(no_of_players-1)].bet<help)
    {
        if(check_credit(i))
        p[i%no_of_players].bet=help;

        j++;
    }
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
        p[i%no_of_players].c[j].suit=-1;
        strcpy(p[i%no_of_players].status,"has folded");
        p[i%no_of_players].bet=p[(i-1)%no_of_players].bet;
    }

}

void place_bet (int round)
{
    int j,i=round+2;
    bet_innit();
    set_bet();
    while(check_bet(i))
    {
            if(p[i%(no_of_players)].c[0].value > -1)
           {
            cout<<p[i%(no_of_players)].name;
            cout<<", it's your turn : "<<"\n\n\t\t\t1. Fold ( Forfeit this round )"<<"\n\n\t\t\t2. Call ( Bet the same amount )"<<"\n\n\t\t\t3. Raise ( Enter a higher bet )\n\n\t\t\t";
            j=0;
            while(j<1)
            {cin>>c;
            if(c==1)
                {
                    strcpy(p[i%(no_of_players)].status,"folded");
                    fold(i);
                    j++;
                }
            else if (c==2)
                {
                    call_bet(i);
                    j++;
                }
            else if (c==3)
                {
                    raise_bet(i);
                    j++;
                }
            else
                {
                    cout<<"Error : Enter a valid choice - ";
                }
            }
            ++i;
           }
    }

}

//----------------------decision making section---------------------------

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
            {p[i].c_high.value=13;
            p[i].c_high.suit=p[i].c[0].suit;}
    else
            {p[i].c_high.value=p[i].c[6].value;
            p[i].c_high.suit=p[i].c[6].suit;}

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
                {p[i].c_high=p[i].c[4];}
            else if (p[i].c[1].suit==p[i].c[5].suit)
                {p[i].c_high=p[i].c[5];}
            else if (p[i].c[2].suit==p[i].c[6].suit)
                {p[i].c_high=p[i].c[6];}
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
           {p[i].c_high.value=4;
            return (true);}
        else if(p[i].c[3].value==9&&p[i].c[4].value==10&&p[i].c[5].value==11&&p[i].c[6].value==12)
            {p[i].c_high.value=13;
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
                {p[i].c_high.value=p[i].c[j+4].value;
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
    if(isstraight_flush(i)&&p[i].c_high.value==0)
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
        (p[i].c_high.value==0) ? p[i].c_high.value=13 : p[i].c_high.value=p[i].c[j].value ;
        (j==3) ? (p[i].c[0].value==0) ? p[i].c_kicker.value=13 : p[i].c_kicker.value=p[i].c[2].value : p[i].c_kicker.value=p[i].c[6].value ;
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
        p[i].c_high=p[i].c[0];
        if(p[i].c[3].value==p[i].c[4].value)
        {p[i].c_kicker=p[i].c[3];
        return(true);}
        else if (p[i].c[4].value==p[i].c[5].value)
        {p[i].c_kicker=p[i].c[4];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {p[i].c_kicker=p[i].c[5];
        return(true);}
        else {}
    }
    else if(p[i].c[1].value==p[i].c[3].value)
    {
        p[i].c_high=p[i].c[1];
        if (p[i].c[4].value==p[i].c[5].value)
        {p[i].c_kicker=p[i].c[4];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {p[i].c_kicker=p[i].c[5];
        return(true);}
    }
    else if(p[i].c[2].value==p[i].c[4].value)
    {
        p[i].c_high=p[i].c[2];
        if (p[i].c[0].value==p[i].c[1].value)
        {p[i].c_kicker=p[i].c[0];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {p[i].c_kicker=p[i].c[5];
        return(true);}
    }
    else if(p[i].c[3].value==p[i].c[5].value)
    {
        p[i].c_high=p[i].c[3];
        if (p[i].c[0].value==p[i].c[1].value)
        {p[i].c_kicker=p[i].c[0];
        return(true);}
         if (p[i].c[1].value==p[i].c[2].value)
        {p[i].c_kicker=p[i].c[1];
        return(true);}
        else if (p[i].c[5].value==p[i].c[6].value)
        {p[i].c_kicker=p[i].c[5];
        return(true);}
    }
    else if(p[i].c[4].value==p[i].c[6].value)
    {
        p[i].c_high=p[i].c[4];
        if (p[i].c[0].value==p[i].c[1].value)
        {p[i].c_kicker=p[i].c[0];
        return(true);}
         if (p[i].c[1].value==p[i].c[2].value)
        {p[i].c_kicker=p[i].c[1];
        return(true);}
        else if (p[i].c[2].value==p[i].c[3].value)
        {p[i].c_kicker=p[i].c[2];
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
        (p[i].c_high.value==0) ? p[i].c_high.value=13 : p[i].c_high.value=p[i].c[j].value ;
        (j==4) ? (p[i].c[0].value==0) ? p[i].c_kicker.value=13 : p[i].c_kicker.value=p[i].c[2].value : p[i].c_kicker.value=p[i].c[6].value ;
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
               if(p[i].c_high.value<p[i].c[j].value)
                {p[i].c[j].value==0 ? p[i].c_high.value=13 : p[i].c_high.value=p[i].c[j].value;
                k++;}
               else
                {p[i].c[j].value==0 ? p[i].c_kicker.value=13 : p[i].c_kicker.value=p[i].c[j].value;
                k++;}
           }
            p[i].c[j].value==0 ? p[i].c_high.value=13 : p[i].c_high.value=p[i].c[j].value;
            p[i].c[j].value==0 ? p[i].c_kicker.value=13 : p[i].c_kicker.value=p[i].c[j].value;
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
            (p[i].c_high.value==0) ? p[i].c_high.value=13 : p[i].c_high.value=p[i].c[j].value ;
        if(j<5)
        (p[i].c[0].value==0) ? p[i].c_kicker.value=13 : p[i].c_kicker.value=p[i].c[6].value ;
        else
        (p[i].c[0].value==0) ? p[i].c_kicker.value=13 : p[i].c_kicker.value=p[i].c[4].value ;

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
        {p[i].c_high=p[i].c[0];
        p[i].c_kicker=p[i].c[6];
        return(true);}
    else
        {p[i].c_high=p[i].c[6];
        p[i].c_kicker=p[i].c[5];
        return (true);}
}

int check_hand (int i, int help)                 //determines card hand strength
{
    {
        if(isroyal_flush(i))
            return (help);
        else if (isstraight_flush(i))
        {help+=(p[i].c_high.value-100);
        return (help);}
        else if (isfour_of_a_kind(i))
         {help+=(p[i].c_high.value-200);
        return (help);}
        else if (isfull_house(i))
        {help+=(p[i].c_high.value-300);
        return (help);}
        else if (isflush(i))
        {help+=(p[i].c_high.value-400);
        return(help);}
        else if (isstraight(i))
        {help+=(p[i].c_high.value-500);
        return(help);}
        else if (isthree_of_a_kind(i))
        {help+=(p[i].c_high.value-600);
        return(help);}
        else if (is2pair(i))
        {help+=(p[i].c_high.value-700);
        return(help);}
        else if (ispair(i))
        {help+=(p[i].c_high.value-800);
        return(help);}
        else if (ishigh(i))
        {help+=(p[i].c_high.value+p[i].c_kicker.value-900);
        return(help);}
        else
        {cout<<"\n\nError deciding winner\n\n";}

    }
}

void find_winner ()              // finds the winner after evaluating check_hand ()
{
    int *score;
    int k, max_score;

    score = new int[no_of_players];   //dynamic array having score of all players


    for(i=0; i<no_of_players; i++)
    {
        help=1000;
        score[i]=check_hand(i,help);
        cout<<"\n\t"<<p[i].name<<" - "<<score[i]<<endl;
    }
    max_score=score[0];
    for(i=0; i<no_of_players; i++)
    {
        if(score[i]<score[i+1])
            {max_score=score[i+1];
            winner=p[i+1].name;}
            else if(score[i]==score[i+1])
            {max_score=score[i];
            winner=p[i].name+p[i+1].name;}

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

void play()                                 // driver code for gameplay
{
    int n=no_of_players;
    char choice;

    while(n-->0)
    {
    cout << "\n\n\t\t\tROUND "<<round<<"\n";

    set_status();
    deal_preflop();
    display_players(2);
    place_bet(round);
    deal_flop();
    display_players(5);
    place_bet(round);
    deal_turn();
    display_players(6);
    place_bet(round);
    deal_river();
    cout<<"\n\n\t\t Final card hands of all players are as follows : \n\n\t";
    display_players(7);
    place_bet(round);
    find_winner();
    pot=0;
    erase_status();
    cout<<"\n\n\tPLAY ANOTHER ROUND, Enter 'y' for YES and 'n' for NO : ";
    cin>>choice;
    if(choice=='n')
        break;
    round++;
    erase_status();
    clr_scrn();
    }

}

int main()                          // DRIVER CODE
{
    display();
    players_settings();
    play();
    return 0;
}



