#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>

void setnull( long *a, int len )
{
  int i;
  for ( i = 0; i < len; i++ )
  {
    a[ i ] = 0;
  }
}

int findel( long *a, int len, long long n )
{
  int i;
  for ( i = 0; i < len; i++ )
  {
    if ( a[ i ] == n )
    {
      return TRUE;
    }
  }
  return FALSE;
}

int multiply( long *a, long *b, int len, int maxel )
{
  int i, j;
  int m = 0;
  for ( i = 0; i < maxel; i++ )
  {
    if ( a[ i ] == 0 )
    {
      break;
    }
    for ( j = 0; j < len; j++ )
    {
      if ( b[ j ] == 0 )
      {
        break;
      }
      if ( findel( a, len, a[ i ] * b[ j ] ) == FALSE )
      {
        m++;
        a[ maxel - 1 + m ] = a[ i ] * b[ j ];
        if ( maxel - 1 + m == len - 1 )
        {
          return maxel - 1 + m;
        }
      }
    }
  }
  for ( j = 0; j < len; j++ )
  {
    if ( b[ j ] == 0 )
    {
      break;
    }
    if ( findel( a, len, b[ j ] ) == FALSE )
      {
        m++;
        a[ maxel - 1 + m ] = b[ j ];
        if ( maxel - 1 + m == len - 1 )
        {
          return maxel - 1 + m;
        }
      }
  }
  m++;
  a[ maxel - 1 + m ] = 1;
  return maxel - 1 + m;
}

long long find()
{
  int len = 3001;
  int i, j = 0;
  int d, d1, d2, d3;
  long a[ len ], b[ len ];
  
  d1 = 0;
  i = 0;
  while ( TRUE )
  {
    i++;
    d = 0;
    d2 = 0;
    d3 = 0;
    setnull( a, len );
    setnull( b, len );
    for( j = 2; j <= ( int ) sqrt( i ); j++ )
    {
      if ( ( ( i % 2 == 0 ) && ( ( i + 1 ) % j == 0 ) ) || ( ( i % 2 == 1 ) && ( ( int ) ( ( i + 1 ) / 2 ) % j == 0 ) ) )
      {
        //if ( findel( a, len, j ) == FALSE )
        {
          a[ d2 ] = j;
          if ( i % 2 == 0 )
          {
            a[ d2 + 1 ] = ( i + 1 ) / j;
          }
          else
          {
            a[ d2 + 1 ] = ( i + 1 ) / 2 / j;
          }
          d += 2;
          d2 += 2;
        }
      }
      if ( ( ( i % 2 == 0 ) && ( ( int ) ( i / 2 ) % j == 0 ) ) || ( ( i % 2 == 1 ) && ( i % j == 0 ) ) )
      {
        //if ( findel( b, len, j ) == FALSE )
        {
          b[ d3 ] = j;
          if ( i % 2 == 0 )
          {
            b[ d3 + 1 ] = i / 2 / j;
          }
          else
          {
            b[ d3 + 1 ] = i / j;
          }
          d += 2;
          d3 += 2;
        }
      }
    }
    if ( d2 * d3 + d2 + d3 > d1 )
    {
      /*printf( "%d ", d2 );
      printf( "%d \n ", d3 );
      printf( "%d ", i );
      printf( "%d ", i + 1 );*/
      d1 = d2 * d3 + d2 + d3;
      d = multiply( a, b, len, d2 );
      //printf( "%d \n", d );
    }
    if( d >= 3000 )
    {
      //printf( "%s \n", "BINGO" );
      return i * ( i + 1 ) / 2;
    }
  }
  
  return 0;
}

int main()
{
  long long n = 0;
  
  n = find();
  printf( "%lld", n );
  
  return 0;
}