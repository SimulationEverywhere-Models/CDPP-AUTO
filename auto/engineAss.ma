[top]
components : engineAss@EngineAss 
out : out
in : in_piston in_engineBody done 
%in : stop
Link : in_piston in_piston@engineAss
Link : in_engineBody in_engineBody@engineAss
Link : out@engineAss out
Link : out@engineAss done@engineAss 
%Link : done done@engineAss
%Link : stop stop@engineAss

[engineAss]
manufacturing : 00:00:02:000 
