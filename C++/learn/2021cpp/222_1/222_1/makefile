way = g++
name = 222
head = 
cpp = main.cpp
icono = 
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	rm /s *.o $(name)