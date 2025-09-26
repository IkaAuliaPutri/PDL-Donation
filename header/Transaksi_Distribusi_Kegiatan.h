TransaksiDistribusiKegiatan DistribusiKegiatan;
TransaksiPengajuanKegiatan kegiatan;
FILE *DisKegiatan;
FILE *TransKegiatan;
FILE *datakegiatan;
void TransDistribusiKegiatan()
{
    // DECLARATION
    SYSTEMTIME t;
    GetLocalTime(&t);
    int last_id=0,kode,ulang_uang;
    OutterBorder();
	system("color 8E");

	//ALGORITM
    kotakCRUDTransaksi();
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(55,16); printf("Transaksi Distribusi Kegiatan");
    gotoxy(50,44),printf("Klik '0' untuk membatalkan Transaksi ....");
    DisKegiatan = fopen("dat/TransaksiDistribusiKegiatan.dat","ab+");
    while (fread(&DistribusiKegiatan, sizeof(DistribusiKegiatan),1,DisKegiatan)==1){
        last_id=DistribusiKegiatan.id_distribusi_kegiatan;
    }
    last_id++;
    DistribusiKegiatan.tanggal = t.wDay;
    DistribusiKegiatan.bulan = t.wMonth;
    DistribusiKegiatan.tahun = t.wYear;
    DistribusiKegiatan.jam = t.wHour;
    DistribusiKegiatan.menit = t.wMinute;
    DistribusiKegiatan.detik = t.wSecond;

    gotoxy(50,21),printf("Tanggal       : %d/%d/%d   %d:%d:%d",  DistribusiKegiatan.tanggal, DistribusiKegiatan.bulan, DistribusiKegiatan.tahun, DistribusiKegiatan.jam, DistribusiKegiatan.menit, DistribusiKegiatan.detik);

    DistribusiKegiatan.id_kasir = login.user_id;
    strcpy(DistribusiKegiatan.namakasir,login.fullname);

    gotoxy(50,23),printf("ID Kasir      : KSR%d",DistribusiKegiatan.id_kasir);
    gotoxy(50,25),printf("Nama Kasir    : %s",DistribusiKegiatan.namakasir);
    gotoxy(50,27),printf("ID Distribusi : TDK%d",last_id); DistribusiKegiatan.id_distribusi_kegiatan = last_id;

    tampilkegiatan();
    ulang:
    gotoxy(69,29);printf("   ");
    gotoxy(50,29),printf("ID Kegiatan   : TKG"); getnum(&kode,5);fflush(stdin);
    if (kode == 0)
    {
        system("cls");
        MenuTransaksi();
    }
    //VALIDASI ID KEGIATAN//
    datakegiatan = fopen("dat/ArsPengajuanKegiatan.dat","rb");
    int found =0;
    if (kode == 0)
    {
        system("cls");
        MenuTransaksi();
    }else if (kode != 0)
    {
        while (!found && !feof(datakegiatan))
        {
            fread(&kegiatan,sizeof(kegiatan),1,datakegiatan);
            if (kegiatan.id_kegiatan == kode)
            {
                found = 1;
            }

        }
        if (found==1)
        {
            DistribusiKegiatan.id_kegiatan = kegiatan.id_kegiatan;
            gotoxy(50,31);printf("Nama Kegiatan         : %s",kegiatan.Nama_Kegiatan);
            strcpy(DistribusiKegiatan.namakegiatan, kegiatan.Nama_Kegiatan);
            gotoxy(50,33),printf("Uang Yang dibutuhkan  : Rp "); RP(kegiatan.total_uang);fflush(stdin);
            DistribusiKegiatan.total_uang = kegiatan.total_uang;
            ulang_uang:
            gotoxy(77,35);printf("                ");
            gotoxy(50,35),printf("Uang Yang disumbangkan: Rp "); getRp(&DistribusiKegiatan.Uang_disumbangkan,1,20,77,35);fflush(stdin);
            if (DistribusiKegiatan.Uang_disumbangkan < DistribusiKegiatan.total_uang)
            {
                MessageBox(NULL, "Uang Tidak boleh kurang !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto ulang_uang;
            }
        }
        else
        {
            MessageBox(NULL, "Data Kegiatan Belum Terdaftar!", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto ulang;
        }

    }
    fwrite(&DistribusiKegiatan, sizeof(DistribusiKegiatan),1,DisKegiatan);fflush(stdin);
    fclose(DisKegiatan);
    fclose(datakegiatan);
    MessageBox(NULL, "Transaksi Berhasil ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    gotoxy(50,44),printf("Klik Enter untuk menampilkan Struk...");
    getch();
    system("cls");
    OutterBorder();
    gotoxy(12,10);	printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(55,16); printf("Bukti Transaksi Distribusi Kegiatan");
    gotoxy(64,18); printf("PDL DONATION");
    gotoxy(59,19); printf("Ruko Summarecon Bekasi");
    gotoxy(56,20); printf("Jl. Boulevaro Baru Summarecon");
    gotoxy(61,21); printf("IG: @PDL.DONATION");
    gotoxy(46,22);printf("================================================");
    gotoxy(47,23);printf("Tanggal    :%d/%d/%d",DistribusiKegiatan.tanggal, DistribusiKegiatan.bulan, DistribusiKegiatan.tahun);
    gotoxy(47,24);printf("Jam        :%d:%d:%d",DistribusiKegiatan.jam, DistribusiKegiatan.menit, DistribusiKegiatan.detik);
    gotoxy(47,25);printf("Nama Kasir :%s",DistribusiKegiatan.namakasir);
    gotoxy(46,26);printf("================================================");
    gotoxy(47,28);printf("Kode Transaksi        :TDK%d",DistribusiKegiatan.id_distribusi_kegiatan);
    gotoxy(47,30);printf("Id Kegiatan           :TKG%d",DistribusiKegiatan.id_kegiatan);
    gotoxy(47,32);printf("Nama Kegiatan         :%s",DistribusiKegiatan.namakegiatan);
    gotoxy(47,34);printf("Uang yang dibutuhkan  : Rp "); RP(DistribusiKegiatan.total_uang);
    gotoxy(47,36);printf("Uang yang disumbangkan: Rp "); RP(DistribusiKegiatan.Uang_disumbangkan);
    gotoxy(64,40);printf("-Terimakasih-");
    gotoxy(55,44),printf("Klik Enter untuk selesai...");
    getch();
    system("cls");
    MenuTransaksi();




}


 void tampilkegiatan()
 {
     // DECLARATION
    int y,i;

    //ALGORITM
    TransKegiatan= fopen("dat/ArsPengajuanKegiatan.dat", "rb");
    gotoxy(125,16); printf("=====Lihat Kegiatan=====");
    gotoxy(121,15);	printf("_______________________________________");
    gotoxy(122,18); printf("ID");
    gotoxy(132,18); printf("Nama");
    gotoxy(121,17); printf("_______________________________________");
    for (i=16;i<=45;i++) // buat nama di atas
	{
		gotoxy(120,i);
		printf("|",127);
	}
	for (i=16;i<=45;i++) // buat nama di atas
	{
		gotoxy(160,i);
		printf("|",127);
	}
	for (i=121;i<=159;i++) // buat nama di atas
	{
		gotoxy(i,45);
		printf("_",127);
	}
    y=20;
    while (fread(&kegiatan, sizeof (kegiatan),1,TransKegiatan)==1){

            gotoxy(122,y); fflush(stdin); printf("TKG%d ", kegiatan.id_kegiatan);
            gotoxy(132,y); fflush(stdin); printf("%s ", kegiatan.Nama_Kegiatan);
            y=y+1;
        }fclose(TransKegiatan);
 }
