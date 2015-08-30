all: file_write file_read

clean: 
	rm file_write file_read

file_write: fileIO_write.c
	@echo 生成用于写入文件的可执行程序
	gcc fileIO_write.c -o file_write

file_read: fileIO_read.c
	@echo 生成用于读取文件的可执行程序
	gcc fileIO_read.c -o file_read

