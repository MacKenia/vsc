way = g++
name = time
head = time.h
cpp = time.cpp main.cpp
icono = 
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	rm -r *.o $(name)