ts = filetransfer.h filetransfer.cpp

all: send recv
	mv -f recv ../recv && ./send
send: send.cpp $(ts)
	g++ -lpthread -o send $(ts) send.cpp 
recv: recv.cpp $(ts)
	g++ -lpthread -o recv $(ts) recv.cpp 