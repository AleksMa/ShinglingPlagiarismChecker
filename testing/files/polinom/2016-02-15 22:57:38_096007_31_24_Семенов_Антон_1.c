#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int64_t gorner_scheme_polynom( int64_t * coefficients, int64_t power, int64_t point )
{
    int64_t polynom_value = coefficients[ power ];

    if ( power > 0 )
    {
        int64_t coefficient_number = power;

        do
        {
            polynom_value = polynom_value*point + coefficients[ coefficient_number - 1] ;
            --coefficient_number;
        }
        while ( coefficient_number > 0 );
    }

    return polynom_value;
}

int64_t gorner_scheme_deriv( int64_t * coefficients, int64_t power, int64_t point )
{
    int64_t deriv_value = coefficients[ power ] * power;

    if ( power > 1 )
    {
        int64_t coefficient_number = power;

        do
        {
            deriv_value = deriv_value*point + coefficients[ coefficient_number - 1] * ( coefficient_number - 1) ;
            --coefficient_number;
        }
        while ( coefficient_number > 1 );
    }

    return deriv_value;
}


int main()
{
    int64_t power = 0;
    int64_t * coefficients = NULL;
    int64_t point = 0;

    scanf( "%lld", &power );
    scanf( "%lld", &point );

    coefficients = calloc( ( power + 1 ) , sizeof( point ) );

    for( int coefficient_number = power; coefficient_number >= 0; --coefficient_number )
    {
        scanf( "%lu", &coefficients[ coefficient_number ] );
    }

    int64_t polynom_value = gorner_scheme_polynom( coefficients, power, point );

    printf( "%lld ", polynom_value );

    int64_t deriv_value = gorner_scheme_deriv( coefficients, power, point );

    printf( "%lld", deriv_value );

    free( coefficients );

    return 0;
}




