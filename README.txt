Visca Velocity Car Game

Project Description
Visca Velocity is a console-based car racing game developed in C++. The game features a dynamic environment with various obstacles, power-ups, coins, and health kits. It employs various data structures such as linked lists, queues, and graphs to manage game elements, ensuring an engaging and challenging gameplay experience.

Features:

Game Elements:

Cars:
	Movement: Manual and automatic car movement on the grid.
	Health: Tracks the car's health.
	Score: Tracks the player's score.
	Saving and Loading: Ability to save and load game states.

Obstacles and Power-Ups:
	Obstacles: Randomly generated obstacles that players must avoid.
	Power-Ups: Randomly generated power-ups that provide benefits to the player.

Coins and MedKits:
	Coins: Collect coins to increase the score.
	MedKits: Collect health kits to restore car health.

Player Management:
	Scores: Tracks player scores and sorts them using bubble sort.
	Milestones: Tracks player achievements and milestones.
	Leaderboard: Maintains a leaderboard using a binary search tree (BST).

Game Functionalities:
	Add and Remove Elements: Add new cars, obstacles, power-ups, coins, and MedKits.
	Display Elements: Display the grid, scores, milestones, and leaderboard.
	Time Tracking: Track and display elapsed time.

Classes and Key Functions:

Car Management:

Car:
	Properties: health, score, x, y, originalValue.
	Methods: move, saveGameState, loadGameState.

Graph:
	Properties: GRID_SIZE, grid, car, obstacles, power, pickedUpPowerUps, coinsHead, MedHead, temp, counter, count, start_time, elapsed_time_seconds, lastMove.
	Methods: dijkstra, generateCoins, generateMeds, calculateAutoMove, generateObstacle, generatePower, updateAndDisplayElapsedTime, generateObstaclesOverTime, printGrid, printGridAuto, moveCarAuto, moveCar.

Linked List Management:
	ScoresNode, MilestoneNode, CoinsCollectedNode
	Properties: score, milestone, value, next.

ScoresLinkedList:
	Properties: head, tail.
	Methods: addScore, printScores, bubbleSort, getSize, getScore.

MilestoneLinkedList:
	Properties: head, tail.
	Methods: addMilestone, printMilestones.

CoinsCollectedLinkedList:
	Properties: head, tail.
	Methods: addCoin, getSize, clear.

Graph and Node Management:

Node:
	Properties: x, y, value, weight, neighbors, next, Neighbors.
	Methods: Node, setWeight, addNeighbor.

Edge:
	Properties: destination, weight.

LinkedList:
	Properties: head, tail.
	Methods: addNode, getNode.

Queue Management:

Queue:
	Properties: front, rear.
	Methods: enqueue, dequeue, isEmpty.

Player Management:

PlayerNode:
	Properties: name, score, next.

PlayerList:
	Properties: head.
	Methods: addPlayer, displayPlayers.

TreeNode:
	Properties: name, score, left, right.

Player:
	Properties: playerList, check, tempHealth, tempScore, tempCoins, temp, name, scores, achievements, coins, leaderboardRoot.
	Methods: extractLastPlayerDetails, loadPlayerData, runGame, rungame, Milestones, milestoneNotExists, writeMilestoneToFile, writePlayerData, displayLeaderboard, buildLeaderboardBST, insertLeaderboard, printDescendingLeaderboard, writeLeaderboardToFile, printDescendingLeaderboardToFile.

Usage:

Start Game:
	Follow the on-screen instructions to start the game.

Control Car:
	Use the designated keys to move the car manually.
	Choose automatic mode for auto-movement of the car.

Collect Items:
	Collect coins, power-ups, and MedKits as they appear on the grid.

Avoid Obstacles:
	Navigate the car to avoid obstacles.

Save and Load Game:
	Save the game state and resume later.

Contributing:
	Contributions are welcome! Please follow these steps:
		Fork the repository.
		Create a new branch (git checkout -b feature-branch).
		Commit your changes (git commit -m 'Add some feature').
		Push to the branch (git push origin feature-branch).
		Open a pull request.

Acknowledgments:
	This project was developed as part of a software engineering course at FAST National University of Computer and Emerging Sciences.
	Special thanks to the course instructor and teaching assistants for their support and guidance.
