
// forward class declarations
class graphPoint;
class Graph;
class Player;

// node color class
enum class nodecolor{ 
   NONE, RED, BLUE };

// the playertype definition
enum class playertype { 
   HUMAN, COMPUTER };

typedef nodecolor playercolor;    // the node colors are also the player colors
typedef unsigned int movevalue;   // the resultant value of a generic move (range is 0-worst to 100-best)


class hexGame {

 private:
   unsigned int boardsize;  // the size of the hex playing board
   Graph *pGameboard;       // the playing board itself

 public:
   hexGame(unsigned int size);
   ~hexGame();    // destructor to free up allocated resources 
   bool makeMove(unsigned int col, unsigned int row);    // returns true if move was good
   bool isMoveLegal(unsigned int col, unsigned int row);  // returns true if move is legal
   unsigned int evaluateMove(unsigned int col, unsigned int row, Player &p); // returns value of move for player p
   

};


// A generic player.  Game unknown.
class Player 
{
 protected:
   const unsigned int index;                        // the assigned index for the player (0-none)
   playertype type;                                 // the type of player (human, computer, ai)

 public:
   Player();
   virtual movevalue makeMove() = 0;                // pure virtual function for making a move
   void setPlayerIndex(unsigned int player_index);
   unsigned int getPlayerIndex();

};

// A hex game player
class HexPlayer:public Player 
{
protected:
   const playercolor playerColor;                  // playercolor::RED or playercolor::BLUE
   const hexGame *pGameBoard;                      // a pointer to the gameboard

public:
   HexPlayer(const playercolor color, const hexGame board );
   nodecolor getPlayerColor();
   virtual movevalue makeMove();                   // makes a move appropriate to this player and returns the value
   
};

// A computer hex game player
class ComputerHexPlayer:public HexPlayer
{

 public:
   ComputerHexPlayer(const playercolor color, const hexGame board );
   virtual movevalue makeMove();       // makes a move appropriate for a computer player and returns the value
   
};

// a human hex game player
class HumanHexPlayer:public HexPlayer
{

 public:
   HumanHexPlayer(const playercolor color, const hexGame board);
   virtual movevalue makeMove();       // makes a move appropriate for a human player and returns the value
   
};

