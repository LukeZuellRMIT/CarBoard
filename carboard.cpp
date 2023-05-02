#include "game.h"
#include "helper.h"

#define MYNAME "Luke Zuell"
#define MYID "s3948720"
#define MYEMAIL "s3948720@student.rmit.edu.au"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void showStudentInformation(string name, string id, string email){
    cout << endl << "-----------------------------" << endl
        << "Name: " << name << endl
        << "No: " << id << endl
        << "Email: " << email << endl
        << "-----------------------------" << endl << endl;
}

void printSelection()   {
    cout << "Please entre your choice: ";
}

void printMainScreen()  {
    cout << "Welcome to Car Board" << endl
        << "--------------------" << endl
        << "1. Play game" << endl
        << "2. Show student's information" << endl
        << "3. Quit" << endl << endl;
    printSelection();
}

void printMainInstructions()    {
    cout << endl << "You can use the following commands to play the game:" << endl << endl
    << "load <g>" << endl
    << "    g: number of the game board to load" << endl
    << "init <x>,<y>,<direction>" << endl
    << "    x: horizontal position of the car on the board (between 0 & 9)" << endl
    << "    y: vertical position of the car on the board (between 0 & 9)" << endl
    << "    direction: direction of the car's movement (north, east, south, west)" << endl
    << "forward (or f)" << endl
    << "turn_left (or l)" << endl
    << "turn_right (or r)" << endl
    << "quit" << endl;
}
void loadInsturctions() {
    cout << "At this stage of the program, only three commands are acceptable:" << endl
    << "load <g>" << endl
    << "init <x>,<y>,<direction>" << endl
    << "quit" << endl;
}

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
    //1Game game = Game();
    
    int mainFunctionRunning = 1;
    int selection = -1;

    printMainScreen();
    while(mainFunctionRunning == 1 && !cin.eof())  {
        cin >> selection;
        if (selection == 1) {
            mainFunctionRunning = 0;
            printMainInstructions();
            cout << endl << "Press enter to continue..." << endl;
            std::cin.ignore(); 
            std::cin.get();
            cout << endl;
            Game myGame = Game();
            myGame.start();

            mainFunctionRunning = 1;
            selection = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printMainScreen();
        }
        else if(selection == 2) {
            showStudentInformation(MYNAME, MYID, MYEMAIL);
            printMainScreen();
        }
        else if(selection == 3) {
            mainFunctionRunning = 0;
            return EXIT_SUCCESS;
        }
        else if (isdigit(selection) == false)  {
            selection = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printMainScreen();
        }
    }
    
    return EXIT_SUCCESS;
}


