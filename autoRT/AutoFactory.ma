[top]
components : chassis@Chassis body@Body trans@Trans finalAss@FinalAss engineSubFact
out : out dummyoutput
in : in
Link : in in@chassis
Link : in in@body
Link : in in@trans
Link : in in@engineSubFact
Link : out@finalAss out
Link : out@finalAss done@finalAss

Link : out@chassis in_chassis@finalAss
Link : out@chassis done@chassis
Link : out@body in_body@finalAss
Link : out@body done@body
Link : out@trans in_trans@finalAss
Link : out@trans done@trans
Link : out@engineSubFact in_engine@finalAss

[chassis]
manufacturing : 00:00:02:000  

[body]
manufacturing : 00:00:02:000  

[trans]
manufacturing : 00:00:02:000  

[finalAss]
manufacturing : 00:00:02:000  

[engineSubFact]
components : piston@Piston engineBody@EngineBody engineAss@EngineAss
out : out
in : in
Link : in in@piston
Link : in in@engineBody
Link : out@piston in_piston@engineAss
Link : out@piston done@piston
Link : out@engineBody in_engineBody@engineAss
Link : out@engineBody done@engineBody
Link : out@engineAss out
Link : out@engineAss done@engineAss

[piston]
manufacturing : 00:00:02:000  

[engineBody]
manufacturing : 00:00:02:000  

[engineAss]
manufacturing : 00:00:02:000  
