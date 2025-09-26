void MenuLaporanTransaksiDistribusiKegiatan()
{
	// DECLARATION
	int PilMenu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    LaporanTransaksiDistribusiKegiatan();
	gotoxy(5,15);	printf("LAPORAN TRANSAKSI");
	gotoxy(5,16);	printf("DISTRIBUSI KEGIATAN");
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
				 LaporanBulananTransaksiDistribusiKegiatan();
				 break;
		case 2 : system("cls");
                 LaporanTahunanTransaksiDistribusiKegiatan();
                 break;
        case 3 : system("cls");
                 SortTransaksiKG();
                 break;
		case 4 : system("cls");
                 MenuLaporan();
                 break;
		case 5 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				  MenuLaporanTransaksiDistribusiKegiatan();
				  break;
	}
}
void LaporanTransaksiDistribusiKegiatan()
{
    // DECLARATION
    int Jumlah_Uang, y,jumlah_disumbangkan;
    OutterBorder();

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);

    y = 19;
    Jumlah_Uang = 0;
    jumlah_disumbangkan = 0;
    if ((DisKegiatan = fopen("dat/TransaksiDistribusiKegiatan.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION| MB_DEFAULT_DESKTOP_ONLY);
        MenuLaporanTransaksiDistribusiKegiatan();

    }while (fread(&DistribusiKegiatan,sizeof(DistribusiKegiatan),1,DisKegiatan) == 1){
        gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Kegiatan=====");
        gotoxy(40,15);	printf("====================================================================================================================");
        gotoxy(41,16); printf("ID Distribusi\tNama Kegiatan\t\tUang Dibutuhkan    Uang Disumbangakan\tTanggal Transaksi\tNama Kasir");
        gotoxy(40,17); printf("====================================================================================================================");
        gotoxy(40,40); printf("====================================================================================================================");
        gotoxy(45,y); printf("TDK%d",DistribusiKegiatan.id_distribusi_kegiatan);
        gotoxy(56,y); printf("%s",DistribusiKegiatan.namakegiatan);
        gotoxy(80,y); printf("Rp "); RP(DistribusiKegiatan.total_uang);
        gotoxy(99,y); printf("Rp "); RP(DistribusiKegiatan.Uang_disumbangkan);
        gotoxy(123,y); printf("%d/%d/%d",DistribusiKegiatan.tanggal,DistribusiKegiatan.bulan,DistribusiKegiatan.tahun);
        gotoxy(144,y); printf("%s",DistribusiKegiatan.namakasir);
         y= y+1;
         Jumlah_Uang=DistribusiKegiatan.total_uang+Jumlah_Uang;
         jumlah_disumbangkan = DistribusiKegiatan.Uang_disumbangkan + jumlah_disumbangkan;

    }fclose(DisKegiatan);

    gotoxy(45,41),printf("JUMLAH UANG :\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(96,41),printf("   Rp "); RP(Jumlah_Uang);


}

void LaporanBulananTransaksiDistribusiKegiatan()
{
    // DECLARATION
    int total,month,year,Jumlah_Uang,y,jumlah_disumbangkan;
    OutterBorder();
	system("color 8E");

	//ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(5,18); printf("Masukan Bulan: "); getnum(&month,2);
    if (month == 0)
    {
        system("cls");
        MenuLaporanTransaksiDistribusiKegiatan();
    }
	gotoxy(5,19);printf("Masukan Tahun: "); getnum(&year,4);
	if (year == 0)
    {
        system("cls");
        MenuLaporanTransaksiDistribusiKegiatan();
    }

    y = 19;
    Jumlah_Uang = 0;
	if ((DisKegiatan = fopen("dat/TransaksiDistribusiKegiatan.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        MenuLaporanTransaksiDistribusiKegiatan();
	}
	while(fread(&DistribusiKegiatan,sizeof(DistribusiKegiatan),1,DisKegiatan) == 1){
        if(month == DistribusiKegiatan.bulan&& year == DistribusiKegiatan.tahun){
            gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Kegiatan=====");
            gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Distribusi\tNama Kegiatan\t\tUang Dibutuhkan    Uang Disumbangakan\tTanggal Transaksi\tNama Kasir");
            gotoxy(40,17); printf("====================================================================================================================");
            gotoxy(40,40); printf("====================================================================================================================");
            gotoxy(45,y); printf("TDK%d",DistribusiKegiatan.id_distribusi_kegiatan);
            gotoxy(56,y); printf("%s",DistribusiKegiatan.namakegiatan);
            gotoxy(80,y); printf("Rp "); RP(DistribusiKegiatan.total_uang);
            gotoxy(99,y); printf("Rp "); RP(DistribusiKegiatan.Uang_disumbangkan);
            gotoxy(123,y); printf("%d/%d/%d",DistribusiKegiatan.tanggal,DistribusiKegiatan.bulan,DistribusiKegiatan.tahun);
            gotoxy(144,y); printf("%s",DistribusiKegiatan.namakasir);
            y= y+1;
            Jumlah_Uang=DistribusiKegiatan.total_uang+Jumlah_Uang;
            jumlah_disumbangkan = DistribusiKegiatan.Uang_disumbangkan + jumlah_disumbangkan;
        }else{
            MessageBox(NULL, "Tidak Ada Transaksi ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuLaporanTransaksiDistribusiKegiatan();

        }
	}fclose(DisKegiatan);

	gotoxy(45,41),printf("JUMLAH UANG :\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(96,41),printf("   Rp "); RP(Jumlah_Uang);
    gotoxy(127,47),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDistribusiKegiatan();


}

void LaporanTahunanTransaksiDistribusiKegiatan()
{
    // DECLARATION
    int total,month,year,Jumlah_Uang,y,jumlah_disumbangkan;
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(5,19);printf("Masukan Tahun: "); getnum(&year,4);
	if (year == 0)
    {
        system("cls");
        MenuLaporanTransaksiDistribusiKegiatan();
    }

    y = 19;
    Jumlah_Uang = 0;
	if ((DisKegiatan = fopen("dat/TransaksiDistribusiKegiatan.dat","rb"))==NULL){
        MessageBox(NULL, "Data Kosong! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        MenuLaporanTransaksiDistribusiKegiatan();
	}
	while(fread(&DistribusiKegiatan,sizeof(DistribusiKegiatan),1,DisKegiatan) == 1){
        if(year == DistribusiKegiatan.tahun){
            gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Kegiatan=====");
            gotoxy(40,15);	printf("====================================================================================================================");
            gotoxy(41,16); printf("ID Distribusi\tNama Kegiatan\t\tUang Dibutuhkan    Uang Disumbangakan\tTanggal Transaksi\tNama Kasir");
            gotoxy(40,17); printf("====================================================================================================================");
            gotoxy(40,40); printf("====================================================================================================================");
            gotoxy(45,y); printf("TDK%d",DistribusiKegiatan.id_distribusi_kegiatan);
            gotoxy(56,y); printf("%s",DistribusiKegiatan.namakegiatan);
            gotoxy(80,y); printf("Rp "); RP(DistribusiKegiatan.total_uang);
            gotoxy(99,y); printf("Rp "); RP(DistribusiKegiatan.Uang_disumbangkan);
            gotoxy(123,y); printf("%d/%d/%d",DistribusiKegiatan.tanggal,DistribusiKegiatan.bulan,DistribusiKegiatan.tahun);
            gotoxy(144,y); printf("%s",DistribusiKegiatan.namakasir);
            y= y+1;
            Jumlah_Uang=DistribusiKegiatan.total_uang+Jumlah_Uang;
            jumlah_disumbangkan = DistribusiKegiatan.Uang_disumbangkan + jumlah_disumbangkan;
        }else{
            MessageBox(NULL, "Tidak Ada Transaksi ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuLaporanTransaksiDistribusiKegiatan();

        }
	}fclose(DisKegiatan);

	gotoxy(45,41),printf("JUMLAH UANG :\t\t\tRp "); RP(Jumlah_Uang);
    gotoxy(96,41),printf("   Rp "); RP(Jumlah_Uang);
    gotoxy(127,47),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDistribusiKegiatan();
}

void SortTransaksiKG()
{
    TransaksiDistribusiKegiatan rent[100];
    TransaksiDistribusiKegiatan temp;
    TransaksiDistribusiKegiatan DKG;
    int pass;
    int i,j,y,jumlahuang = 0,uangdisumbangkan=0;
    FILE *SortTransKG;
    OutterBorder();
    system("color 8E");
    gotoxy(12,10);	printf("%s",login.fullname);

    i=0;
    SortTransKG = fopen("dat/TransaksiDistribusiKegiatan.dat","rb");
    while(fread(&DKG, sizeof(DKG),1,SortTransKG)==1)
    {
        rent[i].id_distribusi_kegiatan=DKG.id_distribusi_kegiatan;
        strcpy(rent[i].namakegiatan, DKG.namakegiatan);
        rent[i].total_uang=DKG.total_uang;
        rent[i].Uang_disumbangkan=DKG.Uang_disumbangkan;
        rent[i].tanggal=DKG.tanggal;
        rent[i].bulan=DKG.bulan;
        rent[i].tahun=DKG.tahun;
        strcpy(rent[i].namakasir, DKG.namakasir);
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
    gotoxy(40,14); printf("\t\t\t\t=====Laporan Transaksi Distribusi Kegiatan=====");
    gotoxy(40,15);	printf("====================================================================================================================");
    gotoxy(41,16); printf("ID Distribusi\tNama Kegiatan\t\tUang Dibutuhkan    Uang Disumbangakan\tTanggal Transaksi\tNama Kasir");
    gotoxy(40,17); printf("====================================================================================================================");
    gotoxy(40,40); printf("====================================================================================================================");
    y=20;

    for(pass = 0; pass<i;pass++){
        gotoxy(45,y); printf("TDK%d",rent[pass].id_distribusi_kegiatan);
        gotoxy(56,y); printf("%s",rent[pass].namakegiatan);
        gotoxy(80,y); printf("Rp "); RP(rent[pass].total_uang);
        gotoxy(99,y); printf("Rp "); RP(rent[pass].Uang_disumbangkan);
        gotoxy(123,y); printf("%d/%d/%d ",rent[pass].tanggal,rent[pass].bulan,rent[pass].tahun);
        gotoxy(144,y); printf("%s",rent[pass].namakasir);
        y++;
        jumlahuang = rent[pass].total_uang + jumlahuang;
        uangdisumbangkan = rent[pass].Uang_disumbangkan + uangdisumbangkan;
    }
    gotoxy(45,41),printf("JUMLAH UANG :\t\t\tRp "); RP(jumlahuang);
    gotoxy(96,41),printf("   Rp "); RP(uangdisumbangkan);
    fclose(SortTransKG);
    gotoxy(127,46),printf("Klik Enter untuk Kembali...");
	getch();
	system("cls");
	MenuLaporanTransaksiDistribusiKegiatan();

}

