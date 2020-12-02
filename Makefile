all:
	@echo "**'#make' here is a '#make helloworld' by defalult to build helloworld.c"
	@echo "**'#make program' to build for a particular program.c\n"
	gcc -o helloworld helloworld.c
	@echo "" # to print one new line after compilation

helloworld:
	gcc -o helloworld helloworld.c

options: options.c
	gcc -o options options.c

thread: thread.c
	gcc -o thread thread.c -lpthread

mutex: mutex.c
	gcc -o mutex mutex.c -lpthread

cond: cond_wait_signal.c
	gcc -o cond cond_wait_signal.c -lpthread

fork: fork.c
	gcc -o fork fork.c

shm: shmrd.c shmwr.c
	gcc -o shmrd shmrd.c
	gcc -o shmwr shmwr.c

bst: bst.c
	gcc -o bst bst.c

quick: quick_sort.c
	gcc -o quick quick_sort.c

merge: merge_sort.c
	gcc -o merge quick_sort.c

clean:
	rm -f a.out helloworld options thread mutex cond fork shmrd shmwr bst quick merge
