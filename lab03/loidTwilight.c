#include <stdio.h>
#include <math.h>

typedef struct {
  int id;
  char name[1000];
  int critical;
} Patient;


int main() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    printf("Nothing to show\n");
    return 0;
  }
  if (n < 0) {
    printf("ErRor.!\n");
    return 0;
  }

  Patient patients[n];
  int maxCritical = 0;
  double sumCritical = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %s %d", &patients[i].id, patients[i].name, &patients[i].critical);
    if (patients[i].critical > maxCritical)
      maxCritical = patients[i].critical;
    sumCritical += patients[i].critical;
  } 

  // sort patients by id
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (patients[j].id > patients[j + 1].id) {
        Patient tmp = patients[j];
        patients[j] = patients[j + 1];
        patients[j + 1] = tmp;
      } 
    }
  }

  printf("All patient:\n");
  for (int i = 0; i < n; i++) {
    printf("  %02d %-10s %d\n", patients[i].id, patients[i].name, patients[i].critical);
  }
  printf("Critical:\n");
  for (int i = 0; i < n; i++) {
    if (patients[i].critical == maxCritical) {
      printf("  %02d %-10s %d\n", patients[i].id, patients[i].name, patients[i].critical);
    }
  }

  double avg = sumCritical / n;
  printf("Average: %.1f\n", ceil(avg*10) / 10);

  return 0;
}
