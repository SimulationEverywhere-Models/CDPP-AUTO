[top]
components : trans@Trans 
out : out
in : in done 
%in : stop
Link : in in@trans
Link : out@trans out
Link : out@trans done@trans 
%Link : done done@trans
%Link : stop stop@trans

[trans]
manufacturing : 00:00:05:000 
