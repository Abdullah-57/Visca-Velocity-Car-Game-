#pragma once

# include <iostream>
# include <thread>
# include <chrono>
# include <Windows.h>
#include<fstream>
#include<sstream>
using namespace std;

class Node;

class ScoresNode
{
public:
    int score;
    ScoresNode* next;

    ScoresNode(int score) : score(score), next(NULL) {}
};

class MilestoneNode
{
public:
    int milestone;
    MilestoneNode* next;

    MilestoneNode(int milestone) : milestone(milestone), next(NULL) {}
};

class MilestoneLinkedList
{
public:
    MilestoneNode* head;
    MilestoneNode* tail;

    MilestoneLinkedList() : head(NULL), tail(NULL) {}

    void addMilestone(int milestone) {
        MilestoneNode* newNode = new MilestoneNode(milestone);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printMilestones() {
        MilestoneNode* current = head;

        cout << "Milestones: ";
        while (current != NULL)
        {
            cout << current->milestone << " ";
            current = current->next;
        }

        cout << endl;
    }
};

class ScoresLinkedList
{
public:
    ScoresNode* head;
    ScoresNode* tail;

    ScoresLinkedList() : head(NULL), tail(NULL) {}

    void addScore(int score) {
        ScoresNode* newNode = new ScoresNode(score);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printScores() {
        ScoresNode* current = head;

        cout << "Scores: ";
        while (current != NULL)
        {
            cout << current->score << " ";
            current = current->next;
        }

        cout << endl;
    }
};

class CoinsCollectedNode
{
public:
    int x;
    //int y;
    CoinsCollectedNode* next;

    CoinsCollectedNode(int x) : x(x), next(NULL) {}
};

class CoinsCollectedLinkedList
{
public:
    CoinsCollectedNode* head;
    CoinsCollectedNode* tail;

    CoinsCollectedLinkedList() : head(NULL), tail(NULL) {}

    void addCoins(int x)
    {
        CoinsCollectedNode* newNode = new CoinsCollectedNode(x);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printCoins()
    {
        CoinsCollectedNode* current = head;

        cout << "Collected Coins: ";
        while (current != NULL)
        {
            cout << "(" << current->x << ", " << ") ";
            current = current->next;
        }

        cout << endl;
    }
};

class LinkedList
{
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    void addNode(Node* node);
    Node* getNode(int index);
};


class Node
{
public:
    char value;
    LinkedList neighbors;
    Node* next;

    Node(char val) : value(val), next(NULL) {}
};

class Coin {
public:
    int value;
    int x, y;
    bool collected;  // New variable to track whether the coin has been collected
    Coin* next;

    Coin(int val, int x, int y) : value(val), x(x), y(y), collected(false), next(nullptr) {}
};



void LinkedList::addNode(Node* node)
{
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

Node* LinkedList::getNode(int index)
{
    Node* current = head;
    for (int i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }
    return current;
}

class Queue
{
public:
    Node* front;
    Node* rear;

    Queue() : front(NULL), rear(NULL) {}

    void enqueue(Node* node)
    {
        if (rear == NULL)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
    }

    Node* dequeue()
    {
        if (front == NULL)
            return NULL;

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        return temp;
    }

    bool isEmpty()
    {
        return front == NULL;
    }
};

class Car
{
public:
    int health;
    int score;
    int x, y;
    char originalValue;

    Car()
    {
        health = 0;
        score = 0;
        x = 0;
        y = 0;
    }

    Car(int health, int x, int y)
    {
        this->health = health;
        this->x = x;
        this->y = y;
    }

    Car(int health, int score, int x, int y)
    {
        this->health = health;
        this->score = score;
        this->x = x;
        this->y = y;
    }

    void move(char direction, Node*** grid, int GRID_SIZE)
    {
        // Save the original value before moving
        originalValue = grid[x][y]->value;

        // Temporary variables for new position
        int newX = x;
        int newY = y;

        switch (direction)
        {
        case 'w':
            newX = max(1, newX - 1);  // Ensure newX doesn't go below 1 (just above the '#' boundary)
            break;
        case 'a':
            newY = max(1, newY - 1);  // Ensure newY doesn't go below 1 (just to the left of the '#' boundary)
            break;
        case 's':
            newX = min(GRID_SIZE - 2, newX + 1);  // Ensure newX doesn't go beyond GRID_SIZE - 2 (just below the '#' boundary)
            break;
        case 'd':
            newY = min(GRID_SIZE - 2, newY + 1);  // Ensure newY doesn't go beyond GRID_SIZE - 2 (just to the right of the '#' boundary)
            break;
        default:
            cout << "Invalid Move! \n";
            return;  // Don't proceed with the move if it's invalid
        }


        // Move the car to the new position
        x = newX;
        y = newY;

        // Clear the previous position
        grid[x][y]->value = originalValue;

    }



};

class Graph
{
public:
    int GRID_SIZE;
    Node*** grid;
    Car* car;
    Queue obstacles;
    bool** pickedUpPowerUps;
    Coin* coinsHead;

    void generateCoins(int numCoins) {
        for (int i = 0; i < numCoins; ++i) {
            int x, y;
            do {
                x = rand() % GRID_SIZE;
                y = rand() % GRID_SIZE;
            } while (grid[x][y]->value == 35 || grid[x][y]->value == 80 || (x == car->x && y == car->y));

            Coin* coin = new Coin(10, x, y);
            coin->next = coinsHead;
            coinsHead = coin;

            grid[x][y]->value = '$';  // Represent a coin with '$'
        }
    }



    void generateObstacle()
    {
        int x, y;
        do
        {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y]->value == 35 || grid[x][y]->value == 80 || (x == car->x && y == car->y));  // Ensure the obstacle is not placed on a wall or on the car

        if (rand() % 10 == 0)
        {
            grid[x][y]->value = 80;
        }
        else
        {
            grid[x][y]->value = 88;  // Set the obstacle
            obstacles.enqueue(grid[x][y]);  // Enqueue the obstacle
        }

    }

    Graph(int difficulty)
    {
        // Set GRID_SIZE based on difficulty level
        if (difficulty == 1)
        {
            GRID_SIZE = 20;
        }
        else if (difficulty == 2)
        {
            GRID_SIZE = 30;
        }
        else if (difficulty == 3)
        {
            GRID_SIZE = 40;
        }
        else
        {
            cout << "Invalid difficulty level. Defaulting to easy (10x10 grid)." << endl;
            GRID_SIZE = 10;
        }

        // Create the grid
        grid = new Node * *[GRID_SIZE];
        for (int i = 0; i < GRID_SIZE; i++)
        {
            grid[i] = new Node * [GRID_SIZE];
        }

        // Initialize grid with nodes and random connections
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (i == 0 || j == 0 || i == GRID_SIZE - 1 || j == GRID_SIZE - 1)
                {
                    grid[i][j] = new Node(35); // Walls
                }
                else if (i % 2 == 0 && j % 2 == 0)
                {
                    grid[i][j] = new Node(43); // Nodes represented by '+'
                }
                else
                {
                    grid[i][j] = new Node(32); // Empty space

                    // Randomly connect nodes with paths
                    if (rand() % 2 == 0)
                    {
                        grid[i][j]->value = 124; // Vertical path represented by '|'
                    }
                    else
                    {
                        grid[i][j]->value = 45; // Horizontal path represented by '-'
                    }
                }
            }
        }

        grid[GRID_SIZE / 2][GRID_SIZE / 2]->value = 67; // Car

        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (i > 0)
                    grid[i][j]->neighbors.addNode(grid[i - 1][j]); // Up
                if (j > 0)
                    grid[i][j]->neighbors.addNode(grid[i][j - 1]); // Left
                if (i < GRID_SIZE - 1)
                    grid[i][j]->neighbors.addNode(grid[i + 1][j]); // Down
                if (j < GRID_SIZE - 1)
                    grid[i][j]->neighbors.addNode(grid[i][j + 1]); // Right
            }
        }

        // Set the car in the middle

        // Create the car
        car = new Car(difficulty == 1 ? 50 : difficulty == 2 ? 35 : 20, 0, 1, 2);
        grid[car->x][car->y]->value = 67; // Car

        // Initialize pickedUpPowerups array
        pickedUpPowerUps = new bool* [GRID_SIZE];
        for (int i = 0; i < GRID_SIZE; i++)
        {
            pickedUpPowerUps[i] = new bool[GRID_SIZE];
            for (int j = 0; j < GRID_SIZE; j++)
            {
                pickedUpPowerUps[i][j] = false;
            }
        }

    }
    int coinsCount = 0;

    bool isPowerupPickedUp(int x, int y)
    {
        return pickedUpPowerUps[x][y];
    }

    void pickUpPowerup(int x, int y)
    {
        pickedUpPowerUps[x][y] = true;
    }

    int countPickedUpPowerups()
    {
        int count = 0;
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (pickedUpPowerUps[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool moveCar(char direction)
    {
        int nextX = car->x + (direction == 's' ? 1 : direction == 'w' ? -1 : 0);
        int nextY = car->y + (direction == 'd' ? 1 : direction == 'a' ? -1 : 0);

        // Check if the next coordinate is within the grid boundaries and is not a space
        if (nextX >= 0 && nextX < GRID_SIZE && nextY >= 0 && nextY < GRID_SIZE &&
            grid[nextX][nextY]->value != ' ')
        {
            char nextValue = grid[nextX][nextY]->value;

            // Clear the previous position
            grid[car->x][car->y]->value = car->originalValue;

            car->move(direction, grid, GRID_SIZE);

            car->originalValue = nextValue;

            // Set the new position value
            grid[car->x][car->y]->value = 'C';

            car->score = car->score + 1;

            if (nextValue == 'P' && !isPowerupPickedUp(nextX, nextY))
            {
                car->score = car->score * 2;
                pickUpPowerup(nextX, nextY);
                grid[nextX][nextY]->value = ' ';
                generateObstacle();
            }
            else if (nextValue == '$') // If the car collects a coin
            {
                car->score = car->score + 5;

                coinsCount++;

                if (coinsHead != nullptr)
                {
                    Coin* currentCoin = coinsHead;
                    Coin* prevCoin = nullptr;

                    while (currentCoin != nullptr)
                    {
                        if (currentCoin->x == nextX && currentCoin->y == nextY)
                        {
                            currentCoin->collected = true;  // Set the collected flag to true
                            grid[nextX][nextY]->value = ' '; // Removing the coin from the grid

                            // Generate a new obstacle after collecting the coin
                            generateObstacle();
                            break;
                        }

                        prevCoin = currentCoin;
                        currentCoin = currentCoin->next;
                    }
                }
            }
            else if (nextValue == 'X') // If the car collides with an obstacle
            {
                car->health = car->health - 5;
                car->score = car->score - 5;

                if (car->health <= 0)
                {
                    cout << "Game Over! Health reached 0." << endl;
                    cout << "Final Health: " << car->health << endl;
                    cout << "Final Score: " << car->score << endl;
                    cout << "Coins Collected: " << coinsCount << endl; // Assuming each coin gives a score of 5
                    cout << "Obstacles Hit: " << (car->health < 50 ? (50 - car->health) / 5 : 0) << endl; // Assuming each hit decreases health by 5
                    cout << "Power-ups Collected: " << countPickedUpPowerups() << endl; // Add a function to count collected power-ups
                    return true;
                    //exit(0); // You can handle game over differently if needed
                }
            }
            else if (nextValue == 'E') // If the car reaches the end
            {
                cout << "You Win!" << endl;
                cout << "Final Score: " << car->score << endl;
                cout << "Final Health: " << car->health << endl;
                cout << "Coins Collected: " << coinsCount << endl; // Assuming each coin gives a score of 5
                cout << "Obstacles Hit: " << (car->health < 50 ? (50 - car->health) / 5 : 0) << endl; // Assuming each hit decreases health by 5
                cout << "Power-ups Collected: " << countPickedUpPowerups() << endl; // Add a function to count collected power-ups
                return true;
                //exit(0); // You can handle game over differently if needed
            }

            generateObstacle();
        }
        // Add an else condition to handle the case where the next coordinate is a space
        else
        {
            // Do nothing, as the car cannot move to a space
        }
        return false;
    }



    


    // Call this method in a loop based on the difficulty level
    void generateObstaclesOverTime(int difficulty)
    {
        while (true)
        {
            this_thread::sleep_for(chrono::seconds(4 / difficulty));  // Wait for a certain amount of time based on the difficulty level
            generateObstacle();
        }
    }
#define ANSI_WHITE_BG "\033[47m"
#define YELLOW_ORANGE "\033[38;5;208m"
#define RESET_COLOR "\033[0m"
#define ROYAL_BLUE "\033[38;5;63m"
#define PINK "\033[95m"
#define ANSI_SILVER "\033[38;5;7m"
#define PURPLE "\033[35m"
#define GREEN "\033[38;5;46m"
#define RED "\033[38;5;196m"
    void printGrid()
    {
        system("cls"); // Clear the console screen (for Windows, use the appropriate command for other systems)

        // Get the console width. This might vary depending on the system.
        int consoleWidth = 120;

        // Calculate padding for centering the grid
        int padding = (consoleWidth - (GRID_SIZE * 2)) / 2;

        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int p = 0; p < padding; p++)
            {
                cout << " ";
            }

            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (i == 1 && j == 1)
                {
                    grid[i][j]->value = 'S';
                    cout << GREEN << "S" << RESET_COLOR;
                }
                else if (i == GRID_SIZE - 2 && j == GRID_SIZE - 2)
                {
                    grid[i][j]->value = 'E';
                    cout << GREEN << "E" << RESET_COLOR;
                }
                else if (grid[i][j]->value == 43) // If it's a node represented by '+'
                {
                    cout << "+";
                }
                else if (grid[i][j]->value == 35)
                {
                    grid[i][j]->value = '#';
                    cout << ANSI_SILVER << "#" << RESET_COLOR;
                }
                else if (grid[i][j]->value == 88)
                {
                    grid[i][j]->value = 'X';
                    cout << RED << "X" << RESET_COLOR;
                }
                else if (grid[i][j]->value == 124) // If it's a vertical path represented by '|'
                {
                    if ((i > 0 && grid[i - 1][j]->value == 43) || (i < GRID_SIZE - 1 && grid[i + 1][j]->value == 43))
                    {
                        grid[i][j]->value = '|';
                        cout << PURPLE << "|" << RESET_COLOR;
                    }
                    else
                    {
                        grid[i][j]->value = ' ';
                        cout<<ANSI_WHITE_BG << " "<<RESET_COLOR;
                    }
                }
                else if (grid[i][j]->value == 45) // If it's a horizontal path represented by '-'
                {
                    grid[i][j]->value = '-';
                    cout << PURPLE << "-" << RESET_COLOR;
                }
                else if (grid[i][j]->value == 80) // If it's a power-up represented by 'P'
                {
                    grid[i][j]->value = 'P';
                    cout << PINK << "P" << RESET_COLOR;
                }
                else if (grid[i][j]->value == '$') // If it's a coin represented by '$'
                {
                    if (coinsHead != nullptr) {
                        Coin* currentCoin = coinsHead;
                        while (currentCoin != nullptr) {
                            if (currentCoin->x == i && currentCoin->y == j) {
                                if (!currentCoin->collected) {
                                    cout << YELLOW_ORANGE << "$" << RESET_COLOR;
                                }
                                else {
                                    grid[i][j]->value = '-';
                                    cout <<PURPLE<< "-"<<RESET_COLOR;  // Print '-' if the coin has been collected
                                }
                                break;
                            }
                            currentCoin = currentCoin->next;
                        }
                    }
                }
                else if (i == car->x && j == car->y) // If it's the car's current position
                {
                    cout << ROYAL_BLUE << "C" << RESET_COLOR;
                }
                else
                {
                    grid[i][j]->value = ' ';
                    cout <<ANSI_WHITE_BG<< " "<<RESET_COLOR;
                }

                // Add spaces between elements
                cout << " ";
            }

            // Move to the next line
            cout << endl;
        }

        cout << "Health: " << car->health << endl;
        cout << "Score: " << car->score << endl;
    }



};

class Player

{

public:

    bool check;

    string name;

    ScoresLinkedList scores;

    MilestoneLinkedList achievements;

    CoinsCollectedLinkedList coins;

    Player() : scores(), achievements(), coins() {}

    void loadPlayerData()
    {
        ifstream inFile("player_data.txt");

        if (inFile.is_open())
        {
            string line;

            while (getline(inFile, line))
            {
                istringstream iss(line);

                string category;
                iss >> category;

                if (category == "Name:")
                {
                    iss >> name;
                }
                else if (category == "Scores:")
                {
                    int score;
                    while (iss >> score)
                    {
                        scores.addScore(score);
                    }
                }
                else if (category == "Collected Coins:")
                {
                    int x, y;
                    while (iss >> x >> y)
                    {
                        coins.addCoins(x);
                    }
                }
            }

            inFile.close();
        }
        else
        {
            cout << "Unable to open the file for loading player data." << endl;
        }
    }

    // Modify the runGame function to save scores and collected coins at the end
// Inside the Player class

    bool runGame(int choice)
    {
        Graph game(choice);
        game.generateCoins(10);
        std::thread obstacleThread(&Graph::generateObstaclesOverTime, &game, choice);
        obstacleThread.detach();
        game.printGrid();

        char move;
        while (true)
        {
            cout << "(w/a/s/d): ";
            cin >> move;

            // TODO: Implement car movement based on user input
            check=game.moveCar(move);

            if (game.car->health <= 0)
            {
                cout << "Game Over! \n";
                cout << "Score: " << game.car->score << endl;

                // Save scores and collected coins when the game is over
                //writePlayerData();

                //break;
            }

            if (check)
            {
                scores.addScore(game.car->score);
                coins.addCoins(game.coinsCount);
                return true;
            }

            // Clear the console
            system("CLS");

            // Print the updated grid
            game.printGrid();

            // Sleep for a bit to control the speed of the game
            Sleep(500);
        }
        return false;
    }


    // Modify the saveGameStats function to append to the file
    void writePlayerData()
    {
        ofstream outFile("player_data.txt", ios::app);  // Append to the file

        if (outFile.is_open())
        {
             //Write player's name to file
            outFile << "Name: " << name << endl;

             //Write player's scores to file
// Write player's scores to file
            outFile << "Scores: ";
            ScoresNode* currentScore = scores.head;
            while (currentScore != nullptr)
            {
                outFile << currentScore->score << " ";
                currentScore = currentScore->next;
            }
            outFile << endl;

             //Write player's collected coins to file
            outFile << "Collected Coins: ";
            CoinsCollectedNode* currentCoin = coins.head;
            while (currentCoin != nullptr)
            {
                outFile  << currentCoin->x;
                currentCoin = currentCoin->next;
            }
            outFile << endl;

            outFile.flush();  // Flush the buffer explicitly

            outFile.close();
        }
        else
        {
            cout << "Unable to open the file for saving player data." << endl;
        }
    }


};