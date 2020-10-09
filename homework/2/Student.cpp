#include "Student.h"
#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
//
Student::Student()
{
  stu = NULL;
  number = 0;
}
//
Student::Student(struct student *datapoint, int n)
{
  stu = new struct student[n];
  for(int i = 0; i < n; i++)
    stu[i] = datapoint[i];
  number = n;
}
//
int Student::Heap()
{
  hstu = new struct student[number];
  for(int i = 0; i < number; i++)
    hstu[i] =stu[i];
  for(int i = PARENT(number - 1); i >= 0; i--)
    shiftdown(i);
  return 0;
}
//
int Student::HeapSort()
{
  int n = number;
  while(number > 0){
    struct student tmp = hstu[0];
    hstu[0] = hstu[number - 1];
    hstu[number - 1] = tmp;
    number--;
    shiftdown(0);
  }
  number = n;
  return 0;
}
//
int Student::shiftdown(int i)
{
  int lc = LEFTCHILD(i);
  if(lc >= number)
    return 0;
  int child = lc;
  int rc = RIGHTCHILD(i);
  if(rc < number && hstu[rc].major > hstu[lc].major)
    child = rc;
  if(hstu[i].major < hstu[child].major){
    struct student tmp = hstu[i];
    hstu[i] = hstu[child];
    hstu[child] = tmp;
    shiftdown(child);
  }
    return 0;
}
//
int Student::printout1(struct student *datapoint)
{
  for(int i = 0; i < number; i++)
    datapoint[i] = hstu[i];
  for (int i = 0; i < number; i++){
    std::cout << datapoint[i].major << ", ";
  }
  std::cout << "\b\b" << std::endl;
  for (int i = 0; i < number; i++){
    std::cout << datapoint[i].std_no << ", ";
  }
  std::cout << "\b\b" << std::endl;
  return 0;
}
//
int Student::Merge()
{
  mstu = new struct student[number];
  for(int i = 0; i < number; i++)
    mstu[i] = hstu[i];
  return 0;
}
//
int Student::MergeSort(int _p, int _q, int _r)
{
  int n1 = _q - _p + 1;
  int n2 = _r - _q;
  struct student L[n1 + 1];
  struct student R[n2 + 1];
  for(int i = 0; i < n1; i++)
    L[i] = mstu[_p + i];
  for(int i = 0; i < n2;i++)
    R[i] = mstu[_q + 1+ i];
  L[n1] = R[n2]={999, 'X', 999};
  int i = 0;
  int j = 0;
  for(int k = _p; k < _r + 1; k++){
    if(L[i].GPA < R[j].GPA){
      mstu[k] = L[i];
      i++;
    }
    else{
      mstu[k] = R[j];
      j++;
    } 
  }
  return 0;
}
//
int Student::_MergeSort(int _p, int _r)
{
  int q;
  if(_p < _r)
    {
      q = (_p + _r) / 2;
      _MergeSort(_p, q);
      _MergeSort(q+1, _r);
      MergeSort(_p, q, _r);
    }
  return 0;
}
//
int Student::printout2(struct student *datapoint)
{
  for(int i = 0; i < number; i++)
    datapoint[i] = mstu[i];
  for (int i = 0; i < number; i++){
    std::cout << datapoint[i].GPA << ", ";
  }
  std::cout << "\b\b" << std::endl;
  for (int i = 0; i < number; i++){
    std::cout << datapoint[i].std_no << ", ";
  }
  std::cout << "\b\b" << std::endl;
  return 0;
}
//


//
int Student::get_length()
{
  return number;
}
//
Student::~Student()
{
  delete[] stu;
  delete[] hstu;
  delete[] mstu;
}
//
int Student::sort_m(struct student *A, int n)
{
  Heap();
  HeapSort();
  printout1(A);
  return 0;
}
//
int Student::arrange(struct student *A, int n)
{
  Merge();
  _MergeSort(0,n-1);
  printout2(A);
  return 0;
}
//
int generate_data(int n, char *major, double *GPA)
{
  typedef std::chrono::high_resolution_clock myclock;
    myclock::time_point beginning = myclock::now();
    // Just do something ...
    int p = n+2;
    for(int i=0;i<n;i++)
      i=i*2-i;
    // obtain a seed from the timer
    myclock::duration d = myclock::now() - beginning;
    unsigned seed = d.count();
    std::default_random_engine generator1(seed);
    std::uniform_int_distribution<int> dist1(0, 500);
    for (int i = 0; i < n; i++){
      *GPA = dist1(generator1) * 0.01;
      GPA ++;
    }
    std::default_random_engine generator2(seed+1);
    std::uniform_int_distribution<int> dist2(1, 3);
    for(int i =0; i < n; i++){
      int e = dist2(generator2);
      if( e == 1)
	*major = 'C';
      else if(e == 2)
	*major = 'M';
      else if(e == 3)
	*major = 'P';
      else
	*major = 'X';
      major ++;
    }
  return 0;
}
//
int Heap_stability(struct student *datapoint, int n)
{
    int j = 1;
    while(datapoint[j].major == 'C')
      {
	if(datapoint[j-1].std_no > datapoint[j].std_no)
	  return 0;
	else j++;
	if(j == n-1)
	  return 1;
      }
    j++;
    while(datapoint[j].std_no == 'M')
      {
	if(datapoint[j-1].std_no > datapoint[j].std_no)
	  return 0;
	else
	  j++;
	if(j == n-1)
	  return 1;
      }
    while(datapoint[j].std_no == 'P')
      {
	if(datapoint[j-1].std_no > datapoint[j].std_no)
	  return 0;
	else
	  j++;
	if(j == n-1)
	  return 1;
      }
    return 2;
  
}
