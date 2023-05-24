const char* message;	

main
{	
	mov [500], 'A';
	mov si, [500];
	mov al , [si];
	mov ah , 0x0e;
	int 0x10;
	
	ret;
}

print_string
{
	mov [500], 'A';
	mov si, [500];
	mov al , [si];
	mov ah , 0x0e;
	int 0x10;
	
	ret;
}
	
