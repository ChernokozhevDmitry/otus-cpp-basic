#pragma once


namespace menu{
    enum class MainMenu{
        Game = 1,             // играть
        Rules = 2,            // правила игры   
        RecordTable = 3,      // таблица рекордов
        ChangePlayerName = 4, // вернуться для смены имени игрока
        Exit = 5,             // выйти из игры
        Nothing = 333         // !QUASTION! начальное присваивание при инициализации,
                              // чтобы исключить warrning C4701:
                              // использована потенциально неинициализированная локальная переменная
                              // "mainmenuresult" в guess_the_number
    };
    MainMenu main(std::string playername);


    enum class GameLevelMenu{
        Back = 0,                     // вернуться в предыдущее меню
        Level1 = 1,                   // диапазон 0..9
        Level2 = 2,                   // диапазон 0..99
        Level3 = 3,                   // диапазон 0..499
        Level4 = 4,                   // диапазон 0..999
        DifficaltySetupByPlayer = 5,  // диапазон 0.. число задает игрок 
        Nothing = 333                 // !QUASTION! начальное присваивание при инициализации,
                                      // чтобы исключить warrning C4701:
                                      // использована потенциально неинициализированная локальная переменная
                                      // "gamelevelmenuresult" в guess_the_number

    };
    GameLevelMenu gamelevel(std::string playername);
} // menu