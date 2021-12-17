

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <stdbool.h>


#include "code-gen.h"
#include "common.h"

char outputFilename[STR_SZ];
char baseFilename[STR_SZ];
FILE *outputFP;
bool debug = false;


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
    
   // Parse compiler flags.
    for( int c = 1; c < argc; c++ )
    {
        if( strcmp( argv[c], STR_VERBOSE ) != 0 )
        {
            debug = true;
        }
    }

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

