void MenuLaporanTransaksiDistribusiYayasan()
{
	// DECLARATION
	int PilMenu;

	//ALGORITM
	OutterBorder();
	system("color 8E");
    LaporanTransaksiDistribusiYayasan();
    gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(5,15);	printf("LAPORAN TRANSAKSI");
	gotoxy(5,16);	printf("DISTRIBUSI YAYASAN");
	gotoxy(2,18);	printf("[1] Laporan Bulanan");
	gotoxy(2,19);	printf("[2] Laporan Tahunan");
	gotoxy(2,20);	printf("[3] Laporan Terbesar");
	gotoxy(2,21);	printf("[4] Kembali");
	gotoxy(2,22);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&PilMenu,1);
	switch (PilMenu)
	{
		case 1 : system("cls");
				 LaporanBulananTransaksiDistribusiYayasan();
				 break;
		case 2 : system("cls");
                 LaporanTahunanTransaksiDistribusiYayasan();
                 break;
        case 3 : system("cls");
                 SortTransaksiYYS();
                 break;
		case 4 : system("cls");
                 MenuLaporan();
                 break;
		case 5 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				  MenuLaporanTransaksiDistribusiYayasan();
				  break;
	}
}
void LaporanTransaksiDistribusiYayasan()
{
	// DECLARATION
    int y;
    int Jumlah_Uang;
    OutterBorder();

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);


    y = 19;

    Jumlah_Uang = 0;
    if ((DisYayasan = fopen("dat/TransaksiDistribusiYayasan.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        MenuLaporanTransaksiDistribusiYayasan();

    }while (fread(&DYayasan,sizeof(DYayasan),1,DisYayasan) == 1){
        gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Yayasan=====");
        gotoxy(40,15);	printf("====================================================================================================================");
        gotoxy(40,17);	printf("====================================================================================================================");
        gotoxy(41,16); printf("ID Distribusi\tNama Yayasan\t\t\tTotal Uang\t\tTanggal Transaksi\t\tNama Kasir");
        gotoxy(40,40); printf("====================================================================================================================");
        gotoxy(45,y); printf("TDY%d",DYayasan.id_distribusi_yayasan);
        gotoxy(56,y); printf("%s",DYayasan.namayayasan);
        gotoxy(88,y); printf("Rp "); RP(DYayasan.total_uang);
        gotoxy(117,y); printf("%d/%d/%d ",DYayasan.tanggal,DYayasan.bulan,DYayasan.tahun);
        gotoxy(144,y); printf("%s",DYayasan.namakasir);
        y++;
         Jumlah_Uang=DYayasan.total_uang+Jumlah_Uang;

    }fclose(DisYayasan);


    gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(Jumlah_Uang);

}


void LaporanBulananTransaksiDistribusiYayasan()
{
    //ALGORITM
    int total,month,year,Jumlah_Uang,y;
    OutterBorder();
	system("color 8E");

	 // DECLARATION
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(5,18); printf("Masukan Bulan: "); getnum(&month,2);
    if (month == 0)
    {
        system("cls");
        MenuLaporanTransaksiDistribusiYayasan();
    }

	gotoxy(5,19);printf("Masukan Tahun: "); getnum(&year,4);
	if (year == 0)
    {
        system("cls");
        MenuLaporanTransaksiDistribusiYayasan();
    }


    y = 19;

    Jumlah_Uang = 0;
	if((DisYayasan=fopen("dat/TransaksiDistribusiYayasan.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuLaporanTransaksiDistribusiYayasan();
	}
	while(fread(&DYayasan,sizeof(DYayasan),1,DisYayasan) == 1){
        if(month == DYayasan.bulan&& year == DYayasan.tahun){
            gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Yayasan=====");
            gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Distribusi\tNama Yayasan\t\t\tTotal Uang\t\tTanggal Transaksi\t\tNama Kasir");
            gotoxy(40,17); printf("====================================================================================================================");
            gotoxy(40,40); printf("====================================================================================================================");
            gotoxy(45,y); printf("TDY%d",DYayasan.id_distribusi_yayasan);
            gotoxy(56,y); printf("%s",DYayasan.namayayasan);
            gotoxy(88,y); printf("Rp "); RP(DYayasan.total_uang);
            gotoxy(117,y); printf("%d/%d/%d ",DYayasan.tanggal,DYayasan.bulan,DYayasan.tahun);
            gotoxy(144,y); printf("%s",DYayasan.namakasir);
            y++;
            Jumlah_Uang=DYayasan.total_uang+Jumlah_Uang;
        }else{
            MessageBox(NULL, "Tidak Ada Transaksi  ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuLaporanTransaksiDistribusiYayasan();
        }
	}fclose(DisYayasan);

	gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(127,47),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDistribusiYayasan();


}
void LaporanTahunanTransaksiDistribusiYayasan()
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
        MenuLaporanTransaksiDistribusiYayasan();
    }

    y = 19;

    Jumlah_Uang = 0;
	if((DisYayasan=fopen("dat/TransaksiDistribusiYayasan.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
		MenuLaporanTransaksiDistribusiYayasan();
	}
	while(fread(&DYayasan,sizeof(DYayasan),1,DisYayasan) == 1){
        if(year == DYayasan.tahun){
            gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Yayasan=====");
            gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Distribusi\tNama Yayasan\t\t\tTotal Uang\t\tTanggal Transaksi\t\tNama Kasir");
            gotoxy(40,17); printf("====================================================================================================================");
            gotoxy(40,40); printf("====================================================================================================================");
            gotoxy(45,y); printf("TDY%d",DYayasan.id_distribusi_yayasan);
            gotoxy(56,y); printf("%s",DYayasan.namayayasan);
            gotoxy(88,y); printf("Rp "); RP(DYayasan.total_uang);
            gotoxy(113,y); printf("%d/%d/%d ",DYayasan.tanggal,DYayasan.bulan,DYayasan.tahun);
            gotoxy(144,y); printf("%s",DYayasan.namakasir);
            y++;
            Jumlah_Uang=DYayasan.total_uang+Jumlah_Uang;
        }else{
            MessageBox(NULL, "Tidak Ada Transaksi  ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuLaporanTransaksiDistribusiYayasan();
        }
	}fclose(DisYayasan);

	gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(127,47),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDistribusiYayasan();


}

void SortTransaksiYYS()
{
    TransaksiDistribusiYayasan rent[100];
    TransaksiDistribusiYayasan temp;
    TransaksiDistribusiYayasan DYS;
    int pass;
    int i,j,y,jumlahuang =0;
    FILE *SortTransYYS;
    OutterBorder();
    system("color 8E");
    gotoxy(12,10);	printf("%s",login.fullname);

    i=0;
    SortTransYYS = fopen("dat/TransaksiDistribusiYayasan.dat","rb");
    while(fread(&DYS, sizeof(DYS),1,SortTransYYS)==1)
    {
        rent[i].id_distribusi_yayasan=DYS.id_distribusi_yayasan;
        strcpy(rent[i].namayayasan, DYS.namayayasan);
        rent[i].total_uang=DYS.total_uang;
        rent[i].tanggal=DYS.tanggal;
        rent[i].bulan=DYS.bulan;
        rent[i].tahun=DYS.tahun;
        strcpy(rent[i].namakasir, DYS.namakasir);
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
    gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Yayasan=====");
    gotoxy(40,15);	printf("====================================================================================================================");
    gotoxy(41,16); printf("ID Distribusi\tNama Yayasan\t\t\tTotal Uang\t\tTanggal Transaksi\t\tNama Kasir");
    gotoxy(40,17); printf("====================================================================================================================");
    gotoxy(40,40); printf("====================================================================================================================");
    y=20;
    for(pass = 0; pass<i;pass++){

        gotoxy(45,y); printf("TDY%d",rent[pass].id_distribusi_yayasan);
        gotoxy(56,y); printf("%s",rent[pass].namayayasan);
        gotoxy(88,y); printf("Rp "); RP(rent[pass].total_uang);
        gotoxy(113,y); printf("%d/%d/%d ",rent[pass].tanggal,rent[pass].bulan,rent[pass].tahun);
        gotoxy(144,y); printf("%s",rent[pass].namakasir);
        y++;
        jumlahuang = rent[pass].total_uang +jumlahuang;
    }
    gotoxy(41,41),printf("JUMLAH UANG :\t\t\t\t\tRp "); RP(jumlahuang);
    fclose(SortTransYYS);
    gotoxy(127,46),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDistribusiYayasan();

}

