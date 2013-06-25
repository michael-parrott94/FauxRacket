/* Implement a REPL for Faux Racket

For current syntax implemented, see Syntax.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include "Sexp.h"
#include "FauxRacket.h"

int main(void)
{
	struct node *prog;
	struct FRVal result;
	struct exp *parsed;
	
	printf( "Welcome to the Faux Racket interpreter!\n" );
	printf( "To use this, enter a program to be interpreted.\n" );
	printf( "To stop, enter the empty program ().\n\n" );
	
	while(1)
	{
		printf( "Enter a Faux Racket program to be interpreted:\n" );
		prog = miread();
		
		//Check for the representation of the empty program
		if( prog->tag == LST && prog->sublst == NULL )
			break;
			
		parsed = parse(prog);
		DEBUG_PRINTF( "parsing complete\n" );
		result = interp_loop( parsed, NULL );
		printf( "%d\n", result.v.n );
		
		//free_sexp( prog );
		//free_ast( parsed );
	}
	free(prog);
	
	printf( "\nEnd\n" );
	return 0;
}
