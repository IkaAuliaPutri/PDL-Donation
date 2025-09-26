TransaksiDistribusiYayasan DYayasan;
StructLogin login;//SESSION

FILE *DisYayasan;
FILE *DataYayasan;
FILE *ArsipYayasan;

void TransDistribusiYayasan()
{
    //DECLARATION
    SYSTEMTIME t;
    GetLocalTime(&t);
    int last_id=0,kode;
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(53,16); printf("Transaksi Distribusi Yayasan");
    gotoxy(50,44),printf("Klik '0' untuk membatalkan Transaksi ....");
    DisYayasan = fopen("dat/TransaksiDistribusiYayasan.dat","ab+");
    while (fread(&DYayasan, sizeof(DYayasan),1,DisYayasan)==1){
        last_id=DYayasan.id_distribusi_yayasan;
    }
    last_id += 1 ;

    DYayasan.tanggal = t.wDay;
    DYayasan.bulan = t.wMonth;
    DYayasan.tahun = t.wYear;
    DYayasan.jam = t.wHour;
    DYayasan.menit = t.wMinute;
    DYayasan.detik = t.wSecond;
    gotoxy(47,21);printf("Tanggal       : %d/%d/%d   %d:%d:%d",  DYayasan.tanggal, DYayasan.bulan, DYayasan.tahun, DYayasan.jam, DYayasan.menit, DYayasan.detik);

    DYayasan.id_kasir = login.user_id;
    strcpy(DYayasan.namakasir,login.fullname);
    gotoxy(47,23);printf("ID Kasir      : KSR%d",DYayasan.id_kasir);
    gotoxy(47,25);printf("Nama Kasir    : %s",DYayasan.namakasir);
    gotoxy(47,27);printf("ID Distribusi : TDY%d", last_id); DYayasan.id_distribusi_yayasan = last_id;
    tampilyayasan();
    ulang:
    gotoxy(63,29);printf("     ");
    gotoxy(47,29),printf("ID Yayasan    : YYS"); getnum(&kode,10);fflush(stdin);
    if (kode == 0)
    {
        system("cls");
        MenuTransaksi();
    }
    DataYayasan = fopen("dat/ArsYayasan.dat","rb");
    int found =0;
    if (kode == 0)
    {
        system("cls");
        MenuTransaksi();
    }else if (kode != 0)
    {
        while (!found && !feof(DataYayasan))
        {
            fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);
            if (Yayasan.id_Yayasan == kode)
            {
                found = 1;
            }

        }
        if (found==1)
        {
            DYayasan.id_yayasan = Yayasan.id_Yayasan;
            gotoxy(47,31);printf("Nama Yayasan  : %s",Yayasan.Nama);
            strcpy(DYayasan.namayayasan,Yayasan.Nama);
            gotoxy(47,33),printf("Total Uang    : Rp "); getRp(&DYayasan.total_uang,1,20,66,33);fflush(stdin);
            if (DYayasan.total_uang == 0)
            {
                system("cls");
                MenuTransaksi();
            }
        }
        else
        {
            MessageBox(NULL, "Data Yayasan Belum Terdaftar!", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto ulang;
        }

    }

    fwrite(&DYayasan, sizeof(DYayasan),1,DisYayasan);fflush(stdin);
    fclose(DisYayasan);
    fclose(DataYayasan);
    MessageBox(NULL, "Transaksi Berhasil ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    gotoxy(50,44),printf("Klik Enter untuk menampilkan Struk...");
    getch();
    system("cls");
    OutterBorder();
    gotoxy(12,10);printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(60,16); printf("Bukti Transaksi Donatur");
    gotoxy(64,18); printf("PDL DONATION");
    gotoxy(59,19); printf("Ruko Summarecon Bekasi");
    gotoxy(56,20); printf("Jl. Boulevaro Baru Summarecon");
    gotoxy(61,21); printf("IG: @PDL.DONATION");
    gotoxy(46,22);printf("================================================");
    gotoxy(47,23);printf("Tanggal    :%d/%d/%d",DYayasan.tanggal, DYayasan.bulan, DYayasan.tahun);
    gotoxy(47,24);printf("Jam        :%d:%d:%d",DYayasan.jam, DYayasan.menit, DYayasan.detik);
    gotoxy(47,25);printf("Nama Kasir :%s",DYayasan.namakasir);
    gotoxy(46,26);printf("================================================");
    gotoxy(47,28);printf("Kode Transaksi    :TDY%d",DYayasan.id_distribusi_yayasan);
    gotoxy(47,30);printf("Id Yayasan        :YYS%d",DYayasan.id_yayasan);
    gotoxy(47,32);printf("Nama Yayasan      :%s",DYayasan.namayayasan);
    gotoxy(47,34);printf("Total Disumbang   : Rp "); RP(DYayasan.total_uang);
    gotoxy(64,40);printf("-Terimakasih-");
    gotoxy(55,44),printf("Klik Enter untuk selesai...");
    getch();
    system("cls");
    MenuTransaksi();



}


void tampilyayasan()
{
    //DECLARATION
    int y,i;

    //ALGORITM
    ArsipYayasan= fopen("dat/ArsYayasan.dat", "rb");
    gotoxy(125,16); printf("=====Lihat Yayasan=====");
    gotoxy(121,15);	printf("_______________________________________");
    gotoxy(122,18); printf("ID");
    gotoxy(132,18); printf("Nama");
    gotoxy(121,17); printf("_______________________________________");
    y = 20;
    for (i=16;i<=45;i++)
	{
		gotoxy(120,i);
		printf("|",127);
	}
	for (i=16;i<=45;i++)
	{
		gotoxy(160,i);
		printf("|",127);
	}
	for (i=121;i<=159;i++)
	{
		gotoxy(i,45);
		printf("_",127);
	}
    while (fread(&Yayasan, sizeof (Yayasan),1,ArsipYayasan)==1){
        gotoxy(122,y); fflush(stdin); printf("YYS%d ", Yayasan.id_Yayasan);
        gotoxy(132,y); fflush(stdin); printf("%s ", Yayasan.Nama);\
        y=y+1;
    }fclose(ArsipYayasan);
}
