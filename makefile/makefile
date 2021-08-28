main: add/add_int.o add/add_float.o sub/sub_int.o sub/sub_float.o main.o
	gcc -o $@ $^
add_int.o: add/add_int.c
	gcc -c $^ -o $@
add_float.o:add/add_float.c
	gcc -c $^ -o $@
sub_int.o:sub_int.c
	gcc -c $^ -o $@
sub_float.o:sub_float.c
	gcc -c $^ -o $@
main.o:main.c
	gcc -c $^ -o $@
clean:sub/sub_float.o sub/sub_int.o add/add_int.o add/add_float.o main.o
	$(RM) $^
