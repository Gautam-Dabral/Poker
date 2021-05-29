#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class card
{
private :
    int v;
    int s;
public :
    void setcard (int x)                   // random integers x and y being passed as arguments
    {v=(x%13); s=(x%4);}
    card (int x)
    {cout<<"too many arguments";}
    card ()
    {}
    friend ostream& operator<<(ostream &, card);

};
ostream& operator<<(ostream& dout, card C)           //overloading operator << for card type data
    {
        dout<<C.v<<" of "<<C.s<<endl;
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
        c1.setcard(rand());
        cout<<c1;
    }

    return 0;
}
