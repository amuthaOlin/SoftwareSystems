#include <stdio.h>
#include <stdlib.h>

int getVal()
{
	/* Prompts the user for input and gets the associated value

   User input is truncated to the first two characters.
   X exits the program. 

   prompt: string prompt to display
   card_name: buffer where result is stored
   val: Place where resulting value is stored
*/
	char card_name[3];
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
	int val = 0;
	switch(card_name[0]) {
	case 'K':
	case 'Q':
	case 'J':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	case 'X':
		val = 12;
		break;
	default:
		val = atoi(card_name);
		if ((val < 1) || (val > 10)) {
			puts("I don't understand that value!");
			val = 0;
		}
	}
	return val;
}

int calcCount(val,count)
{
/* Calculates the count given a value and the old count

   New count integer is returned

   val: Stores new val to be added
   count: stores new count
*/
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;
}

int main()
{
/* Counts cards when given a user input of the card

   prints current count every time a value is added

   prompts: Prompts for a new card name after a name is entered
   val: Stores new val to be added
   count: stores new count
*/
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		int val = getVal();
		if (val == 12){
			card_name[0]='X';
			continue;
		}
		count = calcCount(val,count);
		printf("Current count: %i\n", count);
	}
	return 0;
}