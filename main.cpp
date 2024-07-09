
//Talha_Rizwan_22i-2539_E

//Abdullah_Daoud_22i-2626_E

#include <iostream>

#include <Windows.h>

#include <conio.h>

#include "header.h"

#include <iomanip>

using namespace std;

int main()

{

    //An object of player to store the details of last player

    Player lastPlayer = lastPlayer.extractLastPlayerDetails("player_data.txt");

    int choice;

    //Below 3 lines will take the input of name from user to keep better record of his game data.

    string name;

    cout << "Please Enter Your Name :";

    cin >> name;

    Player player(name);       //Object of player which will run the game

    while (true)

    {

        system("CLS");

        cout << endl << endl << endl << endl << endl << endl;

        //Below code is the Title/Logo of our game

        cout << "\t\t\t\t\t\t" << " /$$    /$$ /$$                                     /$$    /$$          /$$                     /$$   /$$              \n";

        cout << "\t\t\t\t\t\t" << "| $$   | $$|__/                                    | $$   | $$         | $$                    |__/  | $$              \n";

        cout << "\t\t\t\t\t\t" << "| $$   | $$ /$$  /$$$$$$$  /$$$$$$$  /$$$$$$       | $$   | $$ /$$$$$$ | $$  /$$$$$$   /$$$$$$$ /$$ /$$$$$$   /$$   /$$\n";

        cout << "\t\t\t\t\t\t" << "|  $$ / $$/| $$ /$$_____/ /$$_____/ |____  $$      |  $$ / $$//$$__  $$| $$ /$$__  $$ /$$_____/| $$|_  $$_/  | $$  | $$\n";

        cout << "\t\t\t\t\t\t" << " \\  $$ $$/ | $$|  $$$$$$ | $$        /$$$$$$$       \\  $$ $$/| $$$$$$$$| $$| $$  \\ $$| $$      | $$  | $$    | $$  | $$\n";

        cout << "\t\t\t\t\t\t" << "  \\  $$$/  | $$ \\____  $$| $$       /$$__  $$        \\  $$$/ | $$_____/| $$| $$  | $$| $$      | $$  | $$ /$$| $$  | $$\n";

        cout << "\t\t\t\t\t\t" << "   \\  $/   | $$ /$$$$$$$/|  $$$$$$$|  $$$$$$$         \\  $/  |  $$$$$$$| $$|  $$$$$$/|  $$$$$$$| $$  |  $$$$/|  $$$$$$$\n";

        cout << "\t\t\t\t\t\t" << "    \\_/    |__/|_______/  \\_______/ \\_______/          \\_/    \\_______/|__/ \\______/  \\_______/|__/   \\___/   \\____  $$\n";

        cout << "\t\t\t\t\t\t" << "                                                                                                              /$$  | $$\n";

        cout << "\t\t\t\t\t\t" << "                                                                                                             |  $$$$$$/\n";

        cout << "\t\t\t\t\t\t" << "                                                                                                              \\______/ \n";

        cout << endl << endl << endl << endl << endl << endl;

        //Menu for user that if he wants to see the details of last game played or go to modes section

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "====================================" << RESET_COLOR << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| Welcome to the Race Car Game!  ||" << RESET_COLOR << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "====================================" << RESET_COLOR << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 1. Modes                       ||" << RESET_COLOR << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 2. See Details of last Player  ||" << RESET_COLOR << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 3. Exit                        ||" << RESET_COLOR << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "====================================" << RESET_COLOR << endl;


        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "Please select an option: " << RESET_COLOR;

        cin >> choice;

        switch (choice)

        {

        case 1:

            int modeChoice;

            while (true)

            {

                //In modes, user can select 2 different modes :Automatic and manual

                system("CLS");

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "==================================" << RESET_COLOR << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| Modes Menu                   ||" << RESET_COLOR << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "==================================" << RESET_COLOR << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 1. Automatic                ||" << RESET_COLOR << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 2. Manual                   ||" << RESET_COLOR << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 3. Back                     ||" << RESET_COLOR << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "==================================" << RESET_COLOR << endl;


                cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "Please select a mode: " << RESET_COLOR;

                cin >> modeChoice;

                if (modeChoice == 3)

                {

                    break;

                }

                if (modeChoice == 1 || modeChoice == 2)

                {

                    int difficultyChoice;

                    while (true)

                    {

                        system("CLS");

                        //In both modes, there are 3 different difficulties for user to play.

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "==============================" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| Difficulty Levels       ||" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "==============================" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 1. Easy                 ||" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 2. Medium               ||" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 3. Hard                 ||" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "|| 4. Back                 ||" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "==============================" << RESET_COLOR << endl;

                        cout << "\t\t\t\t\t\t\t\t\t\t\t" << YELLOW_ORANGE << "Please select a difficulty level: " << RESET_COLOR;

                        cin >> difficultyChoice;

                        if (difficultyChoice == 4)

                        {

                            break;

                        }

                        if (modeChoice == 1)

                        {

                            //for Automatic

                            player.rungame(difficultyChoice);

                            exit(0);

                        }

                        if (modeChoice == 2)

                        {

                            //For Manual plus in manual gameplay,The records of user in game will be written in file too.

                            player.runGame(difficultyChoice, 2);

                            player.Milestones();           //This file will store the milestones of player.

                            player.writePlayerData();        //This will save the data of all players.

                            player.loadPlayerData();         //This will load data of players. It will help to make the leadernoard of our game.

                            player.writeLeaderboardToFile();    //This will write the leaderboard to file.

                            exit(0);

                        }

                    }

                }

            }

            break;

        case 2:

            //Below code will display the details of last player.

            cout << "Last Player Details:" << endl;

            cout << "Name: " << lastPlayer.name << endl;

            cout << "Scores: " << lastPlayer.tempScore << endl;

            cout << "Press any key to continue...";

            _getch();

            system("CLS");

            break;

        case 3:

            // Exit the game

            exit(0);

        default:

            cout << "Invalid choice! Please try again." << endl;

        }

    }

    return 0;

}