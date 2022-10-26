#include <stdio.h>

typedef struct {
  int id;
  double score;
  char name[1000];
} Product;

int main() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("No reviews found\n");
  } else if (n < 0) {
    printf("ERROR\n");
  } else {
    Product p[n];
    double totalScore = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf %s", &p[i].score, p[i].name);
      p[i].id = i + 1;
      totalScore += p[i].score;
    }
    printf("Average Score: %.2lf\n", totalScore / n);
  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (p[j].score < p[j+1].score) {
          Product tmp = p[j];
          p[j] = p[j+1];
          p[j+1] = tmp;
        } 
      }
    }

    for (int i = 0; i < n; i++) {
      printf("%.2lf %s (id: %d)\n", p[i].score, p[i].name, p[i].id);
    }
  
  }

  return 0;
}


