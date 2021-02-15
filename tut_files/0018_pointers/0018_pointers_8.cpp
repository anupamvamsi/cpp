#include <iostream>

int main() {
  int a;  // goes onto stack

  // heap (dynamic memory)
  int* p;
  p = new int;  // instead of malloc()
  *p = 12;
  delete p;  // instead of free(p)

  // array on heap
  p = new int[20];
  delete[] p;
}

// C style code:
/*
int main() {
  int a;
  int *p;
  // malloc() returns (void*), hence typecasting it to int*
  p = (int*)malloc(sizeof(int));

  // assigning the address at 'p' the int value '10'
  *p = 10;

  // freeing the address at 'p' before proceeding
  free(p);

  // using malloc() to create space for arrays
  p = (int*)malloc(20*sizeof(int));
  p[0] = 12;
  *(p + 1) = 13; // p[1] = 13;

  free(p);

  // IF malloc() IS UNABLE TO ALLOCATE A FREE BLOCK OF MEMORY,
  // IT RETURNS null. IMPORTANT NOTE FOR ERROR HANDLING.
}
*/