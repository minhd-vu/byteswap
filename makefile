all: server client

server: server.cpp header.hpp
	g++ -g -o server server.cpp

client: client.cpp header.hpp
	g++ -g -o client client.cpp

clean:
	rm client server