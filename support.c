// Patel, Vraj H.
// vhp9326
// 2019-06-15
//--------#---------#---------#---------#--------#
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "support.h"

//--------#---------#---------#---------#--------#
int checkArray( int *A, int n )
{
  int errs = 0;
  int tooManyErrs = 0;

  for ( int i = 0; i < n-1; i++ ) {
    if ( A[i] >= A[i+1] ) {
      if ( ++errs > 5 ) {
        if ( !tooManyErrs ) {
          tooManyErrs = 1;
          printf( "  ...\n" );
        }
      } else {
        printf( "Oops: A[%'d] >= A[%'d] : %'d >= %'d\n", i, i+1, A[i], A[i+1] );
      }
    }
  }

  return errs;
}

//--------#---------#---------#---------#--------#
double fillArray( int *A, int n, int order )
{
  clock_t begin;
  clock_t end;
  double  elapsed;

  begin = clock();
  if ( DESCENDING == order ) {
    for ( int i=0; i < n; i++ ) {
      A[ i ] = n-i;
    }
  } else {
    for ( int i=0; i < n; i++ ) {
      A[ i ] = i;
    }

    if ( order == SHUFFLE ) {
      for ( int i=n-1; i > 0; i-- ) {
        int j = drand48()*(i+1);
        exchangeInt( &A[i], &A[j] );
      }
    }
  }
  end = clock();

  elapsed = (double) ( end - begin ) / CLOCKS_PER_SEC;

  return elapsed;
}

//--------#---------#---------#---------#--------#
void getArgs( int argc, char *argv[], int *n, int *ascending, int *descending, int *shuffle )
{
  if ( 5 != argc ||
       1 != sscanf( argv[1], "%d", n ) ||
       0 >= *n  ||
       1 != sscanf( argv[2], "%d", ascending ) ||
       0 > *ascending ||
       1 != sscanf( argv[3], "%d", descending ) ||
       0 > *descending ||
       1 != sscanf( argv[4], "%d", shuffle ) ||
       0 > *shuffle ) {
    printf( "Usage: %s <size> <ascending> <descending> <shuffle>\n  where\n", argv[0] );
    printf( "    <size> >= 1\n" );
    printf( "    <ascending> is how many times to run the ascending test\n" );
    printf( "    <descending> is how many times to run the descending test\n" );
    printf( "    <shuffle> is how many times to run the shuffle test\n" );

    exit( 1 );
  }

  if ( 0 == *ascending + *descending + *shuffle ) {
    printf( "%s: Must select at least one of ascending, descending, or shuffle.\n",
      argv[0] );

    exit( 1 );
  }
}

//--------#---------#---------#---------#--------#
