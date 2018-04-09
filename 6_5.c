#include <stdio.h>
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
int main(int argc, char const *argv[]) {
  int a,b,temp;
  printf("Enter 2 values: \n");
  scanf("%d %d", &a,&b);
  swap(&a,&b);
  printf("Swap to: %d and %d\n", a,b);
  return 0;
}
