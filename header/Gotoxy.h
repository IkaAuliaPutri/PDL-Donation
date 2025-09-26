#define Nmaks 100

void gotoxy(int x, int y);
void FullScreen();
void PrintFile (char file [], int x, int y);
void KotakLogin();
void SetColor(unsigned short color);
void Tanggal ();
void Waktu ();
void OutterBorder();
void Createdby();


void gotoxy(int x, int y)//Fungsi untuk tata letak program, seperti titik koordinat
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void FullScreen()//Fungsi untuk layar penuh
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}


void PrintFile (char file [], int x, int y)	//Fungsi untuk mencetak File TXT, atau notepad
{
	//DECLARATION
	FILE *TXTFile;
	char Data[Nmaks];

	//ALGORITM
	if ((TXTFile = fopen (file , "r")) == NULL )
	{
		puts ("Tidak bisa membuka file ");
	}
	while (fgets (Data, Nmaks, TXTFile ))
	{
		gotoxy(x,y);
		printf("%s", Data);
		y++;
	}
	fclose (TXTFile);
}

void KotakLogin()
{
    int i;
	for(i=26;i<=36;i++) //i untuk mengatur titik mau ke atas atau ke bawah
	{
		gotoxy(59,i),	printf("%c%c",178,178);//garis kotak luar pinggir  sebelah kiri menu login
		gotoxy(107,i),	printf("%c%c",178,178);// garis kotak luar pinggir sebelah kiri
	}
	for(i=60;i<=107;i++)
	{
		gotoxy(i,26), printf("%c%c",178,178); //garis pinggir luar yang atas menu login // gotoxy nya buat garis yang paling atas di luar
		gotoxy(i,36), printf("%c%c",178,178);                                         // gotoxy nya buat garis yang paling bawah di luar
	}
	for(i=65;i<101;i++)
	{
		gotoxy(i,29), 	printf("%c",205);//garis di dalem yang paling atas
		gotoxy(i,31), 	printf("%c",205);// garis di dalem yang di tengah
		gotoxy(i,33),	printf("%c",205);// garis di dalem yang di bawah
	}
	//pinggir atas baris ke-1
	gotoxy(64,29), 	printf("%c", 167); //gambar yang bulat di pinggir
	gotoxy(101,29),	printf("%c", 167);

	//pinggir bawah baris ke-2
	gotoxy(64,30), 	printf("%c", 167);//gambar yang bulat di pinggir
	gotoxy(101,30), printf("%c", 167);

	//pinggir tengah baris ke-3
	gotoxy(64,31), 	printf("%c", 167); //garis yang bulat di pinggir
	gotoxy(101,31), printf("%c", 167);

	//pinggir tengah baris ke -4
	gotoxy(64,32), 	printf("%c", 167);
	gotoxy(101,32), printf("%c", 167);
	gotoxy(64,33), 	printf("%c", 167);
	gotoxy(101,33), printf("%c", 167);


}

void SetColor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void Tanggal ()
{
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("%02d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}
void Waktu ()
{
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
	printf("%02d:%02d", tm.tm_hour, tm.tm_min);
}

int delay(int i)
{
     int j=0;
     while (j<i)
     {
           j++;
     }
     return(i);
}
void loading()
{
     int i;
     gotoxy(72,47),printf("Klik ENTER untuk Masuk...");
     gotoxy(79,31);printf("Loading...");
     gotoxy(66,32);printf("%c",218); // garis siku" di sebelah kiri yang atas
     for(i=67;i<103;i++) // garis sebelah siku" yang di di atas yang panjang tempatnya di tengah di apit siku" 2 di atas
     {
           gotoxy(i,32); printf("%c",196);
     }
     gotoxy(103,32);printf("%c",191); // garis siku" di sebelah kanan yang di atas
     gotoxy(66,33);printf("%c",179); // gasis di bawah siku" di sebelah kiri yaang di atas pas banget di bawahnya
     gotoxy(103,33);printf("%c",179); // garis dibawah siku" di sebelah kanan yang di atas pas banget di bawahnya
     gotoxy(66,34);printf("%c",192); // garis siku" di sebelah kiri yang di bawah
     for(i=67;i<103;i++) // garis sebelah siku" yang di bawah yang panjang tempatnya di tengah di apit 2 siku" di bawah
     {
           gotoxy(i,34); printf("%c",196);
     }
     gotoxy(103,34);printf("%c",217); // garis siku" di sebelah kanan yang di bawah
    for(i=67;i<103;i++) // garis yang di tengah yang buat loading
     {
           gotoxy(i,33); printf("%c ",219); delay(50000000);
     }

}



void OutterBorder()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(10,5); Tanggal ();
    gotoxy(12,7); Waktu ();
    PrintFile("txt/PDLDONATION.txt", 64, 4);

	int i, lebar=167, tinggi=11;
	system("color 8E");//----------------------------- warna utama

	for (i=1;i<=29;i++) // buat nama di atas
	{
		gotoxy(i,11);
		printf("=",186);
	}
	for (i=1;i<=29;i++) // buat nama di bawah
    {
		gotoxy(i,9);
		printf("=",186);
	}


	//----------------------------------------------- pojok kiri di atas cuman setitik doang di pojok
	gotoxy(0,0);printf("%c",219);
	//----------------------------------------------- garis atas horizon yang kuning di atas tebel paling pertama
	for(i=0;i<=lebar;i++)
	{
		gotoxy(i,0);printf("%c",219);
	}
	//----------------------------------------------- garis ketiga dari atas penutup nama pdl
	for(i=0;i<=lebar;i++)
	{
		gotoxy(i,12);
		printf("%c",219);
	}

	//----------------------------------------------- garis kiri vertikal di sebelah kiri sampe bawah //
	for(i=1;i<=48;i++)
	{
		gotoxy(0,i);
		printf("%c",219);
	}
	//kotak dalam menu//
	gotoxy(1,13);printf("%c",201); // yang di sebelah kiri  pojok di atas bentuknya siku"
	gotoxy(1,26);printf("%c",200);// yang di sebelah kiri pojok di bawah bentuknya siku"

	for (i=14;i<=25;i++) // garis buat menu yang sebelah kiri di tengah" gari siku"
	{
		gotoxy(1,i);
		printf("%c",186);
	}
	gotoxy(29,13);printf("%c",187); //yang di sebelah kanan pojok di atas bentuknya siku"
	gotoxy(29,26);printf("%c",188);// yang di sebelah kanan pojok di bawah bentuknya siku"

	for (i=14;i<=25;i++) // yang buat menu yang di sebelah kanan di tengah" garis siku"
	{
		gotoxy(29,i);
		printf("%c",186);
	}

	for (i=1;i<=29;i++) // garis pager di bagian menu yang atas
	{
		gotoxy(i,13);
		printf("%c",186);
	}
	for (i=1;i<=29;i++) // garis pager di bagian menu yang di bawah
	{
		gotoxy(i,26);
		printf("%c",186);
	}
	for(i=26;i<=45;i++) // garis di bagian created by sebelah kiri garis lurus
	{
		gotoxy(0,i);
		printf("%c",219);
	}
	for(i=1;i<=48;i++) // garis lurus ke bawah sebelah kiri
	{
		gotoxy(lebar,i);
		printf("%c",219);
	}


	//--------------------------------------------buat garis bawah yang menu yang deket created by
	for(i=1;i<=30;i++)
	{
		gotoxy(i,27);
		printf("%c",219);
	}

	gotoxy (2,30);printf("===========================");
	gotoxy (10,31);printf ("DIBUAT OLEH");
	gotoxy (2,32);printf("===========================");

	gotoxy (6,35);printf ("IKA AULIA PUTRI");
	gotoxy (8,36);printf ("0320220090");
	gotoxy (6,38);printf ("QONITAH FAIRUZ");
	gotoxy (8,39);printf ("0320220098");
	gotoxy (6,41);printf ("PURNAMA SITI SYAMSIA");
	gotoxy (8,42);printf ("0320220117");
	gotoxy (6,44);printf ("SEKAR AYU RAMADANI");
	gotoxy (8,45);printf ("0320220104");

	for(i=1;i<=167;i++)//garis bawah di deket menunya yang tebel sebelom garis yang tipis di bawah//
	{
		gotoxy(i,48);
		printf("%c",219);
	}

	/*LOGO */

	for (i=1;i<=48;i++) //garis kebawah deket created by sebelah kanan//
	{

		gotoxy (30,i);
		printf("%c",219);

	}for (i=26;i<=48;i++) //garis atas deket menunya yang kotak sebelah kanan
		gotoxy (30,i);
		printf("%c",219);
}

void Createdby()
{
	//DECLARATION
	int a,b,i,j;

	//ALGORITM
    for(i=0;i<=48;i++)
    {
        gotoxy(1,i),printf("%c%c",219,219);//kiri
        gotoxy(165,i),printf("%c%c",219,219);//kanan
    }
    for(i=1;i<=165;i++)
	{
    gotoxy(i,0),	printf("%c%c",219,219); //atas
    gotoxy (i,48), printf("%c",219); //bawah
	}


	PrintFile ("txt/Selamatdatang.txt", 40,6);
	gotoxy(78,40);	printf("Dibuat Oleh : ");
	gotoxy(77,41);	printf("QONITAH FAIRUZ");
	gotoxy(77,42);	printf("IKA AULIA PUTRI");
	gotoxy(75,43);	printf("SEKAR AYU RAMADANI");
	gotoxy(74,44);	printf("PURNAMA SITI SYAMSIA");
}
void kotakCRUDTransaksi()
{
    int i;
    for( i=46;i<=93;i++)
	{
		gotoxy(i,45);
		printf("_",219);
	}

    for( i=16;i<=45;i++)
	{
		gotoxy(45,i);
		printf("|",219);
	}
	 for (i=16;i<=45;i++){
		gotoxy (94,i);
		printf("|",219);
	 }
    gotoxy(46,15); printf("================================================");
    gotoxy(46,17); printf("================================================");
}

