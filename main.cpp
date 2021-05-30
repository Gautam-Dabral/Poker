#include<iostream>
#include"player.cpp"
#include"play.cpp"

using namespace std;




int main()
{
    display();                                // defined in player.cpp
    players_settings();                      // defined in player.cpp
    deal_card(no_of_players);               // defined in play.cpp
    display_hands(no_of_players,names);    // defined in play.cpp
    //compare_hands(names,hand);
    return 0;
}
