#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

//typedef enum value {ace=0,two=1,three=2,four=3,five=4,six=5,seven=6,eight=7,nine=8,ten=9,jack=10,queen=11,king=12}value;
//typedef enum suit {spades=0,hearts=1,diamonds=2,clubs=3}suit;


string suits[]={"spades","hearts","diamonds","clubs"};
string value[]={"ace","two","three","four","five","six","seven",
"eight","nine","ten","jack","queen","king"};


class card
{
private :
    string v;
    string s;
public :
    void setcard (int x)                   // random integers x and y being passed as arguments
    {
	v=value[(x%13)];
    	s=suit[(x%4)];
     }
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
    int seed,i;
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
