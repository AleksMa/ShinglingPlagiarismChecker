#include <stdio.h>
#include <string.h>

int main( int argc, char **argv )
{
    int height = atoi( argv[ 1 ] ), width = atoi( argv[ 2 ] ), i, j;
        
    if ( argc != 4 )
    {
        printf( "Usage: frame <height> <width> <text>\n" );
        return 0;
    }
    
    char string[ 1000 ];
    strcpy( string, argv[ 3 ] );
    
    int len = strlen( string );
    if( width - 2 < len || height < 3 )
    {
        printf( "Error\n" );
        return 0;
    }
    
    for( i = 0; i < width; i++ )
    printf( "*");
    printf( "\n" );
    int PrintString = 0, PosStringX = (width - len) / 2 + 1, PosStringY = height / 2 - 1;
    
    if( height % 2 != 0 )PosStringY++;
    for( i = 0; i < height - 2; i++ )
    {
         if( i == PosStringY - 1 )PrintString = 1;
         
         for( j = 0; j < width; j++ )
         {
             if( j == PosStringX - 1 && PrintString )
             {
                 printf( "%s", string );
                 PrintString = 0;
                 j += len - 1;
             }
             else
             { 
                 if( j == 0 || j == width - 1 )
                 printf( "*" );
                 else printf( " " );
             }
         }
         printf( "\n" );
    }
    
    for( i = 0; i < width; i++ )
    printf( "*" );
    
    printf( "\n" );
    
    return 0;
}
