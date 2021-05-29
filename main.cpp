#include<iostream>
#include"E:\poker_pankaj\player.cpp"
#include"E:\poker_pankaj\play.cpp"
using namespace std;




int main()
{
    display();
    players_settings();
    deal_card(no_of_players);
    display_hands(no_of_players);
    return 0;
}
