#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class card
{
private :
    int v,s;
    string value, suit;
public :
    void setcard (int x)                   // random integers x and y being passed as arguments
    {v=(x%13);
     s=(x%4);
     cardname(v,s);}
    card (int x)
    {cout<<"too many arguments";}
    card ()
    {}
    void cardname(int,int);                      //declaration
    friend ostream& operator<<(ostream &, card);

};
ostream& operator<<(ostream& dout, card C)           //overloading operator << for card type data
    {
        dout<<C.value<<" of "<<C.suit<<endl;
        return(dout);
    }
    void card::cardname(int p, int q)
    {
        switch(p)
        {
        case 0 :
            {value="Ace";
            break;}
        case 1:
            {value="Two";
            break;}
        case 2 :
            {value="Three";
            break;}
        case 3 :
            {value="Four";
            break;}
        case 4 :
            {value="Five";
            break;}
        case 5 :
            {value="Six";
            break;}
        case 6 :
            {value="Seven";
            break;}
        case 7 :
            {value="Eight";
            break;}
        case 8 :
            {value="Nine";
            break;}
        case 9 :
            {value="Ten";
            break;}
        case 10 :
            {value="Jack";
            break;}
        case 11 :
            {value="Queen";
            break;}
        case 12 :
            {value="King";
            break;}
        default :
            {cout<<"error"<<endl;}
        }
        switch (q)
        {
        case 00 :
            {suit="Spades";
            break;}
        case 01 :
            {suit="Hearts";
            break;}
        case 02 :
            {suit="Diamond";
            break;}
        case 03 :
            {suit="Clubs";
            break;}
        default :
            {cout<<"error"<<endl;}

        }
    }

int main ()
{
    int seed,i,x,y;
    card c1;
    seed=time(NULL);
    srand(seed);
    for (i=0; i<5; i++)
    {
        c1.setcard(rand());
        cout<<c1;
    }

    return 0;
}
