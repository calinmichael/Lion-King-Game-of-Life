#include<iostream>
#include<string>
#include<fstream>
#include "player.h"

using namespace std;

Player :: Player(){
    _name = "";
    _strength = 0;
    _stamina = 0;
    _wisdom = 0;
    _pride_points = 0;
    _age = 0;
};

Player :: Player(string name, int age, int strength, int stamina, int wisdom, int pride_points){
    
    _name = name;
    _age = age;
    _pride_points = 20000;

}

// set player character name 
void Player :: setName(string name){
    _name = name;
};

// return the name
string Player :: getName(){
    return _name;
};

// set player actual name
void Player :: setAccName(string name){
    _actualname = name;
};

// return the actual name
string Player :: getAccName(){
    return _actualname;
};

// set player strenth
void Player :: setStrength(int strength){
    _strength = strength;
};

// get player strength
int Player :: getStrength(){
    // default to 100 if it is below
    if(_strength < 100){
        return 100;
    }
    return _strength;
};

// set player stamina
void Player :: setStamina(int stamina){
    _stamina = stamina;
};

// get player stamina
int Player :: getStamina(){
    // default to 100 if it is below
    if(_stamina < 100){
        return 100;
    }
    return _stamina;
};

// set player wisdom
void Player :: setWisdom(int wisdom){
    _wisdom = wisdom;
};

// get player wisdom
int Player :: getWisdom(){
    // default to 100 if it is below
    if(_wisdom < 100){
        return 100;
    }
    return _wisdom;
};

// set player pride points
void Player :: setPridePoints(int pride_points){
    _pride_points = pride_points;
}

// get player pride points
int Player :: getPridePoints(){
    return _pride_points;
};

// set player age
void Player :: setAge(int age){
    _age = age;
};
    
// get player age
int Player :: getAge(){
    return _age;
};


// train cub (didnt use)
void Player :: trainCub(int strength, int stamina, int wisdom){

    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
    _pride_points = _pride_points - 5000;

};

// to pridelands(didnt use)
void Player :: toPrideLands(){
    _pride_points += 5000;
    _strength = _strength + 200;
    _wisdom = _wisdom + 200;
    _stamina = _stamina + 200; 
};

// print player stats
void Player :: printStats(){

    cout << _name << ", age " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;

};

// does player 1 go again?
void Player :: setPlayer1GoAgain(bool num){
    _player1GoAgain = num;
}

// return player
bool Player :: getPlayer1GoAgain(){
    return _player1GoAgain;
}

// does player 2 go again?
void Player :: setPlayer2GoAgain(bool num){
    _player2GoAgain = num;
}

// return player
bool Player :: getPlayer2GoAgain(){
    return _player2GoAgain;
}



// split function
int Player :: split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int count = 0;
    int index = 0;
    int pieces = 0;
    if(input_string == ""){
        return 0;
    }
    
    for(int i = 0; i < (int)input_string.length(); i++){
        if(input_string[i] == separator){
            // if the index is the separator, count ++
            arr[count] = input_string.substr(index,i-index);
            count++;
            index = i + 1;
        }
        if(count == ARR_SIZE){
            
            break;
        }
    }
    
    // separate the string input into separat substrings
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

// read characters from file and use split 
void Player :: showAllCharacters(){
    ifstream in_file("characters.txt");
    if(in_file.fail()){
        cout << "ERROR" << endl;
    }
    string text;
    char separator = '|';
    const int ARR_SIZE = 6;
    string arr[ARR_SIZE];
    int index = 0;
    while(getline(in_file, text)){
        if(index > 0){
            int count = 0;
            int num_splits = split(text, separator, arr, ARR_SIZE);
            for (int i = 0; i < num_splits; i++){
                
            }
            cout << "Choice " << index << ":" << endl;
            cout << arr[count] << ", " << "age " << arr[count+1] << endl;
            cout << "Strength: " << arr[count+2] << endl;
            cout << "Stamina: " << arr[count+3] << endl;
            cout << "Wisdom: " << arr[count+4] << endl;
            cout << "Pride Points: " << arr[count+5] << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
        
        index++;
        
    }
}

// set did player make it to pride rock?
void Player :: setPlayermadeit(int num){
    if(num == 0){
        _playermadeit = true;
    }
    else{
        _playermadeit = false;
    }
}

// get did player make it to pride rock?
bool Player :: getPlayermadeit(){
    return _playermadeit;
}

// set keep track of pride points
void Player :: setkeepTrackPride(int num){
    _pride_points += num;
}

// get keep track of pride points
int Player :: getkeepTrackPride(){
    return _pride_points;
}

// set keep track of strength
void Player :: setkeepTrackStrength(int num){
    _strength += num;
}

// get keep track of strength
int Player :: getkeepTrackStrength(){
    return _strength;
}

// set keep track of stamina
void Player :: setkeepTrackStamina(int num){
    _stamina += num;
}

// get keep track of stamina
int Player :: getkeepTrackStamina(){
    return _stamina;
}

// set keep track of wisdom
void Player :: setkeepTrackWisdom(int num){
    _wisdom += num;
}

// get keep track wisdom
int Player :: getkeepTrackWisdom(){
    return _wisdom;
}

