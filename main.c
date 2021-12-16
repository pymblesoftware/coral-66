

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "code-gen.h"

const int STR_SZ = 255;
char outputFilename[STR_SZ];
char baseFilename[STR_SZ];
FILE *outputFP;


void banner()
{
   printf( "Coral-66\n" );
}

void parse_args( int argc, char **argv )
{
   // TODO: Parse filename from args.
   strcpy( baseFilename, "temp" );
   sprintf( outputFilename, "%s.s", baseFilename );
}

int main( int argc, char **argv ) 
{
   char command[STR_SZ];

   banner();
   parse_args( argc, argv );

   outputFP = fopen( outputFilename, "w" );
   emit_header( outputFP );
   emit_data( outputFP );
   emit_sections( outputFP );
   fclose( outputFP );

   char objectFilename[STR_SZ];
   sprintf( objectFilename, "%s.o", baseFilename );

   sprintf( command, "/usr/bin/as -o %s  %s", objectFilename, outputFilename ); 
   system( command );
}

