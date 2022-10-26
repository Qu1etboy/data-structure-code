#include <stdio.h>

struct address {
  char province[100];
  char subdistrict[100];
};

struct flower {
  char code[10];
  char name[100];
  double price;
  struct address area;
};

int main() {
  struct flower flowers[3];
  for (int i = 0; i < 3; i++) {
    scanf("%s %s %lf %s %s", flowers[i].code, flowers[i].name, &flowers[i].price, flowers[i].area.subdistrict, flowers[i].area.province);
  }
  printf("==== OUTPUT ====\n");
  for (int i = 0; i < 3; i++) {
    printf("code = %s, name = %s, price = %.2lf, subdistrict = %s, province = %s\n", flowers[i].code, flowers[i].name, flowers[i].price, flowers[i].area.subdistrict, flowers[i].area.province);
  }
}