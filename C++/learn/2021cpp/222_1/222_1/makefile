way = g++
name = 222
head = 
cpp = main.cpp
icono = 
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	rm *.o $(name)