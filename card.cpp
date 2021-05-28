#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

typedef enum value {ace=0,two=1,three=2,four=3,five=4,six=5,seven=6,eight=7,nine=8,ten=9,jack=10,queen=11,king=12}value;
typedef enum suit {spades=0,hearts=1,diamonds=2,clubs=3}suit;
class card
{
private :
    value v;
    suit s;
public :
    void setcard (int x, int y)                   // random integers x and y being passed as arguments
    {v=(x%13); s=(y%4);}
    card (int x)
    {cout<<"too many arguments";}
    card ()
    {}
    friend ostream& operator<<(ostream &, card);

};
ostream& operator<<(ostream& dout, card C)           //overloading operator << for card type data
    {
        dout<<C.v<<" of "<<C.s;
        return(dout);
    }

int main ()
{
    int seed,i,x,y;
    card c1;
    seed=time(NULL);
    srand(seed);
    for (i=0; i<5; i++)
    {
        x=rand();
        y=rand();
        c1.setcard(x,y);
        cout<<c1;
    }

    return 0;
}
