test: main.o list.o dlist.o rlist.o
	gcc -o $@ $^
*.o:*.c
	gcc -c $<

clean:
	rm -rf *.o test
