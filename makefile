all: server client

server: server.cpp header.hpp
	g++ -g -o server server.cpp header.hpp

client: client.cpp header.hpp
	g++ -g -o client client.cpp header.hpp

clean:
	rm client server