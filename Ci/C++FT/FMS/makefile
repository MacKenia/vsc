way = g++
name = main
head = sc.h
cpp = main.cpp sc.cpp
icon = 
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icon)
$(icon): $(icon)
	windres -i $(icon) -o $(icon)
rm:
	del /s *.o *.exe