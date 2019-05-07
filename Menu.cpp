#include "Menu.h"

Menu::Menu()
{
    gameEngine = GameEngine();
}

void Menu::runProgram()
{

   int userInput = 0;
   std::string line;

   std::cout << "\n\nWelcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;

    do {
     printMenu();
     std::cin >> userInput;

     // Validate userInput
     if( !(std::cin.eof()) and ((userInput < 1) or (userInput > 4) or (!std::cin)) ){
       std::cin.clear();
       std::cout << "Invalid Input" << std::endl;
     }
     else{
         if ( userInput == 1 ){
           playGame();
         }
         else if( userInput == 2){
           loadGame();
         }
         else if( userInput == 3){
           showStudentInformation();
         }
         else
         {
           std::cout<<"\nGoodbye\n";
         }
       }
     } while ( (std::getline(std::cin, line)) && (userInput != 4) );
}

bool validatePlayerName(std::string playerName)
{
  bool result = false;

  // Only accept UPPERCASE CHARACTERS between 1-40 inclusive in length
  std::regex name ("[A-Z]{1,40}");
  if(std::regex_match(playerName, name)){
      result = true;
  }
  return result;
}

void Menu::playGame()
{
    //read whitespace from previous input before use getline()
    std::cin.ignore();

    std::string playerNames[2];

    std::cout<<"\nStarting a New Game" << std::endl;

    playerNames[0] = inputPlayerNames(1);
    playerNames[1] = inputPlayerNames(2);

    std::cout <<"\n\nLet's Play!\n" << std::endl;
    gameEngine.playGame(playerNames[0], playerNames[1]);
}

std::string Menu::inputPlayerNames(int player){
  bool validatePlayerName(std::string playerName);
  bool initialPrompt = true;
  std::string playerName = "";

  do{
    if(initialPrompt){
      std::cout<<"\nEnter a name for player " << player << "  (uppercase characters only)\n";
      std::cout<<"> ";
      std::getline(std::cin, playerName);
      initialPrompt = false;
    }

    if(!validatePlayerName(playerName))
    {
      std::cout << "\nYour name must contain uppercase characters only, please try again." << std::endl;
      std::cout << "> ";
      std::getline(std::cin, playerName);
    }
  }while(!validatePlayerName(playerName));
  return playerName;
}


void Menu::loadGame()
{
  std::string filename = "";
  std::cout << "Enter the filename from which load a game" << std::endl;
  std::cout << "> ";
  std::cin >> filename;
  //Check file format before loading

  //Load game
  //create an empty board

  //create and shuffle tile bag
  gameEngine.shuffleAndCreateTileBag(gameEngine.getTileBag());

  //Begin reading file
  std::ifstream file(filename);

  if (file.is_open()){
    std::string line = "";
    while(std::getline(file,line)){
      if (line[0] != ' ') {
        //Add Player name
        LinkedList* hand_1 = new LinkedList();
        Player* p1 = new Player(1,line,hand_1);
        gameEngine.addPlayer(p1);

        //Add Player score
        std::getline(file,line);
        int score = std::stoi(line);
        p1->setPlayerScore(score);

        //Add Player tiles
        std::getline(file,line);
        char input[line.size()+1];
        strcpy(input,line.c_str());

        //Add 1st tile
        Tile* tileToAdd = new Tile(input[0],input[1]-48);
        gameEngine.getTileBag()->deleteTile(tileToAdd);
        gameEngine.getPlayer(gameEngine.getPlayerCount())->getPlayerHand()->addBack(tileToAdd);
        //Add 2nd tile
        tileToAdd = new Tile(input[3],input[4]-48);
        gameEngine.getTileBag()->deleteTile(tileToAdd);
        gameEngine.getPlayer(gameEngine.getPlayerCount())->getPlayerHand()->addBack(tileToAdd);
        //Add 3rd tile
        tileToAdd = new Tile(input[6],input[7]-48);
        gameEngine.getTileBag()->deleteTile(tileToAdd);
        gameEngine.getPlayer(gameEngine.getPlayerCount())->getPlayerHand()->addBack(tileToAdd);
        //Add 4th tile
        tileToAdd = new Tile(input[9],input[10]-48);
        gameEngine.getTileBag()->deleteTile(tileToAdd);
        gameEngine.getPlayer(gameEngine.getPlayerCount())->getPlayerHand()->addBack(tileToAdd);
        //Add 5th tile
        tileToAdd = new Tile(input[12],input[13]-48);
        gameEngine.getTileBag()->deleteTile(tileToAdd);
        gameEngine.getPlayer(gameEngine.getPlayerCount())->getPlayerHand()->addBack(tileToAdd);
        //Add 6th tile
        tileToAdd = new Tile(input[15],input[16]-48);
        gameEngine.getTileBag()->deleteTile(tileToAdd);
        gameEngine.getPlayer(gameEngine.getPlayerCount())->getPlayerHand()->addBack(tileToAdd);

      }

      //Begin board input

    }
    file.close();
  }

  std::cout << "Qwirkle gameplay successfully loaded" << std::endl;

  //@TODO: call loadGame in GameEngine here
  //gameEngine.loadGame();



}

void Menu::printMenu(){
	std::cout << "Menu\n"
    "1. New Game\n"
	   "2. Load Game\n"
	   "3. Show student information\n"
	   "4. Quit\n"
     "> " << std::flush;
}

void Menu::showStudentInformation(){
  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Name: Jessica Cruz" << std::endl;
  std::cout << "Student ID: s3571051" << std::endl;
  std::cout << "Email: s3571051@student.rmit.edu.au\n" << std::endl;

  std::cout << "Name: Kevin Vu" << std::endl;
  std::cout << "Student ID: s3678490" << std::endl;
  std::cout << "Email: s3678490@rmit.edu.vn\n" << std::endl;

  std::cout << "Name: Khoi Nguyen" << std::endl;
  std::cout << "Student ID: s3678755" << std::endl;
  std::cout << "Email: s3678755@rmit.edu.vn\n" << std::endl;

  std::cout << "Name: Tuan Vu" << std::endl;
  std::cout << "Student ID: s3678491" << std::endl;
  std::cout << "Email: s3678491@rmit.edu.vn" << std::endl;

  std::cout << "---------------------------------------------\n" << std::endl;
}
