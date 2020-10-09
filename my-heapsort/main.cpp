#include "Heap.h"
#include <iostream>

int main( int argc, char *argv[]){
  char arr[10] = {'A','B','C','D','E','F','G','H','I','J'};
  Heap A(arr, 10);
  A.printout();
  A.sort();
  A.printout();
  return 0;
  
}
