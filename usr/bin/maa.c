#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include "colors.h"

void ascending(int i, int numbers, int j, int a, int n[10]);
void descending(int i, int numbers, int j, int a, int n[10]);
int main() {
  char ch;
  char command[200];
  printf(GRN "Hi, welcome to MAA, which stands for \"my awesome app\" (in linux). Type help for some commands. NOTE: this will be going in a loop until you type exit.\n");
  while (!strcmp(&command, "exit") == 0) {
    printf(MAG "What're you waiting for? Just type the command here:\n");
    scanf("%s", &command);
    if (strcmp( &command, "help") == 0) {
      printf(CYN "Here are the commands: \"rand\" prints a random number between 2 numbers, \"pasgen\" stands for password generator and has an undesired operation. \"time\" prints the time. \"fileadd\" adds a file. \"speak\" says whatever you type. \"rainbowtext\" prints whatever you type, but in rainbow. \"numbersort\" gets 10 numbers, and sorts them in ascending or descending order. \"factorial\" outputs the factorial of the given number (this was, by far, the easiest one to make). To exit the loop, just type \"exit\".\n");
    } else if (strcmp( &command, "rand") == 0) {
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
    } else if (strcmp( &command, "pasgen") == 0) {
      printf(RED "WARNING! UNDESIRED OPERATION! But I'm keeping this command because it's funny...\n");
      printf(CYN "Type any 6 letter word.\n");
      char a[6];
      scanf("%s", & a);
      printf(BLU "Type any 6-digit int.\n");
      char b[6];
      scanf("%d", & b);
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
      printf(GRN "Your password is %s%s%s%s%s%s%d%d%d%d%d%d\n", four, six, two, five, one, three, ten, twelve, seven, nine, eleven, eight);
      printf("Followed by %s%s%s%s%s%s\n", six, five, four, three, two, one);
    } else if (strcmp( &command, "time") == 0) {
      time_t t; // not a primitive datatype
      time( &t);
      printf(GRN "Here is the date right now: %s\n", ctime( & t));
    } else if (strcmp( &command, "fileadd") == 0) {
      char * name[1000];
      char * content[1000];
      printf(MAG "What is the name of your file?\n");
      scanf("%s", &name);
      strcat( &name, ".txt");
      printf(CYN "What is the content of the file? (no spaces)\n");
      scanf("%s", & content);
      FILE * f_ptr;
      f_ptr = fopen( & name, "w");
      if (f_ptr == NULL) {
        printf(RED "Operation failed: could not write to file\n");
        return;
      }
      printf(GRN "Great success!\n");
      fprintf(f_ptr, & content);
      fflush(f_ptr);
      fclose(f_ptr);
    } else if (strcmp( & command, "speak") == 0) {
      char hascopyone[1];
      printf(YEL "Do you already have the file \"espeakcode.sh\" in your directory? Type y (yes) or n (no)\n");
      scanf("%s", & hascopyone);
      if (strcmp( & hascopyone, "y") == 0) {
        printf(CYN "Ok then, moving on...\n");
      } else if (strcmp( & hascopyone, "n") == 0) {
        printf(YEL "Downloading...\n");
        system("wget https://raw.githubusercontent.com/TheDevGoSike283/maa_1.0-1_all/main/usr/bin/espeakcode.sh");
      }
      system("sh espeakcode.sh");
    } else if (strcmp( & command, "rainbowtext") == 0) {
      char hascopytwo[1];
      printf(YEL "Do you already have the file \"rainbowcode.sh\" in your directory? Type y (yes) or n (no)\n");
      scanf("%s", & hascopytwo);
      if (strcmp( & hascopytwo, "y") == 0) {
        printf(CYN "Ok then, moving on...\n");
      } else if (strcmp( & hascopytwo, "n") == 0) {
        printf(YEL "Downloading...\n");
        system("wget https://raw.githubusercontent.com/TheDevGoSike283/maa_1.0-1_all/main/usr/bin/rainbowcode.sh");
      }
      system("sh rainbowcode.sh");
    } else if (strcmp( & command, "numbersort") == 0) {
      int i;
      int j;
      int number;
      int numbers;
      int a;
      printf(CYN "How many numbers to sort?\n");
      scanf("%d", & numbers);
      int n[numbers];
      printf(YEL "Type in %d numbers and they will get sorted in ascending/descending order.\n", numbers);
      char yn;
      for (i = 0; i < numbers; i++) {
        j = i + 1;
        printf(BLU "Type Number %d\n", j);
        scanf("%d", & number);
        n[i] = number;
      }
      printf("Ascending (a) or Descending (d) order? [a/d]\n");
      char order[1];
      scanf("%s", & order);
      if (strcmp( & order, "a") == 0) {
      ascending(i, numbers, j, a, n);
      printf("Would you also like to know the descending order of your numbers? [y/n]\n");
      scanf("%s", & yn);
      if (strcmp( & yn, "y") == 0) {
         descending(i, numbers, j, a, n);
      } else {
        printf(RED "Okay...\n");
      }
    } else if (strcmp( & order, "d") == 0) {
      descending(i, numbers, j, a, n);
    }
    printf("Would you also like to know the ascending order of your numbers? [y/n]\n");
    scanf("%s", & yn);
    if (strcmp( & yn, "y") == 0) {
      ascending(i, numbers, j, a, n);
    } else {
      printf(RED "Okay...\n");
    }
    } else if (strcmp( & command, "factorial") == 0) {
       int factorialof;
       int thefactorial = 1;
       int loopnum1;
       char option1;
       int highernum;
       int lowernum;
       printf("A range of factorials or 1 single factorial? [range/single]\n");
       scanf("%s", & option1);
       if (strcmp( & option1, "single") == 0) {
          printf(GRN "What number do you want the factorial of?\n");
          scanf("%d", & factorialof);
          for (loopnum1 = 1; loopnum1 < factorialof + 1; loopnum1++) {
             thefactorial = thefactorial * loopnum1;
          }
          printf(YEL "The factorial of %d (%d!) is %d.\n", factorialof, factorialof, thefactorial);
       } else if (strcmp( & option1, "range") == 0) {
          printf(CYN "What is the lower number of the range?\n");
          scanf("%d", & lowernum);
          printf("What is the higher number of the range?\n");
          scanf("%d", & highernum);
          for (loopnum1 = 1; loopnum1 < highernum + 1; loopnum1++) {
             thefactorial = thefactorial * loopnum1;
             if (loopnum1 > lowernum - 1) {
                printf("%d! = %d.\n", loopnum1, thefactorial);
             }
          }
       }
    } else if (strcmp( & command, "exit") == 0) {
       printf(RED "...\n");
    } else {
       printf(RED "INVALID COMMAND!\n");
    }
  }
   char clear;
   printf(YEL "Bye! Type maa to reopen this program.\n");
   printf(RED "Clear terminal? [y/n]\n" YEL);
   scanf("%s", & clear);
   if (strcmp( & clear, "y") == 0) {
      system("clear;");
   }
}

void ascending(int i, int numbers, int j, int a, int n[10]) {
   for (i = 0; i < numbers; i++) {
      for (j = i + 1; j < numbers; j++) {
         if (n[i] > n[j]) {
            int a = n[j];
            n[j] = n[i];
            n[i] = a;
         }
      }
   }
   printf(CYN "The numbers in ascending order are: \n");
   for (i = 0; i < numbers; i++) {
      printf(MAG "%d\n", n[i]);
   }
}

void descending(int i, int numbers, int j, int a, int n[10]) {
   for (i = 0; i < numbers; i++) {
      for (j = i + 1; j < numbers; j++) {
         if (n[i] < n[j]) {
            int a = n[i];
            n[i] = n[j];
            n[j] = a;
         }
      }
   }
   printf(CYN "The numbers in descending order are: \n");
   for (i = 0; i < numbers; i++) {
      printf(MAG "%d\n", n[i]);
   }
}
