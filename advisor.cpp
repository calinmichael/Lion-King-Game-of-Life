#include<iostream>
#include<string>
#include<fstream>
#include "advisor.h"
#include "player.h"

using namespace std;


Advisor :: Advisor(){
    _name = "";
    _ability = "";

};

Advisor :: Advisor(string name, string ability){
    _name = name;
    _ability = ability;
};

// set advisor name
void Advisor :: setName(string name){
    _name = name;
};

// get advisor name
string Advisor :: getName(){
    return _name;
};

// set advisor name
void Advisor :: setAbility(string ability){
    _ability = ability;
};

// get advisor name
string Advisor :: getAblility(){
    return _ability;
}

// set advisor id for later selection
void Advisor :: setId(int id){
    _identifier = id;
}

// get advisor id
int Advisor :: getId(){
    return _identifier;
}

// show all advisors initally
void Advisor :: showAllAdvisorsInit(){
    cout << "(1) Rafiki - Invisibility (the ability to become un-seen) " << endl;
    cout << "(2) Nala - Night Vision (the ability to see clearly in darkness) " << endl;
    cout << "(3) Sarabi - Energy Manipulation (the ability to shape and control the properties of energy) " << endl;
    cout << "(4) Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
    cout << "(5) Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
}

// show all advisors 
void Advisor :: showAllAdvisors(){
    cout << "(1) Rafiki - Invisibility (the ability to become un-seen) " << endl;
    cout << "(2) Nala - Night Vision (the ability to see clearly in darkness) " << endl;
    cout << "(3) Sarabi - Energy Manipulation (the ability to shape and control the properties of energy) " << endl;
    cout << "(4) Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
    cout << "(5) Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
    cout << "(6) Keep Previous Advisor" << endl;
}

// print advisor
void Advisor :: printAdvisor(){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Advisor selected : " << _name << " | " << "Advisor ability: " << _ability << endl;
}