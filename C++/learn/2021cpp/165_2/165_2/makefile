way = g++
name = timeoff
head = timeoff.h numday.h
cpp = main.cpp timeoff.cpp numday.cpp 
icon = 
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icon)
$(icon): $(icon).rc
	windres -i $(icon).rc -o $(icon).o
rm:
	del /s *.o *.exe