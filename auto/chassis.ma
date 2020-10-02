[top]
components : chassis@Chassis 
out : out
in : in done 
%in : stop
Link : in in@chassis
Link : out@chassis out
Link : out@chassis done@chassis 
%Link : done done@chassis
%Link : stop stop@chassis

[chassis]
manufacturing : 00:00:05:000 
