#include<iostream>

using namespace std;


int no_of_players;
string *names=NULL;;


void display()
{
    cout<<"\t\t\t\t";
    for(int i=0;i<38;i++)
        cout<<"*";
    cout<<"\n\n \t\t\t\t\t\t7 STUD POKER\n\n\t\t\t\t";
    for(int i=0;i<38;i++)
        cout<<"*";
}

void players_settings()
{
    int n,plyr=0;
    cout<<"\n\n\n\tEnter the no of players: ";
    cin>>no_of_players;
    names=new string[no_of_players];
    n=no_of_players;
    while(n-->0)
    {
       cout<<endl<<"\tEnter player"<<plyr+1<<" name: ";
       cin>>names[plyr];
       plyr++;
    }
    cout<<"\n\n";
    for(int i=0;i<no_of_players;i++)
        cout<<"\t\t\t"<<names[i]<<"\t\t";

    cout<<"\n\n";

}

