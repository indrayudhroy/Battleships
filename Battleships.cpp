#include<iostream>
#include<conio.h>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<fstream>

using namespace std;

class BattleShips
{
public:

	 string index [10];
     bool player [10][10];
     bool enemy [10][10];
     bool playerDisplay [10][10];
     bool enemyDisplay [10][10];
     bool player_aircraftCarrier [10][10];    
     bool player_destroyer [10][10];    
     bool player_cruiser [10][10];    
     bool player_submarine [10][10];    
     bool player_frigate [10][10];        
     bool enemy_aircraftCarrier [10][10];    
     bool enemy_destroyer [10][10];    
     bool enemy_cruiser [10][10];    
     bool enemy_submarine [10][10];    
     bool enemy_frigate [10][10];       
     bool hitRecord [10][10];    
	 ofstream outputFile;
	 ifstream inputFile;
     string option;
     string input;
     int Random_1;
     int Random_2;
     int seed;
     bool Finished;
     bool complete;
     bool condition;
     int Restart;
     int checkAdjacent;
     string Name;
     int destroyerCount;
     int aircraft_carrierCount;
     int cruiserCount;
     int submarineCount;
     int frigateCount;
     string pause;
     string indexSection;
     int record;
     int positionCount;
     int coin;
     int turns;
     string struckShip;
     bool check;
     bool gameOver_check;
     int player_AR;
     int player_cruiseMissile;
     int player_reinforce;
     int player_forceField;
     int player_torpedo;
     bool hitPlayer;
     int scan1;
     int scan2;
     int length;
     int timer;
     int streak;
     int total_enemyShips;
     bool toggle_PowerUps;
     bool AR;
     bool Force_Field;
     int torpedoX;
     int torpedoY;
     bool victory;
     int score;
     int remainingShips;
     string nameRecord;
     string highScore;
     int rank;
     string spaces;
	 string parseInt;
	 int parseValue;

	 BattleShips ()
	 {
		index [0] = "A"; index [1] = "B"; index [2] = "C"; index [3] = "D"; index [4] = "E";
		index [5] = "F"; index [6] = "G"; index [7] = "H"; index [8] = "I"; index [9] = "J";
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                player [m][n] = false;
                enemy [m][n] = false;
                playerDisplay [m][n] = false;
                enemyDisplay [m][n] = false;
                player_aircraftCarrier [m][n] = false;
                player_destroyer [m][n] = false;                
                player_cruiser [m][n] = false;
                player_submarine [m][n] = false;                
                player_frigate [m][n] = false; 
                enemy_aircraftCarrier [m][n] = false;
                enemy_destroyer [m][n] = false;                
                enemy_cruiser [m][n] = false;
                enemy_submarine [m][n] = false;                
                enemy_frigate [m][n] = false;     
                hitRecord [m][n] = false;
            }
        }
		option = "";
        input = "";
        Random_1 = 0;
        Random_2 = 0;
        seed = 0;
        Finished = false;
        complete = false;
        condition = false;
        checkAdjacent = 0;
        Restart = 0;
        Name = "";
        destroyerCount = 1;
        aircraft_carrierCount = 1;
        cruiserCount = 1;
        submarineCount = 1;
        frigateCount = 1;
        pause = "";
        indexSection = "";
        record = 0;
        positionCount = 0;
        coin = 0;
        turns = 0;
        struckShip = "";
        check = false;
        gameOver_check = false;
        player_AR = 1;
        player_cruiseMissile = 1;
        player_reinforce = 2;
        player_forceField = 1;
        player_torpedo = 1;
        hitPlayer = false;
        scan1 = 0;
        scan2 = 0;
        length = 0;
        timer = 0;
        streak = 0;
        total_enemyShips = 18;
        toggle_PowerUps = true;
        AR = false;
        Force_Field = false;
        torpedoX = 0;
        torpedoY = 0;
        victory = false;
        score = 0;
        remainingShips = 0;
        nameRecord = "";
        highScore = "";
        rank = 1;
        spaces = "";
		parseInt = "";
		parseValue = 0;
    }

	void Title_Screen ()
	{
		cout << "                                   # #  ( )\n";
		cout << "                                ___#_#___|__\n";
		cout << "                           _  |____________|  _\n";
		cout << "                    _=====| | |            | | |==== _\n";
		cout << "              =====| |.---------------------------. | |====\n";
		cout << "<--------------------'   .  .  .  .  .  .  .  .   '--------------/---------------------------------------------------\n";
		cout << " \\            o o                                               /                                                  /\n";
		cout << "  \\                                                                                                               /\n";
		cout << "   \\_______________________________________ _________________________________________SIT CHEETAH-X_______________/\n";
		cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
		cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n";
		cout << "\n\n\n";
		for (int i = 1; i <= 70; i++)
        {
            cout << " ";
        }
        cout << "==============================================\n";
        for (int i = 1; i <= 70; i++)
        {
            cout << " ";
        }
        cout << "BATTLESHIPS - THE CLASSIC GAME OF NAVAL COMBAT\n";
        for (int i = 1; i <= 70; i++)
        {
            cout << " ";
        }
        cout << "==============================================\n";
        for (int i = 1; i <= 5; i++)
        {
            cout << "\n";
        }
        cout << "                    ===================\n";
        cout << "                    | (N)EW GAME      |\n";
        cout << "                    |-----------------|\n";
        cout << "                    | (I)NSTRUCTIONS  |\n";
        cout << "                    |-----------------|\n";
        cout << "                    | (S)ETTINGS      |\n";
        cout << "                    |-----------------|\n";        
        cout << "                    | (H)IGH SCORES   |\n";
        cout << "                    |-----------------|\n";        
        cout << "                    | (E)XIT          |\n";
        cout << "                    ===================\n";
        cout << "\n";
        cout << "  ";
        cin >> option;
        if (option == "e" || option == "E")
        {
            exit (0);
        }
        else if (option == "n" || option == "N")
        {
            New_Game ();
        }
        else if (option == "i" || option == "I")
        {
            Instructions ();
        }
        else if (option == "s" || option == "S")
        {
            Settings ();
        }
        else if (option == "h" || option == "H")
        {
            High_Scores ();
        }
        else
        {
            Title_Screen ();
        }
    }    
        
    void Instructions ()
    {
        cout << "\n";
        for (int i = 1; i <= 85; i++)
        {
            cout << " ";
        }
        cout << "INSTRUCTIONS\n";
        for (int i = 1; i <= 85; i++)
        {
            cout << " ";
        }
        cout << "============\n";
        cout << "\n";
        cout << "  OBJECTIVE             : Be the first player to sink all five ships in your opponent's fleet, before he does the same to you.\n";
        cout << "\n";
        cout << "  GETTING READY TO PLAY : Each player secretly places their fleet of five ships on their 10 x 10 ocean grid. Ships may be \n";
        cout << "                          placed either horizontally or vertically but NOT diagonally. During the game, the ships\n";
        cout << "                          may not change their positioning on the ocean grid.\n";
        cout << "\n";
        cout << "  PLAYING THE GAME      : Each player uses the keyboard to issue commands and enter co-ordinates of friendly as well as\n";
        cout << "                          enemy Battleships. The players take turns attacking the enemy fleet, attempting to destroy it\n";
        cout << "                          as fast as possible. You're also provided with 5 POWER - UPs to help you defeat the Computer's\n";
        cout << "                          fleet. Additionally, you are notified when an opposing Battleship is hit or has been completely sunk\n";
        cout << "\n";
        cout << "  WINNING THE GAME      : You win the game when you have sunk all five of your opponent's Battleships first. Subsequently,\n";        
        cout << "                          you can save your score and if it's high enough, it'll be recorded in the High Scores Table for all posterity!\n";
        cout << "\n";
        cout << "  Press ENTER to continue\n";
        //cout << "  ";
        cin.ignore (2);
        Title_Screen ();
    }
    
    void Settings ()
    {
        cout << "\n";
        for (int i = 1; i <= 85; i++)
        {
            cout << " ";
        }
        cout << "SETTINGS\n";
        for (int i = 1; i <= 85; i++)
        {
            cout << " ";
        }
        cout << "========\n";
        cout << "\n";
        for (int i = 1; i <= 75; i++)
        {
            cout << " ";
        }        
        cout << "Customize your gameplay options here\n";
        cout << "\n";
        cout << "\n";
        if (toggle_PowerUps == true)
        {
            cout << "  POWER - UPS are currently turned ON  (Advanced Mode)\n";
        }
        else if (toggle_PowerUps == false)
        {
            cout << "  POWER - UPS are currently turned OFF (Classic Mode)\n";
        }
        cout << "\n";
        cout << "\n";
        cout << "  POWER - UPS :   ON (1)      OFF (2)\n";
        cout << "\n";
        cout << "  Enter your choice (1 or 2) to toggle POWER - UP activation settings\n";
        cout << "  ";
        cin >> input;
        cout << "\n";
        if (input == "1")
        {
            toggle_PowerUps = true;
        }
        else if (input == "2")
        {
            toggle_PowerUps = false;
        }
        cout << "  Your Settings have been saved.\n";
        Title_Screen ();
    }
    
    void High_Scores ()
    {
		rank = 1;
        cout << "\n";
        for (int i = 1; i <= 85; i++)
        {
            cout << " ";
        }
        cout << "HIGH SCORES TABLE\n";
        for (int i = 1; i <= 85; i++)
        {
            cout << " ";
        }
        cout << "=================\n";
        cout << "\n";
        cout << "\n";
        for (int i = 1; i <= 78; i++)
        {
            cout << " ";
        }
        for (int i = 1; i <= 30; i++)
        {
            cout << "=";
        }
        cout << "\n";
        for (int i = 1; i <= 78; i++)
        {
            cout << " ";
        }
        cout << "| NO. |     NAME     | SCORE |\n";
        for (int i = 1; i <= 78; i++)
        {
            cout << " ";
        }		
        cout << "------------------------------\n";		
		ifstream inputFile ("High Scores.hst");
        while (getline (inputFile, nameRecord))
        {
            getline (inputFile, highScore);
            for (int i = 0; i < 12 - (int) nameRecord.length (); i++)
            {
                spaces = spaces + " ";
            }            
            for (int i = 1; i <= 78; i++)
            {
                cout << " ";
            }
            if (rank <= 9)
            {
                cout << "|  " << rank << "  | " << nameRecord << "" << spaces << " |  " << highScore << "  |\n";
            }
            if (rank > 9)
            {
                cout << "|  " << rank << " | " << nameRecord << "" << spaces << " |  " << highScore << "  |\n";
            }
            rank++;
            spaces = "";
        }
        for (int i = 1; i <= 78; i++)
        {
            cout << " ";
        }
        for (int i = 1; i <= 30; i++)
        {
            cout << "=";
        }
        cout << "\n";
        cout << "\n";        
		inputFile.close ();
        cout << "  Press ENTER to continue\n";
        //cout << "  ";
        cin.ignore (2);
        Title_Screen ();
    }

    void Display_Grid_Player ()
    {
        cout << "    ";
        for (int i = 0; i < 10; i++)
        {
            cout << "        " << index [i];
        }
        cout << "\n";
        cout << "        ";
        for (int i = 1; i <= 10; i++)
        {
            cout << " _______ ";
        }
        cout << "\n";
        for (int m = 1; m <= 10; m++)
        {
            if (m < 10)
            {
                cout << "   " << m << "    ";
            }
            else
            {
                cout << "   " << m << "   ";
            }
            for (int n = 0; n < 10; n++)
            {
                if (player [m - 1][n] == false)
                {   
                    cout << "|_______|";
                }
                else
                {
                    cout << "|__[.]__|";
                }
            }
            cout << "\n";  
        }
        cout << "\n";
    }
    
    void Display_Grid_Enemy ()
    {
        cout << "    ";
        for (int i = 0; i < 10; i++)
        {
            cout << "        " << index [i];
        }
        cout << "\n";
        cout << "        ";
        for (int i = 1; i <= 10; i++)
        {
            cout << " _______ ";
        }
        cout << "\n";
        for (int m = 1; m <= 10; m++)
        {
            if (m < 10)
            {
                cout << "   "<< m << "    ";
            }
            else
            {
                cout << "   " << m << "   ";
            }
            for (int n = 0; n < 10; n++)
            {
                if (enemy [m - 1][n] == false)
                {   
                    cout << "|_______|";
                }
                else
                {
                    cout << "|__[.]__|";
                }
            }
            cout << "\n";  
        }
        cout << "\n";
    }
    
    void Display_Player_Game ()
    {
        cout << "    ";
        for (int i = 0; i < 10; i++)
        {
            cout << "        " << index [i];
        }
        cout << "\n";
        cout << "        ";
        for (int i = 1; i <= 10; i++)
        {
            cout << " _______ ";
        }
        cout << "\n";
        for (int m = 1; m <= 10; m++)
        {
            if (m < 10)
            {
                cout << "   " << m << "    ";
            }
            else
            {
                cout << "   " << m << "   ";
            }
            for (int n = 0; n < 10; n++)
            {
                if (playerDisplay [m - 1][n] == false && player [m - 1][n] == false)
                {   
                    cout << "|_______|";
                }
                else if (playerDisplay [m - 1][n] == true && player [m - 1][n] == true)
                {
                    cout << "|__[.]__|";
                }
                else if (player [m - 1][n] == false && playerDisplay [m - 1][n] == true)
                {
                    cout << "|__[X]__|";
                }                
            }
            cout << "\n";  
        }
        cout << "\n";
    }   
    
    void Display_Enemy_Game ()
    {
        for (int i = 1; i <= 75; i++)
        {
            cout << " ";
        }
        cout << "    ";
        for (int i = 0; i < 10; i++)
        {
            cout << "        " << index [i];
        }
        cout << "\n";
        cout << "        ";
        for (int i = 1; i <= 75; i++)
        {
            cout << " ";
        }        
        for (int i = 1; i <= 10; i++)
        {
            cout << " _______ ";
        }
        cout << "\n";
        for (int m = 1; m <= 10; m++)
        {
            for (int i = 1; i <= 75; i++)
            {
                cout << " ";
            }
            if (m < 10)
            {
                cout << "   " << m << "    ";
            }
            else
            {
                cout << "   " << m << "   ";
            }
            for (int n = 0; n < 10; n++)
            {
                if (AR == true && (m >= 4 && m <= 7 && n >= 3 && n <= 6))
                {
                    if (enemyDisplay [m - 1][n] == true && enemy [m - 1][n] == true)
                    {
                        cout << "|__[.]__|";
                    }
                    if (enemyDisplay [m - 1][n] == false && enemy [m - 1][n] == false)
                    {
                        cout << "|_______|";
                    }
                    if (enemy [m - 1][n] == false && enemyDisplay [m - 1][n] == true)
                    {
                        cout << "|__[X]__|";
                    }
                }
                else
                {                        
                    if ((enemyDisplay [m - 1][n] == false && enemy [m - 1][n] == false) || (enemyDisplay [m - 1][n] == true && enemy [m - 1][n] == true))
                    {   
                        cout << "|_______|";
                    }
                    if (enemy [m - 1][n] == false && enemyDisplay [m - 1][n] == true)
                    {
                        cout << "|__[X]__|";
                    }
                }
            }
            cout << "\n";  
        }
        cout << "\n";
    }       

    void Enemy_Assign ()
    {
        Assign_Reset ();
        Destroyer ();
        Assign_Reset ();
        Aircraft_Carrier ();
        Assign_Reset ();
        Cruiser ();
        Assign_Reset ();
        Submarine ();
        Assign_Reset ();
        Frigate ();
        Assign_Reset ();
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                enemyDisplay [m][n] = enemy [m][n];
            }
        }
    }
   
    void Destroyer ()
    {
		srand ((unsigned int) time (NULL));
        Random_1 = rand () % 10;
		srand ((unsigned int) time (NULL));
        Random_2 = rand () % 10;
        enemy [Random_1][Random_2] = true;
        enemy_destroyer [Random_1][Random_2] = true;        
		srand ((unsigned int) time (NULL));
        seed = rand () % 4 + 1;
        while (complete == false)
        {
            if (seed == 1 && Random_1 - 3 >= 0)
            {
                for (int x = 1; x <= 3; x++)
                {
                    enemy [Random_1-x][Random_2] = true;
                    enemy_destroyer [Random_1-x][Random_2] = true;
                }
                complete = true;
            }
            else
            {
                if (seed == 1)
                {
                    seed++;
                }
            }
            if (seed == 2 && Random_2 + 3 < 10)
            {
                for (int x = 1; x <= 3; x++)
                {
                    enemy [Random_1][Random_2+x] = true;
                    enemy_destroyer [Random_1][Random_2+x] = true;
                }
                complete = true;
            }
            else
            {
                if (seed == 2)
                {
                    seed++;
                }
            }
            if (seed == 3 && Random_1+3<10)
            {   
                for (int x = 1; x <= 3; x++)
                {   
                    enemy [Random_1+x][Random_2] = true;
                    enemy_destroyer [Random_1+x][Random_2] = true;                    
                }
                complete = true;
            }
            else
            {
                if (seed == 3)
                {
                    seed++;
                }
            }
            if (seed == 4 && Random_2-3>=0)
            {
                for (int x = 1; x <= 3; x++)
                {
                    enemy [Random_1][Random_2-x] = true;
                    enemy_destroyer [Random_1][Random_2-x] = true;                    
                }
                complete = true;
            }
            else
            {
                seed=1;
            }
        }
    }
    
    void Aircraft_Carrier () 
    {
        while (complete == false)
        {
			srand ((unsigned int) time (NULL));
            Random_1 = rand () % 10;
			srand ((unsigned int) time (NULL));
            Random_2 = rand () % 10;
            if (Random_1 == 0)
            {
                Random_1++;
            }
            if (Random_1 == 9)
            {
                Random_1--;
            }
            if (Random_2 == 0)
            {
                Random_2++;
            }
            if (Random_2 == 9)
            {
                Random_2--;
            }
            if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
            {
                enemy [Random_1][Random_2] = true;
                enemy_aircraftCarrier [Random_1][Random_2] = true;                
                complete = true;
            }
        }
        complete = false;
		srand ((unsigned int) time (NULL));
        seed = rand () % 4 + 1;
        while (Finished == false)
        {
            if (seed == 1 && Random_1-4>=1)
            {            
                for (int i = Random_1-1;i>=Random_1-4;i--)
                {
                    if (i == Random_1-1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else
                    {
                        complete = false;                         
                    }
                    if (condition == true && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else 
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=4)
                {
                    for (int x=1;x<=4;x++)
                    {
                        enemy [Random_1-x][Random_2] = true;
                        enemy_aircraftCarrier [Random_1-x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;
                }
            }
            else 
            {
                if (seed == 1)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 2 && Random_2+4<9)
            {            
                for (int i = Random_2+1;i<=Random_2+4;i++)
                {
                    if (i == Random_2+1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;                                             
                    }
                }
                if (complete == true && checkAdjacent>=4)
                {
                    for (int x=1;x<=4;x++)
                    {
                        enemy [Random_1][Random_2+x] = true;
                        enemy_aircraftCarrier [Random_1][Random_2+x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;
                }
            }
            else 
            {
                if (seed == 2)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 3 && Random_1+4<9)
            {            
                for (int i = Random_1+1;i<=Random_1+4;i++)
                {
                    if (i == Random_1+1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [i][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=4)
                {
                    for (int x=1;x<=4;x++)
                    {
                        enemy [Random_1+x][Random_2] = true;
                        enemy_aircraftCarrier [Random_1+x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;    
                }
            }
            else 
            {
                if (seed == 3)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 4 && Random_2-4>=1)
            {            
                for (int i = Random_2-1;i>=Random_2-4;i--)
                {
                    if (i == Random_2-1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=4)
                {
                    for (int x=1;x<=4;x++)
                    {
                        enemy [Random_1][Random_2-x] = true;
                        enemy_aircraftCarrier [Random_1][Random_2-x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed=1;
                    Restart++;                                    
                }
            }
            else 
            {
                seed=1;
                Restart++;
            }
            checkAdjacent = 0;
            if (Restart>4 && Finished == false)
            {
                Restart = 0;
                Assign_Reset ();
                enemy [Random_1][Random_2] = false;
                while (complete == false)
                {
					srand ((unsigned int) time (NULL));
                    Random_1 = rand () % 10;
					srand ((unsigned int) time (NULL));
                    Random_2 = rand () % 10;
                    if (Random_1 == 0)
                    {   
                        Random_1++;
                    }
                    if (Random_1 == 9)
                    {
                        Random_1--;
                    }
                    if (Random_2 == 0)
                    {
                        Random_2++;
                    }
                    if (Random_2 == 9)
                    {
                        Random_2--;
                    }
                    if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
                    {
                        enemy [Random_1][Random_2] = true;
                        complete = true;
                    }
                }
                complete = false;
				srand ((unsigned int) time (NULL));
                seed = rand () % 4 + 1;
            }
        }
    }        
    
    void Cruiser () 
    {
        while (complete == false)
        {
			srand ((unsigned int) time (NULL));
            Random_1 = rand () % 10;
			srand ((unsigned int) time (NULL));
            Random_2 = rand () % 10;
            if (Random_1 == 0)
            {
                Random_1++;
            }
            if (Random_1 == 9)
            {
                Random_1--;
            }
            if (Random_2 == 0)
            {
                Random_2++;
            }
            if (Random_2 == 9)
            {
                Random_2--;
            }
            if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
            {
                enemy [Random_1][Random_2] = true;
                enemy_cruiser [Random_1][Random_2] = true;                
                complete = true;
            }
        }
        complete = false;
		srand ((unsigned int) time (NULL));
        seed = rand () % 4 + 1;
        while (Finished == false)
        {
            if (seed == 1 && Random_1-3>=1)
            {            
                for (int i = Random_1-1;i>=Random_1-3;i--)
                {
                    if (i == Random_1-1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else
                    {
                        complete = false;                         
                    }
                    if (condition == true && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else 
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=3)
                {
                    for (int x=1;x<=3;x++)
                    {
                        enemy [Random_1-x][Random_2] = true;
                        enemy_cruiser [Random_1-x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;
                }
            }
            else 
            {
                if (seed == 1)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 2 && Random_2+3<9)
            {            
                for (int i = Random_2+1;i<=Random_2+3;i++)
                {
                    if (i == Random_2+1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;                                             
                    }
                }
                if (complete == true && checkAdjacent>=3)
                {
                    for (int x=1;x<=3;x++)
                    {
                        enemy [Random_1][Random_2+x] = true;
                        enemy_cruiser [Random_1][Random_2+x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;
                }
            }
            else 
            {
                if (seed == 2)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 3 && Random_1+3<9)
            {            
                for (int i = Random_1+1;i<=Random_1+3;i++)
                {
                    if (i == Random_1+1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [i][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=3)
                {
                    for (int x=1;x<=3;x++)
                    {
                        enemy [Random_1+x][Random_2] = true;
                        enemy_cruiser [Random_1+x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;    
                }
            }
            else 
            {
                if (seed == 3)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 4 && Random_2-3>=1)
            {            
                for (int i = Random_2-1;i>=Random_2-3;i--)
                {
                    if (i == Random_2-1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=3)
                {
                    for (int x=1;x<=3;x++)
                    {
                        enemy [Random_1][Random_2-x] = true;
                        enemy_cruiser [Random_1][Random_2-x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed=1;
                    Restart++;                                    
                }
            }
            else 
            {
                seed=1;
                Restart++;
            }
            checkAdjacent = 0;
            if (Restart>4 && Finished == false)
            {
                Restart = 0;
                Assign_Reset ();
                enemy [Random_1][Random_2] = false;
                while (complete == false)
                {
                    srand ((unsigned int) time (NULL));
					Random_1 = rand () % 10;
					srand ((unsigned int) time (NULL));
					Random_2 = rand () % 10;
                    if (Random_1 == 0)
                    {   
                        Random_1++;
                    }
                    if (Random_1 == 9)
                    {
                        Random_1--;
                    }
                    if (Random_2 == 0)
                    {
                        Random_2++;
                    }
                    if (Random_2 == 9)
                    {
                        Random_2--;
                    }
                    if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
                    {
                        enemy [Random_1][Random_2] = true;
                        complete = true;
                    }
                }
                complete = false;
				srand ((unsigned int) time (NULL));
                seed = rand () % 4 + 1;
            }
        }
    }
    
    void Submarine () 
    {
        while (complete == false)
        {

			srand ((unsigned int) time (NULL));
            Random_1 = rand () % 10;
			srand ((unsigned int) time (NULL));
            Random_2 = rand () % 10;
            if (Random_1 == 0)
            {
                Random_1++;
            }
            if (Random_1 == 9)
            {
                Random_1--;
            }
            if (Random_2 == 0)
            {
                Random_2++;
            }
            if (Random_2 == 9)
            {
                Random_2--;
            }
            if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false)
            {
                enemy [Random_1][Random_2] = true;
                enemy_submarine [Random_1][Random_2] = true;                
                complete = true;
            }
        }
        complete = false;
		srand ((unsigned int) time (NULL));
        seed = rand () % 4 + 1;
        while (Finished == false)
        {
            if (seed == 1 && Random_1-2>=1)
            {            
                for (int i = Random_1-1;i>=Random_1-2;i--)
                {
                    if (i == Random_1-1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else 
                    {
                        complete = false;
                    }
                }   
                if (complete == true && checkAdjacent>=2)
                {
                    for (int x=1;x<=2;x++)
                    {   
                        enemy [Random_1-x][Random_2] = true;
                        enemy_submarine [Random_1-x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;                        
                }
            }
            else 
            {
                if (seed == 1)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 2 && Random_2+2<9)
            {            
                for (int i = Random_2+1;i<=Random_2+2;i++)
                {
                    if (i == Random_2+1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=2)
                {
                    for (int x=1;x<=2;x++)
                    {
                        enemy [Random_1][Random_2+x] = true;
                        enemy_submarine [Random_1][Random_2+x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;                         
                }
            }
            else 
            {
                if (seed == 2)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 3 && Random_1+2<9)
            {            
                for (int i = Random_1+1;i<=Random_1+2;i++)
                {
                    if (i == Random_1+1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [i][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {//
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=2)
                {
                    for (int x=1;x<=2;x++)
                    {
                        enemy [Random_1+x][Random_2] = true;
                        enemy_submarine [Random_1+x][Random_2] = true;                        
                    }   
                    Finished = true;
                }
                else
                {   
                    seed++;
                    Restart++;                        
                }
            }
            else 
            {   
                if (seed == 3)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 4 && Random_2-2>=1)
            {            
                for (int i = Random_2-1;i>=Random_2-2;i--)
                {
                    if (i == Random_2-1)
                    {
                        condition = false;
                    }
                    else
                    {
                        condition = true;
                    }
                    if (condition == false && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                    if (condition == true && enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;                           
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=2)
                {   
                    for (int x=1;x<=2;x++)
                    {
                        enemy [Random_1][Random_2-x] = true;
                        enemy_submarine [Random_1][Random_2-x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed=1;
                    Restart++;
                }
            }
            else 
            {
                seed=1;
                Restart++;                
            }
            checkAdjacent = 0;
            if (Restart>4 && Finished == false)
            {
                Restart = 0;
                Assign_Reset ();
                enemy [Random_1][Random_2] = false;
                while (complete == false)
                {
					srand ((unsigned int) time (NULL));
                    Random_1 = rand () % 10;
					srand ((unsigned int) time (NULL));
                    Random_2 = rand () % 10;
                    if (Random_1 == 0)
                    {   
                        Random_1++;
                    }
                    if (Random_1 == 9)
                    {
                        Random_1--;
                    }
                    if (Random_2 == 0)
                    {
                        Random_2++;
                    }
                    if (Random_2 == 9)
                    {
                        Random_2--;
                    }
                    if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
                    {
                        enemy [Random_1][Random_2] = true;
                        complete = true;
                    }
                }
                complete = false;
				srand ((unsigned int) time (NULL));
                seed = rand () % 4 + 1;     
            }
        }
    }
    
    void Frigate () 
    {
        while (complete == false)
        {
			srand ((unsigned int) time (NULL));
            Random_1 = rand () % 10;
			srand ((unsigned int) time (NULL));
            Random_2 = rand () % 10;
            if (Random_1 == 0)
            {
                Random_1++;
            }
            if (Random_1 == 9)
            {
                Random_1--;
            }
            if (Random_2 == 0)
            {
                Random_2++;
            }
            if (Random_2 == 9)
            {
                Random_2--;
            }
            if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
            {
                enemy [Random_1][Random_2] = true;
                enemy_frigate [Random_1][Random_2] = true;                
                complete = true;
            }
        }
        complete = false;
		srand ((unsigned int) time (NULL));
        seed = rand () % 4 + 1;
        while (Finished == false)
        {
            if (seed == 1 && Random_1-1>=1)
            {            
                for (int i = Random_1-1;i>=Random_1-1;i--)
                {
                    if (enemy [i][Random_2] == false && enemy [i-1][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else
                    {
                        complete = false;                         
                    }
                }
                if (complete == true && checkAdjacent>=1)
                {
                    for (int x=1;x<=1;x++)
                    {
                        enemy [Random_1-x][Random_2] = true;
                        enemy_frigate [Random_1-x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;
                }
            }
            else 
            {
                if (seed == 1)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 2 && Random_2+1<9)
            {            
                for (int i = Random_2+1;i<=Random_2+1;i++)
                {
                    if (enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1][i+1] == false && enemy [Random_1+1][i] == false)
                    {
                        complete = true;
                        checkAdjacent++;
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=1)
                {
                    for (int x=1;x<=1;x++)
                    {
                        enemy [Random_1][Random_2+x] = true;
                        enemy_frigate [Random_1][Random_2+x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;
                }
            }
            else 
            {
                if (seed == 2)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 3 && Random_1+1<9)
            {            
                for (int i = Random_1+1;i<=Random_1+1;i++)
                {
                    if (enemy [i][Random_2] == false && enemy [i][Random_2+1] == false && enemy [i+1][Random_2] == false && enemy [i][Random_2-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=1)
                {
                    for (int x=1;x<=1;x++)
                    {
                        enemy [Random_1+x][Random_2] = true;
                        enemy_frigate [Random_1+x][Random_2] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed++;
                    Restart++;    
                }
            }
            else 
            {
                if (seed == 3)
                {
                    seed++;
                }                 
                Restart++;
            }
            checkAdjacent = 0;
            if (seed == 4 && Random_2-1>=1)
            {            
                for (int i = Random_2-1;i>=Random_2-1;i--)
                {
                    if (enemy [Random_1][i] == false && enemy [Random_1-1][i] == false && enemy [Random_1+1][i] == false && enemy [Random_1][i-1] == false)
                    {
                        complete = true;
                        checkAdjacent++;                        
                    }
                    else
                    {
                        complete = false;
                    }
                }
                if (complete == true && checkAdjacent>=1)
                {
                    for (int x=1;x<=1;x++)
                    {
                        enemy [Random_1][Random_2-x] = true;
                        enemy_frigate [Random_1][Random_2-x] = true;                        
                    }
                    Finished = true;
                }
                else
                {
                    seed=1;
                    Restart++;                                    
                }
            }
            else 
            {
                seed=1;
                Restart++;
            }
            checkAdjacent = 0;
            if (Restart>4 && Finished == false)
            {
                Restart = 0;
                Assign_Reset ();
                enemy [Random_1][Random_2] = false;
                while (complete == false)
                {
					srand ((unsigned int) time (NULL));
                    Random_1 = rand () % 10;
					srand ((unsigned int) time (NULL));
                    Random_2 = rand () % 10;
                    if (Random_1 == 0)
                    {   
                        Random_1++;
                    }
                    if (Random_1 == 9)
                    {
                        Random_1--;
                    }
                    if (Random_2 == 0)
                    {
                        Random_2++;
                    }
                    if (Random_2 == 9)
                    {
                        Random_2--;
                    }
                    if (enemy [Random_1][Random_2] == false && enemy [Random_1-1][Random_2] == false && enemy [Random_1][Random_2+1] == false && enemy [Random_1+1][Random_2] == false && enemy [Random_1][Random_2-1] == false )
                    {
                        enemy [Random_1][Random_2] = true;
                        complete = true;
                    }
                }
                complete = false;
				srand ((unsigned int) time (NULL));
                seed = rand () % 4 + 1;
            }
        }
    }            
    
    void Assign_Reset () 
    {
        Finished = false;
        complete = false;
        condition = false;
        Restart = 0;
        checkAdjacent = 0;
        seed = 0;
    }

    void New_Game () 
    {
        Enemy_Assign ();
        Briefing ();
        while (positionCount < 5)
        {
            Set_Coordinates ();
        }
        cout << "\n";
        for (int i = 1; i <= 181; i++)
        {
            cout << "=";
        }
        cout << "\n";
        cout << "\n";
        cout << "  You have successfully finished positioning all your Battleships!\n";  
        cout << "\n";
        cout << "  This is what your battlefield finally looks like . . .\n";
        cout << "\n";
        Display_Grid_Player ();
        cout << "\n";
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                playerDisplay [m][n] = player [m][n];
            }
        }        
        cout << "  Would you like to continue (c) or would you like to restart the positioning sequence (r)\n";
        cout << "  ";
        cin >> input;
        if (input == "r" || input == "R")
        {
            Reset_Player_Data ();
            Player_Refresh ();
            Enemy_Refresh ();
            New_Game ();
        }
        else if (input == "c" || input == "C")
        {
            Start_Game ();
        }
    }
    
    void Briefing () 
    {
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "  Please enter your name\n";
        cout << "  ";
        cin >> Name;
        cout << "\n";
        cout << "\n";
        cout << "  Ah, welcome Admiral " << Name << ". The enemy fleet is approaching fast, it's up to you now to take control of our Battleships and halt their advance\n";
        cout << "  In addition to full authority over this fleet, you have been supplied with the latest Satellite Technology equipment\n";
        cout << "  The Alpha Laser Transmitters (ALT) and the Virtual Imaging Radar (VIR) will let you position and efficiently command our Battleships\n";
        cout << "\n";
        cout << "  But remember, the enemy is no pushover. Careful planning and strategic offense will surely be required\n";
        cout << "  Victory can only be ours if the entire enemy fleet is destroyed before they wipe out all our ships\n";
        cout << "\n";
        cout << "  Good Luck Admiral, I'm sure you'll need it!\n";
        cout << "\n";
        cout << "\n";
        cout << "  Press ENTER to continue . . . \n";
        cin.ignore (2);        
        cout << "\n";
        cout << "\n";        
        cout << " .------------.\n";
        cout << " | VIR REPORT |   Here's what Admiral " << Name << "'s battlefield currently looks like:\n";
        cout << " '------------'\n";
    }  
   
    void Set_Coordinates () 
    {               
        Display_Grid_Player ();
        List_Ships ();
        ALT_Panel ();
        cout << "\n";
        cout << "\n";
        cout << "  Which Battleship would you like to position?\n";
        cout << "\n";
        cout << "  Enter the corresponding letter from the ALT Control Panel  (For example, enter 'd' if you want to start placing your Destroyer)\n";
        cout << "  ";
        cin >> input;
        cout << "\n";
        cout << "\n";
        if (input == "a" || input == "A" || input == "d" || input == "D" || input == "c" || input == "C" || input == "s" || input == "S" || input == "f" || input == "F")
        {
            if ((input == "a" || input == "A") && aircraft_carrierCount > 0)
            {
                Place_Aircraft_Carrier ();
                aircraft_carrierCount--;
                cout << "  You have successfully placed an Aircraft Carrier\n";
            }
            else if ((input == "a" || input == "A") && aircraft_carrierCount < 1)
            {
                cout << "  You have already placed your Aircraft Carrier\n";
            }
            if ((input == "d" || input == "D") && destroyerCount > 0)
            {
                Place_Destroyer ();
                destroyerCount--;
                cout << "  You have successfully placed a Destroyer\n";   
            }   
            else if ((input == "d" || input == "D") && destroyerCount < 1)
            {
                cout << "  You have already placed your Destroyer\n";
            }
            if ((input == "c" || input == "C") && cruiserCount > 0)
            {
                Place_Cruiser ();
                cruiserCount--;
                cout << "  You have successfully placed a Cruiser\n";            
            }  
            else if ((input == "c" || input == "C") && cruiserCount < 1)
            {
                cout << "  You have already placed your Cruiser\n";
            }        
            if ((input == "s" || input == "S") && submarineCount > 0)
            {
                Place_Submarine ();
                submarineCount--;
                cout << "  You have successfully placed a Submarine\n";                        
            }    
            else if ((input == "s" || input == "S") && submarineCount < 1)
            {
                cout << "  You have already placed your Submarine\n";
            }        
            if ((input == "f" || input == "F") && frigateCount > 0)
            {
                Place_Frigate ();
                frigateCount--;
                cout << "  You have successfully placed a Frigate\n";            
            }
            else if ((input == "f" || input == "F") && frigateCount < 1)
            {
                cout << "  You have already placed your Frigate\n";
            }       
        }
        else if (input == "r" || input == "R")
        {
            Player_Refresh ();
            Reset_Player_Data ();
            for (int m = 0; m < 10; m++)
            {
                for (int n = 0; n < 10; n++)
                {
                    player [m][n] = enemy [m][n];
                    player_aircraftCarrier [m][n] = enemy_aircraftCarrier [m][n];
                    player_destroyer [m][n] = enemy_destroyer [m][n];
                    player_cruiser [m][n] = enemy_cruiser [m][n];                    
                    player_submarine [m][n] = enemy_submarine [m][n];                    
                    player_frigate [m][n] = enemy_frigate [m][n];                    
                }
            }
            Enemy_Refresh ();
            Enemy_Assign ();
            positionCount = 5;
            cout << "  The AI has randomized the co-ordinates of all your Battleships.\n";
            cout << "\n";
        }
        else
        {
            cout << "\n";
            Set_Coordinates ();
        }
    }
    
    void Place_Aircraft_Carrier () 
    {
        for (int x = 1; x <= 5; x++)
        {
            cout << "  Enter the co-ordinates (e.g. G3) of a grid-square where you'd like to position a component of your Aircraft Carrier\n";
            cout << "  REMEMBER: The grid-squares where you place components of any of your Battleships must be adjacent (vertically or horizontally but NOT diagonally) and must NOT overlap\n";
            cout << "  ";
            cin >> input;
            indexSection = input.substr (0,1);
			if (indexSection [0] >= 97)
			{
				indexSection [0] = indexSection [0] - 32;
			}
            for (int i = 0; i < 10; i++)
            {
                if (indexSection == index [i])
                {
                    record = i;
                }
            }
			parseInt = input.substr (1,2);
			if (parseInt == "10")
			{
				parseValue = 9;
			}
			else
			{
				parseValue = parseInt [0] - '1';
			}
            player [parseValue][record] = true;
            player_aircraftCarrier [parseValue][record] = true;            
            cout << "\n";
            Display_Grid_Player ();
            cout << "\n";
        }
        positionCount++;
    }
    
    void Place_Destroyer () 
    {
        for (int x = 1; x <= 4; x++)
        {
            cout << "  Enter the co-ordinates (e.g. G3) of a grid-square where you'd like to position a component of your Destroyer\n";
            cout << "  REMEMBER: The grid-squares where you place components of any of your Battleships must be adjacent (vertically or horizontally but NOT diagonally) and must NOT overlap\n";
            cout << "  ";
            cin >> input;
            indexSection = input.substr (0,1);
			if (indexSection [0] >= 97)
			{
				indexSection [0] = indexSection [0] - 32;
			}
            for (int i = 0; i < 10; i++)
            {
                if (index [i] == indexSection)
                {
                    record = i;
                }
            }
			parseInt = input.substr (1,2);
			if (parseInt == "10")
			{
				parseValue = 9;
			}
			else
			{
				parseValue = parseInt [0] - '1';
			}
            player [parseValue][record] = true;
            player_destroyer [parseValue][record] = true;            
            cout << "\n";
            Display_Grid_Player ();
            cout << "\n";
        }        
        positionCount++;        
    }
    
    void Place_Cruiser () 
    {
        for (int x = 1; x <= 4; x++)
        {
            cout << "  Enter the co-ordinates (e.g. G3) of a grid-square where you'd like to position a component of your Cruiser\n";
            cout << "  REMEMBER: The grid-squares where you place components of any of your Battleships must be adjacent (vertically or horizontally but NOT diagonally) and must NOT overlap\n";
            cout << "  ";
            cin >> input;
            indexSection = input.substr (0,1);
			if (indexSection [0] >= 97)
			{
				indexSection [0] = indexSection [0] - 32;
			}
            for (int i = 0; i < 10; i++)
            {
                if (index [i] == indexSection)
                {
                    record = i;
                }
            }
			parseInt = input.substr (1,2);
			if (parseInt == "10")
			{
				parseValue = 9;
			}
			else
			{
				parseValue = parseInt [0] - '1';
			}
            player [parseValue][record] = true;
            player_cruiser [parseValue][record] = true;            
            cout << "\n";
            Display_Grid_Player ();
            cout << "\n";
        }        
        positionCount++;        
    }
    
    void Place_Submarine () 
    {
        for (int x = 1; x <= 3; x++)
        {
            cout << "  Enter the co-ordinates (e.g. G3) of a grid-square where you'd like to position a component of your Submarine\n";
            cout << "  REMEMBER: The grid-squares where you place components of any of your Battleships must be adjacent (vertically or horizontally but NOT diagonally) and must NOT overlap\n";
            cout << "  ";
            cin >> input;
            indexSection = input.substr (0,1);
			if (indexSection [0] >= 97)
			{
				indexSection [0] = indexSection [0] - 32;
			}
            for (int i = 0; i < 10; i++)
            {
                if (index [i] == indexSection)
                {
                    record = i;
                }
            }
			parseInt = input.substr (1,2);
			if (parseInt == "10")
			{
				parseValue = 9;
			}
			else
			{
				parseValue = parseInt [0] - '1';
			}
            player [parseValue][record] = true;
            player_submarine [parseValue][record] = true;            
            cout << "\n";
            Display_Grid_Player ();
            cout << "\n";
        }        
        positionCount++;        
    }
    
    void Place_Frigate () 
    {
        for (int x = 1; x <= 2; x++)
        {
            cout << "  Enter the co-ordinates (e.g. G3) of a grid-square where you'd like to position a component of your Frigate\n";
            cout << "  REMEMBER: The grid-squares where you place components of any of your Battleships must be adjacent (vertically or horizontally but NOT diagonally) and must NOT overlap\n";
            cout << "  ";
            cin >> input;
            indexSection = input.substr (0,1);
			if (indexSection [0] >= 97)
			{
				indexSection [0] = indexSection [0] - 32;
			}
            for (int i = 0; i < 10; i++)
            {
                if (index [i] == indexSection)
                {
                    record = i;
                }
            }
			parseInt = input.substr (1,2);
			if (parseInt == "10")
			{
				parseValue = 9;
			}
			else
			{
				parseValue = parseInt [0] - '1';
			}
            player [parseValue][record] = true;
            player_frigate [parseValue][record] = true;            
            cout << "\n";
            Display_Grid_Player ();
            cout << "\n";
        }        
        positionCount++;        
    }
    
    void List_Ships () 
    {          
        cout << "\n";
        cout << "  You have the following Battleships under your control\n";
        cout << "\n";
        cout << "  AIRCRAFT CARRIER  [ 5 Grid-squares ]    x " << aircraft_carrierCount << "\n";
        cout << "  DESTROYER         [ 4 Grid-squares ]    x " << destroyerCount << "\n";        
        cout << "  CRUISER           [ 4 Grid-squares ]    x " << cruiserCount << "\n";
        cout << "  SUBMARINE         [ 3 Grid-squares ]    x " << submarineCount << "\n";
        cout << "  FRIGATE           [ 2 Grid-squares ]    x " << frigateCount << "\n";
        cout << "\n";
    }
    
    void ALT_Panel () 
    {
        cout << "  \t\t\t\t\t\t =========================================\n";
        cout << "  \t\t\t\t\t\t |            ALT CONTROL PANEL          |\n";
        cout << "  \t\t\t\t\t\t |---------------------------------------|\n";        
        cout << "  \t\t\t\t\t\t |---------------------------------------|\n";
        cout << "  \t\t\t\t\t\t | A - Position Aircraft Carrier         |\n";
        cout << "  \t\t\t\t\t\t | D - Position Destroyer                |\n";
        cout << "  \t\t\t\t\t\t | C - Position Cruiser                  |\n";
        cout << "  \t\t\t\t\t\t | S - Position Submarine                |\n";
        cout << "  \t\t\t\t\t\t | F - Position Frigate                  |\n"; 
        cout << "  \t\t\t\t\t\t |.......................................|\n";         
        cout << "  \t\t\t\t\t\t | R - Randomly Position All Battleships |\n"; 
        cout << "  \t\t\t\t\t\t =========================================\n";        
    }    
    
    void Start_Game () 
    {
        cout << "\n";
        for (int i = 1; i <= 80; i++)
        {
            cout << " ";
        }
        cout << "BATTLESHIPS BATTLE\n";
        for (int i = 1; i <= 80; i++)
        {
            cout << " ";
        }
        cout << "==================\n";        
        cout << "\n";
        cout << "\n";
        cout << "  \t\t\t\t\t Admiral " << Name << "  vs  The Computer\n";
        Assign_Reset ();
        Toss ();
        if (coin == 1)
        {
            cout << "\n";
            cout << "  Looks like you get to make the first move\n";
            cout << "\n";
            cout << "  Press ENTER to continue\n";
            cin.ignore (1);
            Player_Turn ();
        }
        else if (coin == 2)
        {
            cout << "\n";
            cout << "  The computer gets to strike first\n";
            cout << "\n";                        
            cout << "  Press ENTER to continue\n";
			cin.ignore (1);
            Enemy_Turn ();
        }
    }
    
    void Toss () 
    {
		srand ((unsigned int) time (NULL));
        coin = rand () % 2 + 1;
    }

    void Player_Turn () 
    {
        gameOver_check = false;
        cout << "\n";
        for (int i =1; i <= 90; i++)
        {
            cout << " ";
        }
        cout << "          The Computer's Battleships Grid : \n";
        cout << "\n";
        Display_Enemy_Game ();
        cout << "\n";
        cout << "\n";
        cout << "                  Admiral " << Name << "'s Battleships Grid :\n";
        cout << "\n";
        Display_Player_Game ();
        cout << "\n";
        if (toggle_PowerUps == true)
        {
            cout << "  AVAILABLE POWER - UPS : \n";
            cout << "  Aerial Reconnaissance (AR) x " << player_AR << "   Cruise Missile (CM) x " << player_cruiseMissile << "   Reinforce (R) x " << player_reinforce << "   Force Field (FF) x " << player_forceField << "   Torpedo (T) x " << player_torpedo << "\n";
            cout << "\n";
            cout << "  Enter the POWER - UP code, given in ( ) to use the corresponding POWER - UP. For example, enter 'AR' to use Aerial Reconnaissance. \n  Enter anything else to skip using a POWER - UP\n";
            cout << "  ";
            cin >> input;
            cout << "\n";
            if ((input == "AR" || input == "ar" || input == "Ar" || input == "aR") && player_AR >= 1)
            {
                cout << "  Aerial Reconnaissance was used - a part of the enemy's grid was revealed\n";
                AR = true;
                player_AR--;
            }
            else if ((input == "AR" || input == "ar" || input == "Ar" || input == "aR") && player_AR < 1)
            {
                cout << "  You have already used the Aerial Reconnaissance POWER - UP\n";
            }
            if ((input == "CM" || input == "cm" || input == "Cm" || input == "cM") && player_cruiseMissile >= 1)
            {
                cout << "  A Cruise Missile was used. Enter a Row No. or Column Letter (e.g. 3 or D) to destroy all ships located along that row or column\n";
                cout << "  ";
                cin >> input;
                if (input == "10" || (input [0] >= 48 && input [0] <= 57))
                {
					parseInt = input.substr (0,2);
					if (parseInt == "10")
					{
						parseValue = 9;
					}
					else
					{
						parseValue = parseInt [0] - '1';
					}
                    for (int i = 0; i < 10; i++)
                    {
                        enemy [parseValue][i] = false;
                        if (enemy [parseValue][i] != enemy_aircraftCarrier [parseValue][i])
                        {
                            struckShip = "Aircraft Carrier";
                            enemy_aircraftCarrier [parseValue][i] = false;                
                        }
                        else if (enemy [parseValue][i] != enemy_destroyer [parseValue][i])
                        {
                            struckShip = "Destroyer";
                            enemy_destroyer [parseValue][i] = false;
                        }
                        else if (enemy [parseValue][i] != enemy_cruiser [parseValue][i])
                        {
                            struckShip = "Cruiser";
                            enemy_cruiser [parseValue][i] = false;
                        }
                        else if (enemy [parseValue][i] != enemy_submarine [parseValue][i])
                        {
                            struckShip = "Submarine";
                            enemy_submarine [parseValue][i] = false;
                        }
                        else if (enemy [parseValue][i] != enemy_frigate [parseValue][i])
                        {
                            struckShip = "Frigate";
                            enemy_frigate [parseValue][i] = false;
                        }           
                    }
                }
                else if (input [0] >= 65 && input [0] <= 122)
                {
                    indexSection = input.substr (0,1);
					if (indexSection [0] >= 97)
					{
						indexSection [0] = indexSection [0] - 32;
					}
                    for (int i = 0; i < 10; i++)
                    {
                        if (index [i] == indexSection)
                        {
                            record = i;
                        }
                    }
                    for (int i = 0; i < 10; i++)
                    {
                        enemy [i][record] = false;
                        if (enemy [i][record] != enemy_aircraftCarrier [i][record])
                        {
                            struckShip = "Aircraft Carrier";
                            enemy_aircraftCarrier [i][record] = false;                
                        }
                        else if (enemy [i][record] != enemy_destroyer [i][record])
                        {
                            struckShip = "Destroyer";
                            enemy_destroyer [i][record] = false;
                        }
                        else if (enemy [i][record] != enemy_cruiser [i][record])
                        {
                            struckShip = "Cruiser";
                            enemy_cruiser [i][record] = false;
                        }
                        else if (enemy [i][record] != enemy_submarine [i][record])
                        {
                            struckShip = "Submarine";
                            enemy_submarine [i][record] = false;
                        }
                        else if (enemy [i][record] != enemy_frigate [i][record])
                        {
                            struckShip = "Frigate";
                            enemy_frigate [i][record] = false;
                        }           
                    }
                }
                player_cruiseMissile--;
            }
            else if ((input == "CM" || input == "cm" || input == "Cm" || input == "cM") && player_cruiseMissile < 1)
            {
                cout << "  You have already used the Cruise Missile POWER - UP\n";
            }
            if ((input == "R" || input == "r") && player_reinforce >= 1)
            {
                cout << "  Reinforce was used. Enter the co-ordinates of a grid-square, where you'd like to repair one of your destroyed Battleships (e.g. G3)\n";
                cout << "  ";
                cin >> input;
                cout << "\n";
                indexSection = input.substr (0,1);
				if (indexSection [0] >= 97)
				{
					indexSection [0] = indexSection [0] - 32;
				}
                for (int i = 0; i < 10; i++)
                {
                    if (index [i] == indexSection)
                    {
                        record = i;
                    }
                }
				parseInt = input.substr (1,2);
				if (parseInt == "10")
				{
					parseValue = 9;
				}
				else
				{
					parseValue = parseInt [0] - '1';
				}
                if (player [parseValue][record] == false && playerDisplay [parseValue][record] == true)
                {
                    player_reinforce--;
                    player [parseValue][record] = true;
                    hitRecord [parseValue][record] = false;
                    cout << "  Enter the initial of the repaired Battleship. E.g. 'A' (Aircraft Carrier) 'D' (Destroyer) 'C' (Cruiser) 'S' (Submarine) 'F' (Frigate)\n";
                    cout << "  ";
                    cin >> option;
                    cout << "\n";
                    if (option == "a" || option == "A")
                    {
                        player_aircraftCarrier [parseValue][record] = true;
                    }
                    if (option == "d" || option == "D")
                    {
                        player_destroyer [parseValue][record] = true;
                    }
                    if (option == "c" || option == "C")
                    {
                        player_cruiser [parseValue][record] = true;
                    }
                    if (option == "s" || option == "S")
                    {
                        player_submarine [parseValue][record] = true;
                    }
                    if (option == "f" || option == "F")
                    {
                        player_frigate [parseValue][record] = true;
                    }
                    cout << "  Your Battleship at grid-square " << input << " was repaired!\n";
                }
                else
                {
                    cout << "  Invalid co-ordinates. Please enter co-ordinates of a previously destroyed Battleship.\n";
                }
            }
            else if ((input == "R" || input == "r") && player_reinforce < 1)
            {
                cout << "  You have already used the Reinforce POWER - UP\n";
            }
            if ((input == "FF" || input == "ff" || input == "Ff" || input == "fF") && player_forceField >= 1)
            {
                cout << "  Force Field was used. Your Battleships received an extra turn.\n";
                Force_Field = true;
                player_forceField--;
            }
            else if ((input == "FF" || input == "ff" || input == "Ff" || input == "fF") && player_forceField < 1)
            {
                cout << "  You have already used the Force Field POWER - UP.\n";
            }
            if ((input == "T" || input == "t") && player_torpedo >= 1)
            {
                cout << "  Torpedo was used. A random component of an enemy Battleship was destroyed.\n";
                while (condition == false)
                {
					srand ((unsigned int) time (NULL));
                    torpedoX = rand () % 10;
					srand ((unsigned int) time (NULL));
                    torpedoY = rand () % 10;
                    if (enemy [torpedoX][torpedoY] == true)
                    {
                        enemy [torpedoX][torpedoY] = false;
                        if (enemy [torpedoX][torpedoY] != enemy_aircraftCarrier [torpedoX][torpedoY])
                        {
                            struckShip = "Aircraft Carrier";
                            enemy_aircraftCarrier [torpedoX][torpedoY] = false;                
                        }
                        else if (enemy [torpedoX][torpedoY] != enemy_destroyer [torpedoX][torpedoY])
                        {
                            struckShip = "Destroyer";
                            enemy_destroyer [torpedoX][torpedoY] = false;
                        }
                        else if (enemy [torpedoX][torpedoY] != enemy_cruiser [torpedoX][torpedoY])
                        {
                            struckShip = "Cruiser";
                            enemy_cruiser [torpedoX][torpedoY] = false;
                        }
                        else if (enemy [torpedoX][torpedoY] != enemy_submarine [torpedoX][torpedoY])
                        {
                            struckShip = "Submarine";
                            enemy_submarine [torpedoX][torpedoY] = false;
                        }
                        else if (enemy [torpedoX][torpedoY] != enemy_frigate [torpedoX][torpedoY])
                        {
                            struckShip = "Frigate";
                            enemy_frigate [torpedoX][torpedoY] = false;
                        }           
                        condition = true;
                    }
                }
                player_torpedo--;
            }
            else if ((input == "T" || input == "t") && player_torpedo < 1)
            {
                cout << "  You have already used the Torpedo POWER - UP.\n";
            }
            cout << "  Press ENTER to continue\n";
            cin.ignore (1);
            cout << "\n";
            for (int i =1; i <= 90; i++)
            {
                cout << " ";
            }
            cout << "          The Computer's Battleships Grid : \n";
            cout << "\n";
            Display_Enemy_Game ();
            cout << "\n";
            cout << "\n";
            cout << "                  Admiral " << Name << "'s Battleships Grid :\n";
            cout << "\n";
            Display_Player_Game ();
            cout << "\n";
        }  
        cout << "  Enter the co-ordinates of an enemy grid-square which you'd like your Battleships to attack (e.g. G3)\n";
        cout << "  ";
        cin >> input;
        cout << "\n";
        indexSection = input.substr (0,1);
		if (indexSection [0] >= 97)
		{
			indexSection [0] = indexSection [0] - 32;
		}
        for (int i = 0; i < 10; i++)
        {
            if (index [i] == indexSection)
            {
                record = i;
            }
        }
		parseInt = input.substr (1,2);
			if (parseInt == "10")
			{
				parseValue = 9;
			}
			else
			{
				parseValue = parseInt [0] - '1';
			}
        if (enemy [parseValue][record] == true)
        {
            enemy [parseValue][record] = false;
            if (enemy [parseValue][record] != enemy_aircraftCarrier [parseValue][record])
            {
                struckShip = "Aircraft Carrier";
                enemy_aircraftCarrier [parseValue][record] = false;                
            }
            else if (enemy [parseValue][record] != enemy_destroyer [parseValue][record])
            {
                struckShip = "Destroyer";
                enemy_destroyer [parseValue][record] = false;
            }
            else if (enemy [parseValue][record] != enemy_cruiser [parseValue][record])
            {
                struckShip = "Cruiser";
                enemy_cruiser [parseValue][record] = false;
            }
            else if (enemy [parseValue][record] != enemy_submarine [parseValue][record])
            {
                struckShip = "Submarine";
                enemy_submarine [parseValue][record] = false;
            }
            else if (enemy [parseValue][record] != enemy_frigate [parseValue][record])
            {
                struckShip = "Frigate";
                enemy_frigate [parseValue][record] = false;
            }           
            cout << "  Score! Your missile hit a " << struckShip << " on that grid-square!\n";
            cout << "\n";
            if (struckShip == "Aircraft Carrier")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (enemy_aircraftCarrier [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Destroyer")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (enemy_destroyer [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Cruiser")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (enemy_cruiser [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Submarine")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (enemy_submarine [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Frigate")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (enemy_frigate [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            if (check == false)
            {
                cout << "  You've just sunk an enemy " << struckShip << "!!!\n";
                cout << "\n";
            }
        }        
        else
        {
            cout << "  Your missile missed its mark! No enemy Battleship was present on that grid-square!\n";
        }
        cout << "\n";
        turns++;
        struckShip = "";
        check = false;
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                if (enemy [m][n] == true)
                {
                    gameOver_check = true;
                }
            }
        }
        cout << "  Press ENTER to end your turn\n";
        cin.ignore (2);
        if (gameOver_check == true && Force_Field == false)
        {
            Enemy_Turn ();        
        }
        else if (gameOver_check == true && Force_Field == true)
        {
            Force_Field = false;
            Player_Turn ();
        }
        else if (gameOver_check == false)
        {
            for (int i =1; i <= 90; i++)
            {
                cout << " ";
            }
            cout << "          The Computer's Battleships Grid : \n";
            cout << "\n";
            Display_Enemy_Game ();
            cout << "\n";
            cout << "\n";
            cout << "                  Admiral " << Name << "'s Battleships Grid :\n";
            cout << "\n";
            Display_Player_Game ();
            cout << "\n";
            victory = true;
            Game_Over ();
        }
    }
    
    void Enemy_Turn () 
    {
        gameOver_check = false;
        cout << "\n";
        for (int i =1; i <= 90; i++)
        {
            cout << " ";
        }
        cout << "          The Computer's Battleships Grid : \n";
        cout << "\n";
        Display_Enemy_Game ();
        cout << "\n";
        cout << "\n";
        cout << "                  Admiral " << Name << "'s Battleships Grid :\n";
        cout << "\n";
        Display_Player_Game ();
        cout << "\n";
        while (complete == false && hitPlayer == false && timer < 5)
        {
			srand ((unsigned int) time (NULL));
            Random_1 = rand () % 10;
			srand ((unsigned int) time (NULL));
            Random_2 = rand () % 10;
            if (hitRecord [Random_1][Random_2] == false)
            {
                complete = true;
            }
        }
        complete = false;
        if (toggle_PowerUps == true)
        {
            timer = timer + 2;
        }
        if (timer >= 5 && hitPlayer == false)
        {
            timer = 0;
            while (complete == false && hitPlayer == false)
            {
                srand ((unsigned int) time (NULL));
				Random_1 = rand () % 10;
				srand ((unsigned int) time (NULL));
				Random_2 = rand () % 10;
                if (hitRecord [Random_1][Random_2] == false && player [Random_1][Random_2] == true)
                {
                    complete = true;
                }
            }
        }   
        
        if (hitPlayer == true)
        {
            if (seed == 0 && scan1 > 0)
            {
                Random_1 = scan1 - 1;
                Random_2 = scan2;
            }
            if (seed == 0 && scan1 <= 0)
            {
                seed++;
            }
            if (seed == 1 && scan2 < 9)
            {
                Random_1 = scan1;
                Random_2 = scan2 + 1;
            }
            if (seed == 1 && scan2 >= 9)
            {
                seed++;
            }            
            if (seed == 2 && scan1 < 9)
            {
                Random_1 = scan1 + 1;
                Random_2 = scan2;
            }
            if (seed == 2 && scan1 >= 9)
            {
                seed++;
            }
            if (seed == 3 && scan2 > 0)
            {
                Random_1 = scan1;
                Random_2 = scan2 - 1;
            }
            if (seed == 3 && scan2 <= 0)
            {
                seed = 0;
            }
            streak++;
        }
               
        if (player [Random_1][Random_2] == false && hitPlayer == true)
        {
            if (streak > 0)
            {
                if (seed == 0)
                {
                    if (Random_1 + streak + 1 < 10)
                    {
                        if (player [Random_1 + streak + 1][Random_2] == true)
                        {
                            Random_1 = Random_1 + streak + 1;
                            streak = 0;
                        }
                    }
                    else
                    {
                        seed++;
                        streak = 0;
                    }
                }
                else if (seed == 1)
                {
                    if (Random_2 - streak - 1 >= 0)
                    {
                        if (player [Random_1][Random_2 - streak - 1] == true)
                        {
                            Random_2 = Random_2 - streak - 1;
                            streak = 0;
                        }
                    }
                    else
                    {
                        seed++;
                        streak = 0;
                    }
                }
                else if (seed == 2)
                {
                    if (Random_1 - streak - 1 >= 0)
                    {
                        if (player [Random_1 - streak - 1][Random_2] == true)
                        {
                            Random_1 = Random_1 - streak - 1;
                            streak = 0;
                        }
                    }
                    else
                    {
                        seed++;
                        streak = 0;
                    }
                }
                else if (seed == 3)
                {
                    if (Random_2 + streak + 1 < 10)
                    {
                        if (player [Random_1][Random_2 + streak + 1] == true)
                        {
                            Random_2 = Random_2 + streak + 1;
                            streak = 0;
                        }
                    }
                    else
                    {
                        seed = 0;
                        streak = 0;
                    }
                }
            }
            else
            {
                streak = 0;
                if (seed <= 2)
                {
                    seed++;
                }
                else
                {
                    seed = 0;
                }
            }
        }
        
        hitRecord [Random_1][Random_2] = true;
            
        if (player [Random_1][Random_2] == true)
        {
            player [Random_1][Random_2]  = false;
            timer = 0;
            hitPlayer = true;
            scan1 = Random_1;
            scan2 = Random_2;
            if (player [Random_1][Random_2] != player_aircraftCarrier [Random_1][Random_2])
            {
                struckShip = "Aircraft Carrier";
                player_aircraftCarrier [Random_1][Random_2]  = false;   
                length = 5;
            }
            else if (player [Random_1][Random_2] != player_destroyer [Random_1][Random_2])
            {
                struckShip = "Destroyer";
                player_destroyer [Random_1][Random_2] = false;
                length = 4;
            }
            else if (player [Random_1][Random_2] != player_cruiser [Random_1][Random_2])
            {
                struckShip = "Cruiser";
                player_cruiser [Random_1][Random_2] = false;
                length = 4;
            }
            else if (player [Random_1][Random_2] != player_submarine [Random_1][Random_2])
            {
                struckShip = "Submarine";
                player_submarine [Random_1][Random_2] = false;
                length = 3;
            }
            else if (player [Random_1][Random_2] != player_frigate [Random_1][Random_2])
            {
                struckShip = "Frigate";
                player_frigate [Random_1][Random_2] = false;
                length = 2;
            }           
            cout << "  Blast! The enemy missile hit your " << struckShip << " on that grid-square!\n";
            cout << "\n";
            if (struckShip == "Aircraft Carrier")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (player_aircraftCarrier [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Destroyer")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (player_destroyer [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Cruiser")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (player_cruiser [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Submarine")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (player_submarine [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            else if (struckShip == "Frigate")
            {
                for (int m = 0; m < 10; m++)
                {
                    for (int n = 0; n < 10; n++)
                    {
                        if (player_frigate [m][n] == true)
                        {
                            check = true;
                        }
                    }
                }
            }
            if (check == false)
            {
                cout << "  The Computer has just destroyed your " << struckShip << "!!!\n";
                cout << "\n";
                hitPlayer = false;
                streak = 0;
                seed = 0;
            }
        }        
        else
        {
            cout << "  The enemy missile missed! None of your Battleships were present on that grid-square!\n";
        }
        cout << "\n";
        struckShip = "";
        timer++;
        check = false;
        complete = false;
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                if (player [m][n] == true)
                {
                    gameOver_check = true;
                }
            }
        }
        cout << "  Press ENTER to continue\n";
        cin.ignore (1);
        if (gameOver_check == true)
        {
            Player_Turn ();        
        }
        else
        {
            for (int i =1; i <= 90; i++)
            {
                cout << " ";
            }
            cout << "          The Computer's Battleships Grid : \n";
            cout << "\n";
            Display_Enemy_Game ();
            cout << "\n";
            cout << "\n";
            cout << "                  Admiral " << Name << "'s Battleships Grid :\n";
            cout << "\n";
            Display_Player_Game ();
            cout << "\n";
            victory = false;
            Game_Over ();
        }
    }
    
    void Reset_Player_Data () 
    {
        destroyerCount = 1;
        aircraft_carrierCount = 1;
        cruiserCount = 1;
        submarineCount = 1;
        frigateCount = 1;
        positionCount = 0;
    }
    
    void Player_Refresh () 
    {
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                player [m][n] = false;
                playerDisplay [m][n] = false;
                player_aircraftCarrier [m][n] = false;
                player_destroyer [m][n] = false;                
                player_cruiser [m][n] = false;
                player_submarine [m][n] = false;                
                player_frigate [m][n] = false;
            }
        }
    }
    
    void Enemy_Refresh () 
    {
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                enemy [m][n] = false;
                enemyDisplay [m][n] = false;
                enemy_aircraftCarrier [m][n] = false;
                enemy_destroyer [m][n] = false;                
                enemy_cruiser [m][n] = false;
                enemy_submarine [m][n] = false;                
                enemy_frigate [m][n] = false; 
            }
        }
    }

    void Game_Over () 
    {
        cout << "\n";
        if (victory == true)
        {
            cout << "  CONGRATULATIONS!!! You successfully destroyed the Computer's entire fleet without losing all your Battleships!\n";
            cout << "\n";
            cout << "  Admiral " << Name << " WINS !!!! (Hallelujah and all that)\n";
        }
        else
        {
            cout << "  GRRRRR!!! You were brutally crushed by the Computer's fleet of Battleships! Better luck next time\n";
            cout << "\n";
            cout << "  The Computer WINS !!!! (cue depressing music)\n";
        }
        Ending ();
    }
    
    void Ending () 
    {
        Calculate_Score ();
        Save_Score ();
        Credits ();
		BattleShips ();
        Title_Screen ();
    }
    
    void Calculate_Score () 
    {
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                if (player [m][n] == true)
                {
                    remainingShips++;
                }
            }
        }
        score = (int)(((10 + remainingShips) * 100) / turns) + (100 - (2 * turns));
        if (toggle_PowerUps == false)
        {
            score = score * 2;
        }
        if (victory == true)
        {
            score = score * 3;
        }
    }
    
    void Save_Score () 
    {
        cout << "\n";
        for (int i = 1; i <= 181; i++)
        {
            cout << "-";
        }
        cout << "\n"; 
        cout << "\n";
        cout << "  Admiral " << Name << "\n";
        cout << "  Your final score is " << score << "\n";
        cout << "\n";
        if (score >= 150)
        {
            cout << "  Would you like to add your score to the High Scores Table? (y/n)\n";
            cout << "  ";
            cin >> option;
            cout << "\n";
            if (option == "y" || option == "Y")
            {
				ofstream outputFile;
				outputFile.open ("High Scores.hst", ios::out | ios::app);
				outputFile << Name << "\n";
				outputFile << score << "\n";
				outputFile.close ();                
                cout << "  Your name has been added to the list of High Scores!\n";
            }
            else if (option == "n" || option == "N")
            {
                cout << "  Your score was not saved to the High Scores Table.\n";
            }
        }
        else if (score < 150)
        {
            cout << "  You aren't eligible for a spot on the High Scores Table yet. Better luck next time!\n";
        }
    }
    
    void Credits () 
    {
        for (int i = 1; i <= 3; i++)
        {
            cout << "\n";
        }
        for (int i = 1; i <= 181; i++)
        {
            cout << "=";
        }
        cout << "\n";
        for (int i = 1; i <= 5; i++)
        {
            cout << "\n";
        }
        cout << "  BattleShips (c) 2013  P Santy Blesson, Simranjeet Singh, Indrayudh Roy\n";
        cout << "\n";
        cout << "  BattleShips is available 'as is' free of charge for use and non-commercial re-distribution. Disassembly of the\n";
        cout << "  system is prohibited. This software may not be sold for profit or included in other packages which are sold for\n";
        cout << "  profit without written authorisation.\n";
        cout << "\n";
        cout << "  All Rights Reserved :)\n";
        cout << "\n";
        cout << "  Press ENTER to continue\n";
        cin.ignore (2);
    }
};

void main ()
{
  	BattleShips play;
	play.Title_Screen ();
}
	
