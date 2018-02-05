/*
Adam Paiz
CS362
Winter
Implementation of testme for quiz
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  char chars[] = {'[','(','{',' ','a','x','}',')',']','r','e','s','t'};
  int rand_int = rand()% 13;
  rand_int -= 1;
    return chars[rand_int];
}

char *inputString()
{
    char * return_char = malloc(sizeof(char)* 6);
    return_char[0] = inputChar();
    return_char[1] = inputChar();
    return_char[2] = inputChar();
    return_char[3] = inputChar();
    return_char[4] = inputChar();
    return_char[5] = '\0';
    return return_char;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    /*
    if(tcCount == 5)
    {
      break;
    }
    */
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
