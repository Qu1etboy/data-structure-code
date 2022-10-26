#include <stdio.h>

void calRecArea(float width, float length, float *pArea) {
  *pArea = width * length;
}

void readData(float *data1, float *data2) {
  printf("Enter width: ");
  scanf("%f", data1);
  printf("Enter length: ");
  scanf("%f", data2);
}

void printData(float area) {
  printf("Rectangle area is %.2f", area);
}

int main() {
  float width, length, area;
  readData(&width, &length);
  calRecArea(width, length, &area);
  printData(area);

  return 0;
}