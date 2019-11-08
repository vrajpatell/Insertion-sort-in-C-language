// Patel, Vraj H.
// vhp9326
// 2019-06-15
//--------#---------#---------#---------#--------#
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "support.h"

//--------#---------#---------#---------#--------#
// DO NOT CHANGE ANYTHING IN THIS FILE!
//--------#---------#---------#---------#--------#
double insertionSortTest( int *A, int size )
{
  clock_t begin;
  clock_t end;
  double  elapsed;

  begin = clock();
  insertionSort( A, size );
  end = clock();

  elapsed = (double) ( end - begin ) / CLOCKS_PER_SEC;

  return elapsed;
}

//--------#---------#---------#---------#--------#
int main( int argc, char *argv[] ) {
  int n;
  int ascending;
  int descending;
  int shuffle;
  int *A;

  double fill;
  double elapsed;
  double total;
  int    errs;

  // No buffering of output.
  setbuf( stdout, NULL );

  // Enable thousand separators in printf().
  setlocale( LC_NUMERIC, "" );

  // Initialize the pseudorandom number generator.
  srand48( time( NULL ) );

  // Announce ourselves.
  printf( "=== Insertion Sort ===\n" );

  // Get how many items to sort, and whether we should
  // do an ascending test, a descending test, and/or
  // a shuffle test.
  getArgs( argc, argv, &n, &ascending, &descending, &shuffle );

  // Allocate the array.
  A = malloc( sizeof( int ) * n );
  if ( NULL == A ) {
    printf( "%s: unable to allocate %d-element array.\n", argv[0], n );
  }
  printf( "%'d item%s in array.\n", n, n == 1 ? "" : "s" );

  //------------------------------------------------
  // Do the ascending test, if requested.
  if ( ascending > 0 ) {
    printf( "--- Ascending test\n" );

    total = 0.0;
    for ( int i=0; i < ascending; i++ ) {
      // printf( "--- Ascending test %d of %d\n", i+1, ascending );

      fill = fillArray( A, n, ASCENDING );
      elapsed = insertionSortTest( A, n );
      total += elapsed;
      errs = checkArray( A, n );

      printf( "%2d/%2d: fill %.3fs, run %.3fs, %d error%s.\n",
        i+1, ascending, fill, elapsed, errs, errs == 1 ? "" : "s"  );
    }

    if ( ascending > 1 ) {
      printf( "Average run time %.3fs\n", total / ascending );
    }
  }

  //------------------------------------------------
  // Do the descending test, if requested.
  if ( descending > 0 ) {
    printf( "--- Descending test\n" );

    total = 0.0;
    for ( int i=0; i < descending; i++ ) {
      fill = fillArray( A, n, DESCENDING );
      elapsed = insertionSortTest( A, n );
      total += elapsed;
      errs = checkArray( A, n );

      printf( "%2d/%2d: fill %.3fs, run %.3fs, %d error%s.\n",
        i+1, descending, fill, elapsed, errs, errs == 1 ? "" : "s"  );
    }

    if ( descending > 1 ) {
      printf( "Average run time %.3fs\n", total / descending );
    }
  }

  //------------------------------------------------
  // Do the shuffle test, if requested.
  if ( shuffle > 0 ) {
    printf( "--- Shuffle test\n" );

    total = 0.0;
    for ( int i=0; i < shuffle; i++ ) {
      fill = fillArray( A, n, SHUFFLE );
      elapsed = insertionSortTest( A, n );
      total += elapsed;
      errs = checkArray( A, n );

      printf( "%2d/%2d: fill %.3fs, run %.3fs, %d error%s.\n",
        i+1, shuffle, fill, elapsed, errs, errs == 1 ? "" : "s"  );
    }

    if ( shuffle > 1 ) {
      printf( "Average run time %.3fs\n", total / shuffle );
    }
  }

  // All done!  Free the allocated array.
  free( A );
}

//--------#---------#---------#---------#--------#
