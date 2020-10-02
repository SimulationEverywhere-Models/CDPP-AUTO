[top]
components : engineBody@EngineBody 
out : out
in : in done 
%in : stop
Link : in in@engineBody
Link : out@engineBody out
Link : out@engineBody done@engineBody 
%Link : done done@engineBody
%Link : stop stop@engineBody

[engineBody]
manufacturing : 00:00:05:000 
