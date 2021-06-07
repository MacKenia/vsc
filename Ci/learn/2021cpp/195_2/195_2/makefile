way = g++
name = employee
head = employee.h
cpp = main.cpp employee.cpp
icon = 
rc = 
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icon)
$(icon): $(rc)
	windres -i $(rc) -o $(icon)
rm:
	del /s *.o *.exe