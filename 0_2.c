#include <stdio.h>
int main(int argc, char const *argv[]) {
  int num,b;
  b = 0;
  printf("Enter a decimal number: ");
  scanf("%d", &num);
  while (num != 1 && num % 2 == 1) {
    b = num % 2;
    printf("%d", b);
  }
  return 0;
}
