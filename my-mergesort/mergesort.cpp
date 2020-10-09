#include "mergesort.h"
int Merge(std::vector<int> &_A, int _p , int _q, int _r)
{
  int n1 = _q - _p + 1 ;
  int n2 = _r - _q ;
  std::vector<int> L(n1 + 1);
  std::vector<int> R(n2 + 1);
  for( int i = 0; i < n1; i++)
    L[i] = _A[_p + i];
  for( int i =0; i < n2; i++)
    R[i] = _A[_q + i + 1];
  const int infty = std::numeric_limits<int>::max();
  L[n1] = R[n2] = infty;
  int i = 0 , j = 0;
  for( int k = _p; k < _r + 1; k++){
    if(L[i] <= R[j]){
      _A[k] = L[i];
      i++;
    }
    else{
      _A[k] = R[j];
      j++;
    }
  }
  return 0;
}
int _MergeSort(std::vector<int> &_A, int _p, int _r)
{
  int q;
  if(_p < _r){
    q = ( _p + _r) / 2;
    _MergeSort(_A, _p, q);
    _MergeSort(_A, q+1, _r);
    Merge(_A, _p, q, _r);
    }
  return 0;
    
}
int MergeSort(std::vector<int> &_A)
{
  _MergeSort(_A, 0, _A.size() - 1);
  return 0;
}
