#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
#include "event.h"
#include "player.h"
#include "advisor.h"
#include "riddle.h"
#include <string>
using namespace std;
class Board{

    private:
        static const int _BOARD_SIZE = 52;
        Tile _tiles[2][_BOARD_SIZE];
        static const int _MAX_PLAYERS = 2;
        int _player_count;
        int _path1;
        int _path2;
        int _increment;
        char _current_color1;
        char _current_color2;
        bool _isPlayer1Turn;
        bool _isPlayer2Turn;
        bool _didPlayer1Move;
        bool _didPlayer2Move;
        bool _player1ReachPrideRock;
        bool _player2ReachPrideRock;
        int _player_position[_MAX_PLAYERS];
        void displayTile(int player_index, int pos);
        void initializeTiles(int player_index);
        bool isPlayerOnTile(int player_index, int pos);
        bool isPlayerOnSameTile();
        bool arePathsEqual();
        
    public:
        Board();
        Board(int player_count);
        void displayTrack(int player_index);
        void initializeBoard();
        void displayBoard();
        bool movePlayer(int player_index);
        bool movePlayerBackwards(int player_index);
        bool movePlayerPositionBefore(int player_index);
        int getPlayerPosition(int player_index) const;
        void spinWheel();
        void setPath1(int path1);
        int getPath1();
        void setPath2(int path2);
        int getPath2();
        bool isGameOn(int num);
        int split(string input_string, char separator, string arr[], const int ARR_SIZE);
        void randomEvent(Player player1, Player player2, Advisor player1advisor, Advisor player2advisor, int p1keepTrackPride, int p1keepTrackStamina, int p1keepTrackStrength, int p1keepTrackWisdom, int p2keepTrackPride, int p2keepTrackStamina, int p2keepTrackStrength, int p2keepTrackWisdom);
        void randomEvent1(Player player1, Advisor player1advisor, int p1keepTrackPride, int p1keepTrackStamina, int p1keepTrackStrength, int p1keepTrackWisdom, int p2keepTrackPride, int p2keepTrackStamina, int p2keepTrackStrength, int p2keepTrackWisdom);
        void randomEvent2(Player player2, Advisor player2advisor, int p1keepTrackPride, int p1keepTrackStamina, int p1keepTrackStrength, int p1keepTrackWisdom, int p2keepTrackPride, int p2keepTrackStamina, int p2keepTrackStrength, int p2keepTrackWisdom);
        void tileEffect(Player player1, Player player2, Advisor player1advisor, Advisor player2advisor, Event positive_event_CubTraining, Event negative_event_CubTraining, Event positive_event_PrideLands, Event negative_event_PrideLands, Riddle riddle1, Riddle riddle2);
        void tileEffect1(Player player1, Advisor player1advisor, Event positive_event_CubTraining, Event negative_event_CubTraining, Event positive_event_PrideLands, Event negative_event_PrideLands,  Riddle riddle1, Riddle riddle2);
        void tileEffect2(Player player2, Advisor player2advisor, Event positive_event_CubTraining, Event negative_event_CubTraining, Event positive_event_PrideLands, Event negative_event_PrideLands,  Riddle riddle1, Riddle riddle2);
        void mainMenu1(Player player1, Advisor player1advisor, Event positive_event_CubTraining, Event negative_event_CubTraining, Event positive_event_PrideLands, Event negative_event_PrideLands, Riddle riddle1, Riddle riddle2);
        void mainMenu2(Player player2, Advisor player2advisor, Event positive_event_CubTraining, Event negative_event_CubTraining, Event positive_event_PrideLands, Event negative_event_PrideLands, Riddle riddle1, Riddle riddle2);
        void setTurn1(int player_index);
        bool getTurn1();
        void setPlayerPosition(int player_index);
        void setTurn2(int player_index);
        bool getTurn2();
        void setPlayer1DidNotMove(int player_index);
        bool get1DidNotMove();
        void setPlayer2DidNotMove(int player_index);
        bool get2DidNotMove();
        char getColor1();
        char getColor2();
        void setPlayer1ReachedPrideRock(int num);
        bool getPlayer1ReachedPrideRock();
        void setPlayer2ReachedPrideRock(int num);
        bool getPlayer2ReachedPrideRock();
        void startGame();
        void setColor2(int colo);


        
};
#endif
