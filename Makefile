output: post.o network.o user.o social_network.o
	g++ -std=c++11 post.o network.o user.o social_network.o -o output

network.o: network.cpp
	g++ -c -std=c++11 network.cpp -o network.o

user.o: user.cpp
	g++ -c -std=c++11 user.cpp -o user.o

social_network.o: social_network.cpp
	g++ -c -std=c++11 social_network.cpp -o social_network.o

post.o: post.cpp
	g++ -c -std=c++11 post.cpp -o post.o

clean:
	rm -f network.o user.o social_network.o post.o output
	