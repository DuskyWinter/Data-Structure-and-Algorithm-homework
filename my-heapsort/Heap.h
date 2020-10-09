#ifndef __mycode__
#define __mycode__
class Heap{
 private:
  char *data;
  int length;
 public:
#define PARENT(i) ((((i) + 1) >> 1) - 1)
#define LEFTCHILD(i) ((((i) + 1) << 1) - 1)
#define RIGHTCHILD(i) (((i) + 1) << 1) 
  int get_length();
  int get_height();
  Heap();
  Heap(char *datahead, int l);
  ~Heap();
  bool is_empty();   //useless
  int printout();
  int sort();
  int shiftdown(int i);
  
};

#else
// Do Nothing
#endif
