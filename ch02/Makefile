test:main.o List.o
	gcc -o $@ $^
*.o:*.c
	gcc -c $<
	
clean:
	rm *.o test
