way = g++
name = frdtest
head = sc.h pos.h frd.h
cpp = main.cpp sc.cpp pos.cpp frd.cpp
icon = 
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icon)
$(icon): $(icon)
	windres -i $(icon) -o $(icon)
rm:
	del /s *.o *.exe