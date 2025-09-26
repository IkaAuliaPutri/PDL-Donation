void MenuLaporanTransaksiDonatur()
{
	// DECLARATION
	int PilMenu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    LaporanTransaksiDonatur();
	gotoxy(2,15);	printf(" LAPORAN TRANSAKSI DONATUR");
	gotoxy(2,18);	printf("[1] Laporan Bulanan");
	gotoxy(2,19);	printf("[2] Laporan Tahunan");
	gotoxy(2,20);	printf("[3] Laporan Terbesar");
	gotoxy(2,21);	printf("[4] Kembali");
	gotoxy(2,22);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&PilMenu,1);
	switch (PilMenu)
	{

		case 1 :system("cls");
				 LaporanBulananTransaksiDonatur();
				 break;
		case 2 :system("cls");
                 LaporanTahunanTransaksiDonatur();
                 break;
        case 3 : system("cls");
                 SortTransaksiDNT();
                 break;
		case 4 :system("cls");
                 MenuLaporan();
                 break;
		case 5 :system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				  MenuLaporanTransaksiDonatur();
				  break;
	}
}

void LaporanTransaksiDonatur()
{
    // DECLARATION
    int Jumlah_Uang, y;
    OutterBorder();

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);

    y = 19;

    Jumlah_Uang = 0;
    if ((TransaksiDNT = fopen("dat/TransaksiDonatur.dat","rb"))==NULL){
        MessageBox(NULL, " Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        MenuLaporanTransaksiDonatur();

    }while (fread(&TransDonatur,sizeof(TransDonatur),1,TransaksiDNT) == 1){
        gotoxy(40,14); printf("\t\t\t\t\t=====Laporan Transaksi Donatur=====");
        gotoxy(40,15);	printf("====================================================================================================================");
        gotoxy(41,16); printf("ID Transaksi\t\tNama Donatur\t\tTotal\t\t\tTanggal Transaksi\t\tNama Kasir");
        gotoxy(40,17); printf("====================================================================================================================");
        gotoxy(40,40); printf("====================================================================================================================");
        gotoxy(45,y); printf("TDN%d",TransDonatur.id_donasi_uang);
        gotoxy(64,y); printf("%s",TransDonatur.NamaDonatur);
        gotoxy(88,y); printf("Rp "); RP(TransDonatur.total_uang);
        gotoxy(116,y); printf("%d/%d/%d ",TransDonatur.tanggal,TransDonatur.bulan,TransDonatur.tahun);
        gotoxy(144,y); printf("%s",TransDonatur.NamaKasir);
         y= y+1;
         Jumlah_Uang=TransDonatur.total_uang+Jumlah_Uang;

    }fclose(TransaksiDNT);

    gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(Jumlah_Uang);

}

void LaporanBulananTransaksiDonatur()
{
    // DECLARATION
    int total,month,year,Jumlah_Uang,y;
    OutterBorder();
	system("color 8E");

	//ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(5,18); printf("Masukan Bulan: "); getnum(&month,2);
    if (month == 0)
    {
        system("cls");
        MenuLaporanTransaksiDonatur();
    }
	gotoxy(5,19);printf("Masukan Tahun: "); getnum(&year,4);
	if (year == 0)
    {
        system("cls");
        MenuLaporanTransaksiDonatur();
    }

    y = 19;

    Jumlah_Uang = 0;
	if((TransaksiDNT=fopen("dat/TransaksiDonatur.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuLaporanTransaksiDonatur();
	}
	while(fread(&TransDonatur,sizeof(TransDonatur),1,TransaksiDNT) == 1){
        if(month == TransDonatur.bulan&& year == TransDonatur.tahun){
            gotoxy(40,14); printf("\t\t\t\t\t=====Laporan Transaksi Donatur=====");
            gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Transaksi\t\tNama Donatur\t\tTotal\t\t\tTanggal Transaksi\t\tNama Kasir");
            gotoxy(40,17); printf("====================================================================================================================");
            gotoxy(40,40); printf("====================================================================================================================");
            gotoxy(45,y); printf("TDN%d",TransDonatur.id_donasi_uang);
            gotoxy(64,y); printf("%s",TransDonatur.NamaDonatur);
            gotoxy(88,y); printf("Rp "); RP(TransDonatur.total_uang);
            gotoxy(116,y); printf("%d/%d/%d  ",TransDonatur.tanggal,TransDonatur.bulan,TransDonatur.tahun);
            gotoxy(144,y); printf("%s",TransDonatur.NamaKasir);
            y= y+1;
            Jumlah_Uang=TransDonatur.total_uang+Jumlah_Uang;
        }else{
            MessageBox(NULL, "Tidak Ada Transaksi ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuLaporanTransaksiDonatur();
        }
	}fclose(TransaksiDNT);

	gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(127,46),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDonatur();


}

void LaporanTahunanTransaksiDonatur()
{
    // DECLARATION
    int total,month,year,Jumlah_Uang,y;
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(5,19);printf("Masukan Tahun: "); getnum(&year,4);
	if (year == 0)
    {
        system("cls");
        MenuLaporanTransaksiDonatur();
    }

    y = 19;

    Jumlah_Uang = 0;
	if((TransaksiDNT=fopen("dat/TransaksiDonatur.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuLaporanTransaksiDonatur();
	}
	while(fread(&TransDonatur,sizeof(TransDonatur),1,TransaksiDNT) == 1){
        if(year == TransDonatur.tahun){
            gotoxy(40,14); printf("\t\t\t\t\t=====Laporan Transaksi Donatur=====");
            gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Transaksi\t\tNama Donatur\t\tTotal\t\t\tTanggal Transaksi\t\tNama Kasir");
            gotoxy(40,17); printf("====================================================================================================================");
            gotoxy(40,40); printf("====================================================================================================================");
            gotoxy(45,y); printf("TDN%d",TransDonatur.id_donasi_uang);
            gotoxy(64,y); printf("%s",TransDonatur.NamaDonatur);
            gotoxy(88,y); printf("Rp "); RP(TransDonatur.total_uang);
            gotoxy(116,y); printf("%d/%d/%d ",TransDonatur.tanggal,TransDonatur.bulan,TransDonatur.tahun);
            gotoxy(144,y); printf("%s",TransDonatur.NamaKasir);
            y= y+1;
            Jumlah_Uang=TransDonatur.total_uang+Jumlah_Uang;
        }else{
            MessageBox(NULL, "Tidak Ada Transaksi ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuLaporanTransaksiDonatur();
        }
	}fclose(TransaksiDNT);

	gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(127,46),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDonatur();


}
void SortTransaksiDNT()
{
    TransaksiDonatur rent[100];
    TransaksiDonatur temp;
    TransaksiDonatur DNT;
    int pass;
    int i,j,y,jumlahuang=0;
    FILE *SortTrans;
    OutterBorder();
    system("color 8E");
    gotoxy(12,10);	printf("%s",login.fullname);

    i=0;
    SortTrans = fopen("dat/TransaksiDonatur.dat","rb");
    while(fread(&DNT, sizeof(DNT),1,SortTrans)==1)
    {
        rent[i].id_donasi_uang=DNT.id_donasi_uang;
        strcpy(rent[i].NamaDonatur, DNT.NamaDonatur);
        rent[i].total_uang=DNT.total_uang;
        rent[i].tanggal=DNT.tanggal;
        rent[i].bulan=DNT.bulan;
        rent[i].tahun=DNT.tahun;
        strcpy(rent[i].NamaKasir, DNT.NamaKasir);
        i++;
    }

    for(pass = 0; pass <= i-2; pass++){
        for(j = i-1;j>= pass+1; j--){
            if (rent[j].total_uang>rent[j-1].total_uang){
                temp = rent[j];
                rent[j] = rent[j-1];
                rent[j-1] = temp;
            }
        }
    }
    gotoxy(40,14); printf("\t\t\t\t\t=====Laporan Transaksi Donatur=====");
    gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Transaksi\t\tNama Donatur\t\tTotal\t\t\tTanggal Transaksi\t\tNama Kasir");
    gotoxy(40,17); printf("====================================================================================================================");
    gotoxy(40,40); printf("====================================================================================================================");
    y=20;
    for(pass = 0; pass<i;pass++){
        gotoxy(45,y); printf("TDN%d",rent[pass].id_donasi_uang);
        gotoxy(64,y); printf("%s",rent[pass].NamaDonatur);
        gotoxy(88,y); printf("Rp "); RP(rent[pass].total_uang);
        gotoxy(116,y); printf("%d/%d/%d ",rent[pass].tanggal,rent[pass].bulan,rent[pass].tahun);
        gotoxy(144,y); printf("%s",rent[pass].NamaKasir);
        y++;
        jumlahuang = rent[pass].total_uang +jumlahuang;
    }
    gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(jumlahuang);
    fclose(SortTrans);
    gotoxy(127,46),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDonatur();

}

