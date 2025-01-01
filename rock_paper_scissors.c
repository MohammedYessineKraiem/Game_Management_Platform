
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int rock_paper_scissors();
int game(char you, char computer);


int game(char you, char computer) {
    if (you == computer)
        return -1;
    if (you == 's' && computer == 'p')
        return 0;
    else if (you == 'p' && computer == 's') 
        return 1;
    if (you == 's' && computer == 'z')
        return 1;
    else if (you == 'z' && computer == 's')
        return 0;
    if (you == 'p' && computer == 'z')
        return 0;
    else if (you == 'z' && computer == 'p')
        return 1;
}

int rock_paper_scissors() {
    int n, result=0;
	int score=0;
    char you, computer, playagain;
	do {
		srand(time(NULL));
    	n = rand() % 100;
    	if (n < 33)
        	computer = 's';
    	else if (n > 33 && n < 66)
        	computer = 'p';
    	else
        	computer = 'z';
		printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");
		printf("Choose your play: ");
		do {
			scanf(" %c", &you);
			you = tolower(you);
			if (you != 's' && you != 'p' && you != 'z') {
				printf("invalid input, replay!");
				printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");
				printf("Choose your play: ");
				continue;
			}
		}while (you !='s' && you !='p' && you !='z');
		result = game(you, computer);
		if (result == -1) {
    		printf("\n\n\t\t\t\tGame Draw!\n");
			score++;
		} 
		else if (result == 1) {
    		printf("\n\n\t\t\t\tWow! You have won the game!\n");
			score+=3;
		} 
		else { 

    		printf("\n\n\t\t\t\tOh! You have lost the game!\n");
			score--;
		}
		printf("\t\t\t\tYou chose: %c and Computer chose: %c\n", you, computer);
		printf("do you want to play again ?(y/n)");
		scanf(" %c", &playagain);
		playagain = tolower(playagain); 
	}while (playagain=='y');

	printf("\nThanks for playing");
	return score;

}