way = g++
name = numday
head = numday.h
cpp = main.cpp numday.cpp
icon = 
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icon)
$(icon): $(icon).rc
	windres -i $(icon).rc -o $(icon).o
rm:
	del /s *.o *.exe