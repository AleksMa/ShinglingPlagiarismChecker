#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void drawborder( int rows, int columns, char* str )
{
    if ( ( rows > 2 ) && ( columns - 2 >= strlen( str ) ) )
    {
        char* full_string = ( char * ) malloc( columns + 1);
        char* empty_string = ( char * ) malloc ( columns + 1);

        for ( int str_iter = 0; str_iter < columns; str_iter++ )
        {
            full_string[ str_iter ] = '*';
            empty_string[ str_iter ] = ' ';
        }

        full_string[ columns ] = '\0';

        empty_string[ columns ] = '\0';
        empty_string[0] = empty_string[ columns - 1] = '*';

        int first_symbols_count = ( columns - strlen( str ) ) / 2;

        char* word_string = ( char * ) malloc ( columns + 1);


        strncpy( word_string, empty_string, first_symbols_count );
        word_string[ first_symbols_count ] = '\0';

        strcat( word_string, str );

        strcat( word_string, empty_string + first_symbols_count + strlen ( str ) );

        int first_rows_count = rows/2 + ( rows%2 - 1 );

        puts( full_string );

        for ( int rows_iter = 1; rows_iter < first_rows_count; ++rows_iter )
        {
            puts( empty_string );
        }

        puts( word_string );

        for ( int rows_iter = first_rows_count + 1; rows_iter < rows - 1; ++rows_iter )
        {
            puts( empty_string );
        }

        puts( full_string );

        free( full_string );
        free( empty_string );
        free( word_string );
    }
    else
    {
        puts( "Error");
    }
}

int main( int argc, char** argv )
{
    switch( argc )
    {
        case 4:

            drawborder( atoi( argv[1] ), atoi( argv[2] ), argv[3] );

            break;

        default:

            puts( "Usage: frame <height> <width> <text>" );
            break;
    }

    return 0;
}

