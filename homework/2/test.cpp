#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>

#define sizeofd sizeof(double)
int generate_data(int n, char *major, double *GPA);
int generate_data(int n, char *major, double *GPA)
{
  typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();
    // Just do something ...
    int p = n+2;
    if(p == n)
      p = 59;
    else
      p--;
    // obtain a seed from the timer
    myclock::duration d = myclock::now() - beginning;
    unsigned seed = d.count();
    std::default_random_engine generator1(seed);
    std::uniform_real_distribution<float> dist1(0, 5);
    for (int i = 0; i < n; i++){
      *GPA = dist1(generator1);
      GPA++;
    }
    std::default_random_engine generator2(seed);
    std::uniform_int_distribution<int> dist2(1, 3);
    for(int i =0; i < n; i++){
      if( dist2(generator2) == 1)
	*major = 'C';
      else if(dist2(generator2) == 2)
	*major = 'M';
      else 
	*major = 'P';

      major ++;
    }
  return 0;
}

int main()
{
  int n = 100;
  char a[n];
  double b[n];
  generate_data(n, a, b);
  for(int i = 0;i < n; i++){
    std::cout << a[i] << " ";
    std::cout << b[i] << " " << std::endl;
  }
  return 0;
}
