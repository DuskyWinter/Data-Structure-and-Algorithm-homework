#include "Heap.h"
#include <iostream>
Heap::Heap()
{
  data = NULL;
  length = 0;
}

Heap::Heap(char *datahead, int l)
{
  data = new char[l];
  // (int*)malloc(sizeof(int)* l);  
  for(int i = 0; i < l; i++)
    data[i] = datahead[i];
  length = l;
  for(int i = PARENT(l - 1); i >= 0; i--)
    shiftdown(i);
  for (int i = 0; i < length; i++){
    std::cout << data[i] << ", ";
  }
  std::cout << "\b\b" << std::endl;
}

Heap::~Heap()
{
  delete[] data;
}

int Heap::get_length(){
  return length;
}

int Heap::get_height(){
  int l = length;
  int dights = 1;
  while(l >>= 1 != 0)
    dights++;
  return dights;
}

bool Heap::is_empty()
{
  bool result = false;
  if (length == 0)
    result = true;
  return result;
}

int Heap::shiftdown(int i)
{
  int lc = LEFTCHILD(i);
  if(lc >= length)
    return 0;
  int child = lc;
  int rc = RIGHTCHILD(i);
  if(rc < length && data[rc] > data[lc])
    child = rc;
  if (data[i] < data[child])
    {
      char tmp = data[i];
      data[i] = data[child];
      data[child] = tmp;
      shiftdown(child);
        for (int i = 0; i < length; i++){
	  std::cout << data[i] << ", ";
  }
	std::cout << "\b\b" << std::endl;
    }
  return 0;
}

int Heap::sort()
{
  int l = length;
  while(length > 0)
    {
      char tmp = data[0];
      data[0] = data[length - 1];
      data[length - 1] = tmp;
      length--;
      shiftdown(0);
    }
  length = l;
  return 0;
}

int Heap::printout(){
  for(int i = 0; i < length; i++)
    std::cout << data[i] << ", ";
  std::cout << "\b\b\n";
  return 0;
}
