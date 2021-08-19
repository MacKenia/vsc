way = g++
name = check
head = 
cpp = birth.cpp
icono = sxc.o
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -fexec-charset=GBK -static -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	del /s *.o *.exe