#include <stdio.h>
#define NUMBER_OF_STUDENT 5

int main() {
  char names[NUMBER_OF_STUDENT][255];
  int scores[NUMBER_OF_STUDENT];
  double totalScore = 0;

  for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
    scanf("%255s %d", names[i], &scores[i]);
    totalScore += scores[i];
  }
  double avg = totalScore / NUMBER_OF_STUDENT;
  
  printf("The average of the score is %.2lf\n", avg);
  printf("Students whose scores are higher than average score are : \n");
  for (int i = 0; i < NUMBER_OF_STUDENT; i++) {
    if (scores[i] > avg) {
      printf("- %s %d\n", names[i], scores[i]);
    }
  }
  return 0;
}