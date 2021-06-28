way = g++
name = rmexe
head = 
cpp = rm_exe.cpp
icon = wfl
$(name): $(cpp) $(head) $(icon).o 
	$(way) -fexec-charset=GBK -static -o $(name) $(cpp) $(head) $(icon).o
$(icon): $(icon).rc
	windres -i $(icon).rc -o $(icon).o
rm:
	del /s *.o

# rm: rm_exe.cpp ico.o
# 	g++ -fexec-charset=GBK -o rm rm_exe.cpp ico.o

# ico.o: ico.rc
# 	windres -i ico.rc -o ico.o

# del: 
# 	del /s *.o