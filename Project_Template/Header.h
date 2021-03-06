/*
 * Header.h
 *
 *  Created on: Jan 23, 2015
 *      Author: aramirez7412
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <sstream>
#include <ios>
#include <iostream>
#include <iomanip>
using namespace std;



/*******************************************************************************
 * OutputHeader
 * -----------------------------------------------------------------------------
 * This function outputs the header to the console or a output stream file that
 * is passed in.
 *
 * Returns: This function does not return anything it is of type "void"
 *
 * Source file included in project folder called "OutpuerHeader.cpp". For more
 * information, please see the source code.
 *******************************************************************************/
void OutputHeader(ostream&     out,
				  const string NAME,
				  const string CLASS,
				  const string SECTION,
				  const int    LAB_NUM,
				  const string LAB_NAME,
				  char         asType);





#endif /* HEADER_H_ */
