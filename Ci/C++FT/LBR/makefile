way = g++
name = lbr
head = xinxi.h zhanghao.h date.h
cpp = main.cpp
icono = 
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -fexec-charset=GBK -finput-charset=GBK -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	del /s *.o *.exe