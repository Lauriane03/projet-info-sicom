
/**
 * @file print.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 22 20:12:17 2012
 * @brief Printing stuff for SFS.
 *
 * Printing stuff for SFS.
 */

#include "print.h"

#include <stdio.h>



void sfs_print_pair( object o ) {

	sfs_print_atom( o->this.pair.car );
	if (o->this.pair.cdr->type != SFS_NIL)
	{	printf(" ");
		sfs_print( o->this.pair.cdr );
	}
}



void sfs_print_atom( object o ) {

	switch (o->type) {
		case (SFS_NUMBER):
			printf("%d", o->this.number.this.integer);
			break;
		case (SFS_STRING):
			printf("%s", o->this.string);
			break;
		case (SFS_BOOLEAN):
			printf("#%c", o->this.character);
			break;
		case (SFS_CHARACTER): 
			printf("#\\%c", o->this.character);
			break;
		case (SFS_SYMBOL):
			printf("%s",o->this.symbol);
			break;
	}
		

}

void sfs_print( object o ) {

	switch (o->type){
		case ( SFS_PAIR ):
			if (o->this.pair.car->type == SFS_PAIR)	
			{	printf("(");					/*Si le car de l'objet est une paire, on ouvre une parenthèse*/
				sfs_print_pair( o->this.pair.car );		/*Puis on lit le car du car de l'objet*/
			}
			else if ( o->this.pair.cdr->type == SFS_NIL )
			{	sfs_print_pair( o );
				printf(")");					/*Si le cdr de l'objet est nul, alors on ferme la liste*/
			}
			else
				sfs_print_pair( o );
			break;
		case ( SFS_NIL ):
				printf("()");
			break;
		default :
			sfs_print_atom( o );
			break;
	}
}
