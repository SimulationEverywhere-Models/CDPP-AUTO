/*******************************************************************
*
*  DESCRIPTION: Atomic Model Trans
*
*******************************************************************/

#ifndef __TRANS_H
#define __TRANS_H

#include <list>
#include "atomic.h"     // class Atomic

class Trans : public Atomic
{
public:
	Trans( const string &name = "Trans" );					//Default constructor

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

};	// class Trans

// ** inline ** // 
inline
string Trans::className() const
{
	return "Trans" ;
}

#endif   //__TRANS_H
