way = g++
name = frdtest
head = frd.h
cpp = main.cpp frd.cpp
icon = 
$(name): $(cpp) $(head) $(icon)
	$(way) -o $(name) $(cpp) $(head) $(icon)
$(icon): $(icon)
	windres -i $(icon) -o $(icon)
rm:
	del /s *.o *.exe