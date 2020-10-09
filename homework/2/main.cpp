#include "Student.h"
#include <iostream>

int main(int argc, char *argv[])
{
  int n;
  std::cin >> n;
  char major[n];
  double GPA[n];
  /* struct data{
    int std_no;
    char major;
    double GPA;
    };*/
  struct student A[n],B[n],C[n];
  generate_data(n, major, GPA);
  for(int i = 0; i < n; i++)
    A[i] = {i+1, major[i], GPA[i]};
  Student S(A, n);
  S.sort_m(B, n);
  S.arrange(C, n);
  int s = Heap_stability(B, n);
  std::cout << s << std::endl;
  return 0;
}
