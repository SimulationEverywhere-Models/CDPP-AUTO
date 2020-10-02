/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"

#include "chassis.h"      // class Chassis
#include "body.h"      // class Body
#include "trans.h"      // class Trans
#include "piston.h"      // class Piston
#include "engineBody.h"      // class EngineBody
#include "engineAss.h"      // class EngineAss
#include "finalAss.h"      // class FinalAss

#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Chassis>() , "Chassis" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Body>() , "Body" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trans>() , "Trans" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Piston>() , "Piston" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<EngineBody>() , "EngineBody" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<EngineAss>() , "EngineAss" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<FinalAss>() , "FinalAss" ) ;

	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
}
