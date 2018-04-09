#include <stdio.h>
int max(int size,int arr[]){
  int i,max;
  max = arr[0];
  for (i = 0; i < size; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int main(int argc, char const *argv[]) {
  int size,i;
  int arr[100];
  printf("Enter size: ");
  scanf("%d", &size);
  printf("Enter array: \n");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Max is: %i\n", max(size,arr));
  return 0;
}
