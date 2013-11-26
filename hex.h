
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


class minimax {
 private:
   Graph &tree;                    // the minimax tree to use in this class.

 public:
   minimax();                                            // class constructor
   void addNode(unsigned int NodeNumber);
   void connectToNode(unsigned int srcNodeNumber, unsigned int destNodeNumber);  // connects two nodes together
   unsigned int operator()(unsigned int topNodeNumber);  // run the algorigthm itself from the top node, return the value found
};


class hexGame {

 private:
   const unsigned int boardsize;  // the size of the hex playing board
   const Graph *pGameboard;       // a pointer to the playing board itself

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
   Player(unsigned int player_index);
   virtual movevalue makeMove() = 0;                // pure virtual function for making a move
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
   virtual movevalue makeMove() = 0;               // pure virtual move function
   
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

