#ifndef PLAYER_H
#define PLAYER_H
#include "advisor.h"
#include<iostream>
#include<string>

using namespace std;

class Player{
    
    public:
        // constructors:
        Player();
        Player(string name, int age, int strength, int stamina, int wisdom, int pride_points);
        void setAccName(string name);
        string getAccName();
        void setName(string name);
        string getName();
        void setStrength(int strength);
        int getStrength();
        void setStamina(int stamina);
        int getStamina();
        void setWisdom(int wisdom);
        int getWisdom();
        void setPridePoints(int pride_points);
        int getPridePoints();
        void setAge(int age);
        int getAge();
        void trainCub(int strength, int stamina, int wisdom);
        void toPrideLands();
        void printStats();
        int split(string input_string, char separator, string arr[], const int ARR_SIZE);
        void showAllCharacters();
        void setPlayer1GoAgain(bool num);
        bool getPlayer1GoAgain();
        void setPlayer2GoAgain(bool num);
        bool getPlayer2GoAgain();
        void setkeepTrackPride(int num);
        void setkeepTrackStrength(int num);
        void setkeepTrackStamina(int num);
        void setkeepTrackWisdom(int num);
        int getkeepTrackPride();
        int getkeepTrackStrength();
        int getkeepTrackStamina();
        int getkeepTrackWisdom();
        void setPlayermadeit(int num);
        bool getPlayermadeit();


    private:

        Advisor advisor;
        // players actual names
        string _actualname;

        // character names
        string _name;
        // stats
        int _strength;
        int _stamina;
        int _wisdom;
        int _pride_points;
        int _age;
        bool _player1GoAgain;
        bool _player2GoAgain;
        bool _playermadeit;
  
 

};

#endif