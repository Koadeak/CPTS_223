#pragma once

#include <iostream>
#include <string>

#include "List.hpp"
#include "Menu.hpp"
#include "FileHandler.hpp"


class Game
{
    public:
    Game(void)
    {
        //command_List();
        current_profile = "New User";
        profile_score = 0;
    }

    void run_Game(void)
    {
        char choice = 0;

        populate_Commands_List();
        
        while(choice != '6')
        {
            system("clear");
            Menu.print_title();
            Menu.print_menu_options(current_profile, profile_score);
            choice = Menu.get_input();

            switch(choice)
            {
            case '1':
                //print rules
                Menu.print_rules();
                break;
            case '2':
                system("clear");
                if (current_profile == "New User")
                {
                    create_new_user();
                }
                else
                {
                }
                play_game();

                break;
            case '3':
                //Load Profile
                if (current_profile != "New User")
                {
                    //save user
                }
                FileHandler.load_profile("profiles.csv", profile_score, current_profile);
                break;
            case '4':
                insert_command();
                break;
            case '5':
                command_List.delete_node_at_end();
                break;   
            case '6':
                break;
            default:
                break;                     
            }
            //command_List.print_list();

            FileHandler.save_list("commands.csv", command_List);
            FileHandler.save_profile("profiles.csv", current_profile, profile_score);
        }
       
    }

    //Honestly, this looks more convoluted than it is. In short, there are three potential nodes stored in an array, then it wipes\
    those nodes and populates them by finding random ndoes in the commands_List. It will always verify that there are no duplicates\
    in the file. It then justs prints all the options to the screen and prompts the user. If the user is right, add to current score, \
    otherwise, remove point from score
    void play_game(void) 
    {
        //Code snippet from https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
	    srand((unsigned) time(NULL));
        int random;
        int how_many_rounds;
        int correct_answer;
        int player_guess;
        Node command_options[3];
        string buffer;

        cout << "How many rounds would you like to play? ";
        cin >> how_many_rounds;

        for (int i = 0; i < how_many_rounds; i++)
        {
            system("clear");
            cout << "Round: " << i + 1 << " of " << how_many_rounds << endl;
            cout << "Current Score: " << profile_score << endl;

            for (int j = 0; j < 3; j++)
            {
                reset_Node(command_options[j]);
            }
            while ((command_options[0] == command_options[1]) || command_options[0] == command_options[2] ||
                    command_options[1] == command_options[0] || command_options[1] == command_options[2])
            {
                for (int j = 0; j < 3; j++)
                {
                    random = rand() % command_List.get_size();
                    command_options[j] = command_List.go_to_command_node(random);
                }
            }
            
            random = rand() % 3;
            correct_answer = random;

            cout << "What does the command " << command_options[correct_answer].command << " Do?" << endl;
            for (int j = 0; j < 3; j++)
            {
                cout << j + 1 << ") " << command_options[j].commandDescription << endl;
            }

            cout << "Please enter (1,2, or 3): ";
            cin >> player_guess;

            if (player_guess == correct_answer + 1)
            {
                profile_score++;
                cout << "That was correct!" << endl;
            }
            else
            {
                cout << "That was incorrect." << endl;;
                profile_score--;
            }


            Menu.pause();
        }        

    }

    private:
    List<Node> command_List;
    FileHandler FileHandler;
    Menu Menu;
    int profile_score;
    string current_profile;


    //Honestly a pretty simple function. It just calls the psuedo static object filehandler, and the\
    function in the other screen does the rest
    void populate_Commands_List(void)
    {
        FileHandler.populate_Command_List("commands.csv", command_List);
    }

    void reset_Node(Node &node)
    {
        node.command = "";
        node.commandDescription = "";
    }

    void create_new_user(void)
    {
        string buffer;
        cout << "It looks like you are a new user" << endl;
        cout << "What is your username? ";
        cin.ignore();
        getline(cin, current_profile);

        cout << "Great, Let's get started!" << endl;
        Menu.pause();
    }

    void insert_command(void)
    {
        string user_input;
        Node node_to_insert;

        cout << "What is the name of the new command? " ;
        cin.ignore();
        getline(cin, user_input);
        node_to_insert.command = user_input;

        cout << "What is the description of the new command? " ;
        cin.ignore();
        getline(cin, user_input);
        node_to_insert.commandDescription = user_input;

        command_List.insert_command_at_end(node_to_insert);
    }
};