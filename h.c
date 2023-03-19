// array.c
// Program to demonstrate Dynamic array operations:
// Traversal, Insertion, Search, Deletion, Merge,
// Sort, Update, Minimum, Maximum.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *create_array( int **Aptr, int *nptr );
int *insert( int **Aptr, int *nptr, int pos, int key );
int *delete( int **Aptr, int *nptr, int pos );
void print_array( int *A, int n );

int main( void ) {

  int *a = NULL; // pointer to beginning of array
  int n = 0;     // pointer to the last element
  int pos = 0, key = 0;

  char answer = 'q';

  begin:;
  printf( "\n%s",
    "Choose from the following options:\n"
    "   To list array contents enter     L\n"
    "   To create an array enter         C\n"
    "   To insert a new element enter    I\n"
    "   To update an existing element    U\n"
    "   To delete an element enter       D\n"
    "   To end the program enter         Q\n : " );
  scanf( " %c%*[^\n]%*c", &answer );

  switch ( toupper( answer ) ) {

    case 'L': {
      if ( NULL != a ) {
        printf( "Contents of the array:\n\t" );
        print_array( a, n );
        puts( "" );
      }
      else
        puts( "** No array is created **" );
      goto begin;
    }

    case 'C': {
      if ( NULL != a ) {
        printf( "%s", "There already exists an array.\n"
          "Do you want to delete it? " );
        scanf( " %c%*[^\n]%*c", &answer );

        if ( toupper( answer ) == 'Y' ) {
          free( a ); a = NULL;
        }
        else goto begin;
      }

      if ( create_array( &a, &n ) != NULL ) {
        printf( "Enter %d elements:\n\t", n );

        // Populate the array
        for ( int i = 1; i <= n; ++i )
          scanf( "%d", &a[ i ] );

        printf( "Resultant array:\n\t" );
        print_array( a, n );
        puts( "" );
      }
      else
        puts( "** Insufficient memory **" );
      goto begin;
    }

    case 'I': {
      if ( NULL != a ) {
        do {
          printf( "%s", "Enter insertion point: " );
          scanf( "%d", &pos );
        } while ( pos < 1 || pos > n );

        printf( "%s", "Enter value to insert: " );
        scanf( "%d", &key );

        if ( insert( &a, &n, pos, key ) != NULL ) {
          printf( "Resultant array:\n\t" );
          print_array( a, n );
          puts( "" );
        }
      }
      else
        puts( "** No array is created **" );
      goto begin;
    }

    case 'U': {
      if ( NULL != a ) {
        do {
        printf( "%s", "Enter updation point: " );
          scanf( "%d", &pos );
        } while ( pos < 1 || pos > n );

        printf( "%s", "Enter new updated value: " );
        scanf( "%d", &key );

        a[ pos ] = key;

        printf( "Resultant array:\n\t" );
        print_array( a, n );
        puts( "" );
      }
      else
        puts( "** No array is created **" );
      goto begin;
    }

    case 'D': { // Take care of empty array
      if ( NULL != a ) {

        if ( 1 == n ) {
          printf( "The array has only one element.\n"
            "Do you want to delete the array? " );
          scanf( " %c%*[^\n]%*c", &answer );

          if ( toupper( answer ) == 'Y' ) {
            free( a ); a = NULL;
          }
          goto begin;
        }

        do {
          printf( "%s", "Enter deletion point: " );
          scanf( "%d", &pos );
        } while ( pos < 1 || pos > n );

        if ( delete( &a, &n, pos ) != NULL ) {
          printf( "Resultant array:\n\t" );
          print_array( a, n );
          puts( "" );
        }
      }
      else
        puts( "** No array is created **" );
      goto begin;
    }

    case 'Q': {
      puts( "Ending the program." );
      free( a );
      a = NULL;
      return 0;
    }

    default:
      puts( "** Invalid input; try again **" );
      goto begin;
  }
}

int *create_array( int **Aptr, int *nptr ) {

  do {
    printf( "%s", "Enter array size: " );
    scanf( "%d", nptr );
  } while ( *nptr < 1 );

  // Create an array A[1:n], A[0] is invalid.
  int *p = NULL;
  p = malloc( ( *nptr + 1 ) * sizeof( int ) );
  // *Aptr = calloc( ( n + 1 ), sizeof( int ) );
  // *Aptr = realloc( NULL, ( n + 1 ) * sizeof( int ) );
  // Note: True array size must be (n + 1),
  // because C uses 0-origin indices for arrays.
  // and we are implementing an 1-origin array.

  *Aptr = p;
  return p;
}

// Aptr = pointer to 1-origin array A[1:n]
// nptr = pointer to current number of elements n
// It returns A[1:n+1] (i.e, pointer to the beginning
// of new A) on success or NULL pointer on failure.
int *insert( int **Aptr, int *nptr, int pos, int key ) {

  // Expand the array for new element
  int *p = NULL; // pointer to (possibly) new block
  p = realloc( *Aptr, ( *nptr + 2 ) * sizeof *p );
  if ( NULL == p ) {
    puts( "** Unable to expand **" );
    return NULL;
  }
  // Note: If a == p holds, then it implies that
  // the existing memory block was expanded.
  // Otherwise, a new memory block of requested
  // size was allocated, the contents of the
  // old block were copied into the new one and
  // the old block was freed. If p == NULL, then
  // there wasn't enough memory to perform either
  // of the operations, in which case, the old
  // block is untouched, but it can be contracted.
  *Aptr = p; // equivalent to A = p

  for ( int i = *nptr; i >= pos; --i )
    ( *Aptr )[ i + 1 ] = ( *Aptr )[ i ];

  ( *Aptr )[ pos ] = key;
  ++( *nptr ); // as n points to the last element

  return p;
}

// Same return behaviour as insert() function.
int *delete( int **Aptr, int *nptr, int pos ) {

  // Contract the array by 1 element

  int temp = ( *Aptr )[ pos ];

  for ( int i = pos; i <= *nptr - 1; ++i )
    ( *Aptr )[ i ] = ( *Aptr )[ i + 1 ];

  int *p = NULL; // pointer to (possibly) new block
  p = realloc( *Aptr, ( *nptr ) * sizeof *p );
  if ( NULL == p ) {
    puts( "** Unable to contract **" );

    for ( int i = ( *nptr - 1 ); i >= pos; --i )
      ( *Aptr )[ i + 1 ] = ( *Aptr )[ i ];
    ( *Aptr )[ pos ] = temp;

    return NULL;
  }

  *Aptr = p;
  --( *nptr );

  return p;
}

void print_array( int *A, int n ) {
  for ( int i = 1; i <= n; ++i )
    printf( "%d ", A[ i ] );
}
