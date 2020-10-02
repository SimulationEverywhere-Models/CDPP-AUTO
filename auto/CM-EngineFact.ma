[top]
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
manufacturing : 00:00:03:000  

[engineAss]
manufacturing : 00:00:04:000  
