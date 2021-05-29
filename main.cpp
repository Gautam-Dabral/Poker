#include<iostream>
#include"player.cpp"
#include"play.cpp"

using namespace std;




int main()
{
    display();
    players_settings();
    deal_card(no_of_players);
    display_hands(no_of_players,names);
    return 0;
}
