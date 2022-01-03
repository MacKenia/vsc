ts = filetransfer.h filetransfer.cpp

all: send recv

send: send.cpp $(ts)
	g++ -lncursesw -lpthread -o send $(ts) send.cpp 
recv: recv.cpp $(ts)
	g++ -lncursesw -lpthread -o recv $(ts) recv.cpp 

main: 