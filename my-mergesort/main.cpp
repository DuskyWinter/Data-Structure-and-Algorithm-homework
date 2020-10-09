#include<iostream>
#include"mergesort.h"

int main( int argc, char *argv[])
{
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for( int i = 0; i < n; i++)
    std::cin >> arr[i];
  MergeSort(arr);
  for( int i = 0; i < n; i++)
    std::cout << arr[i] << ", ";
  std::cout << "\b\b" << std::endl;
  
  return 0;
}
