all: programa

programa: pastas arquivos.o movendo
	@gcc obj/*.o -o bin/loteria
	./bin/loteria

movendo:
	@mv *.o obj

arquivos.o: 	
	@gcc -c src/*.c -I inc/ 

pastas: 
	@mkdir -p obj bin	

clean:
	@rm -rf obj/ bin/	