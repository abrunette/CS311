/*==========================================================
slist.h for HW3P3 Provided by Rika for those who could not
get it to work.
============================================================*/

#ifndef SLIST_H
#define SLIST_H

#include "llist.h"

class slist: public llist
{
	public:
		slist();
		slist(const slist&);
		int search(el_t) ;
		void replace(el_t , int );
	        slist& operator=(const slist& );

};
#endif
