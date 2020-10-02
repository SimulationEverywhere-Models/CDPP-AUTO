/*******************************************************************
*
*  DESCRIPTION: Atomic Model Body
*
*******************************************************************/

#ifndef __BODY_H
#define __BODY_H

#include <list>
#include "atomic.h"     // class Atomic

class Body : public Atomic
{
public:
	Body( const string &name = "Body" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
//	Model &outputFunction( const InternalMessage & );
	Model &outputFunction( const CollectMessage & );
	
private:
	const Port &in;
//	const Port &stop;
	const Port &done;
	Port &out;
	VTime manufacturingTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	VTime timeLeft;

};	// class Body

// ** inline ** // 
inline
string Body::className() const
{
	return "Body" ;
}

#endif   //__BODY_H
