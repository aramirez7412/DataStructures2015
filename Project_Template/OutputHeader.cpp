#include "Header.h"

/*******************************************************************************
 * OutputHeader (Function)
 * -----------------------------------------------------------------------------
 * This function is used to output the header to the console or an file
 * associated with the ostream passed (first parameter called "out"
 * -----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * --------------
 * ostream&     out     : Must be previously defined
 * const string NAME    : Must be previously defined
 * const string CLASS   : Must be previously defined
 * const string SECTION : Must be previously defined
 * const int    LAB_NUM : Must be previously defined
 * const string LAB_NAME: Must be previously defined
 * char         asType  : Must be previously defined\
 *
 * POST-CONDITIONS
 * ---------------
 *      **************************************************
 *	    * Programmed by : Anthony Ramirez
 *      * Student ID    : 369397
 *      * CS1D          :Tuesday/Thursday
 *      * ASSIGNMENT #1 : Lab name
 *      **************************************************
 ******************************************************************************/


void OutputHeader(ostream&     out,      //IN - Used for output
				  const string NAME,     //IN - Used for output
				  const string CLASS,    //IN - Used for output
				  const string SECTION,  //IN - Used for output
				  const int    LAB_NUM,  //IN - Used for output
				  const string LAB_NAME, //IN - Used for output
				  char         asType)   //IN - Used for output


{
	out << left;
	out << "**************************************************\n";
	out << "* Programmed by : " << NAME << "\n";
	out << "* "   << setw(14)   << "Student ID" << ": 369397";
	out << "\n* " << setw(14)   << CLASS << ":" << SECTION;
	if (toupper(asType) == 'L')
	{
		out << "\n* LAB # " << setw(9);
	}
	else
	{
		out << "\n* ASSIGNMENT #" << setw(2);
	}
	out << LAB_NUM << ": " << LAB_NAME;
	out << "\n**************************************************\n";

\
}

