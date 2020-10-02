/*******************************************************************
*
*  DESCRIPTION: Atomic Model EngineBody
*
*******************************************************************/

#ifndef __ENGINEBODY_H
#define __ENGINEBODY_H

#include <list>
#include "atomic.h"     // class Atomic

class EngineBody : public Atomic
{
public:
	EngineBody( const string &name = "EngineBody" );					//Default constructor

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

};	// class EngineBody

// ** inline ** // 
inline
string EngineBody::className() const
{
	return "EngineBody" ;
}

#endif   //__ENGINEBODY_H
