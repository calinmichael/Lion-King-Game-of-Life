#ifndef ADVISOR_H
#define ADVISOR_H

#include<iostream>
#include<string>

using namespace std;

class Advisor{
    
    public:
        // constructors
        Advisor();
        Advisor(string name, string ability);
        void setName(string name);
        string getName();
        void setAbility(string ability);
        string getAblility();
        void printAdvisor();
        void showAllAdvisorsInit();
        void showAllAdvisors();
        void setId(int id);
        int getId();
        
    private:
        // data members
        string _name;
        string _ability;
        int _identifier;

};

#endif