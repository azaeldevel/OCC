
char actual 'A';
char actual2 ;
unsigned char actual3 122;
signed char actual4 -126;
short counter 1309;
short flag2 -21598;

int main()
{
	mov ax,1;
	mov bx,2;
	mov cx,3;
	mov dx,4;
	
	mov al , 'B';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'o';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'o';
	mov ah , 0x0e;
	int 0x10;
	mov al , 't';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'i';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'n';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'g';
	mov ah , 0x0e;
	int 0x10;
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'b';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'y';
	mov ah , 0x0e;
	int 0x10;
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'A';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'z';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'a';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'e';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'l';
	mov ah , 0x0e;
	int 0x10;
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'R';
	mov ah , 0x0e;
	int 0x10;
	mov al , '.';
	mov ah , 0x0e;
	int 0x10;
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'M';
	mov ah , 0x0e;
	int 0x10;
	mov al , '.';
	mov ah , 0x0e;
	int 0x10;
	
	mov ax, 0x0e21;
	int 0x10;
	
	mov ax, 0x0e21;
	mov ds, ax;
	
	mov ax, 0x0000;
	mov ax, ds;
	int 0x10;
	
	mov bx, ax;
	mov cx, ax;
	mov dh, al;
	mov dl, ah;
	
	mov ax,12345;
	mov bx,0;
	mov cx,0;
	mov dx,0;
	
	//mov dx, [ bx + si ];	
	//mov dx, [ bp + si ];	
	mov [ 0x2369 ], ax;
	mov cx, [ 0x2369 ];
	
	mov [ 0x2380 ], 0x1234;
	mov dx, [ 0x2380 ];
	mov [ 0x2390 ], 'A';
	mov [ 0x2391 ], 'a';
	
	mov bx, [ 0x2390 ];
	mov ss, [ 0x2390 ];
	mov [ 0x2395 ], ss;
	mov al, [si];
	mov al, [bx + si + 125];
	
	//return 0;
}

int flag3 1598;

