/**
 * @file   Student.h
 * @author Jeason Cheung <jeason@Jeason-Cheung>
 * @date   Thu Oct  8 05:26:58 2020
 * 
 * @brief  Two sorting algorithm to sort out students' data.
 * 
 * 
 */
#ifndef __mycode__
#define __mycode__
struct student{
  int std_no;                    /**< Student number, every student has a unique ID number. */
  char major;                    /** Student major marked by one character, M for math, P for
                                 Physics, C for Chemistry. */    
  double GPA;                    /** GPA range: 0 ~ 5 */
};
#define PARENT(i) ((((i) + 1) >> 1) - 1)
#define LEFTCHILD(i) ((((i) + 1) << 1) -1)
#define RIGHTCHILD(i) (((i) + 1) << 1)
    
class Student{
  
private:
  struct student *stu;		/**< Store students' data */
  struct student *hstu;
  struct student *mstu;
  int  number;		 /**< Number of students */
public:
  Student();
  Student(struct student *datapoint, int n);
  int get_length();
  ~Student();
  int Heap();
  int HeapSort();
  int shiftdown(int i);
  int printout1(struct student *datapoint);
  int Merge();
  int MergeSort(int _p, int _q, int _r);
  int _MergeSort(int _p, int _r);
  int printout2(struct student *datapoint);
  /** 
   * Use heapsort to sort students' majors
   * 
   * @param A Store n students' data.
   * @param n Number of students.
   * 
   * @return Error code, 0 for OK.
   */
  int sort_m(struct student *A, int n);

  /** 
   * Use mergesort to sort students' GPA
   * 
   * @param A Store n students' data.
   * @param n Number of students.
   * 
   * @return Error code, 0 for OK.
   */
  int arrange(struct student *A, int n);

  int printout();
  
  
  
};
//
//
int generate_data(int n, char *major, double *GPA);
int  Heap_stability(struct student *datapoint, int n);


#else
// Do Nothing
#endif  
  
  
