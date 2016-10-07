
/**
 * @file eval.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 22 20:11:30 2012
 * @brief Evaluation stuff for SFS.
 *
 * Evaluation stuff for SFS.
 */

#include "eval.h"

object sfs_eval( object input ) {

	if ( input->this.type == SFS_SYMBOL )
	{	if ( input->this.pair.car == "quote" )
			return input->this.pair.cdr;
		if ( input->this.pair.car == "'" )
		{	strcpy( input->this.pair.car, "quote" );
			return sfs_eval( input );
		}
	}
	else 
	    	return input;
}

