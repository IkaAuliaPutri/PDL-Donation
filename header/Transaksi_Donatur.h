TransaksiDonatur TransDonatur;

FILE *TransaksiDNT;
FILE *lihatdonatur;
FILE *DataDonatur;


void TransaksiDoanatur()
{
    //DECLARATION
    SYSTEMTIME t;
    GetLocalTime(&t);
    int last_id=0,kode,found;
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(60,16); printf("Transaksi Donatur");
    gotoxy(50,44),printf("Klik '0' untuk membatalkan Transaksi ....");
    TransaksiDNT = fopen("dat/TransaksiDonatur.dat","ab+");
    while (fread(&TransDonatur, sizeof(TransDonatur),1,TransaksiDNT)==1){
        last_id=TransDonatur.id_donasi_uang;
    }
    last_id++;

    TransDonatur.tanggal = t.wDay;
    TransDonatur.bulan = t.wMonth;
    TransDonatur.tahun = t.wYear;
    TransDonatur.jam = t.wHour;
    TransDonatur.menit = t.wMinute;
    TransDonatur.detik = t.wSecond;
    gotoxy(47,21),printf("Tanggal       : %d/%d/%d   %d:%d:%d",  TransDonatur.tanggal, TransDonatur.bulan, TransDonatur.tahun, TransDonatur.jam, TransDonatur.menit, TransDonatur.detik);

    TransDonatur.id_kasir = login.user_id;
    strcpy(TransDonatur.NamaKasir,login.fullname);

    gotoxy(47,23),printf("ID Kasir      : KSR%d", TransDonatur.id_kasir);

    gotoxy(47,25),printf("Nama Kasir    : %s",TransDonatur.NamaKasir);

    gotoxy(47,27),printf("ID Transaksi  : TDN%d", last_id); TransDonatur.id_donasi_uang = last_id;

    tampildonatur();
    ulang:
    gotoxy(67,29);printf("    ");
    gotoxy(47,29),printf("ID Donatur    : DNT"); getnum(&kode,10);fflush(stdin);
    if (kode == 0)
    {
        system("cls");
        MenuTransaksi();
    }

    //VALIDASI ID D0NATUR//
    lihatdonatur = fopen("dat/ArsDonatur.dat","rb");
    found = 0;

    if (kode == 0)
    {
        system("cls");
        MenuTransaksi();
    }else if (kode != 0)
    {
        while ((!found )&& (!feof(lihatdonatur)))
        {
            fread(&Donatur,sizeof(Donatur),1,lihatdonatur);
            if ( Donatur.id_Donatur == kode )
            {
                found = 1;
            }
        }
        if (found==1)
        {
            TransDonatur.id_donatur = Donatur.id_Donatur;
            gotoxy(47,31);printf("Nama Donatur  : %s",Donatur.Full_Nama);
            strcpy(TransDonatur.NamaDonatur,Donatur.Full_Nama);
            gotoxy(47,33),printf("Total Uang    : Rp "); getRp(&TransDonatur.total_uang,1,20,66,33);fflush(stdin);
            if (TransDonatur.total_uang == 0)
            {
                system("cls");
                MenuTransaksi();
            }
        }
        else
        {
            MessageBox(NULL, "Data Donatur Belum Terdaftar !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto ulang;
        }
    }

    fwrite(&TransDonatur, sizeof(TransDonatur),1,TransaksiDNT);fflush(stdin);
    MessageBox(NULL, "Transaksi Berhasil ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    gotoxy(50,44),printf("Klik Enter untuk menampilkan Struk...");
    fclose(TransaksiDNT);
    fclose(lihatdonatur);
    getch();
    system("cls");
    OutterBorder();
    gotoxy(12,10);	printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(60,16); printf("Bukti Transaksi Donatur");
    gotoxy(64,18); printf("PDL DONATION");
    gotoxy(59,19); printf("Ruko Summarecon Bekasi");
    gotoxy(56,20); printf("Jl. Boulevaro Baru Summarecon");
    gotoxy(61,21); printf("IG: @PDL.DONATION");
    gotoxy(46,22);printf("================================================");
    gotoxy(47,23);printf("Tanggal    :%d/%d/%d",TransDonatur.tanggal, TransDonatur.bulan, TransDonatur.tahun);
    gotoxy(47,24);printf("Jam        :%d:%d:%d",TransDonatur.jam, TransDonatur.menit, TransDonatur.detik);
    gotoxy(47,25);printf("Nama Kasir :%s",TransDonatur.NamaKasir);
    gotoxy(46,26);printf("================================================");
    gotoxy(47,28);printf("Kode Transaksi  :TDN%d",TransDonatur.id_donasi_uang);
    gotoxy(47,30);printf("Id Donatur      :DNT%d",TransDonatur.id_donatur);
    gotoxy(47,32);printf("Nama Donatur    :%s",TransDonatur.NamaDonatur);
    gotoxy(47,34);printf("Total Donasi    : Rp "); RP(TransDonatur.total_uang);

    gotoxy(64,40);printf("-Terimakasih-");
    gotoxy(55,44),printf("Klik Enter untuk selesai...");
    getch();
    system("cls");
    MenuTransaksi();



}

void tampildonatur()
{
    //DECLARATION
    int y,i;

    //ALGORITM
    DataDonatur= fopen("dat/ArsDonatur.dat", "rb");
    gotoxy(125,16); printf("=====Lihat Donatur=====");
    gotoxy(121,15);	printf("______________________________");
    gotoxy(122,18); printf("ID");
    gotoxy(132,18); printf("Nama");
    gotoxy(121,17); printf("______________________________");
    y = 20;
    for (i=16;i<=45;i++)
	{
		gotoxy(120,i);
		printf("|",127);
	}
	for (i=16;i<=45;i++)
	{
		gotoxy(151,i);
		printf("|",127);
	}
	for (i=121;i<=150;i++)
	{
		gotoxy(i,45);
		printf("_",127);
	}
    while (fread(&Donatur, sizeof (Donatur),1,DataDonatur)==1){
        gotoxy(122,y); fflush(stdin); printf("DNT%d ", Donatur.id_Donatur);
        gotoxy(132,y); fflush(stdin); printf("%s", Donatur.Full_Nama);
        y=y+1;
    }fclose(DataDonatur);

}

