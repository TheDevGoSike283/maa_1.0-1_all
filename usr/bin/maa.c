#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "colors.h"
int main() {
	char command[200];
	printf(GRN "Hi, welcome to MAA, which stands for \"my awesome app\" (in linux). Commands: \"rand\" prints a random number between 2 numbers, \"pasgen\" stands for password generator and has an undesired operation. \"time\" prints the time. \"fileadd\" adds a file. \"speak\" says whatever you type. \"rainbowtext\" prints whatever you type, but in rainbow.\n");
	printf(MAG "What're you waiting for? Just type the command here:\n");
	scanf("%s", &command);
	if (strcmp(&command, "rand") == 0) {
		int num1;
		int num2;
		printf(CYN "What is the first number?\n");
		scanf("%d", &num1);
		printf(MAG "What is the second number? (Has to be higher than first number.)\n");
		scanf("%d", &num2);
		srand(time(0));
		int lower = num1, upper = num2;
    		printf(GRN "The random number is: ");
    		for (int i = 0; i < 1; i++) {
        		int num = (rand() % (upper - lower + 1)) + lower;
        		printf(BLU "%d \n", num);
    		}
	} else if (strcmp(&command, "pasgen") == 0) {
		printf(RED "WARNING! UNDESIRED OPERATION! But I'm keeping this command because it's funny...\n");
		printf(CYN "Type any 6 letter word.\n");
		char a[6];
		scanf("%s", &a);
		printf(BLU "Type any 6-digit int.\n");
		char b[6];
		scanf("%d", &b);
		char one = a[0];
		char two = a[1];
		char three = a[2];
		char four = a[3];
		char five = a[4];
		char six = a[5];
	   int seven = b[0];
		int eight = b[1];
		int nine = b[2];
		int ten = b[3];
		int eleven = b[4];
		int twelve = b[5];
		printf(GRN "Your password is %s%s%s%s%s%s%d%d%d%d%d%d\n", &four, &six, &two, &five, &one, &three, &ten, &twelve, &seven, &nine, &eleven, &eight);
		printf("Followed by %s%s%s%s%s%s\n", &six, &five, &four, &three, &two, &one);
	} else if (strcmp(&command, "time") == 0) {
		  time_t t;   // not a primitive datatype
		  time(&t);
		  printf(GRN "Here is the date right now: %s\n", ctime(&t));
	} else if (strcmp(&command, "fileadd") == 0) {
			char *name[1000];
			char *content[1000];
			printf(MAG "What is the name of your file?\n");
			scanf("%s", &name);
			strcat(&name, ".txt");
			printf(CYN "What is the content of the file? (no spaces)\n");
			scanf("%s", &content);
			FILE *f_ptr;
			f_ptr = fopen(&name, "w");
			if (f_ptr == NULL) {
				printf(RED "Operation failed: could not write to file\n");
				return;
			}
			printf(GRN "Great success!\n");
			fprintf(f_ptr, &content);
			fflush(f_ptr);
			fclose(f_ptr);
	} else if (strcmp(&command, "speak") == 0) {
		char hascopyone[1];
		printf(YEL "Do you already have the file \"espeakcode.sh\" in your directory? Type y (yes) or n (no)\n");
		scanf("%s", &hascopyone);
		if (strcmp(&hascopyone, "y") == 0) {
			printf(CYN "Ok then, moving on...\n");
		} else if (strcmp(&hascopyone, "n") == 0) {
			printf(YEL "Downloading...\n");
			system("wget https://raw.githubusercontent.com/TheDevGoSike283/maa_1.0-1_all/main/usr/bin/espeakcode.sh");
		}
		system("sh espeakcode.sh");
	} else if (strcmp(&command, "rainbowtext") == 0) {
		char hascopytwo[1];
		printf(YEL "Do you already have the file \"rainbowcode.sh\" in your directory? Type y (yes) or n (no)\n");
		scanf("%s", &hascopytwo);
		if (strcmp(&hascopytwo, "y") == 0) {
			printf(CYN "Ok then, moving on...\n");
		} else if (strcmp(&hascopytwo, "n") == 0) {
			printf(YEL "Downloading...\n");
			system("wget https://raw.githubusercontent.com/TheDevGoSike283/maa_1.0-1_all/main/usr/bin/rainbowcode.sh");
		}
		system("sh rainbowcode.sh");
	} else {
		printf(RED "INVALID COMMAND!\n");
	}

	printf(YEL "Bye! Type maa to reopen this program.\n");
}
