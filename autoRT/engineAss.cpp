/*******************************************************************
*
*  DESCRIPTION: Atomic Model EngineAss
*
*******************************************************************/

/** include files **/
#include "engineAss.h"      // class EngineAss
#include "message.h"    // class ExternalMessage, InternalMessage
#include "parsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: EngineAss
* Description: 
********************************************************************/
EngineAss::EngineAss( const string &name )
: Atomic( name )
, in_piston( addInputPort( "in_piston" ) )
, in_engineBody( addInputPort( "in_engineBody" ) )
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
Model &EngineAss::initFunction()
{
	elements_piston.erase( elements_piston.begin(), elements_piston.end() ) ;
	elements_engineBody.erase( elements_engineBody.begin(), elements_engineBody.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &EngineAss::externalFunction( const ExternalMessage &msg )
{
	int n=(int) msg.value();

	if( msg.port() == in_piston ) // parts received one by one
	{	
		elements_piston.push_back( 1 ) ;
		if( elements_piston.size() == 1 && elements_engineBody.size()>=1)
			holdIn( AtomicState::active, manufacturingTime );
		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements_piston.push_back( 1 ) ;
	}




	if( msg.port() == in_engineBody )
	{	
		elements_engineBody.push_back( 1 ) ;
		if( elements_engineBody.size() == 1 && elements_piston.size()>=1)
			holdIn( AtomicState::active, manufacturingTime );
		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements_engineBody.push_back( 1 ) ;
	}

	if( msg.port() == done )
	{
		elements_piston.pop_front() ;		
		elements_engineBody.pop_front() ;
		if( !elements_piston.empty() &&  !elements_engineBody.empty())
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
Model &EngineAss::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
//Model &EngineAss::outputFunction( const InternalMessage &msg )
Model &EngineAss::outputFunction( const CollectMessage &msg )
{
//	sendOutput( msg.time(), out, elements.front() ) ;////////////++++++++++++++++++++++++++++++++
	sendOutput( msg.time(), out, 1 ) ;
	return *this ;
}
