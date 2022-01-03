#include <stdio.h>

int main() {
  int n, b, size, n1;
  int i, j;
  int a[20];
  printf("Enter the number of chunk and size of each chunk: \n");
  scanf("%d%d", & n, & b);
  size = n * b;
  for (i = 0; i < n; i++) {
    printf("Enter the %d values of chunk %d:\n", b, i + 1);
    for (j = (i * b); j < (i * b) + b; j++) {
      scanf("%d", & a[j]);
    }
    printf("\n");
  }
  printf("Original stream:\n");
  for (i = 0; i < size; i++) {
    if ((i + 1) % b == 0)
      printf("%d\t\t", a[i]);
    else
      printf("%d ", a[i]);
  }
  printf("\n");
  printf("\nInterleaved stream:\n");
  for (i = 0; i < b; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", a[i + (j * b)]);
    }
    printf("\t");
  }
  printf("\n");
  printf("\n\tAT RECEIVER SIDE\n");
  printf("Enter number of chunks received:\n");
  scanf("%d", & n1);
  for (i = 0; i < n1; i++) {
    printf("Enter %d values of chunk %d:\n", b, i + 1);
    for (j = (i * n); j < (i * n) + n; j++) {
      scanf("%d", & a[j]);
    }
    printf("\n");
  }
  printf("Reconstructed stream:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n1; j++) {
      printf("%d ", a[i + (j * n)]);
    }
    printf("\t");
  }
  printf("\n");
  return 0;
}
