#include <stdio.h>
int main(int argc, char const *argv[]) {
  unsigned long fib[50],i;
  fib[0]=0;
  fib[1]=1;
  for ( i = 2; i < 50; i++) {
    fib[i]=fib[i-1]+fib[i-2];
  }
  for ( i = 0; i < 50; i++) {
    printf("%lu  ", fib[i]);
    if ((i!= 0) && ((i+1) % 10 == 0)){
    printf("\n");
    }
  }
  return 0;
}
