[top]
components : body@Body 
out : out
in : in done 
%in : stop
Link : in in@body
Link : out@body out
Link : out@body done@body 
%Link : done done@body
%Link : stop stop@body

[body]
manufacturing : 00:00:05:000 
