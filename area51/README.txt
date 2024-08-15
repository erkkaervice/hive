-c: Tells the compiler to compile the source file into an object file but not link it.
$<: Automatic variable that represents the first prerequisite. In this context, it is the .c file being compiled (e.g., src/file1.c).
-o $@: Specifies the output file. $@ is an automatic variable that represents the target file, which in this case is the .o file (e.g., obj/file1.o).


-o $(NAME) specifies the output file name for the executable.
-L$(LIBFT_DIR) adds the $(LIBFT_DIR) directory to the list of library search paths.
-lft links against the libft library found in the specified directories.