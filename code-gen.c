

#include <stdio.h>
#include "code-gen.h"


void emit_header( FILE *fp )
{
    fprintf( fp, ".section	__TEXT,__text,regular,pure_instructions \n " );
    fprintf( fp, ".build_version macos, 12, 0	sdk_version 12, 0 \n " );
}

void emit_data( FILE *fp )
{
    fprintf( fp, ".section	__DATA,__data \n" );
    fprintf( fp, ".globl	_def                            ## @def \n" );
    fprintf( fp, ".p2align	2 \n" );
    fprintf( fp, "_def: \n" );
    fprintf( fp, "	.long	0x3dfbe76d                      ## float 0.123000003 \n" );

    fprintf( fp, "	.globl	_abc                            ## @abc \n" );
    fprintf( fp, "	.p2align	2 \n" );
    fprintf( fp, "_abc: \n" );
    fprintf( fp, "	.long	888                             ## 0x378 \n" );

}


void emit_var( FILE *fp, char *symbol, char *type, char *initialValue, char *textInitialiser )
{
    fprintf( fp, ".globl	_%s                            ## @%s \n", symbol, symbol );
    fprintf( fp, ".p2align	2 \n" );
    fprintf( fp, "_%s: \n", symbol );
    fprintf( fp, "	.long	%s                      ## %s %s \n", initialValue, type, textInitialiser );
}


void emit_sections( FILE *fp  )
{
    fprintf( fp, ".subsections_via_symbols \n" );
}



