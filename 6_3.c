#include <stdio.h>
#include <string.h>
int string(char str[]){
  int len;
  len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}
int main(int argc, char const *argv[]) {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  printf("The length is: %d\n", string(str));
  return 0;
}
