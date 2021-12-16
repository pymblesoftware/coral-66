

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

void banner()
{
   printf( "Coral-66\n" );
}

int main( int argc, char **argv ) 
{
   char command[255];
   char filename[255];

   banner();
   
   strcpy( filename, "temp.s" );
   sprintf( command, "/usr/bin/as %s", filename ); 
   system( command );
}

