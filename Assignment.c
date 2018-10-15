#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int infLoop = 1, inputNum, count, totalCount=0;
	int randNum;
	int r2 = 9999;
	int countGame=0;
	float avg;
	char m;
	srand(time(NULL));
	printf("WELCOME to the guessing game!\n");
	printf("MENU: 's' to start a game, 'n' to set a new range, or 'q' to quit:\n");
	do {
		scanf("\n%c", &m);
		switch (m) {

		case 's':
			countGame++;
			randNum = rand() % (r2);
			count=1;
			printf("The secret number is BETWEEN 0 AND %i Guess: \n", r2);
			while (randNum != inputNum) {
				scanf("%d", &inputNum);
				if (randNum > inputNum) {
					printf("Too LOW! Guess:\n");
					count++;
				} else if (randNum < inputNum) {
					printf("Too High! Guess:\n");
					count++;
				}
			}
			printf("Correct: You TOOK %i guesses\n", count);
			printf("MENU: 's' to start a game, 'n' to set a new range, or 'q' to quit:\n");
			totalCount+=count;

			break;
		case 'n':
			printf("Enter a new MAXIMUM\n");
			scanf("%d", &r2);
			printf("MENU: 's' to start a game, 'n' to set a new range, or 'q' to quit:\n");
			break;
		case 'q':
			if(countGame==0){
				printf("Thanks for playing. Your guess count AVERAGE is 0.00\n");
			}
			else{
			avg = (float)totalCount / countGame;
			printf("Thanks for playing. Your guess count AVERAGE is %.1f\n", avg);
			exit(0);
			}
			break;
		default:
			printf("UNRECOGNIZED command.\n");
			printf("MENU: 's' to start a game, 'n' to set a new range, or 'q' to quit:\n");
			break;
		}

	} while (infLoop > 0);
	return 0;
}
