// MENU UTAMA //

void MenuManager()
{
	// DECLARATION
	int PilMenu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    PrintFile("txt/SelamatDatangManager.txt", 62, 18);
	gotoxy(9,16);	printf("MENU MANAGER");
	gotoxy(2,18);	printf("[1] Laporan Transaksi ");
	gotoxy(2,19);	printf("[2] Data Pengajuan Kegiatan");
	gotoxy(2,20);	printf("[3] Kembali");
	gotoxy(2,21);	printf("[4] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&PilMenu,1);
	switch (PilMenu)
	{
		case 1 : system("cls");
                 MenuLaporan();
				 break;

		case 2 : system("cls");
                 gotoxy(5,10);printf("%s",login.fullname);
                 LaporanTransaksiPengajuanKegiatan();
                  gotoxy(127,46);printf("Klik 'Enter' Untuk Kembali !");
                 getch();
                 system("cls");
                 MenuManager();
				 break;

		case 3 : system("cls");
                 Masuklogin();
                 break;

		case 4 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);

		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				  MenuManager();
				  break;
	}
}


void MenuAdmin ()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

	//ALGORITM
	gotoxy(12,10);	printf("%s",login.fullname);
    PrintFile("txt/SelamatDatangAdmin.txt", 62, 18);
	gotoxy(8,15);	printf ("MENU ADMIN");
	gotoxy(4,17);	printf ("[1] Data User");
	gotoxy(4,18);	printf ("[2] Data Donatur");
	gotoxy(4,19);	printf ("[3] Data Inisiator");
	gotoxy(4,20);	printf ("[4] Data Yayasan");
	gotoxy(4,21);	printf ("[5] Kembali");
	gotoxy(4,22);	printf ("[6] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&Menu,1);
	switch (Menu)
	{
	    case 1 : system("cls");
                 MenuCRUDUser();
				 break;
		case 2 : system("cls");
                 MenuCRUDDonatur();
				 break;
		case 3 : system("cls");
                 MenuCRUDInisiator();
			     break;
        case 4 : system("cls");
                 MenuCRUDYayasan();
                 break;
		case 5 : system("cls");
                 Masuklogin();
                 break;
        case 6 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);
				 break;
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				 getch();
		         MenuAdmin();
				 break;
	}
}


void MenuKasir()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

	//ALGORITM
	gotoxy(12,10);	printf("%s",login.fullname);
    PrintFile("txt/SelamatDatangKasir.txt", 62, 18);
	gotoxy(9,15);	printf ("MENU KASIR");
	gotoxy(4,17);	printf ("[1] Transaksi");
	gotoxy(4,18);	printf ("[2] Data Pengajuan ");
	gotoxy(8,19);	printf ("Kegiatan");
	gotoxy(4,20);	printf ("[3] Kembali");
	gotoxy(4,21);	printf ("[4] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&Menu,1);
	switch (Menu)
	{
		case 1 : system("cls");
                 MenuTransaksi();
				 break;
        case 2 : system("cls");
                 MenuCRUDPengajuankegiatan();
                 break;
        case 3 : system("cls");
                 Masuklogin();
                 break;
        case 4 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				 getch();
		         MenuKasir();
				 break;
	}
}


void MenuTransaksi()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

	//ALGORITM
	gotoxy(12,10);	printf("%s",login.fullname);
    PrintFile("txt/SelamatDatangKasir.txt", 62, 18);
	gotoxy(9,15);	printf ("MENU TRANSAKSI");
	gotoxy(4,17);	printf ("[1] Transaksi Donatur");
	gotoxy(4,18);	printf ("[2] Transaksi Distribusi ");
	gotoxy(8,19);	printf ("Yayasan");
	gotoxy(4,20);	printf ("[3] Transaksi Distribusi ");
	gotoxy(8,21);	printf ("Kegiatan");
	gotoxy(4,22);	printf ("[4] Kembali");
	gotoxy(4,23);	printf ("[5] Keluar Program");
	gotoxy(12,25);	printf("["); gotoxy(16,25);	printf("]");
	gotoxy(14,25); getnum(&Menu,1);
	switch (Menu)
	{
		case 1 : system("cls");
                 TransaksiDoanatur();
				 break;
		case 2 : system("cls");
                 TransDistribusiYayasan();
			     break;
		case 3 : system("cls");
                 TransDistribusiKegiatan();
				 break;
        case 4 : system("cls");
                 MenuKasir();
				 break;
        case 5 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				 getch();
		         MenuTransaksi();
				 break;
	}
}

void MenuLaporan()
{
	// DECLARATION
	int PilMenu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    PrintFile("txt/SelamatDatangManager.txt", 62, 18);
	gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(9,14);	printf("MENU LAPORAN");
	gotoxy(5,16);	printf("[1] Laporan Transaksi ");
	gotoxy(9,17);	printf("Donatur");
	gotoxy(5,18);	printf("[2] Laporan Transaksi");
	gotoxy(9,19);	printf("Yayasan");
	gotoxy(5,20);	printf("[3] Laporan Transaksi");
	gotoxy(9,21);	printf("Kegiatan");
	gotoxy(5,22);	printf("[4] Kembali");
	gotoxy(5,23);	printf("[5] Keluar Program");
	gotoxy(12,25);	printf("["); gotoxy(16,25);	printf("]");
	gotoxy(14,25); getnum(&PilMenu,1);
	switch (PilMenu)
	{
		case 1 : system("cls");
                 MenuLaporanTransaksiDonatur();
				 break;
		case 2 : system("cls");
                 MenuLaporanTransaksiDistribusiYayasan();
				 break;

		case 3 : system("cls");
                 MenuLaporanTransaksiDistribusiKegiatan();
                 break;

		case 4 : system("cls");
                 MenuManager();
                 break;

		case 5 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);

		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				  MenuLaporan();
				  break;
	}
}

