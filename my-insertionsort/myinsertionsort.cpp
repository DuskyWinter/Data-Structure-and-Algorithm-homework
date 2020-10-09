#include<iostream>
#include<vector>
int insertionSort (std::vector<double> &_arr);
int insertionSort (std::vector<double> &_arr){
  for(int j = 1; j < _arr.size() ; j++ ){
    double key = _arr[j];
    int i=j-1;
    while(i >= 0 && key < _arr[i]){
      _arr[i + 1] = _arr[i];
      i = i - 1;
    }
    _arr[i + 1]=key;
  }
  return 0;
}
int INSERTION_SORT(double A[],int length);
int INSERTION_SORT(double A[],int length){
  for(int j = 1; j < length ; j++ ){
    double key = A[j];
    int i=j-1;
    while(i >= 0 && key < A[i]){
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1]=key;
  }
  return 0;
}

int main(int argc,char *argv[] ){
  int n;
  std::cin >> n;
  std::vector<double> arr(n);
  /*  double *A = NULL;
  if((A = (double*)std::malloc(sizeof(double) * N)) == NULL){

    std::cerr << "No enough memory." << std::endl;
    std::exit(-1);
    }*/
  for(std::vector<double>::iterator arr_iterator = arr.begin();
      arr_iterator != arr.end();
      ++arr_iterator)
    std::cin >> *arr_iterator;
  /*  for(int i = 0;i < N; i++){
      std::cin >> A[i];
  }*/
  //  INSERTION_SORT(A,N);
  insertionSort(arr)
  for(std::vector<double>::iterator arr_iterator = arr.begin();
      arr_iterator != arr.end();
      ++arr_iterator)
    std::cout << *arr_iterator << " ";
  std::cout << std::endl;
  
  return 0;
}
