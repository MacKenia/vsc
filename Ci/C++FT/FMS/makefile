way = g++
name = friendManageSystem
head = sc.h frd.h login.h
cpp = main.cpp sc.cpp frd.cpp login.cpp
icon = ico48.o
$(name): $(cpp) $(head) $(icon)
	$(way) -fexec-charset=GBK -static -o $(name) $(cpp) $(head) $(icon)
rm:
	del /s *.o *.exe