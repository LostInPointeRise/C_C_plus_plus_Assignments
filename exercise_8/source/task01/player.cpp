#include "player.hpp"
#include <iostream>
#include <iomanip>


#define PLAYER_1_WON_MESSAGE "Player 1 (X)"
#define PLAYER_2_WON_MESSAGE "Player 2 (O)"

Player::Player(int _id){

    turn = _id;
} 

std::ostream& operator<<(std::ostream& os, const Player& player){

    return os << "Winner is: " <<  (( player.turn == 1 ) ?  PLAYER_1_WON_MESSAGE : PLAYER_2_WON_MESSAGE);
}
