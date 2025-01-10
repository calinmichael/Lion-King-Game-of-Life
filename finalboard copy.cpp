#include "board.h"
#include "player.h"
#include "event.h"
#include "riddle.h"
#include<iostream>
#include<string>
#include<fstream>
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

using namespace std;

// initialize board using initialize tiles
void Board :: initializeBoard(){
    for(int i = 0; i < 2; i++){
        initializeTiles(i);
    }
}

#include<cstdlib>
#include<ctime>

// initialize tiles giving them a randomized effect for each tile
// assign different colors
void Board :: initializeTiles(int player_index){
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    for(int i = 0; i < total_tiles; i++){
        if(i == total_tiles - 1){
            temp.color = 'O';
        }
        else if(i == 0){
            temp.color = 'Y';
        }
        else if(green_count < 30 && rand() % (total_tiles - i) < 30 - green_count){
            temp.color = 'G';
            green_count++;
        }
        else{
            int color_choice = rand() % 5;
            switch(color_choice){
                case 0:{
                    temp.color = 'B';
                    break;
                }
                case 1:{
                    temp.color = 'P';
                    break;
                }
                case 2:{
                    temp.color = 'N';
                    break;
                }
                case 3:{
                    temp.color = 'R';
                    break;
                }
                case 4:{
                    temp.color = 'U';
                    break;
                }
            }
        }
        // go through each index and add a color
        _tiles[player_index][i] = temp;
    }
}

// constructor
Board :: Board(){
    _player_count = 1;
    _player_position[0] = 0;
    initializeTiles(0);
}

// set each player at the beginning
Board :: Board(int player_count){
    if(player_count > _MAX_PLAYERS){
        _player_count = _MAX_PLAYERS;
    }
    else{
        _player_count = player_count;
    }
    for(int i = 0; i < _player_count; i++){
        _player_position[i] = 0;
    }
    initializeBoard();
}

// path choice player 1
void Board :: setPath1(int path1){
    _path1 = path1;
}

int Board :: getPath1(){
    return _path1;
}

// path choice player 2
void Board :: setPath2(int path2){
    _path2 = path2;
}

int Board :: getPath2(){
    return _path2;
}

// checks if player is on the tile
bool Board :: isPlayerOnTile(int player_index, int pos){
    if(_player_position[player_index] == pos){
        return true;
    }
    return false;
}

// is game running
bool Board :: isGameOn(int num){
    if(num == 0){
        return true;
    }
    return false;
}

// are both players on the same tile?
bool Board :: isPlayerOnSameTile(){
    if(_path1 == _path2){
        if(_player_position[0] == _player_position[1]){
            return true;
        }
    }
    return false;
}

// is path 1 equal to path 2?
bool Board :: arePathsEqual(){
    if(_path1 == _path2){
        return true;
    }
    return false;
}

//display tile
void Board :: displayTile(int player_index, int pos){
    string color = "";
    int players = isPlayerOnTile(player_index, pos);
    int isPlayer1OnTile = isPlayerOnTile(0, pos);
    int isPlayer2OnTile = isPlayerOnTile(1, pos);
    int playerstat = isPlayerOnSameTile();
    int pathstat = arePathsEqual();

    // checks if the player is on the color red
    // sets current color for both players equal to red
    if(_tiles[player_index][pos].color == 'R'){
        color = RED;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'R';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'R';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'R';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'R';
                    }
                }
            }
        }

        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        
                            if(getTurn2() == true){
                                _current_color2 = 'R';
                            }
                        
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                     
                            if(getTurn1() == true){
                                _current_color1 = 'R';
                            }
                       
                        
                    }
                }
            }
            else{
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'R';
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        _current_color2 = 'R';
                    }
                }
            }
            
        }
    }

    // checks if the player is on the color green
    // sets current color for both players equal to green
    else if (_tiles[player_index][pos].color == 'G'){
        color = GREEN;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'G';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'G';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'G';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'G';
                    }
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getTurn2() == true){
                           
                            _current_color2 = 'G';
                        
                        }
                        
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        if(getTurn1() == true){
                            
                            _current_color1 = 'G';
                        
                        }
                        
                    }
                }
            }
            else{
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'G';
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        _current_color2 = 'G';
                    }
                } 
            }
            
        }
    
         
    }
    // checks if the player is on the color blue
    // sets current color for both players equal to blue
    else if (_tiles[player_index][pos].color == 'B'){
        color = BLUE;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'B';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'B';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'B';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'B';
                    }
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getTurn2() == true){
                            
                                _current_color2 = 'B';
                            
                        }
                        
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        if(getTurn1() == true){
                            
                                _current_color1 = 'B';
                            
                              
                            
                        }
                        
                    }
                }
            }
            else{
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'B';
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        _current_color2 = 'B';
                    }
                }
            }
            
        }
    
    }

    // checks if the player is on the color purple
    // sets current color for both players equal to purple
    else if (_tiles[player_index][pos].color == 'U'){
        color = PURPLE;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'U';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'U';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'U';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'U';
                    }
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getTurn2() == true){
                            _current_color2 = 'U';
                        }
                        
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        if(getTurn1() == true){

                            _current_color1 = 'U';
                        
                        }
                        
                    }
                }
            }
            else{
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'U';
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        _current_color2 = 'U';
                    }
                }
            }
            
        }  
    }
    // checks if the player is on the color brown
    // sets current color for both players equal to brown
    else if (_tiles[player_index][pos].color == 'N'){
        color = BROWN;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'N';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'N';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'N';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'N';
                    }
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getTurn2() == true){
                            _current_color2 = 'N';
                        }
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                            _current_color1 = 'N';
                        
                        
                        
                    }
                }
            }
            else{
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'N';
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        _current_color2 = 'N';
                    }
                }
            }
            
        }
        
    }

    // checks if the player is on the color pink
    // sets current color for both players equal to pink
    else if (_tiles[player_index][pos].color == 'P'){
        color = PINK;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'P';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'P';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'P';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'P';
                    }
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getTurn2() == true){
                            
                
                            _current_color2 = 'P';

                        }
                        
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        if(getTurn1() == true){
                           
        
                            _current_color1 = 'P';
                        
                        }
                        
                    }
                }
            }
            else{
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'P';
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        _current_color2 = 'P';
                    }
                }
            }
            
        }
        
        
    }

    // checks if the player is on the color orange
    // sets current color for both players equal to orange
    else if (_tiles[player_index][pos].color == 'O'){
        color = ORANGE;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'O';
                    }
                    
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'O';
                    }
                   
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'O';
                    }
                    
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'O';
                    }
                    
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getPlayerPosition(0) == getPlayerPosition(1))
                        {
     
                            _current_color2 = 'O';
                        }
                        else{
                            _current_color2 = 'O';
                        }
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        if(getPlayerPosition(0) == getPlayerPosition(1)){
           
                            _current_color1 = 'O';
                        }
                        else{
                            _current_color1 = 'O';
                        }
                    }
                }
            }
            else{
                if(player_index == 0){
                if(isPlayer1OnTile == true){
                    _current_color1 = 'O';
                }
                
            
            }
            else if(player_index == 1){
                if(isPlayer2OnTile == true){
                    _current_color2 = 'O';
                }
            }
            }
            
        }

       
        
    }
    // checks if the player is on the color grey
    // sets current color for both players equal to grey
    else if (_tiles[player_index][pos].color == 'Y'){
        color = GREY;
        if(pathstat == true){
            if(_path1 == 1){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'Y';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'Y';
                    }
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    if(isPlayer1OnTile == true){
                        _current_color1 = 'Y';
                    }
                    else if(isPlayer2OnTile == true){
                        _current_color2 = 'Y';
                    }
                }
            }
        }
        else{
            if(_path2 == 1 && _path1 == 2){
                if(player_index == 0){
                    if(isPlayer1OnTile == true){
                        if(getPlayerPosition(0) == getPlayerPosition(1))
                        {
           
                            _current_color2 = 'Y';
                        }
                        else{
                            _current_color2 = 'Y';
                        }
                    }
                }
                else if(player_index == 1){
                    if(isPlayer2OnTile == true){
                        if(getPlayerPosition(0) == getPlayerPosition(1)){
             
                            _current_color1 = 'Y';
                        }
                        else{
                            _current_color1 = 'Y';
                        }
                    }
                }
            }
            else{
                if(player_index == 0){
                if(isPlayer1OnTile == true){
                    _current_color1 = 'Y';
                }
            }
            else if(player_index == 1){
                if(isPlayer2OnTile == true){
                    _current_color2 = 'Y';
                }
            }
            }
            
        }

    }

    // display both characters on the same tile at the same time
    if(players == true && playerstat == true){
        if(pos == 0){
            if(_path1 == 1){
                if(player_index == 0){
                    cout << color << "|1&2|" << RESET;
                }
                else{
                    cout << color << "|  |" << RESET;
                }
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    cout << color << "|1&2|" << RESET;
                }
                else{
                    cout << color << "|  |" << RESET;
                }
            }
        }
        else if(pos > 0){
            if(_path1 == 1){
                if(player_index == 0){
                    cout << color << "|1&2|" << RESET;
                    _current_color2 = _current_color1;
                }
                else{
                    cout << color << "| |" << RESET;
                }
                
            
            }
            else if(_path1 == 2){
                if(player_index == 1){
                    cout << color << "|1&2|" << RESET;
                    _current_color2 = _current_color1;
                }
                else{
                    cout << color << "| |" << RESET;
                }
            }
        }
    }

    // display each character individually
    else if(players == true && pathstat == false){
        if(_path1 == 2){
            if(_path2 == 1){
                if(player_index == 0){
                    cout << color << "|" << player_index + 2 << "|" << RESET;
                }
                else if(player_index == 1){
                    cout << color << "|" << (player_index) << "|" << RESET;
                }  
            }
        }
        else if(_path1 == 1){
            if(_path2 == 2){
                if(player_index == 0){
                    cout << color << "|" << player_index + 1 << "|" << RESET;
                }
                else if(player_index == 1){
                    cout << color << "|" << player_index + 1 << "|" << RESET;
                }
            }
        }
        
    }

    // display player 1
    else if(isPlayer1OnTile == true && pathstat == true){
        if(_path1 == 1){
            if(player_index == 0){
                cout << color << "|" << (player_index + 1) << "|" << RESET;
            }
            else{
                cout << color << "| |" << RESET;
            }
        }
        else if(_path1 == 2){
            if(player_index == 1){
                
                cout << color << "|" << (player_index) << "|" << RESET;
      
            }
            else{
                cout << color << "| |" << RESET;
            }
        }
        
    }

    // display player 2
    else if(isPlayer2OnTile == true && pathstat == true){
        if(_path1 == 1){
            if(player_index == 0){
                
                cout << color << "|" << (player_index + 2) << "|" << RESET;
 
            }
            else{
                cout << color << "| |" << RESET;
            }
        }
        else if(_path1 == 2){
            if(player_index == 1){
                cout << color << "|" << (player_index + 1) << "|" << RESET;
            }
        }
    }
    else {
        cout << color << "| |" << RESET;
    }

    // sets position for player 1 to 51 if it is greater than 51 to show the player on the orange tile
    if(_player_position[0] > 51){
        _player_position[0] = 51;
    }

    // sets position for player 2 to 51 if it is greater than 51 to show the player on the orange tile
    else if(_player_position[1] > 51){
        _player_position[1] = 51;
    }
     
    // sets color for player 1 to orange if it is greater than 51 to show the player on the orange tile
    if(_player_position[0] > 51){
        _current_color1 = 'O';
    }

    // sets color for player 2 to orange if it is greater than 51 to show the player on the orange tile
    else if(_player_position[1] > 51){
        _current_color2 = 'O';
    }


}

// display track up until 51 tiles
void Board :: displayTrack(int player_index){
    for(int i = 0; i < _BOARD_SIZE; i++){
        displayTile(player_index, i);
    }
    cout << endl;
}

// display both tiles
void Board :: displayBoard(){
    for(int i = 0; i < 2; i++){
        displayTrack(i);
        if(i == 0){
            cout << endl;
        }
    }
}


// spin wheel function
void Board :: spinWheel(){
    int ran_num = rand() % (6 + 1 - 1) + 1;
    _increment = ran_num;
    cout << ran_num;
}

// increment player position based on spin wheel function result
bool Board::movePlayer(int player_index){
// Increment player position
    _player_position[player_index] += _increment;
    if (_player_position[player_index] >= _BOARD_SIZE - 1){
// Player reached last tile
        return true;
    }
    return false;
}

void Board:: setTurn1(int player_index){
    // is player1 at play?
    if(player_index == 0){
        _isPlayer1Turn = true;
    }
    else{
        _isPlayer1Turn = false;
    }
}

bool Board :: getTurn1(){
    return _isPlayer1Turn;
}

void Board :: setTurn2(int player_index){
    //is player2 at play?
    if(player_index == 1){
        _isPlayer2Turn = true;
    }
    else{
        _isPlayer2Turn = false;
    }
}

bool Board :: getTurn2(){
    return _isPlayer2Turn;
}

// sets player did not move so that it is players turn until they move
void Board :: setPlayer1DidNotMove(int player_index){
    if(player_index == 0){
        _didPlayer1Move = true;
    }
    else{
        _didPlayer1Move = false;
    }
}

bool Board :: get1DidNotMove(){
    return _didPlayer1Move;
}


// sets player did not move so that it is players turn until they move
void Board :: setPlayer2DidNotMove(int player_index){
    if(player_index == 1){
        _didPlayer2Move = true;
    }
    else{
        _didPlayer2Move = false;
    }
}

bool Board :: get2DidNotMove(){
    return _didPlayer2Move;
}

// set true if position is >= 51
void Board :: setPlayer1ReachedPrideRock(int num){
    if(num == 0){
        _player1ReachPrideRock = true;
    }
    else{
        _player1ReachPrideRock = false;
    }
}

bool Board :: getPlayer1ReachedPrideRock(){
    return _player1ReachPrideRock;
}

// set true if position is >= 51
void Board :: setPlayer2ReachedPrideRock(int num){
    if(num == 1){
        _player2ReachPrideRock = true;
    }
    else{
        _player2ReachPrideRock = false;
    }
}

bool Board :: getPlayer2ReachedPrideRock(){
    return _player2ReachPrideRock;
}

// used when player reaches a red tile
bool Board :: movePlayerBackwards(int player_index){
    _player_position[player_index] -= 10;
    if(_player_position[player_index] == _BOARD_SIZE - 1){
        return true;
    }
    return false;
}

// used when player reaches brown tile
bool Board :: movePlayerPositionBefore(int player_index){
    _player_position[player_index] -= _increment;
    if(_player_position[player_index] == _BOARD_SIZE - 1){
        return true;
    }
    return false;
}


// return the player position
int Board::getPlayerPosition(int player_index) const {
    if (player_index >= 0 && player_index <= _player_count){
        return _player_position[player_index];
    }
    return -1;
}

// set player position to zero for edge cases where player lands on red tile that is less than 10 spaces ahead
void Board :: setPlayerPosition(int player_index){
    if(player_index == 0){
        _player_position[0] = 0;
    }
    else if(player_index == 1){
        _player_position[1] = 0;
    }
}

// return color 1
char Board :: getColor1(){
    return _current_color1;
}

// return color 2
char Board :: getColor2(){
    return _current_color2;
}

// split funtion
int Board :: split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int count = 0;
    int index = 0;
    int pieces = 0;
    if(input_string == ""){
        return 0;
    }
    
    for(int i = 0; i < (int)input_string.length(); i++){
        if(input_string[i] == separator){
            arr[count] = input_string.substr(index,i-index);
            count++;
            index = i + 1;
        }
        if(count == ARR_SIZE){
            
            break;
        }
    }
    
    if(count > 1 && count < ARR_SIZE){
       pieces = count + 1;
       arr[count] = input_string.substr(index, input_string.length());
       return pieces;
    }
    
    if(count == 1){
        pieces = count + 1;
        arr[count] = input_string.substr(index, input_string.length());
        
        return pieces;
    }
    
    pieces = count + 1;
    if(pieces > ARR_SIZE){
        
        return -1;
        
    }
    else if(count == 0){
        arr[0] = input_string;
        return 1;
    }
    
    else {
        return count;
    }
}



void Board :: setColor2(int num){
    if (num == 0){
        _current_color2 = _current_color1;
    }
}

