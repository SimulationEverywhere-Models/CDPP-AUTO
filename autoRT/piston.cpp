/*******************************************************************
*
*  DESCRIPTION: Atomic Model Piston
*
*******************************************************************/

/** include files **/
#include "piston.h"      // class Piston
#include "message.h"    // class ExternalMessage, InternalMessage
#include "parsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Piston
* Description: 
********************************************************************/
Piston::Piston( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
//, stop( addInputPort( "stop" ) )
, done( addInputPort( "done" ) )
, out( addOutputPort( "out" ) )
, manufacturingTime( 0, 0, 10, 0 )
{
	string time( ParallelMainSimulator::Instance().getParameter( description(),"manufacturing" ) ) ;

	if( time != "" )
		manufacturingTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Piston::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Piston::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		int n=(int) msg.value();
		elements.push_back( 1 ) ;
		if( elements.size() == 1 )
			holdIn( AtomicState::active, manufacturingTime );

		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements.push_back( 1 ) ;
	}

	if( msg.port() == done )
	{
		elements.pop_front() ;
		if( !elements.empty() )
			holdIn( AtomicState::active, manufacturingTime );
	}
/*
	if( msg.port() == stop )
		if( state() == active && msg.value() )
		{
			timeLeft = msg.time() - lastChange();
			passivate();
		} else
			if( state() == passive && !msg.value() )
				holdIn( active, timeLeft );
*/
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Piston::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
//Model &Piston::outputFunction( const InternalMessage &msg )
Model &Piston::outputFunction( const CollectMessage &msg )
{
	sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
