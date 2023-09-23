#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Menu
{
    public:
    void print_title(void)
    {
        cout << "      ___  ___      _       _       _____ _                " << endl;
        cout << "      |  \\/  |     | |     | |     |_   _| |               " << endl;
        cout << "      | .  . | __ _| |_ ___| |__     | | | |_              " << endl;
        cout << "      | |\\/| |/ _` | __/ __| '_ \\    | | | __|             " << endl;
        cout << "      | |  | | (_| | || (__| | | |  _| |_| |_              " << endl;
        cout << "      \\_|  |_/\\__,_|\\__\\___|_| |_|  \\___/ \\__|             " << endl;
        cout << "                                                           " << endl;
        cout << "                                                           " << endl;
        cout << " _     _                    _____    _ _ _   _             " << endl;
        cout << "| |   (_)                  |  ___|  | (_) | (_)            " << endl;
        cout << "| |    _ _ __  _   ___  __ | |__  __| |_| |_ _  ___  _ __  " << endl;
        cout << "| |   | | '_ \\| | | \\ \\/ / |  __|/ _` | | __| |/ _ \\| '_ \\ " << endl;
        cout << "| |___| | | | | |_| |>  <  | |__| (_| | | |_| | (_) | | | |" << endl;
        cout << "\\_____/_|_| |_|\\__,_/_/\\_\\ \\____/\\__,_|_|\\__|_|\\___/|_| |_|" << endl << endl;
    }

    void print_menu_options(string current_user, int current_score)
    {
        cout << "Current User: " << current_user << endl;
        cout << "Score: " << current_score << endl;
        cout << "What would you like to do? " << endl;
        cout << "1) Print Rules" << endl;
        cout << "2) Play Game" << endl;
        cout << "3) Load previous save" << endl;
        cout << "4) Insert command" << endl;
        cout << "5) Delete command" << endl;
        cout << "6) Exit" << endl;
    }

    char get_input(void)
    {
        char choice;
        cout << "What would you like to do ";
        cin >> choice;
        
        return choice;
    }

    void pause(void)
    {
        char buffer = 0;

        cout << "Enter anything to continue. . . " ;
        cin >> buffer;
    }

    void print_rules(void)
    {
        system("clear");
        cout << " Welcome to Match it: Linux Edition!" << endl;
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;

        cout << "Menu Options: " << endl << endl;

        cout << "1) Print the rules: an explanation for this would be rudundant lol" << endl << endl;
        cout << "2) Play Game: The object of the game is to rack up as many points\nas possible.\ 
                    Initially, you will be asked how many rounds you want to play.\n \
                    Once selected, a linux terminal line command will be displayed.\n\
                    Your job: Decide which command is correct command. If you choose\n\
                    the correct command, you will gain a point. If you choose wrong\n\
                    you lose a point (Yes, you're score can go in the negetives,\n\
                    don't let that happen). Have Fun" << endl << endl;
        cout << "3) Load Previous Save: Your progress will be saved like it or not.\nYou may always return to it, just type in the name you signed in with!" << endl << endl;
        cout << "4) Insert Command: You may insert your own custom commands! All \nYou have is input the desired information!" << endl << endl;
        cout << "5) Remove a command: Removes a command from the end of the list \n(You'll need to work to get rid of the default commands)" << endl << endl;
        cout << "6) Exit: Exits the game and saves any progress changed" << endl << endl;

        pause();
    }
    private:

};