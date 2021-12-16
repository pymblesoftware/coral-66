

#include <stdio.h>
#include "code-gen.h"


void emit_header( FILE *fp )
{
	fprintf( fp, ".section	__TEXT,__text,regular,pure_instructions \n " );
	fprintf( fp, ".build_version macos, 12, 0	sdk_version 12, 0 \n " );
 	fprintf( fp, ".subsections_via_symbols \n" );
}

