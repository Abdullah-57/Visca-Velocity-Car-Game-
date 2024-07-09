
//Talha_Rizwan_22i-2539_E

//Abdullah_Daoud_22i-2626_E

#pragma once

#include <iostream>

#include <thread>

#include <chrono>

#include <conio.h>

#include <Windows.h>

#include <fstream>

#include <sstream>

//definitions of colors i am using

#define ANSI_WHITE_BG "\033[47m"

#define YELLOW_ORANGE "\033[38;5;208m"

#define RESET_COLOR "\033[0m"

#define ROYAL_BLUE "\033[38;5;63m"

#define PINK "\033[95m"

#define ANSI_SILVER "\033[38;5;7m"

#define PURPLE "\033[35m"

#define GREEN "\033[38;5;46m"

#define RED "\033[38;5;196m"

using namespace std;

//Fowrard declaration

class Node;

//Nodes to store the score of players

class ScoresNode

{

public:

    int score;

    ScoresNode* next;


    ScoresNode(int score) : score(score), next(NULL) {}

};

//Nodes to store the milestones of players

class MilestoneNode

{

public:

    string milestone;

    MilestoneNode* next;


    MilestoneNode(string milestone) : milestone(milestone), next(NULL) {}

};

//LinkedList of milestones achieved by players

class MilestoneLinkedList

{

public:

    MilestoneNode* head;

    MilestoneNode* tail;

    MilestoneLinkedList() : head(NULL), tail(NULL) {}

    void addMilestone(string milestone)        //Function to add a new milestone

    {

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

    void printMilestones()     //Function to print milestones

    {

        MilestoneNode* current = head;

        cout << "Milestones: ";

        while (current != NULL)

        {

            cout << current->milestone << endl;

            current = current->next;

        }

        cout << endl;

    }

};

//LinkedList of scores of players

class ScoresLinkedList

{

public:

    ScoresNode* head;

    ScoresNode* tail;

    ScoresLinkedList() : head(NULL), tail(NULL) {}

    void addScore(int score)    //Function to add a score in the list

    {

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

    void printScores()      //Function to print list of scores

    {

        ScoresNode* current = head;

        cout << "Scores: ";

        while (current != NULL)

        {

            cout << current->score << " ";

            current = current->next;

        }


        cout << endl;

    }



    void bubbleSort()   //Function to sort the scores of players in ascending or descending order

    {
        if (head == NULL)

            return; // Nothing to sort if the list is empty

        bool swapped;

        ScoresNode* ptr1;

        ScoresNode* lptr = NULL;

        do

        {
            swapped = false;

            ptr1 = head;

            while (ptr1->next != lptr)

            {

                if (ptr1->score < ptr1->next->score)

                {

                    // Swap the scores

                    int temp = ptr1->score;

                    ptr1->score = ptr1->next->score;

                    ptr1->next->score = temp;

                    swapped = true;
                }

                ptr1 = ptr1->next;

            }

            lptr = ptr1;

        } while (swapped);

    }



    int getSize()   //Function to get size of list of scores for easy traversal

    {

        int count = 0;

        ScoresNode* current = head;

        while (current != NULL)

        {

            count++;

            current = current->next;

        }


        return count;

    }

    int getScore(int index)   //Function to retreive score of any index of list 

    {
        ScoresNode* current = head;

        for (int i = 0; i < index && current != NULL; i++)

        {

            current = current->next;

        }


        return current != NULL ? current->score : -1; // Return -1 if index is out of bounds

    }

};

//Nodes to store coins collected by players

class CoinsCollectedNode

{

public:

    int value;

    CoinsCollectedNode* next;


    CoinsCollectedNode(int value) : value(value), next(nullptr) {}

};

//LinkedList for storing coins collection of players

class CoinsCollectedLinkedList

{

public:

    CoinsCollectedNode* head;

    CoinsCollectedNode* tail;

    CoinsCollectedLinkedList() : head(nullptr), tail(nullptr) {}

    void addCoin(int value)    //Function to add coins to list

    {

        CoinsCollectedNode* newNode = new CoinsCollectedNode(value);

        if (head == nullptr)

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

    int getSize()   //Function to get size of list for easy traversal of list

    {

        int count = 0;

        CoinsCollectedNode* current = head;


        while (current != nullptr)

        {

            count++;

            current = current->next;

        }

        return count;
    }

    ~CoinsCollectedLinkedList()   //Destructor

    {

        CoinsCollectedNode* current = head;

        CoinsCollectedNode* nextNode;

        while (current != nullptr)

        {

            nextNode = current->next;

            delete current;

            current = nextNode;

        }

        head = nullptr;

        tail = nullptr;

    }

    void clear()   //Function to clear the list

    {

        CoinsCollectedNode* current = head;

        CoinsCollectedNode* nextNode;

        while (current != nullptr)

        {

            nextNode = current->next;

            delete current;

            current = nextNode;

        }

        head = nullptr;

        tail = nullptr;

    }

};

//Linked list used to add neighbours of nodes in the graph

class LinkedList

{

public:

    Node* head;

    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    void addNode(Node* node);

    Node* getNode(int index);

};

//Class of Edge to add a path between nodes

class Edge

{

public:

    Node* destination;

    int weight;


    Edge(Node* dest, int w) : destination(dest), weight(w) {}

};

//Nodes that are part of our graph

class Node

{

public:

    int x, y;  //Cordinates of our nodes

    char value;   //Char value will be assigned to every node

    int weight;   //Weight of nodes

    LinkedList neighbors;      //Lineked list of its neighbours for every node

    Node* next;

    Edge* Neighbors[4];    //Each node will have 4 max egedes with its 4 neighbours (up, down, left, right).

    Node(char val) : value(val), next(NULL) {}

    void setWeight(int w)   //Function to set the weight of nodes

    {


        weight = w;

    }

    void addNeighbor(Node* neighbor, int weight)     //Function to add 4 edges between each node

    {

        // Determine the direction of the neighbor

        if (neighbor->x == x - 1 && neighbor->y == y)

        {

            Neighbors[0] = new Edge(neighbor, weight); // Up

        }

        else if (neighbor->x == x + 1 && neighbor->y == y)

        {

            Neighbors[1] = new Edge(neighbor, weight); // Down

        }

        else if (neighbor->x == x && neighbor->y == y - 1)

        {

            Neighbors[2] = new Edge(neighbor, weight); // Left

        }

        else if (neighbor->x == x && neighbor->y == y + 1)

        {

            Neighbors[3] = new Edge(neighbor, weight); // Right

        }

    }

};

//linkedList of coins that will be added in the map/Graph

class Coin

{

public:

    int value;

    int x, y;

    bool collected;  // New variable to track whether the coin has been collected

    Coin* next;

    Coin(int val, int x, int y) : value(val), x(x), y(y), collected(false), next(nullptr) {}

};



void LinkedList::addNode(Node* node)  //Insertion of a node in LinkedList

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

Node* LinkedList::getNode(int index)  //Function to retreive a node

{
    Node* current = head;

    for (int i = 0; i < index && current != NULL; i++)

    {

        current = current->next;

    }

    return current;

}

//Implementation of Queues which will be used to add obstacles and power ups.

class Queue

{

public:

    Node* front;

    Node* rear;

    Queue() : front(NULL), rear(NULL) {}

    //Below are the essential functions of queue

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

//Class of a car which is a part of our racing game

class Car

{

public:

    int health;   //Health of car

    int score;      //Score of car

    int x, y;     //Cordinates of car

    char originalValue;    //The char value which will represent the car in the graph

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

    //Function of a car to move

    void move(char direction, Node*** grid, int GRID_SIZE)

    {

        // Save the game state before moving :will be essential when player pauses the game

        saveGameState();

        // Temporary variables for new position

        int newX = x;

        int newY = y;

        //Directions of car to move/Charachters that will help the car to move

        switch (direction)

        {

        case 'w':

            newX = max(1, newX - 1);

            break;

        case 'a':

            newY = max(1, newY - 1);

            break;

        case 's':

            newX = min(GRID_SIZE - 2, newX + 1);

            break;

        case 'd':

            newY = min(GRID_SIZE - 2, newY + 1);

            break;

        default:

            cout << "Invalid Move! \n";

            return;

        }

        // Moveing the car to the new position

        x = newX;

        y = newY;

        // Clearing the previous position

        grid[x][y]->value = originalValue;

    }

    // Saveing the current state of the game to a file

    void saveGameState()

    {

        ofstream outFile("resume.txt");

        if (outFile.is_open())

        {

            outFile << x << " " << y << " " << score << " " << health << endl;

            outFile.close();

        }

        else

        {

            cout << "Unable to save game state!\n";

        }

    }

    // Loading the game state from a file

    void loadGameState()

    {

        ifstream inFile("resume.txt");

        if (inFile.is_open())

        {

            inFile >> x >> y >> score >> health;

            inFile.close();

        }

        else

        {

            cout << "Unable to load game state!\n";

        }

    }

};

//Class of Graph to make our map

class Graph

{

public:

    int GRID_SIZE;   //Grid size of our grid/Map

    Node*** grid;

    Car* car;   // The object our car

    Queue obstacles;    //The queue of obstacles

    Queue power;

    bool** pickedUpPowerUps;   //The powerpickup bool: will turn false if the player has picked up that power

#define GRIDSIZE 10

    Coin* coinsHead;    //The list of coins

    Coin* MedHead;

    //Below are the members to store temp values

    int temp;

    int counter = 0;

    int count = 0;

    int elapsed_time_seconds;

    char lastMove = ' ';  // Variable to store the last move

    int coinsCount = 0;

    chrono::high_resolution_clock::time_point start_time;

    //Dijkstra algorithm to find the shortest path of our map on the basis of weights

    void dijkstra(int startX, int startY)

    {

        if (temp == 4)

        {

            const int INF = INT_MAX;

            int dist[GRIDSIZE][GRIDSIZE];

            bool visited[GRIDSIZE][GRIDSIZE];

            // Initializeing distances and visited array

            for (int i = 0; i < GRIDSIZE; ++i)

            {

                for (int j = 0; j < GRID_SIZE; ++j)

                {

                    dist[i][j] = INF;

                    visited[i][j] = false;

                }

            }

            dist[startX][startY] = 0;

            for (int count = 0; count < GRID_SIZE * GRID_SIZE - 1; ++count)

            {

                int minDist = INF;

                int minI, minJ;

                // Finding the minimum distance vertex

                for (int i = 0; i < GRID_SIZE; ++i)

                {

                    for (int j = 0; j < GRID_SIZE; ++j)

                    {

                        if (!visited[i][j] && dist[i][j] < minDist)

                        {

                            minDist = dist[i][j];

                            minI = i;

                            minJ = j;

                        }

                    }

                }

                visited[minI][minJ] = true;

                // Updating the distance value of the neighboring vertices

                for (int i = 0; i < 4; ++i)

                {

                    if (grid[minI][minJ]->Neighbors[i] != nullptr)

                    {

                        int newX = grid[minI][minJ]->Neighbors[i]->destination->x;

                        int newY = grid[minI][minJ]->Neighbors[i]->destination->y;

                        int weight = grid[minI][minJ]->Neighbors[i]->weight;

                        // Check if the neighboring node's weight is less
                        if (!visited[newX][newY] && weight < dist[newX][newY])

                        {

                            dist[newX][newY] = weight;

                        }

                    }

                }

            }

        }

    }

    //Function to generate coins in our map randomly

    void generateCoins(int numCoins)

    {

        for (int i = 0; i < numCoins; ++i)

        {

            int x, y;

            do

            {

                x = rand() % GRID_SIZE;

                y = rand() % GRID_SIZE;

            } while (grid[x][y]->value == 35 || grid[x][y]->value == 80 || (x == car->x && y == car->y));

            Coin* coin = new Coin(10, x, y);

            coin->next = coinsHead;

            coinsHead = coin;

            grid[x][y]->value = '$';  // Represent a coin with '$'

        }

    }

    //Function to generate MedKit in our map randomly

    void generateMeds()

    {

        for (int i = 0; i < 1; ++i)

        {

            int x, y;

            do

            {

                x = 10;

                y = 10;

            } while (grid[x][y]->value == 35 || grid[x][y]->value == 80 || (x == car->x && y == car->y));

            Coin* coin = new Coin(1, x, y);

            coin->next = MedHead;

            MedHead = coin;

            grid[x][y]->value = 'M';  // Represent a Med with 'M'

        }

    }

    //For Auto movement of car in Automatic movement

    char calculateAutoMove()

    {
        // Geting the current position of the car

        int x = car->x;

        int y = car->y;

        if (count > 0)
        {
            if (temp == 3 && count == 1)
            {
                count++;
                return 'w';

            }

            else if ((temp == 3 && count == 2) || (temp == 3 && count == 3))
            {
                count++;
                return 'a';

            }

            else if (temp == 3 && count < 9)
            {
                count++;
                return 's';

            }

            else if (temp == 3 && count < 11)
            {
                count++;
                return 'd';

            }
        }

        // Attempting to move based on the last move

        switch (lastMove)

        {

        case 'a':

            // If last move was left, prioritize down and then right

            if (x + 1 < GRID_SIZE && grid[x + 1][y]->value != ' ' && grid[x + 1][y]->value != '#')

            {

                lastMove = ' ';

                return 's'; // Move down

            }

            break;

        default:

            break;

        }

        // If there is no clear path based on the last move, try any available direction

        if (y + 1 < GRID_SIZE && grid[x][y + 1]->value != ' ' && grid[x][y + 1]->value != '#')

        {

            return 'd'; // Move right

        }

        else if (x + 1 < GRID_SIZE && grid[x + 1][y]->value != ' ' && grid[x + 1][y]->value != '#')

        {

            return 's'; // Move down

        }

        else if (x - 1 >= 0 && grid[x - 1][y]->value != ' ' && grid[x - 1][y]->value != '#')

        {


            count++;

            return 'w'; // Move up

        }

        else if (y - 1 >= 0 && grid[x][y - 1]->value != ' ' && grid[x][y - 1]->value != '#')

        {

            lastMove = 'a';

            return 'a'; // Move left

        }

        else

        {

            // If there is no clear path, stay in the current direction

            return lastMove;

        }

    }

    //Function to generate obstacles in our map randomly

    void generateObstacle()

    {

        int x, y;

        do

        {

            x = rand() % GRID_SIZE;

            y = rand() % GRID_SIZE;

        } while (grid[x][y]->value == 35 || grid[x][y]->value == 80 || grid[x][y]->value == '$' || grid[x][y]->value == 'M' || (x == car->x && y == car->y));  // Ensure the obstacle is not placed on a wall or on the car

        if (rand() % 10 == 0)

        {

            grid[x][y]->value = 80;

        }

        else

        {

            grid[x][y]->value = 88;  // Seting the obstacle

            obstacles.enqueue(grid[x][y]);  // Enqueuing the obstacle

        }


    }

    void generatePower()

    {

        int x, y;

        do

        {

            x = rand() % GRID_SIZE;

            y = rand() % GRID_SIZE;

        } while (grid[x][y]->value == 35 || grid[x][y]->value == 80 || grid[x][y]->value == 'M' || (x == car->x && y == car->y));  // Ensure the obstacle is not placed on a wall or on the car

        if (rand() % 10 == 0)

        {

            grid[x][y]->value = 80;

        }

        else

        {

            grid[x][y]->value = 88;  // Setting the power

            power.enqueue(grid[x][y]);  // Enqueuing the power

        }


    }

    void updateAndDisplayElapsedTime()

    {

        auto current_time = chrono::high_resolution_clock::now();

        auto elapsed_seconds = chrono::duration_cast<chrono::seconds>(current_time - start_time);

        elapsed_time_seconds = static_cast<int>(elapsed_seconds.count());

    }

    //Constructor of aur graph

    Graph(int difficulty, int mode = 1)

    {

        start_time = chrono::high_resolution_clock::now();

        elapsed_time_seconds = 0;

        temp = difficulty;

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

        // Creating the grid

        grid = new Node * *[GRID_SIZE];

        for (int i = 0; i < GRID_SIZE; i++)

        {

            grid[i] = new Node * [GRID_SIZE];

        }

        // Initializing grid with nodes and random connections

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

        //Adding nodes in adjacency list

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


                // Setting the weights for other types of nodes based on your game logic

                if (grid[i][j]->value == 'X') // Obstacle

                {

                    grid[i][j]->setWeight(INT_MAX); // Infinite weight for obstacles

                }

                else if (grid[i][j]->value == 'P') // Power-up

                {

                    grid[i][j]->setWeight(2); // Set a weight for power-ups

                }

                else if (grid[i][j]->value == '$') // Coin

                {

                    grid[i][j]->setWeight(1); // Set a weight for coins

                }

                else if (grid[i][j]->value == 'E') // End

                {

                    grid[i][j]->setWeight(0); // Set a weight for the end

                }

                else

                {

                    grid[i][j]->setWeight(1); // Set a default weight for other nodes

                }

            }
        }

        //These are the checks which will assign health on the basis of modes and difficulty which will be the input of our user

        if (mode == 1)

        {

            // Creating the car

            car = new Car(difficulty == 1 ? 50 : difficulty == 2 ? 50 : 50, 0, 1, 2);

            grid[car->x][car->y]->value = 67; // Car

        }

        if (mode == 2)

        {

            // Creating the car

            car = new Car(difficulty == 1 ? 50 : difficulty == 2 ? 35 : 20, 0, 1, 2);

            grid[car->x][car->y]->value = 67; // Car

        }

        // Initializing pickedUpPowerups array

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

    //Function to check whether a powerup is picked up or not

    bool isPowerupPickedUp(int x, int y)

    {

        return pickedUpPowerUps[x][y];

    }

    //Function for picking up power ups

    void pickUpPowerup(int x, int y)

    {

        pickedUpPowerUps[x][y] = true;

    }

    //Function for counting the power ups

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

    //Function for car to move automatically

    bool moveCarAuto(char direction)

    {

        //These will store the next cordinates of car for validation

        int nextX = car->x + (direction == 's' ? 1 : direction == 'w' ? -1 : 0);

        int nextY = car->y + (direction == 'd' ? 1 : direction == 'a' ? -1 : 0);

        // Checking if the next coordinate is within the grid boundaries and is not a space

        if (nextX >= 0 && nextX < GRID_SIZE && nextY >= 0 && nextY < GRID_SIZE && grid[nextX][nextY]->value != ' ')

        {

            char nextValue = grid[nextX][nextY]->value;

            // Clearing the previous position

            grid[car->x][car->y]->value = '*';  // '*' represents the car's previous position

            car->move(direction, grid, GRID_SIZE);

            car->originalValue = nextValue;

            // Setting the new position value

            grid[car->x][car->y]->value = 'C';

            car->score = car->score + 1;

            //If car picked up the powerups, the update in map and scores..

            if (nextValue == 'P' && !isPowerupPickedUp(nextX, nextY))

            {

                car->score = car->score * 2;

                pickUpPowerup(nextX, nextY);

                grid[nextX][nextY]->value = ' ';

                generateObstacle();

            }

            //If car collected the coins, the update in map and scores..

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

            //If car hit the obstalces, the update in health and scores..

            else if (nextValue == 'X') // If the car collides with an obstacle

            {

                car->health = car->health - 5;

                car->score = car->score - 5;

                if (car->health <= 0)  //If the health of car gets to zero, the game will be over

                {

                    cout << "Game Over! Health reached 0." << endl;

                    cout << "Final Health: " << car->health << endl;

                    cout << "Final Score: " << car->score << endl;

                    cout << "Coins Collected: " << coinsCount << endl; // Assuming each coin gives a score of 5

                    cout << "Obstacles Hit: " << (car->health < 50 ? (50 - car->health) / 5 : 0) << endl;

                    cout << "Power-ups Collected: " << countPickedUpPowerups() << endl; // Add a function to count collected power-ups

                    return true;

                }

            }

            else if (nextValue == 'E') // If the car reaches the end

            {

                cout << "You Win!" << endl;

                cout << "Final Score: " << car->score << endl;

                cout << "Final Health: " << car->health << endl;

                cout << "Coins Collected: " << coinsCount << endl; // Assuming each coin gives a score of 5

                cout << "Obstacles Hit: " << (car->health < 50 ? (50 - car->health) / 5 : 0) << endl;

                cout << "Power-ups Collected: " << countPickedUpPowerups() << endl; // Add a function to count collected power-ups

                return true;

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

    //Function for manual (based on input of user directions) movement of car

    bool moveCar(char direction)

    {

        int nextX = car->x + (direction == 80 ? 1 : direction == 72 ? -1 : 0);

        int nextY = car->y + (direction == 77 ? 1 : direction == 75 ? -1 : 0);

        // Checking if the next coordinate is within the grid boundaries and is not a space

        if (nextX >= 0 && nextX < GRID_SIZE && nextY >= 0 && nextY < GRID_SIZE && grid[nextX][nextY]->value != ' ')

        {

            char nextValue = grid[nextX][nextY]->value;

            // Clearing the previous position

            grid[car->x][car->y]->value = car->originalValue;

            car->move(direction, grid, GRID_SIZE);

            car->originalValue = nextValue;

            // Setting the new position value

            grid[car->x][car->y]->value = 'C';

            //The score will only increment when the user gives the right direction and car moves to next cordinate

            if (direction == 72 || direction == 75 || direction == 80 || direction == 77)

            {

                car->score = car->score + 1;

            }

            //If car picked up the powerups, the update in map and scores..

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


            //If car collected the medkit, the update in map and health..

            else if (nextValue == 'M') // If the car collects a Medkit

            {

                counter++;

                car->health = car->health + 5;

                if (MedHead != nullptr)

                {

                    Coin* currentCoin = MedHead;

                    Coin* prevCoin = nullptr;

                    while (currentCoin != nullptr)

                    {

                        if (currentCoin->x == nextX && currentCoin->y == nextY)

                        {

                            currentCoin->collected = true;  // Set the collected flag to true

                            grid[nextX][nextY]->value = ' '; // Removing the MedKit from the grid

                            // Generate a new obstacle after collecting the MedKit

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

                car->health = car->health + 5;

                car->score = car->score + 5;

                if (car->health <= 0)

                {

                    cout << "Game Over! Health reached 0." << endl;

                    cout << "Final Health: " << car->health << endl;

                    cout << "Final Score: " << car->score << endl;

                    cout << "Coins Collected: " << coinsCount << endl; // Assuming each coin gives a score of 5

                    if (temp == 1)

                    {

                        cout << "Obstacles Hit: " << (car->health < 50 ? ((50 - car->health) / 5) + counter : 0) << endl;

                    }

                    else if (temp == 2)

                    {

                        cout << "Obstacles Hit: " << (car->health < 40 ? ((40 - car->health) / 5) + counter : 0) << endl;


                    }

                    else if (temp == 3)

                    {

                        cout << "Obstacles Hit: " << (car->health < 30 ? ((30 - car->health) / 5) + counter : 0) << endl;


                    }

                    cout << "Power-ups Collected: " << countPickedUpPowerups() << endl; // Add a function to count collected power-ups

                    return true;


                }

            }

            else if (nextValue == 'E') // If the car reaches the end

            {

                updateAndDisplayElapsedTime();

                if ((temp == 1 && elapsed_time_seconds <= 30) || (temp == 2 && elapsed_time_seconds <= 45) || (temp == 3 && elapsed_time_seconds <= 60))

                {

                    car->score += 20;

                }

                if ((temp == 1 && elapsed_time_seconds > 30) || (temp == 2 && elapsed_time_seconds > 45) || (temp == 3 && elapsed_time_seconds > 60))

                {

                    car->score -= 10;

                }

                cout << "You Win!" << endl;

                cout << "Final Score: " << car->score << endl;

                cout << "Final Health: " << car->health << endl;


                cout << "Coins Collected: " << coinsCount << endl; // Assuming each coin gives a score of 5

                if (temp == 1)

                {

                    cout << "Obstacles Hit: " << (car->health < 50 ? ((50 - car->health) / 5) + counter : 0) << endl;

                }

                else if (temp == 2)

                {

                    cout << "Obstacles Hit: " << (car->health < 40 ? ((40 - car->health) / 5) + counter : 0) << endl;


                }

                else if (temp == 3)

                {

                    cout << "Obstacles Hit: " << (car->health < 30 ? ((30 - car->health) / 5) + counter : 0) << endl;


                }

                cout << "Power-ups Collected: " << countPickedUpPowerups() << endl; // Add a function to count collected power-ups

                return true;

            }

            generateObstacle();
        }

        else

        {

            // Do nothing, as the car cannot move to a space

        }

        return false;

    }

    //The obstacles will be generated on the basis of time

    void generateObstaclesOverTime(int difficulty)

    {

        while (true)

        {

            this_thread::sleep_for(chrono::seconds(4 / difficulty));  // Wait for a certain amount of time based on the difficulty level

            generateObstacle();

        }

    }

    //Both functions for printing grid/map

    void printGrid()

    {

        system("cls"); // Clearing the console screen 

        int consoleWidth = 215;

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


                    cout << ANSI_SILVER << "+" << RESET_COLOR;

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

                        cout << ANSI_SILVER << "|" << RESET_COLOR;

                    }

                    else

                    {

                        grid[i][j]->value = ' ';

                        cout << ANSI_WHITE_BG << " " << RESET_COLOR;

                    }

                }

                else if (grid[i][j]->value == 45) // If it's a horizontal path represented by '-'

                {

                    grid[i][j]->value = '-';

                    cout << ANSI_SILVER << "-" << RESET_COLOR;

                }

                else if (grid[i][j]->value == 80) // If it's a power-up represented by 'P'

                {

                    if (isPowerupPickedUp(i, j))

                    {

                        grid[i][j]->value = '-';

                        cout << PINK << "-" << RESET_COLOR;

                    }

                    else

                    {

                        grid[i][j]->value = 'P';

                        cout << PINK << "P" << RESET_COLOR;

                    }

                }

                else if (grid[i][j]->value == '$') // If it's a coin represented by '$'

                {

                    if (coinsHead != nullptr)

                    {

                        Coin* currentCoin = coinsHead;

                        while (currentCoin != nullptr)

                        {

                            if (currentCoin->x == i && currentCoin->y == j)

                            {

                                if (!currentCoin->collected)

                                {

                                    cout << YELLOW_ORANGE << "$" << RESET_COLOR;

                                }

                                else

                                {

                                    grid[i][j]->value = '-';

                                    cout << ANSI_SILVER << "-" << RESET_COLOR;  // Print '-' if the coin has been collected

                                }

                                break;

                            }

                            currentCoin = currentCoin->next;

                        }

                    }

                }

                else if (grid[i][j]->value == 'M') // If it's a MedKit represented by 'M'

                {

                    if (MedHead != nullptr)

                    {

                        Coin* currentCoin = MedHead;

                        while (currentCoin != nullptr)

                        {

                            if (currentCoin->x == i && currentCoin->y == j)

                            {

                                if (!currentCoin->collected)

                                {

                                    cout << GREEN << "M" << RESET_COLOR;

                                }

                                else

                                {

                                    grid[i][j]->value = '-';

                                    cout << ANSI_SILVER << "-" << RESET_COLOR;  // Print '-' if the MedKit has been collected

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

                    cout << ANSI_WHITE_BG << " " << RESET_COLOR;

                }

                // Adding spaces between elements

                cout << " ";

            }

            // Moving to the next line

            cout << endl;

        }


        cout << endl;

        cout << RED << "Health: " << RED << car->health << RESET_COLOR << endl;

        cout << GREEN << "Score: " << GREEN << car->score << RESET_COLOR << endl << endl;

        updateAndDisplayElapsedTime();

        cout << "Time: " << elapsed_time_seconds << " seconds" << endl;

        cout << GREEN << "Start: " << GREEN << "S" << RESET_COLOR << endl;

        cout << GREEN << "End: " << GREEN << "E" << RESET_COLOR << endl;

        cout << ROYAL_BLUE << "Car: " << ROYAL_BLUE << "C" << RESET_COLOR << endl;

        cout << ANSI_SILVER << "Grid Paths: " << ANSI_SILVER << "- " << RESET_COLOR << ANSI_SILVER << "| " << RESET_COLOR << ANSI_SILVER << "+ " << RESET_COLOR << endl;

        cout << RED << "Obstacles: " << RED << "X" << RESET_COLOR << endl;

        cout << GREEN << "Med Kit: " << GREEN << "M" << RESET_COLOR << endl;

        cout << PINK << "Power-ups: " << PINK << "P" << RESET_COLOR << endl;

        cout << YELLOW_ORANGE << "Coins: " << YELLOW_ORANGE << "$" << RESET_COLOR << endl;


    }


    void printGridAuto()

    {

        system("cls"); // Clearing the console screen

        int consoleWidth = 215;

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

                    cout << ANSI_SILVER << "+" << RESET_COLOR;

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

                        cout << ANSI_SILVER << "|" << RESET_COLOR;

                    }

                    else

                    {

                        grid[i][j]->value = ' ';

                        cout << ANSI_WHITE_BG << " " << RESET_COLOR;

                    }

                }

                else if (grid[i][j]->value == 45) // If it's a horizontal path represented by '-'

                {

                    grid[i][j]->value = '-';

                    cout << ANSI_SILVER << "-" << RESET_COLOR;

                }

                else if (grid[i][j]->value == 80) // If it's a power-up represented by 'P'

                {

                    if (isPowerupPickedUp(i, j))

                    {

                        grid[i][j]->value = '-';

                        cout << ANSI_SILVER << "-" << RESET_COLOR;

                    }

                    else

                    {

                        grid[i][j]->value = 'P';

                        cout << PINK << "P" << RESET_COLOR;

                    }

                }

                else if (grid[i][j]->value == '$') // If it's a coin represented by '$'

                {

                    if (coinsHead != nullptr)

                    {

                        Coin* currentCoin = coinsHead;

                        while (currentCoin != nullptr)

                        {

                            if (currentCoin->x == i && currentCoin->y == j)

                            {

                                if (!currentCoin->collected)

                                {

                                    cout << YELLOW_ORANGE << "$" << RESET_COLOR;

                                }

                                else

                                {

                                    grid[i][j]->value = '-';

                                    cout << ANSI_SILVER << "-" << RESET_COLOR;  // Print '-' if the coin has been collected

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

                else if (grid[i][j]->value == '*') // If it's the car's trail

                {

                    cout << GREEN << "*" << RESET_COLOR;

                }

                else

                {

                    grid[i][j]->value = ' ';

                    cout << ANSI_WHITE_BG << " " << RESET_COLOR;

                }

                // Adding spaces between elements

                cout << " ";

            }

            // Moving to the next line

            cout << endl;

        }


        cout << endl;

        cout << RED << "Health: " << RED << car->health << RESET_COLOR << endl;

        cout << GREEN << "Score: " << GREEN << car->score << RESET_COLOR << endl << endl;

        cout << GREEN << "Start: " << GREEN << "S" << RESET_COLOR << endl;

        cout << GREEN << "End: " << GREEN << "E" << RESET_COLOR << endl;

        cout << ROYAL_BLUE << "Car: " << ROYAL_BLUE << "C" << RESET_COLOR << endl;

        cout << ANSI_SILVER << "Grid Paths: " << ANSI_SILVER << "- " << RESET_COLOR << ANSI_SILVER << "| " << RESET_COLOR << ANSI_SILVER << "+ " << RESET_COLOR << endl;

        cout << RED << "Obstacles: " << RED << "X" << RESET_COLOR << endl;

        cout << PINK << "Power-ups: " << PINK << "P" << RESET_COLOR << endl;

        cout << YELLOW_ORANGE << "Coins: " << YELLOW_ORANGE << "$" << RESET_COLOR << endl;


    }


};

//structure for a player

struct PlayerNode
{

    string name;

    int score;

    PlayerNode* next;

    PlayerNode(string playerName, int playerScore) : name(playerName), score(playerScore), next(nullptr) {}

};

//linked list for players

class PlayerList

{

public:

    PlayerNode* head;

    PlayerList() : head(nullptr) {}

    // Function to add a player to the list

    void addPlayer(string playerName, int playerScore)

    {

        PlayerNode* newNode = new PlayerNode(playerName, playerScore);

        newNode->next = head;

        head = newNode;

    }

    // Function to display the players in the list

    void displayPlayers()

    {

        PlayerNode* current = head;

        while (current != nullptr)

        {

            cout << "Player: " << current->name << "\t Score: " << current->score << endl;

            current = current->next;

        }

    }

};

//tree node for leaderboard

struct TreeNode

{

    string name;

    int score;

    TreeNode* left;

    TreeNode* right;

    TreeNode(string playerName, int playerScore) : name(playerName), score(playerScore), left(nullptr), right(nullptr) {}

};


class Player

{

public:

    PlayerList playerList;  // Linked list of players

    bool check;

#define MAX_MILESTONES 10

    int tempHealth;

    int tempScore;

    int tempCoins;

    int temp;

    string name;

    ScoresLinkedList scores;

    MilestoneLinkedList achievements;

    CoinsCollectedLinkedList coins;

    TreeNode* leaderboardRoot;

    Player() : tempScore(0), tempCoins(0) {}

    Player(string name) : scores(), achievements(), coins()

    {

        this->name = name;
    }

    // Function to extract details of the last player from the file

    Player extractLastPlayerDetails(const string& filename) {

        Player lastPlayer;

        ifstream inFile(filename);

        if (inFile.is_open())

        {

            string line;

            Player players[100];  // Assuming a maximum of 100 players, adjust as needed

            int playerCount = 0;

            while (getline(inFile, line))

            {

                istringstream iss(line);

                string category;

                iss >> category;

                if (category == "Name:")

                {

                    iss >> players[playerCount].name;

                }

                else if (category == "Scores:")

                {

                    iss >> players[playerCount].tempScore;

                }

                else if (category == "Collected" || category == "Coins:")

                {

                    iss >> players[playerCount].tempCoins;

                    playerCount++;

                }

            }

            // Checking if there are any players in the file

            if (playerCount > 0)

            {

                // Extracting details of the last player

                lastPlayer = players[playerCount - 1];

            }

            inFile.close();

        }

        else

        {


        }

        return lastPlayer;

    }

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

                        // Adding the player and score to the linked list

                        playerList.addPlayer(name, score);

                    }

                }

                else if (category == "CollectedCoins:" || category == "Collected" || category == "Coins:")

                {

                    coins.clear();

                    int coinValue;

                    while (iss >> coinValue)

                    {

                        coins.addCoin(coinValue);

                    }

                }

                else

                {


                }

            }


            inFile.close();

        }

        else

        {

            cout << "Unable to open the file for loading player data." << endl;

        }

    }

    //gameplay for manual game

    bool runGame(int choice, int mode)

    {

        auto start_time = chrono::high_resolution_clock::now();

        temp = choice;

        Graph game(choice, mode);

        // Checking if a resume file exists

        bool resume = false;

        ifstream resumeFile("resume.txt");

        if (resumeFile)

        {

            char resumeChoice;

            cout << "Do you want to resume the game? (y/n): ";

            cin >> resumeChoice;

            if (resumeChoice == 'y' || resumeChoice == 'Y')

            {

                // Loading the saved coordinates from the file

                int savedX, savedY;

                resumeFile >> savedX >> savedY;

                game.car->x = savedX;

                game.car->y = savedY;

                game.car->loadGameState();

                game.generateCoins(10);

                game.generateMeds();

                resume = true;

            }

            resumeFile.close();

        }

        if (!resume)

        {

            game.generateMeds();

            game.generateCoins(10);

            thread obstacleThread(&Graph::generateObstaclesOverTime, &game, choice);

            obstacleThread.detach();

            game.printGrid();

        }

        char move;

        bool paused = false;  // Flag to track pause state

        while (true)

        {
            // Checking for a pause key (for example, 'P')

            if (!_kbhit())

            {

                // If no key is pressed, reset the paused flag

                paused = false;

            }

            else if (!paused)

            {
                char pauseKey = _getch();

                if (pauseKey == 'P' || pauseKey == 'p')

                {
                    cout << "Game Paused. Press any key to resume, 'E' to exit, or 'R' to restart..." << endl;

                    char resumeOrExit = _getch();

                    if (resumeOrExit == 'E' || resumeOrExit == 'e')

                    {
                        cout << "Exiting the game..." << endl;

                        // Saveing the current coordinates for potential resume

                        ofstream resumeFile("resume.txt");

                        resumeFile << game.car->x << " " << game.car->y << " " << game.car->score << " " << game.car->health << endl;

                        // Exiting the game

                        break;
                    }

                    else if (resumeOrExit == 'R' || resumeOrExit == 'r')

                    {

                        cout << "Restarting the game..." << std::endl;

                        // Removeng the resume file

                        remove("resume.txt");

                        // Restarting the game

                        return true;

                    }

                    else

                    {
                        cout << "Resuming the game..." << endl;

                        paused = true;  // Setting the paused flag to true

                    }

                }

            }

            if (!paused)

            {

                cout << "(w/a/s/d): ";

                move = _getch();

            }

            else

            {

                cout << "(w/a/s/d): ";

                // If resuming, get user input for the car's movement

                move = _getch();

            }

            //car movement based on user input

            check = game.moveCar(move);

            if (game.car->health <= 0)

            {


                cout << "Game Over! \n";

                cout << "Score: " << game.car->score << endl;

                ofstream resumeFile("resume.txt");

                resumeFile << game.car->x << " " << game.car->y << " " << game.car->score << " " << game.car->health << endl;

                // Exiting the game

                break;

            }

            if (check)

            {

                // Updateing and displaying elapsed time 

                auto current_time = chrono::high_resolution_clock::now();

                auto elapsed_seconds = chrono::duration_cast<chrono::seconds>(current_time - start_time).count();

                if (elapsed_seconds % 1 == 0)

                {

                    game.updateAndDisplayElapsedTime();

                }

                tempCoins = game.coinsCount;

                tempScore = game.car->score;

                tempHealth = game.car->health;

                return true;

            }

            // Clearing the console

            system("CLS");

            // Printing the updated grid

            game.printGrid();

            this_thread::sleep_for(chrono::milliseconds(500));

        }

        return false;

    }

    //Gameplay for automatic play

    bool rungame(int choice)

    {

        temp = choice;

        Graph game(choice);

        game.generateCoins(10);

        thread obstacleThread(&Graph::generateObstaclesOverTime, &game, choice);

        obstacleThread.detach();

        game.printGridAuto();

        game.dijkstra(0, 0);

        while (true)

        {
            // Calculateing the next move automatically

            char autoMove = game.calculateAutoMove();

            //car movement based on autoMove

            bool check = game.moveCarAuto(autoMove);

            // Checking if the car's health is zero

            if (game.car->health <= 0)

            {

                cout << "Game Over! \n";

                cout << "Score: " << game.car->score << endl;

            }

            if (check)

            {

                tempCoins = game.coinsCount;

                tempScore = game.car->score;

                tempHealth = game.car->health;

                return true;

            }

            // Clearing the console

            system("CLS");

            // Printing the updated grid

            game.printGridAuto();

            Sleep(500);

        }

        return false;

    }

    //Function which will be adding milestones and writing it in file

    void Milestones()

    {

        // Existing milestones array

        string existingMilestones[MAX_MILESTONES];

        int milestoneCount = 0;

        // Reading existing milestones from the file into an array

        ifstream inFile("milestones.txt");

        if (inFile.is_open())

        {

            string line;

            while (getline(inFile, line) && milestoneCount < MAX_MILESTONES)

            {

                istringstream iss(line);

                string category;

                if (iss >> category)

                {

                    if (category == "Milestone:")

                    {

                        if (iss >> existingMilestones[milestoneCount])

                        {

                            milestoneCount++;

                        }

                    }

                }

            }

            inFile.close();

        }

        // Checking and adding new milestones

        if (tempScore >= 100 && milestoneNotExists(existingMilestones, milestoneCount, "Scored 100 or more than 100."))

        {

            string milestone = "Scored 100 or more than 100.";

            achievements.addMilestone(milestone);

            writeMilestoneToFile(milestone, "milestones.txt", existingMilestones, milestoneCount);

        }

        if (tempScore >= 50 && milestoneNotExists(existingMilestones, milestoneCount, "Scored 50 or more than 50."))

        {

            string milestone = "Scored 50 or more than 50.";

            achievements.addMilestone(milestone);

            writeMilestoneToFile(milestone, "milestones.txt", existingMilestones, milestoneCount);

        }

        if (tempCoins == 10 && milestoneNotExists(existingMilestones, milestoneCount, "Collected all possible coins."))

        {

            string milestone = "Collected all possible coins.";

            achievements.addMilestone(milestone);

            writeMilestoneToFile(milestone, "milestones.txt", existingMilestones, milestoneCount);

        }

        if ((temp == 1 && tempHealth == 50) || (temp == 2 && tempHealth == 35) || (temp == 3 && tempHealth == 20))

        {

            string milestone = "Survived and won the race without getting Hurt.";

            if (milestoneNotExists(existingMilestones, milestoneCount, milestone))

            {

                achievements.addMilestone(milestone);

                writeMilestoneToFile(milestone, "milestones.txt", existingMilestones, milestoneCount);

            }

        }

        // Checking if the player's score is greater than the first position in the leaderboard

        int leaderboardFirstScore = (scores.getSize() > 0) ? scores.getScore(0) : 0;

        if (tempScore > leaderboardFirstScore)

        {

            string milestone = "Achieved a higher score than the top player in the leaderboard.";

            if (milestoneNotExists(existingMilestones, milestoneCount, milestone))

            {

                achievements.addMilestone(milestone);

                writeMilestoneToFile(milestone, "milestones.txt", existingMilestones, milestoneCount);

            }

        }

    }

    bool milestoneNotExists(string existingMilestones[], int milestoneCount, const string& milestone)

    {

        for (int i = 0; i < milestoneCount; ++i)

        {

            if (existingMilestones[i] == milestone)

            {

                return false;  // Milestone already exists

            }

        }

        return true;  // Milestone does not exist

    }

    //Write milestones achieved by players in file

    void writeMilestoneToFile(const string& milestone, const string& filename, string existingMilestones[], int& milestoneCount)

    {

        ofstream outFile(filename, ios::app);  // Append to the file

        if (outFile.is_open())

        {

            outFile << "Milestone: " << milestone << endl;

            // Checking array bounds before updating

            if (milestoneCount < MAX_MILESTONES)

            {

                existingMilestones[milestoneCount] = milestone;

                milestoneCount++;

            }

            else

            {

                cout << "Maximum number of milestones reached!" << endl;

            }


            outFile.close();

        }

        else

        {

            cout << "Unable to open the file for saving milestones." << endl;

        }

    }


    //Writing the player data in a file

    void writePlayerData()

    {

        ofstream outFile("player_data.txt", ios::app);  // Appending to the file

        if (outFile.is_open())

        {

            // Writing player's name to file

            outFile << "Name: " << name << endl;


            // Writing player's scores to file

            outFile << "Scores: " << tempScore << endl;

            // Writing player's collected coins to file

            outFile << "Collected Coins: " << tempCoins;

            outFile << endl;


            outFile.close();

        }

        else

        {

            cout << "Unable to open the file for saving player data." << endl;

        }

    }

    void displayLeaderboard()

    {

        // Building the leaderboard BST

        leaderboardRoot = buildLeaderboardBST();

        // Displaying the leaderboard in descending order

        cout << "Leaderboard:" << endl;

        printDescendingLeaderboard(leaderboardRoot);

    }

    // Helper function to build the leaderboard BST

    TreeNode* buildLeaderboardBST()

    {

        TreeNode* root = nullptr;

        // Inserting players and scores into the BST

        PlayerNode* current = playerList.head;

        while (current != nullptr)

        {

            root = insertLeaderboard(root, current->name, current->score);

            current = current->next;

        }

        return root;

    }

    // Helper function to insert a player and score into the leaderboard BST
    TreeNode* insertLeaderboard(TreeNode* node, string playerName, int playerScore)

    {

        if (node == nullptr)

        {

            return new TreeNode(playerName, playerScore);

        }

        if (playerScore >= node->score)

        {

            node->right = insertLeaderboard(node->right, playerName, playerScore);

        }

        else

        {

            node->left = insertLeaderboard(node->left, playerName, playerScore);

        }

        return node;

    }


    // Helper function to print the leaderboard BST in descending order
    void printDescendingLeaderboard(TreeNode* node)

    {

        if (node == nullptr)

        {

            return;

        }

        // Traversing right first (since we want descending order)

        printDescendingLeaderboard(node->right);

        // Printing the node's data

        cout << "Player: " << node->name << "\t Score: " << node->score << endl;

        // Traversing left

        printDescendingLeaderboard(node->left);

    }


    //Function to write Leaderboard in file

    void writeLeaderboardToFile()

    {

        // Building the leaderboard BST

        leaderboardRoot = buildLeaderboardBST();

        // Opening the file for writing

        ofstream outFile("leaderboard.txt");

        if (outFile.is_open())

        {

            // Displaying the leaderboard in the file

            outFile << "Leaderboard:" << std::endl;

            // Calling the helper function to print the leaderboard in descending order

            printDescendingLeaderboardToFile(leaderboardRoot, outFile);

            cout << "Leaderboard written to 'leaderboard.txt'" << endl;

            outFile.close();

        }

        else

        {

            cout << "Unable to open the file for writing the leaderboard." << endl;

        }

    }

    // Helper function to print the leaderboard BST in descending order to the file

    void printDescendingLeaderboardToFile(TreeNode* node, ofstream& outFile)

    {

        if (node == nullptr)

        {

            return;

        }

        // Traversing right first (since we want descending order)

        printDescendingLeaderboardToFile(node->right, outFile);

        // Printing the node's data to the file

        outFile << "Player: " << node->name << "\t Score: " << node->score << std::endl;

        // Traverseing left

        printDescendingLeaderboardToFile(node->left, outFile);

    }



};