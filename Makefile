all:
	gcc -o helloworld helloworld.c

helloworld:
	gcc -o helloworld helloworld.c

clean:
	rm -f helloworld
