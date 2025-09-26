void getallinput(char input[], int min, int max, int type);
void getnum(int *nilai, int max);
void getteks(char input[], int max);
void getalpha(char input[], int max);
void Vline( int min, int max, int x, int a);
void Hline( int min, int max,int y, int a);
void BoxLine(int xmin, int xmax, int ymin, int ymax, int kar);
void getRp(int *nilai, int min, int max, int x, int y);

void getinputmin(char input[], int min, int max, int type);
void getinput(char input[], int max, int type);
void getpass(char input[], int max);
void getteksnum(char input[], int max);
void getletter(char input[], int max);
void RP(int n);


void getallinput(char input[], int min, int max, int type)
{
	char inpkey;
	int i,n,x,m;
	n = 0;
	x=0;
	do
	{
		inpkey = getch(); // membaca masukan dari keyboard per-karakter //

//---- Menghapus Input ----//
//start//
		if(inpkey == '\b' && n != 0)
		{
			printf("\b \b");
			n--;
			input[n]='\0';
		}
//end//
		else if(isprint(inpkey)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else{
				if(type == 3){ //isdigit = angka doang
					if(isdigit(inpkey)) {
						printf("%c", inpkey);
						input[n]=inpkey;
						n++;
					}
					else printf("\a"); //pemberitahuan suara tidak dapat di input (allert)
				}
				else if(type == 2){ //isalpha = alpabet dan spasi co : nama
					if(isalpha(inpkey) || inpkey == ' ') {
						printf("%c", inpkey);
						input[n]=inpkey;
						n++;
					}
					else printf("\a");
				}
				else { // inpkeyword //0= bebas
					if(type == 1)
							{
								if (inpkey=='\r')
								{
									inpkey='\0';
									break;
								}
								input[n]=inpkey;
								printf("*");
								n++;
								}


					else
					{
						printf("%c", inpkey);
						input[n]=inpkey;
						n++;
					}
				}
			}
		}
		else if(inpkey == 13)
		{
			if(n < min) {
				printf("\a");
				inpkey = 0;
			}
			else input[n]='\0';
		}
		//else if(current == 27) end();
	}
	while(inpkey != 13);
}
void getnum(int *nilai, int max)
{
	char input[max];
	getinput(input, max, 3);
	*nilai = atoi(input);
}

void getteks(char input[], int max)
{
	getinput(input, max, 0);
}
void getalpha(char input[], int max)
{
	getinput(input, max, 2);
}

void Vline( int min, int max, int x, int a)
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(x,i);printf("%c",a);
	}
}
void Hline( int min, int max,int y, int a)
{
	int i;
	for(i=min;i<=max;i++)
	{
		gotoxy(i,y);printf("%c",a);
	}
}

void getRp(int *nilai, int min, int max, int x, int y)
{
	char input[255];
	char inpkey;
	int i,n,m;
	n = 0;
	do
	{
		inpkey = getch(); // membaca masukan dari keyboard per-karakter //

		if(inpkey == '\b' && n != 0) /* Hapus karakter */
		{
			n--;
			input[n]='\0';

			m = n % 3;
			if((n-m) % 3 == 0 || n == m) {
				printf("\b \b");
				printf("\b \b");
			} else {
				printf("\b \b");
			}

			gotoxy(x, y);		/* Cetak ulang sesuai format */
			for(i = 0; i < n; i++) {
				if((i+1) == m || (i+1-m) % 3 == 0) {
					printf("%c", input[i]);
					if(i != (n-1)) {
						printf(".");
					}
				} else {
					printf("%c", input[i]);
				}
			}
		} else if(isprint(inpkey)){  /* Karakter yang bisa di print */
			if(n == max) {
				continue;
			} else {
				if(isdigit(inpkey)) { /* Print angka */
					gotoxy(x, y);
					input[n]=inpkey;
					n++;
					m = n % 3;
					for(i = 0; i < n; i++) { /* Cetak ulang sesuai format */
						if((i+1) == m || (i+1-m) % 3 == 0) {
							printf("%c", input[i]);
							if(i != (n-1)) {
								printf(".");
							}
						} else {
							printf("%c", input[i]);
						}
					}

				}
				else printf("\a"); /* Pemberitahuan suara tidak dapat di input (alert) */
			}
		}
		else if(inpkey == 13)	/* Jika menekan enter sebelum mengisi karakter akan muncul suara tidak dapat diinput (alert) */
		{
			if(n < min) {
				printf("\a");
				inpkey = 0;
			}
			else input[n]='\0';
		}
	}
	while(inpkey != 13);

	*nilai = atoi(input);   /* Memasukkan nilai input (char) ke nilai (int) */
}





void getinputmin(char input[], int min, int max, int type)
{
	char current;
	int i,n;
	n = 0;
	do
	{
		current = getch();

		if(current == '\b' && n != 0) 		//backspace
		{
			printf("\b \b");
			n--;
			input[n]='\0';
		}
		//else if(current >= 32 && current <= 122){
		else if(isprint(current)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else{
				if(type == 3){ //isdigit = angka doang
					if(isdigit(current)) {
						printf("%c", current);
						input[n]=current;
						n++;
					}
					else printf("\a");
				}
				else if(type == 2){ //isalpha = alpabet dan spasi co : nama
					if(isalpha(current) || current == ' ') {
						printf("%c", current);
						input[n]=current;
						n++;
					}
					else printf("\a");
				}
				else { // password //0= bebas
					if(type == 1) printf("*");
					else printf("%c", current);
					input[n]=current;
					n++;
				}
			}
		}
		else if(current == 13)
		{
			if(n < min) {
				printf("\a");
				current = 0;
			}
			else input[n]='\0';
		}
		//else if(current == 27) end();
	}
	while(current != 13);
}

void getinput(char input[], int max, int type)
{
	getinputmin(input, 1, max, type);
}

void getpass(char input[], int max)					//teks sebagai password jadi ada bintangnya
{
	getinput(input, max, 1);
}

void getteksnum(char input[], int max)				//tidak bisa input huruf
{
	getinput(input, max, 3);
}

void getletter(char input[], int max)				//tidak bisa input angka
{
	getinput(input, max, 2);
}


void RP(int n)
{
    if (n<0)
    {
        printf("-");
        RP (-n);
        return;
    }
    if (n<1000)
    {
        printf("%d",n);
        return;
    }
    RP (n/1000);
    printf(".%03d",n%1000);
}

