/*********************************************************************
 * @file   Message.cpp
 * @brief  .
 * 
 * Project: Excalibur
 * 
 * @author Xander Boosinger (xboosinger@gmail.com)
 * @date   April 2025
 * 
 *********************************************************************
/*
 *			*	/\
 *			   / /	*
 *		*	__/ /__
 *		      /	  *
 *			 /
 */

#include "Message.h"

#include "MultiField.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

Message::~Message()
{
	static vector<NamedMultiFieldWrapper*> deleted;

	for (int i = 0; i < deleted.size(); ++i)
	{
		if (resources == deleted[i])
		{
			int a = 0;
			++a;
		}
	}

	deleted.push_back(resources);

	cout << "Deleted " << resources << endl;

	//delete resources;
}
