[top]
components : piston@Piston 
out : out
in : in done 
%in : stop
Link : in in@piston
Link : out@piston out
Link : out@piston done@piston 
%Link : done done@piston
%Link : stop stop@piston

[piston]
manufacturing : 00:00:05:000 
