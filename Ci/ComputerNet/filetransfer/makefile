ts = filetransfer.h filetransfer.cpp

all: transfer
	cp transfer ../
transfer: send.cpp $(ts)
	g++ -lncursesw -lpthread -o transfer $(ts) send.cpp 
recv: recv.cpp $(ts)
	g++ -lncursesw -lpthread -o recv $(ts) recv.cpp 
