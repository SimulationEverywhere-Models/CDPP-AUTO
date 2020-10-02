/*******************************************************************
*
*  DESCRIPTION: Atomic Model FinalAss
*
*******************************************************************/

#ifndef __FINALASS_H
#define __FINALASS_H

#include <list>
#include "atomic.h"     // class Atomic

class FinalAss : public Atomic
{
public:
	FinalAss( const string &name = "FinalAss" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
//	Model &outputFunction( const InternalMessage & );
	Model &outputFunction( const CollectMessage & );

private:
	const Port &in_chassis, &in_body, &in_trans, &in_engine ;
//	const Port &stop;
	const Port &done;
	Port &out;
	VTime manufacturingTime;
	typedef list<Value> ElementList ;
	ElementList elements_chassis, elements_body, elements_trans, elements_engine;

	VTime timeLeft;

};	// class FinalAss

// ** inline ** // 
inline
string FinalAss::className() const
{
	return "FinalAss" ;
}

#endif   //__FINALASS_H
