// Patel, Vraj H.
// vhp9326
// 2019-06-15
//--------#---------#---------#---------#--------#
#include <stdio.h>
#include <time.h>

#include "support.h"

//--------#---------#---------#---------#--------#
void insertionSort( int *A, int size )
{
  int i,j,k;
  for(i=1; i<size; ++i)
  {
    k = A[i];
    j = i - 1;
    while ((j >=0) && (k < A[j]))
    {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = k;
  }
}

//--------#---------#---------#---------#--------#
