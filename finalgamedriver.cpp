#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "player.h"
#include "tile.h"
#include "board.h"
#include "advisor.h"
#include "event.h"

using namespace std;

int main()
{
    // define everything and create objects etc:
    srand(time(0));
    string name1;
    string name2;
    string characterchoice1;
    string characterchoice2;
    Player characters;
    Player();
    Player player1;
    Player player2;
    Advisor player1advisor;
    Advisor player2advisor;
    string path1;
    string path2;
    string advisor1;
    string advisor2;
    Board();
    Board board(2);
    string input;
    string wheelInput;
    Event();
    Event positive_event_CubTraining;
    Event negative_event_CubTraining;
    Event positive_event_PrideLands;
    Event negative_event_PrideLands;
    Riddle riddle1;
    Riddle riddle2;

    // starts by introduction:
    cout << endl;
    cout << "Welcome to the game of life!" << endl;
    cout << "You are about to partake in a wonderous journey with unexpected twists and turns..." << endl;
    cout << "We hope you are prepared" << endl;
    cout << "These are the characters from which you will choose 1 for each player:" << endl;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    //shows all characters:
    characters.showAllCharacters();

    // requests user info for each player:
    cout << "Now, each player please enter your name" << endl;
    cout << "Player 1 Name: " << endl;
    cin >> name1;
    player1.setAccName(name1);

    cout << "Player 2 Name: " << endl;
    cin >> name2;
    player2.setAccName(name2);


    // character selection: 
    cout << "Player 1 Choose Your Character 1-5: " << endl;
    cin >> characterchoice1;

    while ((characterchoice1[0] != '1' && characterchoice1[0] != '2' && characterchoice1[0] != '3' && characterchoice1[0] != '4' && characterchoice1[0] != '5') || (characterchoice1.length() > 1))
    {
        cout << "Please enter a valid choice within range: " << endl;
        cin >> characterchoice1;
    }

    cout << "Player 2 Choose Your Character 1-5: " << endl;
    cin >> characterchoice2;

    while ((characterchoice2[0] != '1' && characterchoice2[0] != '2' && characterchoice2[0] != '3' && characterchoice2[0] != '4' && characterchoice2[0] != '5') || (characterchoice2 == characterchoice1) || (characterchoice2.length() > 1))
    {
        if (characterchoice1 != characterchoice2)
        {
            cout << "Please enter a valid choice within range (1-5): ";
        }
        else
        {
            cout << "Player one has already chosen that character!!" << endl;
            cout << "Please enter a valid choice (1-5) that is not the same as player 1:";
        }
        cin >> characterchoice2;
    }

    // read in text from "characters.txt":

    ifstream in_file("characters.txt");
    string text;
    if (in_file.fail())
    {
        cout << "Error opening file" << endl;
    }
    const int ARR_SIZE = 6;
    string arr[ARR_SIZE];
    char separator = '|';
    int index = 0;
    while (getline(in_file, text))
    {
        // split the text and populate array using split function:
        board.split(text, separator, arr, ARR_SIZE);
        if (index > 0)
        {
            if (index == stoi(characterchoice1))
            {
                // assigns player 1 based off of what they choose:
                player1.setName(arr[0]);
                player1.setAge(stoi(arr[1]));
                player1.setStrength(stoi(arr[2]));
                player1.setStamina(stoi(arr[3]));
                player1.setWisdom(stoi(arr[4]));
                player1.setPridePoints(stoi(arr[5]));
            }
            else if (index == stoi(characterchoice2))
            {
                // assigns player 2 based off of what they choose:
                player2.setName(arr[0]);
                player2.setAge(stoi(arr[1]));
                player2.setStrength(stoi(arr[2]));
                player2.setStamina(stoi(arr[3]));
                player2.setWisdom(stoi(arr[4]));
                player2.setPridePoints(stoi(arr[5]));
            }
        }
        index++;
    }

    // prints the stats:

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << name1 << " has selected: " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    player1.printStats();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << name2 << " has selected: " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    player2.printStats();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;


    // path selection:

    cout << "Your next task is going to be to choose which path your mammal takes" << endl;
    cout << "You have two options: (1) Cub training, (2) Straight to Pride Lands" << endl;
    cout << "Player 1: make your choice --> ";
    cin >> path1;
    while (((path1[0] != '1') && (path1[0] != '2')) || path1.length() > 1)
    {
        cout << "Please pick 1 or 2:" << endl;
        cin >> path1;
    }

    switch (stoi(path1))
    {
    case 1:
    {
        // sets stats for cub training: -5000 PridePoints, +500 Stamina, Strength, +1000 Wisdom
        player1.setkeepTrackWisdom(1000);
        player1.setkeepTrackPride(-5000);
        player1.setkeepTrackStamina(500);
        player1.setkeepTrackStrength(500);
        player1.setPridePoints(player1.getPridePoints());
        player1.setStamina(player1.getStamina());
        player1.setStrength(player1.getStrength());
        player1.setWisdom(player1.getWisdom());
        cout << "Here is a list of all advisors: " << endl;
        player1advisor.showAllAdvisorsInit();

        // advisor selection:

        cout << "Please pick your initial advisor: ";
        cin >> advisor1;
        while ((advisor1[0] != '1' && advisor1[0] != '2' && advisor1[0] != '3' && advisor1[0] != '4' && advisor1[0] != '5') || (advisor1.length() > 1))
        {
            cout << "Please enter a valid advisor (1 - 5): ";
            cin >> advisor1;
        }
        switch (stoi(advisor1))
        {
        case 1:
        {
            player1advisor.setName("Rafiki");
            player1advisor.setAbility("Invisibility");
            player1advisor.setId(1);
            break;
        }
        case 2:
        {
            player1advisor.setName("Nala");
            player1advisor.setAbility("Night Vision");
            player1advisor.setId(2);
            break;
        }
        case 3:
        {
            player1advisor.setName("Sarabi");
            player1advisor.setAbility("Energy Manipulation");
            player1advisor.setId(3);
            break;
        }
        case 4:
        {
            player1advisor.setName("Zazu");
            player1advisor.setAbility("Weather Control");
            player1advisor.setId(4);
            break;
        }
        case 5:
        {
            player1advisor.setName("Sarafina");
            player1advisor.setAbility("Super Speed");
            player1advisor.setId(5);
            break;
        }
        }
        cout << endl;
        cout << "Your new character stats are: " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        player1.printStats();
        player1advisor.printAdvisor();

        break;
    }
    case 2:
    {
        // sets stats for pride lands: +5000 PridePoints, +200 Stamina, Strength, Wisdom
        player1.setkeepTrackPride(5000);
        player1.setkeepTrackStamina(200);
        player1.setkeepTrackStrength(200);
        player1.setkeepTrackWisdom(200);
        player1.setPridePoints(player1.getPridePoints());
        player1.setStrength(player1.getStrength());
        player1.setStamina(player1.getStamina());
        player1.setWisdom(player1.getWisdom());
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Your new character stats are: " << endl;
        player1.printStats();
        player1advisor.setId(0);
        cout << "You do not get an initial advisor." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        break;
    }
    }

    // set path for player 1
    board.setPath1(stoi(path1));

    // player 2 chooses:

    cout << "Player 2: make your choice --> ";
    cin >> path2;
    while ((path2[0] != '1' && path2[0] != '2') || (path2.length() > 1))
    {
        cout << "Please pick 1 or 2:" << endl;
        cin >> path2;
    }

    switch (stoi(path2))
    {
    case 1:
    {
        // sets stats for cub training: -5000 PridePoints, +500 Strength, Stamina, +1000 wisdom:
        player2.setkeepTrackWisdom(1000);
        player2.setkeepTrackPride(-5000);
        player2.setkeepTrackStamina(500);
        player2.setkeepTrackStrength(500);
        player2.setPridePoints(player2.getPridePoints());
        player2.setStamina(player2.getStamina());
        player2.setStrength(player2.getStrength());
        player2.setWisdom(player2.getWisdom());
        cout << "Here is a list of all advisors: " << endl;
        player2advisor.showAllAdvisorsInit();

        // advisor selection:
        // choose and set

        cout << "Please pick your initial advisor: ";
        cin >> advisor2;
        while ((advisor2[0] != '1' && advisor2[0] != '2' && advisor2[0] != '3' && advisor2[0] != '4' && advisor2[0] != '5') || ( advisor1 == advisor2) || (advisor2.length() > 1))
        {
            if(advisor1 == advisor2){
                cout << "Please choose a different advisor from player 1!" << endl;
                cin >> advisor2;
            }
            else{
                cout << "Please enter a valid advisor (1 - 5): ";
                cin >> advisor2;
            }
        }
        switch (stoi(advisor2))
        {
        case 1:
        {
            player2advisor.setName("Rafiki");
            player2advisor.setAbility("Invisibility");
            player2advisor.setId(1);
            break;
        }
        case 2:
        {
            player2advisor.setName("Nala");
            player2advisor.setAbility("Night Vision");
            player2advisor.setId(2);
            break;
        }
        case 3:
        {
            player2advisor.setName("Sarabi");
            player2advisor.setAbility("Energy Manipulation");
            player2advisor.setId(3);
            break;
        }
        case 4:
        {
            player2advisor.setName("Zazu");
            player2advisor.setAbility("Weather Control");
            player2advisor.setId(4);
            break;
        }
        case 5:
        {
            player2advisor.setName("Sarafina");
            player2advisor.setAbility("Super Speed");
            player2advisor.setId(5);
            break;
        }
        }
        cout << endl;
        cout << "Your new character stats are: " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        player2.printStats();
        player2advisor.printAdvisor();
        break;
    }
    case 2:
    {
        // sets stats for pride lands: +5000 PridePoints, +200 Wisdom, Strength, Stamina:
        player2.setkeepTrackPride(5000);
        player2.setkeepTrackStamina(200);
        player2.setkeepTrackStrength(200);
        player2.setkeepTrackWisdom(200);
        player2.setPridePoints(player2.getPridePoints());
        player2.setStrength(player2.getStrength());
        player2.setStamina(player2.getStamina());
        player2.setWisdom(player2.getWisdom());
        player2.printStats();
        player2advisor.setId(0);
        break;
    }
    default:
    {
        cout << "Please enter a valid path (1 or 2): " << endl;
        cin >> path2;
    }
    }

    board.setPath2(stoi(path2));

    board.displayBoard();
    cout << endl;

    // player1 starts the game so set that equal to true:
    board.setTurn1(0);


    // while loop runs until either player 1 or player 2 has reached to or past pride rock:
    while (board.isGameOn(0) && board.getPlayerPosition(0) < 51 && board.getPlayerPosition(1) < 51)
    {
        // sets the game on to true:
        board.isGameOn(0);

        // checks condition if it is player 1 turn:
        if (board.getTurn1() == true)
        {

            // outputs a main menu for the player:
            string input;
            cout << "Player 1 its your turn to move!" << endl;
            cout << "(1) Check Player Progress: Review Pride Point and Leadership Trait stats." << endl;
            cout << "(2) Review Character: Check your character name and age." << endl;
            cout << "(3) Check Position: board details and view current position." << endl;
            cout << "(4) Review Your Advisor: Check who your current advisor is on the game." << endl;
            cout << "(5) Move Forward: For each player's turn, access this option to spin the virtual spinner." << endl;
            cout << "Your pick: ";

            // requests user input to choose 1 - 5:
            cin >> input;
            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5') || (input.length() > 1))
            {
                cout << "Please select a valid option: ";
                cin >> input;
            }
            switch (stoi(input))
            {
            case 1:
            {
                string input;
                // displays points:
                cout << "Pride Points: " << player1.getPridePoints() << endl;
                cout << "Stamina: " << player1.getStamina() << endl;
                cout << "Strength: " << player1.getStrength() << endl;
                cout << "Wisdom: " << player1.getWisdom() << endl;
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);

                break;
            }
            case 2:
            {
                // displays name and age:
                cout << "Name: " << player1.getName() << endl;
                cout << "Age: " << player1.getAge() << endl;
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                break;
            }
            case 3:
            {
                string input;
                // reverses order for visual purposes and displays player 1 position:
                if (board.getPath1() == 2 && board.getPath1() != board.getPath2())
                {   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player1.getName() << " is at position: " << board.getPlayerPosition(1) << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player1.getName() << " is at position: " << board.getPlayerPosition(0) << endl;
                }
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                cout << "Would you like to display the board? " << endl;
                cout << "(1) Yes " << endl;
                cout << "(2) No" << endl;
                cout << "Your choice: ";
                cin >> input;
                while((input[0] != '1' && input[0] != '2') || (input.length()>1)){
                    cout << "Please select a valid input (1-2): " ;
                    cin >> input;
                }
                switch(stoi(input)){
                    case 1:{
                        cout << "Here it is: " << endl;
                        board.displayBoard();
                        cout << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                    case 2: {
                        cout << "Skip" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                }
                break;
            }
            case 4:
            {
                string input;
                // diplays advisor if player 1 has one:
                if (board.getPath1() == 2)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "You dont have an advisor" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Current advisor is " << player1advisor.getName() << endl;
                    cout << "Would you like to see you advisors ability?" << endl;
                    cout << "(1) Yes" << endl;
                    cout << "(2) No" << endl;
                    cout << "Your choice: ";
                    cin >> input;
                    while((input[0] != '1' && input[0] != '2' )|| (input.length()>1)){
                        cout << "Please select a valid input (1-2): " ;
                        cin >> input;
                    }
                    switch(stoi(input)){
                        case 1:{
                            cout << player1advisor.getName() << "'s ability is: " << player1advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                        case 2:{
                            cout << "Skip" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                    }
                }
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                
                break;
            }
            case 5:
            {
                // this case is used to move player 1:
                string wheelInput;
                cout << "Player 1, to move, in order to spin the virtual wheel type any variation of 'spin': " << endl;
                cin >> wheelInput;
                while (((wheelInput[0] != 's') && (wheelInput[0] != 'S')) || ((wheelInput[1] != 'p') && (wheelInput[1] != 'P')) || ((wheelInput[2] != 'i') && (wheelInput[2] != 'I')) || ((wheelInput[3] != 'n') && (wheelInput[3] != 'N')) || wheelInput.length() > 4)
                {
                    cout << "Please enter the correct phrase: ";
                    cin >> wheelInput;
                }
                
                // use spin wheel to move player 1 a random number of tiles between 1 and 6:
                cout << "Move ";
                board.spinWheel();
                cout << " spaces." << endl;

                // if player 1 chooses path 2, move the second icon visually
                if (board.getPath1() == 2 && board.getPath1() != board.getPath2())
                {
                    board.movePlayer(1);
                }
                // else move it as normal
                else
                {
                    board.movePlayer(0);
                }
                // sets the fact that player 1 has moved:
                board.setPlayer1DidNotMove(1);
                board.displayBoard();

                // checks if player has moved:
                if (board.get1DidNotMove() == false)
                {
                    // if player has moved, check the tile color it lands on and proceed with a tile effect:
                    switch (board.getColor1())
                    {
                    case 'R':
                    {
                        // set stats for red tile
                        player1.setkeepTrackStamina(-100);
                        player1.setkeepTrackStrength(-100);
                        player1.setkeepTrackWisdom(-100);
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Red" << endl;
                        // move player backwards:
                        // reverses if player 1 picks path 2:
                        if (board.getPath1() == 2 && board.getPath1() != board.getPath2())
                        {
                            if (board.getPlayerPosition(1) > 10)
                            {
                                board.movePlayerBackwards(1);
                            }
                            else
                            {
                                board.setPlayerPosition(1);
                            }
                        }
                        else
                        {
                            if (board.getPlayerPosition(0) > 10)
                            {
                                board.movePlayerBackwards(0);
                            }
                            else
                            {

                                board.setPlayerPosition(0);
                            }
                        }

                        cout << "Uh-oh, your character has been set back, and it lost 100 strength, stamina, and wisdom points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                    }
                    case 'G':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Green" << endl;
                        // random number generator from 1-2:
                        int will_something_happen = rand() % (2) + 1;
                        cout << "Percent chance: " << will_something_happen << endl;
                        // if number is equal to 1, enter the if block:
                        if (will_something_happen == 1)
                        {
                            // read from file "random_events.txt":
                            ifstream in_file("random_events.txt");
                            if (in_file.fail())
                            {
                                cout << "Error" << endl;
                            }
                            string text;
                            char separator = '|';
                            const int ARR_SIZE = 4;
                            string arr[ARR_SIZE];
                            int index = 0;
                            // define different number generators for different cases: 

                            int odd_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (odd_rand_negative_event % 2 == 0)
                            {
                                odd_rand_negative_event++;
                            }
                            cout << "odd rand negative: " << odd_rand_negative_event << endl;
                            int even_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (even_rand_negative_event % 2 != 0)
                            {
                                even_rand_negative_event++;
                                if(even_rand_negative_event == 26){
                                    even_rand_negative_event -= 2;
                                }
                            }
                            cout << "even rand negative:" << even_rand_negative_event << endl;
                            int even_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (even_rand_positive_event % 2 != 0)
                            {
                                even_rand_positive_event++;
                                if(even_rand_positive_event == 60){
                                    even_rand_positive_event -= 2;
                                }
                            }
                            cout << "even rand positive:" << even_rand_positive_event << endl;
                            int odd_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (odd_rand_positive_event % 2 == 0)
                            {
                                odd_rand_positive_event++;
                                if(odd_rand_positive_event == 59){
                                    odd_rand_positive_event --;
                                }
                            }
                            cout << "odd rand positive: " << odd_rand_positive_event << endl;
                            // random number generator between one and 2, determining if the event will be positive or negative
                            int choose_rand_out_of_2 = rand() % (2) + 1;

                            /*cout << "1 or 2: " << choose_rand_out_of_2 << endl;*/
                            // checks player path: 
                            if (board.getPath1() == 1)
                            {
                                // positive or negative?
                                // 1 = negative, 2 = positive
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator:
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is cub training '0':
                                            if (arr[1] == "0")
                                            {
                                                if (index > 6 && index < 26)
                                                {
                                                    // select the correct event from file and set it to Event:
                                                    if (index == odd_rand_negative_event)
                                                    {
                                                        negative_event_CubTraining.whatHappens = arr[0];
                                                        negative_event_CubTraining.pathType = stoi(arr[1]);
                                                        negative_event_CubTraining.advisor = stoi(arr[2]);
                                                        negative_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }

                                        index++;
                                    }
                                    // consequence:
                                    
                                    cout << "Uh-oh, ";
                                    cout << player1.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_CubTraining.whatHappens << endl;
                                    // checks if advisors match:
                                    if (player1advisor.getId() == stoi(arr[2]))
                                    {
                                        cout << "Lucky pick, you are saved by your chosen advisor: " << player1advisor.getName() << "!!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }
                                    else
                                    {
                                        // set stats:
                                        player1.setkeepTrackPride(negative_event_CubTraining.pridePointAffect);
                                        cout << "lose " << negative_event_CubTraining.pridePointAffect << " pride points!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }

                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            if (index > 28 && index < 60)
                                            {
                                                // select the correct event from file:
                                                if (index == even_rand_positive_event)
                                                {
                                                    if (arr[1] == "0")
                                                    {
                                                        positive_event_CubTraining.whatHappens = arr[0];
                                                        positive_event_CubTraining.pathType = stoi(arr[1]);
                                                        positive_event_CubTraining.advisor = stoi(arr[2]);
                                                        positive_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }

                                        index++;
                                    }
                                    // consequence:
                                    
                                    // set stats:
                                    player1.setkeepTrackPride(positive_event_CubTraining.pridePointAffect);
                                    cout << "Nice, ";
                                    cout << player1.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_CubTraining.whatHappens << endl;
                                    cout << "win " << positive_event_CubTraining.pridePointAffect << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                }
                            }
                            else if (board.getPath1() == 2)
                            {
                                // positive or negative
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 5 && index < 26)
                                                {
                                                    // select the correct event from file:
                                                    if (index == even_rand_negative_event)
                                                    {
                                                        negative_event_PrideLands.whatHappens = arr[0];
                                                        negative_event_PrideLands.pathType = stoi(arr[1]);
                                                        negative_event_PrideLands.advisor = stoi(arr[2]);
                                                        negative_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    cout << "Uh-oh, ";
                                    cout << player1.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_PrideLands.whatHappens << endl;

                                    // set stats:
                                    player1.setkeepTrackPride(negative_event_PrideLands.pridePointAffect);
                                    cout << "lose " << negative_event_PrideLands.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 28 && index < 60)
                                                {
                                                    // select the correct event from file:
                                                    if (index == odd_rand_positive_event)
                                                    {
                                                        positive_event_PrideLands.whatHappens = arr[0];
                                                        positive_event_PrideLands.pathType = stoi(arr[1]);
                                                        positive_event_PrideLands.advisor = stoi(arr[2]);
                                                        positive_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence: 
                                    
                                    // set stats:
                                    player1.setkeepTrackPride(positive_event_PrideLands.pridePointAffect);
                                    cout << "Nice, ";
                                    cout << player1.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_PrideLands.whatHappens << endl;
                                    cout << "win " << positive_event_PrideLands.pridePointAffect << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                }
                            }
                        }
                        else
                        {
                            cout << "Nothing happens to you! Positively or Negatively" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    case 'B':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Blue" << endl;
                        cout << "Aha! A peaceful oasis... " << endl;
                        cout << "This tile allows you to spin again, and it boosts your points!" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // set stats:
                        player1.setkeepTrackStamina(200);
                        player1.setkeepTrackStrength(200);
                        player1.setkeepTrackWisdom(200);
                        // player 1 goes again
                        player1.setPlayer1GoAgain(true);
                        break;
                    }
                    case 'P':
                    {
                        string input;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Pink" << endl;
                        cout << "You have reached an advisor checkpoint! " << endl;
                        cout << "If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor" << endl;
                        
                        // set stats:
                        player1.setkeepTrackStamina(300);
                        player1.setkeepTrackStrength(300);
                        player1.setkeepTrackWisdom(300);
                        // check path:
                        if (board.getPath1() == 1)
                        {
                            // prompt player to choose:
                            player1advisor.showAllAdvisors();
                            cout << "Your choice: ";
                            cin >> input;
                            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5' && input[0] != '6') || (input.length() > 1))
                            {
                                cout << "Please select a valid choice (1-6): ";
                                cin >> input;
                            }
                            // assign:
                            switch (stoi(input))
                            {
                            case 1:
                            {
                                player1advisor.setName("Rafiki");
                                player1advisor.setAbility("Invisibility");
                                player1advisor.setId(1);
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                cout << "Your new advisor/ability is: ";
                                break;
                            }
                            case 2:
                            {
                                player1advisor.setName("Nala");
                                player1advisor.setAbility("Night Vision");
                                player1advisor.setId(2);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 3:
                            {
                                player1advisor.setName("Sarabi");
                                player1advisor.setAbility("Energy Manipulation");
                                player1advisor.setId(3);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 4:
                            {
                                player1advisor.setName("Zazu");
                                player1advisor.setAbility("Weather Control");
                                player1advisor.setId(4);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 5:
                            {
                                player1advisor.setName("Sarafina");
                                player1advisor.setAbility("Super Speed");
                                player1advisor.setId(5);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 6:
                            {
                                player1advisor.setName(player1advisor.getName());
                                player1advisor.setAbility(player1advisor.getAblility());
                                player1advisor.setId(player1advisor.getId());
                                cout << "You remain with the same advisor!" << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            }
                            cout << player1advisor.getName() << ", " << player1advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Also, your Stamina, Strength, and Wisdom Points increase by 300. " << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

                        }
                        else
                        {
                            cout << "Your Stamina, Strength, and Wisdom Points increase by 300. " << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    case 'N':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Brown" << endl;
                        cout << "Yikes! You have landed on a Hyena tile. " << endl;
                        cout << "Unfortunately, You have been mauled by the Hyenas, been brought back to your starting position, and lost 300 stamina points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // set stats:
                        player1.setkeepTrackStamina(-300);
                        // check board before moving player:
                        if (board.getPath1() == 2)
                        {
                            board.movePlayerPositionBefore(1);
                        }
                        else
                        {
                            board.movePlayerPositionBefore(0);
                        }
                        break;
                    }
                    case 'U':
                    {
                        // read in text from "riddles.txt":
                        ifstream in_file("riddles.txt");
                        string text;
                        string answer;
                        string ans;
                        int index = 0;
                        const int ARR_SIZE = 2;
                        string arr[ARR_SIZE];
                        char separator = '|';
                        int rand_num = rand() % (27) + 1;
                        if (in_file.fail())
                        {
                            cout << "Error opening file" << endl;
                        }
                        while (getline(in_file, text))
                        {
                            // split text:
                            board.split(text, separator, arr, ARR_SIZE);
                            if (index > 0)
                            {
                                // sets ans = to arr[1] which in this case is the answer for the riddle:
                                // eliminates extra whitespace at the end of the string:
                                ans = arr[1];
                                if (ans[ans.length() - 1 == ' '])
                                {
                                    ans = ans.substr(0, ans.length() - 1);
                                }
                                // assign riddle 1:
                                if (index == rand_num)
                                {
                                    riddle1.question = arr[0];
                                    riddle1.answer = ans;
                                }
                            }
                            index++;
                        } 
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Purple" << endl;
                        cout << "You have landed on a challenge tile" << endl;
                        cout << "You are tasked with answering the riddle. Answer correctly, and you will receive 500 pridepoints. Otherwise its the next players turn." << endl;
                        cout << "Your riddle: " << riddle1.question << endl;
                        /*for (int i = 0; i < riddle1.answer.length(); i++)
                        {
                            cout << "i: [" << i << "] " << riddle1.answer[i] << endl;
                        }*/
                        cout << "Your answer: ";
                        cin >> answer;
                        if (answer == riddle1.answer)
                        {
                            // set stats if correct:
                            player1.setkeepTrackPride(500);
                            cout << "Nice, you answered correctly!" << endl;
                            cout << "+500 pride points" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "That's incorrect, the correct answer was: " << riddle1.answer << endl;
                            cout << "Turn is over." << endl; 
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    }
                }

                // set stats for player 1 alltogether after player 1 turn:
                player1.setPridePoints(player1.getPridePoints());
                player1.setStrength(player1.getStrength());
                player1.setStamina(player1.getStamina());
                player1.setWisdom(player1.getWisdom());
                // checks conditions to conserve turn overs:
                if (board.getColor1() == 'B')
                {
                    // if tile color for player 2 is blue or player 2 did not move:
                    // set turn 1 true again:
                    board.setTurn1(0);
                    // set turn 2 false:
                    board.setTurn2(0);
                }
                else if (board.get1DidNotMove() == true)
                {
                    board.setTurn1(0);
                    board.setTurn2(0);
                }
                else
                {
                    // set turn 1 false:
                    board.setTurn1(1);
                    // set turn 2 true:
                    board.setTurn2(1);
                }

                break;
            }
            }
        }

        // checks condition if it is player 2 turn:
        else if (board.getTurn2() == true)
        {
            // outputs a meny for the player:
            string input;
            cout << "Player 2 its your turn to move!" << endl;
            cout << "(1) Check Player Progress: Review Pride Point and Leadership Trait stats." << endl;
            cout << "(2) Review Character: Check your character name and age." << endl;
            cout << "(3) Check Position: Display board to view current position." << endl;
            cout << "(4) Review Your Advisor: Check who your current advisor is on the game." << endl;
            cout << "(5) Move Forward: For each player's turn, access this option to spin the virtual spinner." << endl;
            cout << "Your pick: ";

            // requests user input to choose 1 - 5:
            cin >> input;
            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5') || (input.length() > 1))
            {
                cout << "Please select a valid option: ";
                cin >> input;
            }
            switch (stoi(input))
            {
            case 1:
            {
                // displays points:
                cout << "Pride Points: " << player2.getPridePoints() << endl;
                cout << "Stamina: " << player2.getStamina() << endl;
                cout << "Strength: " << player2.getStrength() << endl;
                cout << "Wisdom: " << player2.getWisdom() << endl;
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                break;
            }
            case 2:
            {
                // displays name and age:
                cout << "Name: " << player2.getName() << endl;
                cout << "Age: " << player2.getAge() << endl;
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                break;
            }
            case 3:
            {
                string input;
                // reverses order for visual purposes and displays player 2 position:
                if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player2.getName() << " is at position: " << board.getPlayerPosition(0) << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player2.getName() << " is at position: " << board.getPlayerPosition(1) << endl;
                }
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                cout << "Would you like to display the board? " << endl;
                cout << "(1) Yes " << endl;
                cout << "(2) No" << endl;
                cout << "Your choice: ";
                cin >> input;
                while((input[0] != '1' && input[0] != '2') || (input.length()>1)){
                    cout << "Please select a valid input (1-2): " ;
                    cin >> input;
                }
                switch(stoi(input)){
                    case 1:{
                        cout << "Here it is: " << endl;
                        board.displayBoard();
                        cout << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                    case 2: {
                        cout << "Skip" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                }
                break;
            }
            case 4:
            {
                string input;
                // diplays advisor if player 2 has one:
                if (board.getPath2() == 2)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "You do not have an advisor." << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Current advisor is " << player2advisor.getName() << endl;
                    cout << "Would you like to see you advisors ability?" << endl;
                    cout << "(1) Yes" << endl;
                    cout << "(2) No" << endl;
                    cout << "Your choice: ";
                    cin >> input;
                    while((input[0] != '1' && input[0] != '2' )|| (input.length()>1)){
                        cout << "Please select a valid input (1-2): " ;
                        cin >> input;
                    }
                    switch(stoi(input)){
                        case 1:{
                            cout << player2advisor.getName() << "'s ability is: " << player2advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                        case 2:{
                            cout << "Skip" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                    }
                }
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                break;
            }
            case 5:
            {
                // this case is used to move player 2:
                string wheelInput;
                cout << "Player 2, to move, in order to spin the virtual wheel type any variation of 'spin': " << endl;
                cin >> wheelInput;
                while (((wheelInput[0] != 's') && (wheelInput[0] != 'S')) || ((wheelInput[1] != 'p') && (wheelInput[1] != 'P')) || ((wheelInput[2] != 'i') && (wheelInput[2] != 'I')) || ((wheelInput[3] != 'n') && (wheelInput[3] != 'N'))|| wheelInput.length() > 4)
                {
                    cout << "Please enter the correct phrase: ";
                    cin >> wheelInput;
                }
                // use spin wheel to move player 2 a random number of tiles between 1 and 6:
                cout << "Move ";
                board.spinWheel();
                cout << " spaces." << endl;

                // if player 2 chooses path 1, move the second icon visually
                if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                {
                    board.movePlayer(0);
                }
                // else move it as normal
                else
                {
                    board.movePlayer(1);
                }
                // sets the fact that player 2 has moved:
                board.setPlayer2DidNotMove(0);
                board.displayBoard();
                
                // checks if player has moved:
                if (board.get2DidNotMove() == false)
                {
                    // if player has moved, check the tile color it lands on and proceed with a tile effect:
                    switch (board.getColor2())
                    {
                    case 'R':
                    {
                        // set stats for red tile:
                        player2.setkeepTrackStamina(-100);
                        player2.setkeepTrackStrength(-100);
                        player2.setkeepTrackWisdom(-100);
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Red" << endl;
                        // move player backwards:
                        // reverses if player 2 picks path 1:
                        if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                        {
                            if (board.getPlayerPosition(0) > 10)
                            {
                                board.movePlayerBackwards(0);
                            }
                            else
                            {
                                board.setPlayerPosition(0);
                            }
                        }
                        else
                        {
                            if (board.getPlayerPosition(1) > 10)
                            {
                                board.movePlayerBackwards(1);
                            }
                            else
                            {
                                board.setPlayerPosition(1);
                            }
                        }

                        cout << "Uh-oh, your character has been set back, and it lost 100 strength, stamina, and wisdom points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                    }
                    case 'G':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Green" << endl;
                        // random number generator from 1 - 2:
                        int will_something_happen = rand() % (2) + 1;
                        cout << "Percent chance: " << will_something_happen << endl;
                        // if number is equal to 1, enter the if block:
                        if (will_something_happen == 1)
                        {
                            // read from file "random_events.txt":
                            ifstream in_file("random_events.txt");
                            if (in_file.fail())
                            {
                                cout << "Error" << endl;
                            }
                            string text;
                            char separator = '|';
                            const int ARR_SIZE = 4;
                            string arr[ARR_SIZE];
                            int index = 0;
                            // define different number generators for different cases: 

                            int odd_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (odd_rand_negative_event % 2 == 0)
                            {
                                odd_rand_negative_event++;
                                
                            }
                            cout << "odd_rand_negative_event: " << odd_rand_negative_event << endl;
                            
                            int even_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (even_rand_negative_event % 2 != 0)
                            {
                                even_rand_negative_event++;
                                if(even_rand_negative_event == 26){
                                    even_rand_negative_event -= 2;
                                }
                                
                            }
                            cout << "even_rand_negative_event: " << even_rand_negative_event << endl;
                            
                 
                            int even_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (even_rand_positive_event % 2 != 0)
                            {
                                even_rand_positive_event++;
                                if(even_rand_positive_event == 60){
                                    even_rand_positive_event -= 2;
                                }
                            }
                            cout << "even_rand_positive_event: " << even_rand_positive_event << endl;

                                                    
                            int odd_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (odd_rand_positive_event % 2 == 0)
                            {
                                odd_rand_positive_event++;
                            }
                            cout << "odd_rand_positive_event: " << odd_rand_positive_event << endl;

                            
                            // random number generator between one and 2, determining if the event will be positive or negative:
                            int choose_rand_out_of_2 = rand() % (2) + 1;

                            /*cout << "1 or 2: " << choose_rand_out_of_2 << endl;*/
                            // checks player path 
                            if (board.getPath2() == 1)
                            {
                                // positive or negative?
                                // 1 = negative, 2 = positive
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is cub training '0':
                                            if (arr[1] == "0")
                                            {
                                                if (index > 6 && index < 26)
                                                {
                                                    // select the correct event from file:
                                                    if (index == odd_rand_negative_event)
                                                    {
                                                        negative_event_CubTraining.whatHappens = arr[0];
                                                        negative_event_CubTraining.pathType = stoi(arr[1]);
                                                        negative_event_CubTraining.advisor = stoi(arr[2]);
                                                        negative_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:

                                    cout << "Uh-oh, ";
                                    cout << player2.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_CubTraining.whatHappens << endl;
                                    // checks if advisors match:
                                    if (player2advisor.getId() == stoi(arr[2]))
                                    {
                                        cout << "Lucky pick, you are saved by your chosen advisor: " << player2advisor.getName() << "!!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }
                                    else
                                    {
                                        // set stats:
                                        player2.setkeepTrackPride(negative_event_CubTraining.pridePointAffect);
                                        cout << "lose " << negative_event_CubTraining.pridePointAffect << " pride points!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
      
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is cub training '0':
                                            if (arr[1] == "0")
                                            {
                                                if (index > 28 && index < 60)
                                                {
                                                    // select the correct event from file:
                                                    if (index == even_rand_positive_event)
                                                    {
                                                        positive_event_CubTraining.whatHappens = arr[0];
                                                        positive_event_CubTraining.pathType = stoi(arr[1]);
                                                        positive_event_CubTraining.advisor = stoi(arr[2]);
                                                        positive_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    
                                    // set stats:
                                    player2.setkeepTrackPride(positive_event_CubTraining.pridePointAffect);
                                    cout << "Nice, ";
                                    cout << player2.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_CubTraining.whatHappens << endl;
                                    cout << "win " << positive_event_CubTraining.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    
                                    break;
                                }
                                }
                            }
                            else if (board.getPath2() == 2)
                            {
                                // positive or negative
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 5 && index < 26)
                                                {
                                                    // select the correct event from file:
                                                    if (index == even_rand_negative_event)
                                                    {
                                                        negative_event_PrideLands.whatHappens = arr[0];
                                                        negative_event_PrideLands.pathType = stoi(arr[1]);
                                                        negative_event_PrideLands.advisor = stoi(arr[2]);
                                                        negative_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    cout << "Uh-oh, ";
                                    cout << player2.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_PrideLands.whatHappens << endl;

                                    // set stats:
                                    player2.setkeepTrackPride(negative_event_PrideLands.pridePointAffect);
                                    cout << "lose " << negative_event_PrideLands.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;                                       
                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 28 && index < 60)
                                                {
                                                    // select the correct event from file:
                                                    if (index == odd_rand_positive_event)
                                                    {
                                                        positive_event_PrideLands.whatHappens = arr[0];
                                                        positive_event_PrideLands.pathType = stoi(arr[1]);
                                                        positive_event_PrideLands.advisor = stoi(arr[2]);
                                                        positive_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:

                                    // set stats:
                                    player2.setkeepTrackPride(positive_event_PrideLands.pridePointAffect);

                                    cout << "Nice, ";
                                    cout << player2.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_PrideLands.whatHappens << endl;

                                    cout << "win " << positive_event_PrideLands.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                }
                            }
                        }
                        else
                        {
                            cout << "Nothing happens to you! Positively or Negatively" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    case 'B':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Blue" << endl;
                        cout << "Aha! A peaceful oasis... " << endl;
                        cout << "This tile allows you to spin again, and it boosts your points!" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << endl;
                        // set stats:
                        player2.setkeepTrackStrength(200);
                        player2.setkeepTrackStamina(200);
                        player2.setkeepTrackWisdom(200);
                        // player 2 goes again:
                        player2.setPlayer2GoAgain(true);
                        break;
                    }
                    case 'P':
                    {
                        string input;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Pink" << endl;
                        cout << "You have reached an advisor checkpoint! " << endl;
                        cout << "If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor" << endl;
                        // set stats:
                        player2.setkeepTrackStamina(300);
                        player2.setkeepTrackStrength(300);
                        player2.setkeepTrackWisdom(300);
                        // check path:
                        if (board.getPath2() == 1)
                        {
                            // prompt user to choose:
                            player2advisor.showAllAdvisors();
                            cout << "Your choice: ";
                            cin >> input;
                            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5' && input[0] != '6') || (input.length() > 1))
                            {
                                cout << "Please select a valid choice (1-6): ";
                                cin >> input;
                            }
                            // assign:
                            switch (stoi(input))
                            {
                            case 1:
                            {
                                player2advisor.setName("Rafiki");
                                player2advisor.setAbility("Invisibility");
                                player2advisor.setId(1);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 2:
                            {
                                player2advisor.setName("Nala");
                                player2advisor.setAbility("Night Vision");
                                player2advisor.setId(2);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 3:
                            {
                                player2advisor.setName("Sarabi");
                                player2advisor.setAbility("Energy Manipulation");
                                player2advisor.setId(3);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 4:
                            {
                                player2advisor.setName("Zazu");
                                player2advisor.setAbility("Weather Control");
                                player2advisor.setId(4);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 5:
                            {
                                player2advisor.setName("Sarafina");
                                player2advisor.setAbility("Super Speed");
                                player2advisor.setId(5);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 6:
                            {
                                player2advisor.setName(player2advisor.getName());
                                player2advisor.setAbility(player2advisor.getAblility());
                                player2advisor.setId(player2advisor.getId());
                                cout << "You remain with the same advisor!" << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            }
                            cout << player2advisor.getName() << ", " << player2advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Also your Stamina, Strength, and Wisdom Points increase by 300." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "Your Stamina, Strength, and Wisdom Points increase by 300." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    case 'N':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Brown" << endl;
                        cout << "Yikes! You have landed on a Hyena tile. " << endl;
                        cout << "Unfortunately, You have been mauled by the Hyenas, been brought back to your starting position, and lost 300 stamina points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // check board before moving character:
                        if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                        {
                            board.movePlayerPositionBefore(0);
                        }
                        else
                        {
                            board.movePlayerPositionBefore(1);
                        }

                        // set stats:
                        player2.setkeepTrackStamina(-300);

                        break;
                    }
                    case 'U':
                    {
                        // read in text from "riddles.txt":
                        ifstream in_file("riddles.txt");
                        string text;
                        string answer;
                        string ans;
                        string ques;
                        int index = 0;
                        const int ARR_SIZE = 2;
                        string arr[ARR_SIZE];
                        char separator = '|';
                        int rand_num = rand() % (27) + 1;
                        if (in_file.fail())
                        {
                            cout << "Error opening file" << endl;
                        }
                        while (getline(in_file, text))
                        {
                            // split text:
                            board.split(text, separator, arr, ARR_SIZE);
                            if (index > 0)
                            {
                                // sets ans = to arr[1] which in this case is the answer for the riddle:
                                // eliminates extra whitespace at the end of the string:
                                ans = arr[1];
                                if (ans[ans.length() - 1 == ' '])
                                {
                                    ans = ans.substr(0, ans.length() - 1);
                                }
                                // assign riddle 2:
                                if (index == rand_num)
                                {
                                    riddle2.question = arr[0];
                                    riddle2.answer = ans;
                                }
                            }
                            index++;
                        }
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Purple" << endl;
                        cout << "You have landed on a challenge tile" << endl;
                        cout << "You are tasked with answering the riddle. Answer correctly, and you will receive 500 pridepoints. Otherwise its the next players turn." << endl;
                        cout << "Your riddle: " << riddle2.question << endl;
                        /*for (int i = 0; i < riddle2.answer.length(); i++)
                        {
                            cout << "i: [" << i << "] " << riddle2.answer[i] << endl;
                        }*/
                        cout << "Your answer: ";
                        cin >> answer;
                        if (answer == riddle2.answer)
                        {
                            // set stats if correct:
                            player2.setkeepTrackPride(500);
                            cout << "Nice, you answered correctly!" << endl;
                            cout << "+500 pride points" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "That's incorrect, the correct answer was: " << riddle2.answer << endl;
                            cout << "Turn is over." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    }
                }

                // set stats for player 2 alltogether after player 2 turn:
                player2.setPridePoints(player2.getPridePoints());
                player2.setStrength(player2.getStrength());
                player2.setStamina(player2.getStamina());
                player2.setWisdom(player2.getWisdom());
                // checks conditions to conserve turn overs:
                if (board.getColor2() == 'B' || board.get2DidNotMove() == true)
                {
                    // if tile color for player 2 is blue or player 2 did not move:
                    // set turn 1 false: 
                    board.setTurn1(1);
                    // set turn 2 true again:
                    board.setTurn2(1);
                }
                else
                {
                    // set turn 1 true:
                    board.setTurn1(0);
                    // set turn 2 false:
                    board.setTurn2(0);
                }
                

                break;
            }
            }
        }


        // checks board path conditions:
        // if path2 = 1 and path1 = 2:
        if (board.getPath2() == 1 && board.getPath1() == 2)
        {
            if (board.getPlayerPosition(0) >= 51 && board.getPlayerPosition(0) != 0)
            {
                // set player 2 made it to pride rock to true:
                player2.setPlayermadeit(0);
            }
            else
            {
                // set player 2 made it to pride rock to false, and continue the :
                player2.setPlayermadeit(1);
            }

            if (board.getPlayerPosition(1) >= 51 && board.getPlayerPosition(1) != 0)
            {
                // set player 1 made it to pride rock to true:
                player1.setPlayermadeit(0);
            }

            else
            {
                // set player 2 made it to pride rock to false:
                player1.setPlayermadeit(1);
            }
        }

        // other cases:
        else
        {
            if (board.getPlayerPosition(0) >= 51 && board.getPlayerPosition(0) != 0)
            {
                player1.setPlayermadeit(0);
            }
            else
            {
                player1.setPlayermadeit(1);
            }

            if (board.getPlayerPosition(1) >= 51 && board.getPlayerPosition(1) != 0)
            {
                player2.setPlayermadeit(0);
            }

            else
            {
                player2.setPlayermadeit(1);
            }
        }

    }
    // end of main while loop


// separate if blocks for who makes it to pride rock first:
    // if player 1 makes it to pride rock before player 2:
    if (player1.getPlayermadeit() == true)
    {
        cout << player1.getName() << " has reached pride rock!" << endl;
        cout << "Player 2, keep going until you reach pride rock as well" << endl;
        // while loop for player 2 runs until player 2 makes it to pride rock:
        while (player2.getPlayermadeit() == false)
        {
            // outputs a meny for the player:
            string input;
            cout << "(1) Check Player Progress: Review Pride Point and Leadership Trait stats." << endl;
            cout << "(2) Review Character: Check your character name and age." << endl;
            cout << "(3) Check Position: Display board to view current position." << endl;
            cout << "(4) Review Your Advisor: Check who your current advisor is on the game." << endl;
            cout << "(5) Move Forward: For each player's turn, access this option to spin the virtual spinner." << endl;
            cout << "Your pick: ";

            // requests user input to choose 1 - 5:
            cin >> input;
            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5') || (input.length() > 1))
            {
                cout << "Please select a valid option: ";
                cin >> input;
            }
            switch (stoi(input))
            {
            case 1:
            {
                // displays points:
                cout << "Pride Points: " << player2.getPridePoints() << endl;
                cout << "Stamina: " << player2.getStamina() << endl;
                cout << "Strength: " << player2.getStrength() << endl;
                cout << "Wisdom: " << player2.getWisdom() << endl;
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                break;
            }
            case 2:
            {
                // displays name and age:
                cout << "Name: " << player2.getName() << endl;
                cout << "Age: " << player2.getAge() << endl;
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                break;
            }
            case 3:
            {
                string input;
                // reverses order for visual purposes and displays player 2 position:
                if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player2.getName() << " is at position: " << board.getPlayerPosition(0) << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player2.getName() << " is at position: " << board.getPlayerPosition(1) << endl;
                }
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                cout << "Would you like to display the board? " << endl;
                cout << "(1) Yes " << endl;
                cout << "(2) No" << endl;
                cout << "Your choice: ";
                cin >> input;
                while((input[0] != '1' && input[0] != '2' )|| (input.length()>1)){
                    cout << "Please select a valid input (1-2): " ;
                    cin >> input;
                }
                switch(stoi(input)){
                    case 1:{
                        cout << "Here it is: " << endl;
                        board.displayBoard();
                        cout << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                    case 2: {
                        cout << "Skip" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                }
                break;
            }
            case 4:
            {
                string input;
                // diplays advisor if player 2 has one:
                if (board.getPath2() == 2)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "You do not have an advisor." << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Current advisor is " << player2advisor.getName() << endl;
                    cout << "Would you like to see you advisors ability?" << endl;
                    cout << "(1) Yes" << endl;
                    cout << "(2) No" << endl;
                    cout << "Your choice: ";
                    cin >> input;
                    while((input[0] != '1' && input[0] != '2') || (input.length()>1)){
                        cout << "Please select a valid input (1-2): " ;
                        cin >> input;
                    }
                    switch(stoi(input)){
                        case 1:{
                            cout << player2advisor.getName() << "'s ability is: " << player2advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                        case 2:{
                            cout << "Skip" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                    }
                }
                // sets the fact that player 2 has not moved:
                board.setPlayer2DidNotMove(1);
                break;
            }
            case 5:
            {
                // this case is used to move player 2:
                string wheelInput;
                cout << "Player 2, to move, in order to spin the virtual wheel type any variation of 'spin': " << endl;
                cin >> wheelInput;
                while (((wheelInput[0] != 's') && (wheelInput[0] != 'S')) || ((wheelInput[1] != 'p') && (wheelInput[1] != 'P')) || ((wheelInput[2] != 'i') && (wheelInput[2] != 'I')) || ((wheelInput[3] != 'n') && (wheelInput[3] != 'N'))|| wheelInput.length() > 4)
                {
                    cout << "Please enter the correct phrase: ";
                    cin >> wheelInput;
                }
                // use spin wheel to move player 2 a random number of tiles between 1 and 6:
                cout << "Move ";
                board.spinWheel();
                cout << " spaces." << endl;

                // if player 2 chooses path 1, move the second icon visually
                if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                {
                    board.movePlayer(0);
                }
                // else move it as normal
                else
                {
                    board.movePlayer(1);
                }
                // sets the fact that player 2 has moved:
                board.setPlayer2DidNotMove(0);
                board.displayBoard();
                
                // checks if player has moved:
                if (board.get2DidNotMove() == false)
                {
                    // if player has moved, check the tile color it lands on and proceed with a tile effect:
                    switch (board.getColor2())
                    {
                    case 'R':
                    {
                        // set stats for red tile:
                        player2.setkeepTrackStamina(-100);
                        player2.setkeepTrackStrength(-100);
                        player2.setkeepTrackWisdom(-100);
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Red" << endl;
                        // move player backwards:
                        // reverses if player 2 picks path 1:
                        if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                        {
                            if (board.getPlayerPosition(0) > 10)
                            {
                                board.movePlayerBackwards(0);
                            }
                            else
                            {
                                board.setPlayerPosition(0);
                            }
                        }
                        else
                        {
                            if (board.getPlayerPosition(1) > 10)
                            {
                                board.movePlayerBackwards(1);
                            }
                            else
                            {
                                board.setPlayerPosition(1);
                            }
                        }

                        cout << "Uh-oh, your character has been set back, and it lost 100 strength, stamina, and wisdom points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                    }
                    case 'G':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Green" << endl;
                        // random number generator from 1 - 2:
                        int will_something_happen = rand() % (2) + 1;
                        cout << "Percent chance: " << will_something_happen << endl;
                        // if number is equal to 1, enter the if block:
                        if (will_something_happen == 1)
                        {
                            // read from file "random_events.txt":
                            ifstream in_file("random_events.txt");
                            if (in_file.fail())
                            {
                                cout << "Error" << endl;
                            }
                            string text;
                            char separator = '|';
                            const int ARR_SIZE = 4;
                            string arr[ARR_SIZE];
                            int index = 0;
                            
                            // define different number generators for different cases: 
                            int odd_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (odd_rand_negative_event % 2 == 0)
                            {
                                odd_rand_negative_event++;
                            }
                            /*cout << "odd_rand_negative_event: " << odd_rand_negative_event << endl;*/
                            
                            int even_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (even_rand_negative_event % 2 != 0)
                            {
                                even_rand_negative_event++;
                                if(even_rand_negative_event == 26){
                                    even_rand_negative_event -= 2;
                                }
                            }
                            /*cout << "even_rand_negative_event: " << even_rand_negative_event << endl;*/
                            
                            int even_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (even_rand_positive_event % 2 != 0)
                            {
                                even_rand_positive_event++;
                                if(even_rand_positive_event == 60){
                                    even_rand_positive_event -= 2;
                                }
                            }
                            /*cout << "even_rand_positive_event: " << even_rand_positive_event << endl;*/
                            
                            int odd_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (odd_rand_positive_event % 2 == 0)
                            {
                                odd_rand_positive_event++;
                            }
                            /*cout << "odd_rand_positive_event: " << odd_rand_positive_event << endl;*/

                            // random number generator between one and 2, determining if the event will be positive or negative:
                            int choose_rand_out_of_2 = rand() % (2) + 1;

                            /*cout << "1 or 2: " << choose_rand_out_of_2 << endl;*/
                            // checks player path:
                            if (board.getPath2() == 1)
                            {
                                // positive or negative?
                                // 1 = negative, 2 = positive
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is cub training '0':
                                            if (arr[1] == "0")
                                            {
                                                if (index > 6 && index < 26)
                                                {
                                                    if (index == odd_rand_negative_event)
                                                    {
                                                        // select the correct event from file:
                                                        negative_event_CubTraining.whatHappens = arr[0];
                                                        negative_event_CubTraining.pathType = stoi(arr[1]);
                                                        negative_event_CubTraining.advisor = stoi(arr[2]);
                                                        negative_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    cout << "Uh-oh, ";
                                    cout << player2.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_CubTraining.whatHappens << endl;
                                    // checks if advisors match:
                                    if (player2advisor.getId() == stoi(arr[2]))
                                    {
                                        cout << "Lucky pick, you are saved by your chosen advisor: " << player2advisor.getName() << "!!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }
                                    else
                                    {
                                        // set stats:
                                        player2.setkeepTrackPride(negative_event_CubTraining.pridePointAffect);
                                        cout << "lose " << negative_event_CubTraining.pridePointAffect << " pride points!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is cub training '0':
                                            if (arr[1] == "0")
                                            {
                                                if (index > 28 && index < 60)
                                                {
                                                    // select the correct event from file:
                                                    if (index == even_rand_positive_event)
                                                    {
                                                        positive_event_CubTraining.whatHappens = arr[0];
                                                        positive_event_CubTraining.pathType = stoi(arr[1]);
                                                        positive_event_CubTraining.advisor = stoi(arr[2]);
                                                        positive_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    
                                    // set stats:
                                    player2.setkeepTrackPride(positive_event_CubTraining.pridePointAffect);
                                    cout << "Nice, ";
                                    cout << player2.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_CubTraining.whatHappens << endl;
                                    cout << "win " << positive_event_CubTraining.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                
                                    break;
                                }
                                }
                            }
                            else if (board.getPath2() == 2)
                            {
                                // positive or negative
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 5 && index < 26)
                                                {
                                                    // select the correct event from file:
                                                    if (index == even_rand_negative_event)
                                                    {
                                                        negative_event_PrideLands.whatHappens = arr[0];
                                                        negative_event_PrideLands.pathType = stoi(arr[1]);
                                                        negative_event_PrideLands.advisor = stoi(arr[2]);
                                                        negative_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    cout << "Uh-oh, ";
                                    cout << player2.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_PrideLands.whatHappens << endl;

                                    // set stats:
                                    player2.setkeepTrackPride(negative_event_PrideLands.pridePointAffect);
                                    cout << "lose " << negative_event_PrideLands.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;                                       
                                    break;
                                }
                                case 2:
                                {
                                    // split text at the separator
                                    while (getline(in_file, text))
                                    {
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 28 && index < 60)
                                                {
                                                    // select the correct event from file:
                                                    if (index == odd_rand_positive_event)
                                                    {
                                                        positive_event_PrideLands.whatHappens = arr[0];
                                                        positive_event_PrideLands.pathType = stoi(arr[1]);
                                                        positive_event_PrideLands.advisor = stoi(arr[2]);
                                                        positive_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:

                                    // set stats:
                                    player2.setkeepTrackPride(positive_event_PrideLands.pridePointAffect);

                                    cout << "Nice, ";
                                    cout << player2.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_PrideLands.whatHappens << endl;

                                    cout << "win " << positive_event_PrideLands.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                }
                            }
                        }
                        else
                        {
                            cout << "Nothing happens to you! Positively or Negatively" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }

                    case 'B':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Blue" << endl;
                        cout << "Aha! A peaceful oasis... " << endl;
                        cout << "This tile allows you to spin again, and it boosts your points!" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // set stats:
                        player2.setkeepTrackStrength(200);
                        player2.setkeepTrackStamina(200);
                        player2.setkeepTrackWisdom(200);
                        
                        break;
                    }

                    case 'P':
                    {
                        string input;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Pink" << endl;
                        cout << "You have reached an advisor checkpoint! " << endl;
                        cout << "If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor" << endl;
                        // set stats:
                        player2.setkeepTrackStamina(300);
                        player2.setkeepTrackStrength(300);
                        player2.setkeepTrackWisdom(300);
                        // check path:
                        if (board.getPath2() == 1)
                        {
                            // prompt user to choose:
                            player2advisor.showAllAdvisors();
                            cout << "Your choice: ";
                            cin >> input;
                            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5' && input[0] != '6') || (input.length() > 1))
                            {
                                cout << "Please select a valid choice (1-6): ";
                                cin >> input;
                            }
                            // assign:
                            switch (stoi(input))
                            {
                            case 1:
                            {
                                player2advisor.setName("Rafiki");
                                player2advisor.setAbility("Invisibility");
                                player2advisor.setId(1);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 2:
                            {
                                player2advisor.setName("Nala");
                                player2advisor.setAbility("Night Vision");
                                player2advisor.setId(2);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 3:
                            {
                                player2advisor.setName("Sarabi");
                                player2advisor.setAbility("Energy Manipulation");
                                player2advisor.setId(3);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 4:
                            {
                                player2advisor.setName("Zazu");
                                player2advisor.setAbility("Weather Control");
                                player2advisor.setId(4);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 5:
                            {
                                player2advisor.setName("Sarafina");
                                player2advisor.setAbility("Super Speed");
                                player2advisor.setId(5);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 6:
                            {
                                player2advisor.setName(player2advisor.getName());
                                player2advisor.setAbility(player2advisor.getAblility());
                                player2advisor.setId(player2advisor.getId());
                                cout << "You remain with the same advisor!" << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            }
                            cout << player2advisor.getName() << ", " << player2advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Also your Stamina, Strength, and Wisdom Points increase by 300." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "Your Stamina, Strength, and Wisdom Points increase by 300." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }

                    case 'N':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Brown" << endl;
                        cout << "Yikes! You have landed on a Hyena tile. " << endl;
                        cout << "Unfortunately, You have been mauled by the Hyenas, been brought back to your starting position, and lost 300 stamina points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // check board before moving character:
                        if (board.getPath2() == 1 && board.getPath1() != board.getPath2())
                        {
                            board.movePlayerPositionBefore(0);
                        }
                        else
                        {
                            board.movePlayerPositionBefore(1);
                        }

                        // set stats:
                        player2.setkeepTrackStamina(-300);
                        break;
                    }

                    case 'U':
                    {
                        // read in text from "riddles.txt":
                        ifstream in_file("riddles.txt");
                        string text;
                        string answer;
                        string ans;
                        string ques;
                        int index = 0;
                        const int ARR_SIZE = 2;
                        string arr[ARR_SIZE];
                        char separator = '|';
                        int rand_num = rand() % (27) + 1;
                        if (in_file.fail())
                        {
                            cout << "Error opening file" << endl;
                        }
                        while (getline(in_file, text))
                        {
                            // split text:
                            board.split(text, separator, arr, ARR_SIZE);
                            if (index > 0)
                            {
                                // sets ans = to arr[1] which in this case is the answer for the riddle:
                                // eliminates extra whitespace at the end of the string:
                                ans = arr[1];
                                if (ans[ans.length() - 1 == ' '])
                                {
                                    ans = ans.substr(0, ans.length() - 1);
                                }
                                // assign riddle 2:
                                if (index == rand_num)
                                {
                                    riddle2.question = arr[0];
                                    riddle2.answer = ans;
                                }
                            }
                            index++;
                        }
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Purple" << endl;
                        cout << "You have landed on a challenge tile" << endl;
                        cout << "You are tasked with answering the riddle. Answer correctly, and you will receive 500 pridepoints. Otherwise its the next players turn." << endl;
                        cout << "Your riddle: " << riddle2.question << endl;
                        /*for (int i = 0; i < riddle2.answer.length(); i++)
                        {
                            cout << "i: [" << i << "] " << riddle2.answer[i] << endl;
                        }*/
                        cout << "Your answer: ";
                        cin >> answer;
                        if (answer == riddle2.answer)
                        {
                            // set stats if correct:
                            player2.setkeepTrackPride(500);
                            cout << "Nice, you answered correctly!" << endl;
                            cout << "+500 pride points" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "That's incorrect, the correct answer was: " << riddle2.answer << endl;
                            cout << "Turn is over." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    }
                }

                // set stats for player 2 alltogether after 1 loop thru:
                player2.setPridePoints(player2.getPridePoints());
                player2.setStrength(player2.getStrength());
                player2.setStamina(player2.getStamina());
                player2.setWisdom(player2.getWisdom());

                // checks board path conditions:
                // if path2 = 1 and path1 = 2:
                if (board.getPath1() == 2 && board.getPath2() == 1)
            {
                if (board.getPlayerPosition(0) >= 51)
                {
                    // set player 2 made it to pride rock to true:
                    player2.setPlayermadeit(0);
                }
                else
                {
                    // set player 2 made it to pride rock to false:
                    player2.setPlayermadeit(1);
                }
            }
            else
            {
                if (board.getPlayerPosition(1) >= 51)
                {
                    // set player 2 made it to pride rock to true:
                    player2.setPlayermadeit(0);
                }
                else
                {
                    // set player 2 made it to pride rock to false:
                    player2.setPlayermadeit(1);
                }
            }
                break;
            }
            }

            
        }
    }

    // if player 2 makes it to pride rock before player 1:
    else if (player2.getPlayermadeit() == true)
    {
        cout << player2.getName() << " has reached pride rock!" << endl;
        cout << "Player 1, Keep goint until you reach pride rock as well" << endl;
        // while loop for player 1 runs until player 1 makes it to pride rock:
        while (player1.getPlayermadeit() == false)
        {
            // outputs a meny for the player:
            string input;
            cout << "(1) Check Player Progress: Review Pride Point and Leadership Trait stats." << endl;
            cout << "(2) Review Character: Check your character name and age." << endl;
            cout << "(3) Check Position: Display board to view current position." << endl;
            cout << "(4) Review Your Advisor: Check who your current advisor is on the game." << endl;
            cout << "(5) Move Forward: For each player's turn, access this option to spin the virtual spinner." << endl;
            cout << "Your pick: ";
            // requests user input to choose 1 - 5:
            cin >> input;
            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5') || (input.length() > 1))
            {
                cout << "Please select a valid option: ";
                cin >> input;
            }
            switch (stoi(input))
            {
            case 1:
            {
                // displays points:
                cout << "Pride Points: " << player1.getPridePoints() << endl;
                cout << "Stamina: " << player1.getStamina() << endl;
                cout << "Strength: " << player1.getStrength() << endl;
                cout << "Wisdom: " << player1.getWisdom() << endl;
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                break;
            }
            case 2:
            {
                // displays name and age:
                cout << "Name: " << player1.getName() << endl;
                cout << "Age: " << player1.getAge() << endl;
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                break;
            }
            case 3:
            {   
                string input;
                // reverses order for visual purposes and displays player 2 position:
                if (board.getPath1() == 2 && board.getPath1() != board.getPath2())
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player1.getName() << " is at position: " << board.getPlayerPosition(1) << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << player1.getName() << " is at position: " << board.getPlayerPosition(0) << endl;
                }
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                cout << "Would you like to display the board? " << endl;
                cout << "(1) Yes " << endl;
                cout << "(2) No" << endl;
                cout << "Your choice: ";
                cin >> input;
                while((input[0] != '1' && input[0] != '2') || (input.length()>1)){
                    cout << "Please select a valid input (1-2): " ;
                    cin >> input;
                }
                switch(stoi(input)){
                    case 1:{
                        cout << "Here it is: " << endl;
                        board.displayBoard();
                        cout << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                    case 2: {
                        cout << "Skip" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    break;
                    }
                }
                break;
            }
            case 4:
            {
                string input;
                // diplays advisor if player 1 has one:
                if (board.getPath1() == 2)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "You dont have an advisor" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
                else
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Current advisor is " << player1advisor.getName() << endl;
                    cout << "Would you like to see you advisors ability?" << endl;
                    cout << "(1) Yes" << endl;
                    cout << "(2) No" << endl;
                    cout << "Your choice: ";
                    cin >> input;
                    while((input[0] != '1' && input[0] != '2') || (input.length()>1)){
                        cout << "Please select a valid input (1-2): " ;
                        cin >> input;
                    }
                    switch(stoi(input)){
                        case 1:{
                            cout << player1advisor.getName() << "'s ability is: " << player1advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                        case 2:{
                            cout << "Skip" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                        }
                    }
                }
                // sets the fact that player 1 has not moved:
                board.setPlayer1DidNotMove(0);
                break;
            }
            case 5:
            {
                // this case is used to move player 1:
                string wheelInput;
                cout << "Player 1, to move, in order to spin the virtual wheel type any variation of 'spin': " << endl;
                cin >> wheelInput;
                while (((wheelInput[0] != 's') && (wheelInput[0] != 'S')) || ((wheelInput[1] != 'p') && (wheelInput[1] != 'P')) || ((wheelInput[2] != 'i') && (wheelInput[2] != 'I')) || ((wheelInput[3] != 'n') && (wheelInput[3] != 'N'))|| wheelInput.length() > 4)
                {
                    cout << "Please enter the correct phrase: ";
                    cin >> wheelInput;
                }
                // use spin wheel to move player 1 a random number of tiles between 1 and 6:
                cout << "Move ";
                board.spinWheel();
                cout << " spaces." << endl;

                // if player 1 chooses path 2, move the second icon visually
                if (board.getPath1() == 2 && board.getPath1() != board.getPath2())
                {
                    board.movePlayer(1);
                }
                // else move it as normal
                else
                {
                    board.movePlayer(0);
                }
                // sets the fact that player 1 has moved:
                board.setPlayer1DidNotMove(1);
                board.displayBoard();

                // checks if player has moved:
                if (board.get1DidNotMove() == false)
                {
                    // if player has moved, check the tile color it lands on and proceed with a tile effect:
                    switch (board.getColor1())
                    {
                    case 'R':
                    {
                        // set stats for red tile
                        player1.setkeepTrackStamina(-100);
                        player1.setkeepTrackStrength(-100);
                        player1.setkeepTrackWisdom(-100);
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Red" << endl;
                        // move player backwards:
                        // reverses if player 1 picks path 2:
                        if (board.getPath1() == 2 && board.getPath1() != board.getPath2())
                        {
                            if (board.getPlayerPosition(1) > 10)
                            {
                                board.movePlayerBackwards(1);
                            }
                            else
                            {
                                board.setPlayerPosition(1);
                            }
                        }
                        else
                        {
                            if (board.getPlayerPosition(0) > 10)
                            {
                                board.movePlayerBackwards(0);
                            }
                            else
                            {

                                board.setPlayerPosition(0);
                            }
                        }

                        cout << "Uh-oh, your character has been set back, and it lost 100 strength, stamina, and wisdom points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        break;
                    }
                    case 'G':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Green" << endl;
                        // random number generator from 1-2:
                        int will_something_happen = rand() % (2) + 1;
                        cout << "Percent chance: " << will_something_happen << endl;
                        // if number is equal to 1, enter the if block:
                        if (will_something_happen == 1)
                        {
                            // read from file "random_events.txt":
                            ifstream in_file("random_events.txt");
                            if (in_file.fail())
                            {
                                cout << "Error" << endl;
                            }
                            string text;
                            char separator = '|';
                            const int ARR_SIZE = 4;
                            string arr[ARR_SIZE];
                            int index = 0;
                            // define different number generators for different cases: 

                            int odd_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (odd_rand_negative_event % 2 == 0)
                            {
                                odd_rand_negative_event++;
                            }
                            int even_rand_negative_event = 6 + rand() % (25 - 6 + 1);
                            if (even_rand_negative_event % 2 != 0)
                            {
                                even_rand_negative_event++;
                                if(even_rand_negative_event == 26){
                                    even_rand_negative_event -= 2;
                                }
                            }
                            int even_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (even_rand_positive_event % 2 != 0)
                            {
                                even_rand_positive_event++;
                                if(even_rand_positive_event == 60){
                                    even_rand_positive_event -= 2;
                                }
                            }
                            int odd_rand_positive_event = (rand() % (59 - 29 + 1)) + 29;
                            if (odd_rand_positive_event % 2 == 0)
                            {
                                odd_rand_positive_event++;
                            }

                            // random number generator between 1 and 2, determining if the event will be positive or negative:
                            int choose_rand_out_of_2 = rand() % (2) + 1;

                            /*cout << "1 or 2: " << choose_rand_out_of_2 << endl;*/
                            // checks player path:
                            if (board.getPath1() == 1)
                            {
                                // positive or negative?
                                // 1 = negative, 2 = positive
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator:
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is cub training '0':
                                            if (arr[1] == "0")
                                            {
                                                if (index > 6 && index < 26)
                                                {
                                                    // select the correct event from file and set it to Event:
                                                    if (index == odd_rand_negative_event)
                                                    {
                                                        negative_event_CubTraining.whatHappens = arr[0];
                                                        negative_event_CubTraining.pathType = stoi(arr[1]);
                                                        negative_event_CubTraining.advisor = stoi(arr[2]);
                                                        negative_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }

                                        index++;
                                    }
                                    // consequence:
                                    cout << "Uh-oh, ";
                                    cout << player1.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_CubTraining.whatHappens << endl;
                                    // checks if advisors match:
                                    if (player1advisor.getId() == stoi(arr[2]))
                                    {
                                        cout << "Lucky pick, you are saved by your chosen advisor: " << player1advisor.getName() << "!!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }
                                    else
                                    {
                                        // set stats:
                                        player1.setkeepTrackPride(negative_event_CubTraining.pridePointAffect);
                                        cout << "lose " << negative_event_CubTraining.pridePointAffect << " pride points!" << endl;
                                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    }

                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            if (index > 28 && index < 60)
                                            {
                                                // select the correct event from file:
                                                if (index == even_rand_positive_event)
                                                {
                                                    if (arr[1] == "0")
                                                    {
                                                        positive_event_CubTraining.whatHappens = arr[0];
                                                        positive_event_CubTraining.pathType = stoi(arr[1]);
                                                        positive_event_CubTraining.advisor = stoi(arr[2]);
                                                        positive_event_CubTraining.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }

                                        index++;
                                    }
                                    // consequence:
                                    
                                    // set stats:
                                    player1.setkeepTrackPride(positive_event_CubTraining.pridePointAffect);
                                    cout << "Nice, ";
                                    cout << player1.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_CubTraining.whatHappens << endl;
                                    cout << "win " << positive_event_CubTraining.pridePointAffect << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                }
                            }
                            else if (board.getPath1() == 2)
                            {
                                // positive or negative
                                switch (choose_rand_out_of_2)
                                {
                                case 1:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 5 && index < 26)
                                                {
                                                    // select the correct event from file:
                                                    if (index == even_rand_negative_event)
                                                    {
                                                        negative_event_PrideLands.whatHappens = arr[0];
                                                        negative_event_PrideLands.pathType = stoi(arr[1]);
                                                        negative_event_PrideLands.advisor = stoi(arr[2]);
                                                        negative_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence:
                                    cout << "Uh-oh, ";
                                    cout << player1.getName();
                                    cout << " suffers a negative event: ";
                                    cout << negative_event_PrideLands.whatHappens << endl;

                                    // set stats:
                                    player1.setkeepTrackPride(negative_event_PrideLands.pridePointAffect);
                                    cout << "lose " << negative_event_PrideLands.pridePointAffect << " pride points!" << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                case 2:
                                {
                                    while (getline(in_file, text))
                                    {
                                        // split text at the separator
                                        board.split(text, separator, arr, ARR_SIZE);
                                        for (int i = 0; i < ARR_SIZE; i++)
                                        {
                                            // if event path type is pridelands '1':
                                            if (arr[1] == "1")
                                            {
                                                if (index > 28 && index < 60)
                                                {
                                                    // select the correct event from file:
                                                    if (index == odd_rand_positive_event)
                                                    {
                                                        positive_event_PrideLands.whatHappens = arr[0];
                                                        positive_event_PrideLands.pathType = stoi(arr[1]);
                                                        positive_event_PrideLands.advisor = stoi(arr[2]);
                                                        positive_event_PrideLands.pridePointAffect = stoi(arr[3]);
                                                    }
                                                }
                                            }
                                        }
                                        index++;
                                    }
                                    // consequence: 
                                    
                                    // set stats:
                                    player1.setkeepTrackPride(positive_event_PrideLands.pridePointAffect);
                                    cout << "Nice, ";
                                    cout << player1.getName();
                                    cout << " enjoys a positive event: ";
                                    cout << positive_event_PrideLands.whatHappens << endl;
                                    cout << "win " << positive_event_PrideLands.pridePointAffect << endl;
                                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                    break;
                                }
                                }
                            }
                        }
                        else
                        {
                            cout << "Nothing happens to you! Positively or Negatively" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }

                        break;
                    }

                    case 'B':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Blue" << endl;
                        cout << "Aha! A peaceful oasis... " << endl;
                        cout << "This tile allows you to spin again, and it boosts your points!" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // set stats:
                        player1.setkeepTrackStamina(200);
                        player1.setkeepTrackStrength(200);
                        player1.setkeepTrackWisdom(200);
                        break;
                    }
                    case 'P':
                    {
                        string input;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Pink" << endl;
                        cout << "You have reached an advisor checkpoint! " << endl;
                        cout << "If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor" << endl;

                        // set stats:
                        player1.setkeepTrackStamina(300);
                        player1.setkeepTrackStrength(300);
                        player1.setkeepTrackWisdom(300);
                        // check path:
                        if (board.getPath1() == 1)
                        {
                            // prompt player to choose:
                            player1advisor.showAllAdvisors();
                            cout << "Your choice: ";
                            cin >> input;
                            while ((input[0] != '1' && input[0] != '2' && input[0] != '3' && input[0] != '4' && input[0] != '5' && input[0] != '6' )|| (input.length() > 1))
                            {
                                cout << "Please select a valid choice (1-6): ";
                                cin >> input;
                            }
                            // assign
                            switch (stoi(input))
                            {
                            case 1:
                            {
                                player1advisor.setName("Rafiki");
                                player1advisor.setAbility("Invisibility");
                                player1advisor.setId(1);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 2:
                            {
                                player1advisor.setName("Nala");
                                player1advisor.setAbility("Night Vision");
                                player1advisor.setId(2);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 3:
                            {
                                player1advisor.setName("Sarabi");
                                player1advisor.setAbility("Energy Manipulation");
                                player1advisor.setId(3);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 4:
                            {
                                player1advisor.setName("Zazu");
                                player1advisor.setAbility("Weather Control");
                                player1advisor.setId(4);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 5:
                            {
                                player1advisor.setName("Sarafina");
                                player1advisor.setAbility("Super Speed");
                                player1advisor.setId(5);
                                cout << "Your new advisor/ability is: ";
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            case 6:
                            {
                                player1advisor.setName(player1advisor.getName());
                                player1advisor.setAbility(player1advisor.getAblility());
                                player1advisor.setId(player1advisor.getId());
                                cout << "You remain with the same advisor!" << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                                break;
                            }
                            }
                            cout << player1advisor.getName() << ", " << player1advisor.getAblility() << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Also, your Stamina, Strength, and Wisdom Points increase by 300. " << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "Your Stamina, Strength, and Wisdom Points increase by 300. " << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    case 'N':
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Brown" << endl;
                        cout << "Yikes! You have landed on a Hyena tile. " << endl;
                        cout << "Unfortunately, You have been mauled by the Hyenas, been brought back to your starting position, and lost 300 stamina points." << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        // set stats:
                        player1.setkeepTrackStamina(-300);
                        // check board before moving player:
                        if (board.getPath1() == 2)
                        {
                            board.movePlayerPositionBefore(1);
                        }
                        else
                        {
                            board.movePlayerPositionBefore(0);
                        }
                        break;
                    }

                    case 'U':
                    {
                        // read in text from "riddles.txt":
                        ifstream in_file("riddles.txt");
                        string text;
                        string answer;
                        string ans;
                        int index = 0;
                        const int ARR_SIZE = 2;
                        string arr[ARR_SIZE];
                        char separator = '|';
                        int rand_num = rand() % (27) + 1;
                        if (in_file.fail())
                        {
                            cout << "Error opening file" << endl;
                        }
                        while (getline(in_file, text))
                        {
                            // split text:
                            board.split(text, separator, arr, ARR_SIZE);
                            if (index > 0)
                            {
                                // sets ans = to arr[1] which in this case is the answer for the riddle:
                                // eliminates extra whitespace at the end of the string:
                                ans = arr[1];
                                if (ans[ans.length() - 1 == ' '])
                                {
                                    ans = ans.substr(0, ans.length() - 1);
                                }
                                // assign riddle 1:
                                if (index == rand_num)
                                {
                                    riddle1.question = arr[0];
                                    riddle1.answer = ans;
                                }
                            }
                            index++;
                        }
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Current color: Purple" << endl;
                        cout << "You have landed on a challenge tile" << endl;
                        cout << "You are tasked with answering the riddle. Answer correctly, and you will receive 500 pridepoints. Otherwise its the next players turn." << endl;
                        cout << "Your riddle: " << riddle1.question << endl;
                        /*for (int i = 0; i < riddle1.answer.length(); i++)
                        {
                            cout << "i: [" << i << "] " << riddle1.answer[i] << endl;
                        }*/
                        cout << "Your answer: ";
                        cin >> answer;
                        if (answer == riddle1.answer)
                        {
                            // sets stats if correct:
                            player1.setkeepTrackPride(500);
                            cout << "Nice, you answered correctly!" << endl;
                            cout << "+500 pride points" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        else
                        {
                            cout << "That's incorrect, the correct answer was: " << riddle1.answer << endl;
                            cout << "Turn is over." << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                        break;
                    }
                    }
                }
                
                // set stats for player 1 alltogether after 1 loop thru:
                player1.setPridePoints(player1.getPridePoints());
                player1.setStrength(player1.getStrength());
                player1.setStamina(player1.getStamina());
                player1.setWisdom(player1.getWisdom());
                
                // checks board path conditions:
                // if path1 = 2 and path2 = 1:
                if (board.getPath1() == 2 && board.getPath2() == 1)
                {
                    if (board.getPlayerPosition(1) >= 51)
                    {
                        // set player 1 made it to pride rock to true:
                        player1.setPlayermadeit(0);
                    }
                    else
                    {
                        // set player 1 made it to pride rock to false:
                        player1.setPlayermadeit(1);
                    }
                }
                else
                {
                    if (board.getPlayerPosition(0) >= 51)
                    {
                        // set player 1 made it to pride rock to true:
                        player1.setPlayermadeit(0);
                    }
                    else
                    {
                        // set player 1 made it to pride rock to false:
                        player1.setPlayermadeit(1);
                    }
                }
                break;
            }

                
            }
        }
        
    }
    // player point calculation:
    int p1calc_total_strength = player1.getStrength()/100;
    int p1calc_total_stamina = player1.getStamina()/100;
    int p1calc_total_wisdom = player1.getWisdom()/100;
    p1calc_total_strength = p1calc_total_strength * 1000;
    p1calc_total_stamina = p1calc_total_stamina * 1000;
    p1calc_total_wisdom = p1calc_total_wisdom * 1000;
    int p1_pride_point_change = p1calc_total_strength + p1calc_total_stamina + p1calc_total_wisdom;
    player1.setStrength(0);
    player1.setStamina(0);
    player1.setWisdom(0);
    player1.setPridePoints(player1.getPridePoints() + p1_pride_point_change);

    int p2calc_total_strength = player2.getStrength()/100;
    int p2calc_total_stamina = player2.getStamina()/100;
    int p2calc_total_wisdom = player2.getWisdom()/100;
    p2calc_total_strength = p2calc_total_strength * 1000;
    p2calc_total_stamina = p2calc_total_stamina * 1000;
    p2calc_total_wisdom = p2calc_total_wisdom * 1000;
    int p2_pride_point_change = p2calc_total_strength + p2calc_total_stamina + p2calc_total_wisdom;
    player2.setStrength(0);
    player2.setStamina(0);
    player2.setWisdom(0);
    player2.setPridePoints(player2.getPridePoints() + p2_pride_point_change);
    
    // write to the file "player_stats.txt" displaying the winner and each players stats.
    ofstream out_file("player_stats.txt");
    if(out_file.is_open()){
        if(player1.getPridePoints() > player2.getPridePoints()){
            out_file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            out_file << player1.getAccName() << " is the winner" << endl; 
            out_file << player1.getName() << "'s stats are: " << endl;
            out_file << "Cumulative Pride Points: " << player1.getPridePoints() << endl;
            out_file << "Total Strength: " << player1.getStrength() << endl;
            out_file << "Total Stamina: " << player1.getStamina() << endl;
            out_file << "Total Wisdom: " << player1.getWisdom() << endl;
            out_file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            out_file << player2.getAccName() << ", better luck next time!" << endl; 
            out_file << player2.getName() << "'s stats are: " << endl;
            out_file << "Cumulative Pride Points: " << player2.getPridePoints() << endl;
            out_file << "Total Strength: " << player2.getStrength() << endl;
            out_file << "Total Stamina: " << player2.getStamina() << endl;
            out_file << "Total Wisdom: " << player2.getWisdom() << endl;
            out_file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
        else if(player2.getPridePoints() > player1.getPridePoints()){
            out_file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            out_file << player2.getAccName() << " is the winner" << endl; 
            out_file << player2.getName() << "'s stats are: " << endl;
            out_file << "Cumulative Pride Points: " << player2.getPridePoints() << endl;
            out_file << "Total Strength: " << player2.getStrength() << endl;
            out_file << "Total Stamina: " << player2.getStamina() << endl;
            out_file << "Total Wisdom: " << player2.getWisdom() << endl;
            out_file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            out_file << player1.getAccName() << ", better luck next time!" << endl; 
            out_file << player1.getName() << "'s stats are: " << endl;
            out_file << "Cumulative Pride Points: " << player1.getPridePoints() << endl;
            out_file << "Total Strength: " << player1.getStrength() << endl;
            out_file << "Total Stamina: " << player1.getStamina() << endl;
            out_file << "Total Wisdom: " << player1.getWisdom() << endl;
            out_file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
        out_file.close();
    }

    cout << "PLAYER 1 STATS: " << endl;
    player1.printStats();
    cout << endl;
    cout << "PLAYER 2 STATS: " << endl;
    player2.printStats();
}


