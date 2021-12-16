

%{


#include "tokens.h"


%}


%%

"ABSOLUTE"   { return T_ABSOLUTE; }
"AND"        { return T_AND; }
"ANSWER"     { return T_ANSWER; }
"ARRAY"      { return T_ARRAY; }
"BEGIN"      { return T_BEGIN; }
"BIT"        { return T_BIT; }
"BITS"       { return T_BITS; }
"CODE"       { return T_CODE; }
"COMMENT"    { return T_COMMENT; }
"COMMON"     { return T_COMMON; }
"DEFINE"     { return T_DEFINE; }
"DELETE"     { return T_DELETE; }
"DIFFER"     { return T_DIFFER; }
"LABEL"      { return T_LABEL; }
"DO"         { return T_DO; }
"LIBRARY"    { return T_LIBRARY; }
"TABLE"      { return T_TABLE; }
"ELSE"       { return T_ELSE; }
"LITERAL"    { return T_LITERAL; }
"THEN"       { return T_THEN; }
"LOCATION"   { return T_LOCATION; }
"UNION"      { return T_UNION; }
"END"        { return T_END; }
"UNSIGNED"   { return T_UNSIGNED; }
"EXTERNAL"   { return T_EXTERNAL; }
"MASK"       { return T_MASK; }
"FINISH"     { return T_FINISH; }
"OCTAL"      { return T_OCTAL; }
"UNTIL"      { return T_UNTIL; }
"FIXED"      { return T_FIXED; }
"OR"         { return T_OR; }
"VALUE"      { return T_VALUE; }
"FLOATING"   { return T_FLOATING; }
"OVERLAY"    { return T_OVERLAY; }
"WHILE"      { return T_WHILE; }
"FOR"        { return T_FOR; }
"PRESET"     { return T_PRESET; }
"WITH"       { return T_WITH; }
"GOTO"       { return T_GOTO; }
"PROCEDURE"  { return T_PROCEDURE; }
"IF"         { return T_IF; }
"RECURSIVE"  { return T_RECURSIVE; }
"INTEGER"    { return T_INTEGER; }
"STEP"       { return T_STEP; }

%%


