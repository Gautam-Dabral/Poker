#include<iostream>
using namespace std;


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
            {cout<<"error"<<endl;}
        }
}


void get_suit_name(int q)
{

    switch (q)
        {
        case 00 :
            {cout<<"Spades";
            break;}
        case 01 :
            {cout<<"Hearts";
            break;}
        case 02 :
            {cout<<"Diamond";
            break;}
        case 03 :
            {cout<<"Clubs";
            break;}

        }
}
