

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "code-gen.h"

char outputFilename[255];
FILE *outputFP;


void banner()
{
   printf( "Coral-66\n" );
}

void parse_args( int argc, char **argv )
{
   strcpy( outputFilename, "temp.s" );
}

int main( int argc, char **argv ) 
{
   char command[255];

   banner();
   parse_args( argc, argv );

   outputFP = fopen( outputFilename, "w" );
   emit_header( outputFP );
   fclose( outputFP );
   
   sprintf( command, "/usr/bin/as %s", outputFilename ); 
   system( command );
}

