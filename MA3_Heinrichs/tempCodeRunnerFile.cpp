std::map<std::string, TwitterData> username_sorted_map;

    for (int i = 0; i < 5; i++)
    {
        username_sorted_map[twitter_data[i].getEmail()] = twitter_data[i];
    }


    std::map<std::string, TwitterData>::iterator it = username_sorted_map.begin();

    while (it != username_sorted_map.end())
    {
        cout << "hello" << endl;
        it++;
    }