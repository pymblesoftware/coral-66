

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "code-gen.h"

const int STR_SZ = 255;
const char *STR_EXT = ".crl";
const char *STR_SEP = ".";
char outputFilename[STR_SZ];
char baseFilename[STR_SZ];
FILE *outputFP;


void banner()
{
   printf( "Coral-66\n" );
}

char *getBaseFilename( char *filename )
{
    return strtok( filename, STR_SEP );
}

void parse_args( int argc, char **argv )
{
   // Parse filename from args.
   strcpy( baseFilename, "temp" );

   for( int c = 1; c < argc; c++ )
   {
       if( strstr( argv[c], STR_EXT ) != NULL )
       {
           strcpy( baseFilename, getBaseFilename(argv[c]) );
       }
   }
    
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

