/*******************************************************************
*
*  DESCRIPTION: Atomic Model Chassis
*
*******************************************************************/

#ifndef __CHASSIS_H
#define __CHASSIS_H

#include <list>
#include "atomic.h"     // class Atomic

class Chassis : public Atomic
{
public:
	Chassis( const string &name = "Chassis" );					//Default constructor

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

};	// class Chassis

// ** inline ** // 
inline
string Chassis::className() const
{
	return "Chassis" ;
}

#endif   //__CHASSIS_H
