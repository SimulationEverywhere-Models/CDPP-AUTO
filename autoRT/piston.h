/*******************************************************************
*
*  DESCRIPTION: Atomic Model Piston
*
*******************************************************************/

#ifndef __PISTON_H
#define __PISTON_H

#include <list>
#include "atomic.h"     // class Atomic

class Piston : public Atomic
{
public:
	Piston( const string &name = "Piston" );					//Default constructor

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

};	// class Piston

// ** inline ** // 
inline
string Piston::className() const
{
	return "Piston" ;
}

#endif   //__PISTON_H
