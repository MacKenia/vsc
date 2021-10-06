way = g++
name = 2
head = List.h
cpp = 2.4.cpp
icono = 
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	del /s *.o *.exe