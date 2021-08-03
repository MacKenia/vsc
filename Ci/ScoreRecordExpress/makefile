way = g++
name = ScoreRcordExpress
head = sc.h
cpp = sc.cpp ScoreRcord.cpp
icono = 
iconr = 
$(name): $(cpp) $(head) $(icono)
	$(way) -fexec-charset=GBK -o $(name) $(cpp) $(head) $(icono)
$(icono): $(iconr)
	windres -i $(iconr) -o $(icono)
rm:
	del /s *.o *.exe