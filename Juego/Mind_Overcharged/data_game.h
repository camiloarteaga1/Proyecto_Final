#ifndef DATAGAME_H
#define DATAGAME_H

#include <fstream>

class Data_Game
{
public:
    Data_Game();
    void SetUp();
    void LoadData();
    void SaveData();

public:
    char UsersDF[20]; //User name, password, game data.
    // char ;

};

#endif // DATAMANAGER_H
