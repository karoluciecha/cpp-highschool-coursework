#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int GRID_SIZE = 10;
int computerGrid[GRID_SIZE][GRID_SIZE];
int playerGrid[GRID_SIZE][GRID_SIZE];

int lastHit = -1;
int lastHitShipID = 0;

int lastPlayerHit = -1;
int lastPlayerHitShipID = 0;

struct Ship
{
    int size;
    int remainingParts;
    int coordinates[10][2];
};

Ship playerShips[10];
Ship computerShips[10];

void placeShip(Ship fleet[], int grid[][GRID_SIZE], int shipID, int size, int coords[][2])
{
    fleet[shipID].size = size;
    fleet[shipID].remainingParts = size;
    for (int i = 0; i < size; i++)
    {
        fleet[shipID].coordinates[i][0] = coords[i][0];
        fleet[shipID].coordinates[i][1] = coords[i][1];
        grid[coords[i][0]][coords[i][1]] = shipID;
    }
}

int getRandom(int max) {
    return rand() % max;
}

void generateFleet(Ship fleet[], int grid[][GRID_SIZE], void (*placeFunction)(Ship[], int[][GRID_SIZE], int, int, int[][2]))
{
    for (int size = 1; size <= 5; size++)
    {
        int x, y, orientation;
        int shipCoords[5][2];
        
        do {
            x = getRandom(GRID_SIZE);
            y = getRandom(GRID_SIZE);
            orientation = getRandom(2);
        } while ((orientation == 1 && y + size > GRID_SIZE) || (orientation == 0 && x + size > GRID_SIZE));
        
        for (int i = 0; i < size; i++) {
            shipCoords[i][0] = orientation == 0 ? x + i : x;
            shipCoords[i][1] = orientation == 1 ? y + i : y;
        }
        
        placeFunction(fleet, grid, size, size, shipCoords);
    }
}

void initializeGame()
{
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
        {
            computerGrid[i][j] = 0;
            playerGrid[i][j] = 0;
        }
    
    generateFleet(playerShips, playerGrid, placeShip);
    generateFleet(computerShips, computerGrid, placeShip);
}

int countRemainingShips(Ship fleet[])
{
    int count = 0;
    for (int i = 1; i <= 5; i++)
        if (fleet[i].remainingParts > 0)
            count++;
    return count;
}

bool attack(const string& attacker, int x, int y, int grid[][GRID_SIZE], Ship fleet[], int &lastHit, int &lastHitShipID)
{
    cout << attacker << " strikes position (" << x << ", " << y << ") and... ";
    
    if (grid[x][y] > 0)
    {
        int shipID = grid[x][y];
        fleet[shipID].remainingParts--;
        lastHit = (fleet[shipID].remainingParts > 0) ? 1 : 0;
        lastHitShipID = shipID;
        grid[x][y] = -1;
        
        if (lastHit == 1)
            cout << "Hit! Ship was damaged!" << endl;
        else
            cout << "Drown! Ship was sunk!" << endl;
        
        return true;
    }
    grid[x][y] = -2;
    cout << "Miss! Nothing's there." << endl;
    return false;
}

void displayGrid()
{
    cout << "-----------------------------------------" << endl;
    cout << "-         Welcome to Battleship!        -" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "-      Computer:              Player:   -" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "  0 1 2 3 4 5 6 7 8 9       0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        cout << i << " ";
        for (int j = 0; j < GRID_SIZE; j++)
            cout << (computerGrid[i][j] == -1 ? "X " : computerGrid[i][j] == -2 ? "O " : "~ ");
        cout << "     " << i << " ";
        for (int j = 0; j < GRID_SIZE; j++)
            cout << (playerGrid[i][j] == -1 ? "X " : playerGrid[i][j] == -2 ? "O " : "~ ");
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Remaining Ships: " << countRemainingShips(computerShips) << "     "
         << "Remaining Ships: " << countRemainingShips(playerShips) << endl;
    cout << "-----------------------------------------\n" << endl;
}

void runBattleShipProgram()
{
    srand(static_cast<unsigned int>(time(NULL)));
    initializeGame();

    int x, y;
    
    while (countRemainingShips(computerShips) > 0 && countRemainingShips(playerShips) > 0)
    {
        displayGrid();
        
        do {
            cout << "Enter attack coordinates (x y): ";
            cin >> x >> y;
            if (cin.fail() || x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || computerGrid[x][y] < 0) {
                cout << "Invalid input! Either out of range or already attacked. Try again.\n" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || computerGrid[x][y] < 0);
        
        attack("\nPlayer", x, y, computerGrid, computerShips, lastHit, lastHitShipID);
        
        do {
            x = getRandom(GRID_SIZE);
            y = getRandom(GRID_SIZE);
        } while (playerGrid[x][y] < 0);
        attack("Computer", x, y, playerGrid, playerShips, lastPlayerHit, lastPlayerHitShipID);
    }
    
    displayGrid();
    cout << ((countRemainingShips(computerShips) == 0) ? "You win!" : "Computer wins!") << endl;
}