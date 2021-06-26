way = g++
name = frdtest
head = sc.h pos.h frd.h login.h
cpp = main.cpp sc.cpp pos.cpp frd.cpp login.cpp
icon = ico48.o
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icon)
rm:
	del /s *.o *.exe