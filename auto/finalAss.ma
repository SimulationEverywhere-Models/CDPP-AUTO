[top]
components : finalAss@FinalAss 
out : out
in : in_chassis in_body in_trans in_engine done 
%in : stop
Link : in_chassis in_chassis@finalAss
Link : in_body in_body@finalAss
Link : in_trans in_trans@finalAss
Link : in_engine in_engine@finalAss
Link : out@finalAss out
Link : out@finalAss done@finalAss 
%Link : done done@finalAss
%Link : stop stop@finalAss

[finalAss]
manufacturing : 00:00:02:000 
