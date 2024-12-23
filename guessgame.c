#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//Guess game

int main() {

const int MIN=100;
const int MAX=120;
int guesses=0;
int guess=0;

srand(time(0));
int answer= (rand()%MAX)+ MIN;

do
{
    printf("Guess the number:\n");
    scanf("%d",&guess);

    if(guess==answer)
    {
        printf("CORRECT!!!\n");
    }
    else if(answer<guess)
    {
        printf("Too High!\n"); 
    }
    else
    {
        printf("Too Low!\n"); 
    }
    guesses++;

} while (guess != answer);

   printf("**************************\n");
   printf("Answer is %d \n",answer);
   printf("Number of gesses: %d \n",guesses);
   printf("**************************\n");

    return 0;
}