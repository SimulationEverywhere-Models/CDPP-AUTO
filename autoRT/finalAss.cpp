/*******************************************************************
*
*  DESCRIPTION: Atomic Model FinalAss
*
*******************************************************************/

/** include files **/
#include "finalAss.h"      // class FinalAss
#include "message.h"    // class ExternalMessage, InternalMessage
#include "parsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: FinalAss
* Description: 
********************************************************************/
FinalAss::FinalAss( const string &name )
: Atomic( name )
, in_chassis( addInputPort( "in_chassis" ) )
, in_body( addInputPort( "in_body" ) )
, in_trans( addInputPort( "in_trans" ) )
, in_engine( addInputPort( "in_engine" ) )
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
Model &FinalAss::initFunction()
{
	elements_chassis.erase( elements_chassis.begin(), elements_chassis.end() ) ;
	elements_body.erase( elements_body.begin(), elements_body.end() ) ;
	elements_trans.erase( elements_trans.begin(), elements_trans.end() ) ;
	elements_engine.erase( elements_engine.begin(), elements_engine.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &FinalAss::externalFunction( const ExternalMessage &msg )
{
	int n=(int) msg.value();

	if( msg.port() == in_chassis ) // parts received one by one
	{	
		elements_chassis.push_back( 1 ) ;
		if( elements_chassis.size() == 1  && elements_body.size()>=1 
		 && elements_trans.size()>=1      && elements_engine.size()>=1)
			holdIn( AtomicState::active, manufacturingTime );
		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements_chassis.push_back( 1 ) ;
	}

	if( msg.port() == in_body ) // parts received one by one
	{	
		elements_body.push_back( 1 ) ;
		if( elements_body.size() == 1  && elements_chassis.size()>=1 
		 && elements_trans.size()>=1   && elements_engine.size()>=1)
			holdIn( AtomicState::active, manufacturingTime );
		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements_body.push_back( 1 ) ;
	}

	if( msg.port() == in_trans ) // parts received one by one
	{	
		elements_trans.push_back( 1 ) ;
		if( elements_trans.size() == 1  && elements_body.size()>=1 
		 && elements_chassis.size()>=1  && elements_engine.size()>=1)
			holdIn( AtomicState::active, manufacturingTime );
		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements_trans.push_back( 1 ) ;
	}

	if( msg.port() == in_engine ) // parts received one by one
	{	
		elements_engine.push_back( 1 ) ;
		if( elements_engine.size() == 1  && elements_body.size()>=1 
		 && elements_trans.size()>=1     && elements_chassis.size()>=1)
			holdIn( AtomicState::active, manufacturingTime );
		//push the left ones into queue if more than 1 received
		for(int i=2;i<=n;i++) elements_engine.push_back( 1 ) ;
	}


	if( msg.port() == done )
	{
		elements_chassis.pop_front() ;		
		elements_body.pop_front() ;		
		elements_trans.pop_front() ;		
		elements_engine.pop_front() ;
		if( !elements_chassis.empty() &&  !elements_body.empty() 
		 && !elements_trans.empty()   &&  !elements_engine.empty())
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
Model &FinalAss::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
//Model &FinalAss::outputFunction( const InternalMessage &msg )
Model &FinalAss::outputFunction( const CollectMessage &msg )
{
//	sendOutput( msg.time(), out, elements.front() ) ;////////////++++++++++++++++++++++
	sendOutput( msg.time(), out, 1 ) ;
	return *this ;
}
