
/**
 * @file object.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 15 18:02:57 2012
 * @brief Object definitions for SFS.
 *
 * Object definitions for SFS.
 */

#include "object.h"
#include "mem.h"
#include <string.h>

object make_object( uint type ) {

    object t = sfs_malloc( sizeof( *t ) );

    t->type = type;

    return t;
}

object make_nil( void ) {

    object t = make_object( SFS_NIL );

    t->this.special = NULL;

    return t;
}

object make_empty_list( void ) {
	
	object L = make_nil();
	
	return L;
}

object make_boolean( char c ) { 

	object b = make_object(SFS_BOOLEAN);

	b->this.character = c;

	return b;
	
}

object make_integer( int a) {
	
	object b = make_object(SFS_NUMBER);
	
	b->this.number.this.integer = a;
	
	return b;
}

object make_symbol( char* c ) { 

	object s = make_object(SFS_SYMBOL);
	
	strcpy(s->this.symbol,c);

	return s;
}

object make_character(char c){

	object a = make_object(SFS_CHARACTER);

	a->this.character = c;

	return a;
}

object make_string(char* c){

	object s = make_object(SFS_STRING);

	strcpy(s->this.string,c);

	return s;
}
