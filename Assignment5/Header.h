/*
 * Header.h
 *
 *  Created on: Feb 17, 2015
 *      Author: aramirez7412
 */

#ifndef HEADER_H_
#define HEADER_H_


#include <iostream>
#include <iomanip>
//#include "Vector.h"

//#include "binaryNode.h"
using namespace std;


void OutputHeader(ostream&     out,      //IN - Used for output
				  const string NAME,     //IN - Used for output
				  const string CLASS,    //IN - Used for output
				  const string SECTION,  //IN - Used for output
				  const int    LAB_NUM,  //IN - Used for output
				  const string LAB_NAME, //IN - Used for output
				  char         asType);   //IN - Used for output



#endif /* HEADER_H_ */
