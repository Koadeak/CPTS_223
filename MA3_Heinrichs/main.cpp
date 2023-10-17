/*
Gabe Heinrichs
MA3
*/

#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for ( i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    map<string, TwitterData> username_sorted_map;
    map<string, TwitterData> email_sorted_map;


    for (i = 0; i < 5; i++)
    {
        username_sorted_map[twitter_data[i].getUserName()] = twitter_data[i];
        email_sorted_map[twitter_data[i].getEmail()] = twitter_data[i];
    }

    i = 0;
    map<string, TwitterData>::iterator it = username_sorted_map.begin();

    while (it != username_sorted_map.end())
    {
        cout << it->first << ": " << it->second.print() << endl;
        ++it;
    }
    cout << endl;

    username_sorted_map.erase("savage1");
    cout << "Removed savage1" << endl;

    it = username_sorted_map.begin();

    while (it != username_sorted_map.end())
    {
        cout << it->first << ": " << it->second.print() << endl;
        ++it;
    }
    cout << endl;

    it = email_sorted_map.begin();
    
    while (it != email_sorted_map.end())
    {
        cout << it->first << ": " << it->second.print() << endl;
        ++it;
    }
    cout << endl;

    email_sorted_map.erase("kat@gmail.com");
    it = email_sorted_map.begin();
    cout << "Removed kat@gmail.com from map" << endl;
    
    while (it != email_sorted_map.end())
    {
        cout << it->first << ": " << it->second.print() << endl;
        ++it;
    }
    cout << endl;

    return 0;
}