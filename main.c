

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Implementation Du Projet Dans une application; Run in Command Prompt
//gcc main.c rock_paper_scissors.c hangman.c pacman.c snake_game.c -o Programme_Finale


// Functions
void displayGameInfo();
void chooseGame();
void addNewGame();  
void displayUserStats();
int hangman();
int pacman();
int rock_paper_scissors();
int snake_game();

#define MAX_GAMES 10
#define MAX_SCORE_RAM 60
int score_rps , score_hng ,score_snk, score_pm ;

//stats
char gameList[MAX_GAMES][20] = {"Rock Paper Scissors", "Hangman Game", "Snake Game", "Pac-Man"};
int gameCount =4 ; //real max game count and doesnt incremenate unless developper add a new game
int playCount[MAX_GAMES] = {0}; // Track the number of times each game is played
int userScores[MAX_SCORE_RAM] = {0}; // user performance scores
char new_game_des[MAX_GAMES][66] ; // descriptions of new games

// Main Code
int main(){
	int input=0;
	while (input != 5) {

		printf("\n\n********######"
			"WELCOME TO OUR GAME MANAGMENT PLATFORM "
			"#####********\n");
		printf("\n\n1. Show me the list"
			" of games \n2. Choose what "
			"Game to play\n");
		printf("3. Progress And info"
			"rmation about User\n");
		printf(
			"4. Add New Game - Code Your "
			"Way\n");
		printf("5. Exit");
		printf("\n\nEnter one of "
			"the above: ");
		scanf("%d", &input);

		//input
		switch (input) {

		// Game info
		case 1:
            displayGameInfo();
			break;

		// Choose the game to play
		case 2:
            chooseGame();
			break;

		// Stats
		case 3:
            displayUserStats();
			break;

		// New game
		case 4:
            addNewGame();
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}

// Options

void displayGameInfo() { 
    // Rock Paper Scissors
    printf("Game 1: Rock Paper Scissors\n");
    printf("Description of Game 1:\n");
    printf("A classic game where players choose between three options: Rock, Paper, or Scissors.\n");
    printf("The rules are simple:\n");
    printf("- Rock beats Scissors.\n");
    printf("- Scissors beat Paper.\n");
    printf("- Paper beats Rock.\n");
    printf("The game is played against the computer, each time you launch the game you have one go, launch again to play more\n\n");

    // Hangman Game
    printf("Game 2: Hangman Game\n");
    printf("Description of Game 2:\n");
    printf("An educational and fun game where the player guesses a word by suggesting one letter at a time.\n");
    printf("Each incorrect guess brings the hangman closer to completion.\n");
    printf("The goal is to figure out the full word before the drawing is finished. you have hints that can help you\n\n");

    // Snake Game
    printf("Game 3: Snake Game\n");
    printf("Description of Game 3:\n");
    printf("A classic arcade game where the player controls a snake that grows longer as it eats food.\n");
    printf("The challenge is to avoid crashing into the walls or the snake's own tail while collecting as many points as possible.\n\n");

    // Pac-Man
    printf("Game 4: Pac-Man\n");
    printf("Description of Game 4:\n");
    printf("A legendary arcade game where the player controls Pac-Man, navigating a maze to eat all the dots while avoiding ghosts.\n");
    printf("Special power pellets allow Pac-Man to temporarily turn the tables and eat the ghosts.\n");
    printf("The game ends when all lives are lost. I recommend this game\n\n");

    //new games
    if (gameCount>4){
        for (int i = 4 ; i<gameCount ; ++i){
            printf("\n\nGame %d : %s\n", i+1 ,gameList[i]);
            printf("Description of game %d :", i+1);
            printf(new_game_des[i-4]);
        }
    }
}

void addNewGame() {
    if (gameCount >= MAX_GAMES) {
        printf("Cannot add more games. Maximum limit reached.\n");
        return;
    }
    char game_desc[66];
    printf("Enter the name of the new game: ");
    scanf(" %[^\n]", gameList[gameCount]);
    gameCount++;
    printf("\nAdd description of the Game : ");
    fflush(stdin);
    fgets(game_desc,66,stdin);
    game_desc[strcspn(game_desc,"\n")]='\0';
    //scanf("%s",&game_desc);
    strcpy(new_game_des[gameCount - 5], game_desc);
    printf("\nGame added successfully! Stay Tuned, We'll Let You know when it's fully ready to be played\n");
}

void chooseGame() {
    int gameChoice;

    printf("\nChoose a game to play (1-%d): ", gameCount);
    scanf("%d", &gameChoice);

    if (gameChoice < 1 || gameChoice > gameCount) {
        printf("Invalid game choice.\n");
        return;
    }
    playCount[gameChoice-1]++;
    if (gameChoice>4){
        printf("Oops! ,Game: %s Not added yet,we're working on it ;)", gameList[gameChoice - 1] );
    }else{
        printf("Launching.............: %s\n", gameList[gameChoice - 1]);
        switch (gameChoice)
        {
        case 1:
            score_rps = rock_paper_scissors();
            if (score_rps>=userScores[0]){
                userScores[0]=score_rps;
            }
            break;

        case 2:
            score_hng = hangman();
            if (score_hng>=userScores[1]){
                userScores[1]=score_hng;
            }
            break;
        case 3:
            snake_game();
            if (score_snk>= userScores[2]){
                userScores[2]=score_snk;
            }
            break;
        case 4:
            score_pm = pacman();
            if (score_pm>=userScores[4]){
                userScores[4]=score_pm;
            }
            break;
        }      
    }
}

void displayUserStats() {

    printf("\n ********###### User Statistics:********###### \n");
    // Most played game
    int maxPlays = 0, maxIndex = 0;
    for (int i = 0; i < gameCount; i++) {
        if (playCount[i] > maxPlays) {
            maxPlays = playCount[i];
            maxIndex = i;
        }
    }
    printf("######Most played game in the last 100 times: %s (%d times)\n", gameList[maxIndex], maxPlays);

    // Total games available
    printf("######Total games available: %d\n", gameCount);

    // score in each game
    printf("######Your best score in each game is\n");
    for (int i =0 ; i<gameCount && i!=4 ; i++){ 
        printf("%s : %d\n", gameList[i], userScores[i]);   
    }

    // Best and worst game 
    int bestIndex = 0, worstIndex = 0;
    for (int i = 0; i < gameCount && i!=4 ; i++) {
        if (userScores[i] > userScores[bestIndex]) bestIndex = i;
        if (userScores[i] < userScores[worstIndex]) worstIndex = i;
    }
    printf("Your best game (performance-wise): %s\n", gameList[bestIndex]);
    printf("Your worst game (performance-wise): %s\n", gameList[worstIndex]);
    
}
