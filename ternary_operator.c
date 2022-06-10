/*
Example of ternary operator
*/

#include <stdio.h>

int main()
{
  int speed;
  printf("\nEnter your speed as an integer: ");
  scanf("%d", &speed);
  speed = (speed <= 65)? (65) : (speed <= 70)? (70) : (90);
  switch(speed)
  {
    case 65: printf("\nNo speeding ticket.\n\n"); break;
    case 70: printf("\nSpeeding ticket.\n\n"); break;
    case 90: printf("\nExpensive speeding ticket.\n\n"); break;
    default: printf("\nIncorrect speed.\n\n"); // default case
  }
  return 0;
}
