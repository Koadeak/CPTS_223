#pragma once
#include <iostream>
#include <fstream>
#include "List.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::getline;


//This entire class acts more as a static class, I'm just not sure how to specify it as such. It's main benefit is that\
it allows me to keep everything under one function name. It's better for clarity and readability
class FileHandler
{
    public:

    //This function will populate the list in the Game class by using the command.csv format specified in the rubric.\
    
    void populate_Command_List(string file_Name,List<Node> &List)
    {
        fstream local_File(file_Name);
        string extracted_element;
        char *token, parse_string[200];
        Node tempNode;        

        while(!local_File.eof())
        {
            
            //getline
            getline(local_File, extracted_element);

            strcpy(parse_string, extracted_element.c_str());
            cout << extracted_element << endl;
            token = strtok(parse_string, ",");
            tempNode.command = token;


            token = strtok(NULL, "\"");
            tempNode.commandDescription = token;

            List.insert_command_at_end(tempNode);
        }

        local_File.close();
    }

    void load_profile(string file_name, int &current_score, string &profile_Name)
    {
        fstream local_file(file_name);
        string current_Line, line_name;
        char *token, parse_string[20];
        string search_profile_name = "";

        cout << "What profile would you like to load: " ;
        cin >> search_profile_name;

        while (!local_file.eof() && !local_file.peek() == std::ifstream::traits_type::eof())
        {
            getline(local_file, current_Line);
            
            strcpy(parse_string, current_Line.c_str());

            token = strtok(parse_string, ",");
            line_name = token;

            if (line_name == search_profile_name)
            {
                profile_Name = line_name;
                token = strtok(NULL, "\n");
                current_score = std::stoi(token);
                return;
            }
        }


        local_file.close();

        cout << "This profile does not exist in the database." << endl;
        cout << "Please select new game to create a new profile" << endl;
    }

    void save_profile(string file_name, string &current_profile, int &profile_score)
    {
        fstream local_in_file(file_name);
        ofstream local_out_file;
        string current_Line, line_name;
        char *token, parse_string[20];
        string search_profile_name = "";
        int target_player = 0, file_profile_score;
        Profile_Node temp_profile;
        List<Profile_Node> profile_List;

        if (current_profile == "New User")
        {
            return;
        }


        while (!local_in_file.eof() && !local_in_file.peek() == std::ifstream::traits_type::eof())
        {
            getline(local_in_file, current_Line);
            
            strcpy(parse_string, current_Line.c_str());

            token = strtok(parse_string, ",");
            line_name = token;
            temp_profile.profile_name = line_name;
            token = strtok(NULL, "\n");
            file_profile_score = std::stoi(token);

            if (line_name == current_profile)
            {
                temp_profile.profile_score = profile_score; 
            }
            profile_List.insert_profile_at_end(temp_profile);
        }
        
        local_in_file.close();

        local_out_file.open(file_name);

        profile_List.print_profile_list();

        if (profile_List.is_empty())
        {
            local_out_file << current_profile << "," << profile_score << endl;
        }
        else
        {
            for (int i = 0 ; i < profile_List.get_size(); i++)
            {
                cout << profile_List.go_to_profile_node(i).profile_name << "," << profile_List.go_to_profile_node(i).profile_score << endl;
            }
        }

        local_out_file.close();
    }

    void save_list(string file_name, List<Node> &command_list)
    {
        ofstream out_file(file_name);
        if (!out_file.is_open())
        {
            cout << "Error opening file: " << file_name << endl;
            return;
        }

        for (int i = 0; i < command_list.get_size(); i++)
        {
            Node current_Node = command_list.go_to_command_node(i);
            out_file << current_Node.command << ",\"" << current_Node.commandDescription << "\"";
            if (i < command_list.get_size() - 1)
            {
                out_file << endl;
            }
        }
        out_file.close();
    }
    

    private:

};