CC=g++
CFLAGS = -std=c++11 -I.
DEPS = rover.h queue.h stack.h
QOBJ = queue.o
SOBJ = stack.o
OBJ = rover.o rovercontrol.o scandata.o $(QOBJ) $(SOBJ)
ARGS = commands.txt

%.o: %c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ 

rovercontrol: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	clear
	clear
	./$@ $(ARGS)

testrover: rovercontrol
	./rovercontrol commands.txt > tmp.txt
	diff tmp.txt expected.txt > diffout.txt

testqueue: $(QOBJ) testqueue.cpp
	$(CC) $(CFLAGS) -g -o $@ $^
	./testqueue

teststack: $(SOBJ) teststack.cpp
	$(CC) $(CFLAGS) -g -o $@ $^
	./teststack
    
clean:
	$(info ---Whoosh!---)
	rm -f *.o
