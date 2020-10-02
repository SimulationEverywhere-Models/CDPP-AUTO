/*******************************************************************
*
*  DESCRIPTION: Atomic Model EngineAss
*
*******************************************************************/

#ifndef __ENGINEASS_H
#define __ENGINEASS_H

#include <list>
#include "atomic.h"     // class Atomic

class EngineAss : public Atomic
{
public:
	EngineAss( const string &name = "EngineAss" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
//	Model &outputFunction( const InternalMessage & );
	Model &outputFunction( const CollectMessage & );
	
private:
	const Port &in_piston, &in_engineBody ;
//	const Port &stop;
	const Port &done;
	Port &out;
	VTime manufacturingTime;
	typedef list<Value> ElementList ;
	ElementList elements_piston, elements_engineBody ;

	VTime timeLeft;

};	// class EngineAss

// ** inline ** // 
inline
string EngineAss::className() const
{
	return "EngineAss" ;
}

#endif   //__ENGINEASS_H
