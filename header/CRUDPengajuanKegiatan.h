TransaksiPengajuanKegiatan kegiatan;
FILE *UpdateKegiatan;
FILE *deleteKegiata;
FILE *ArsipINS;
FILE *DataINS;
FILE *TransKegiatan;

void MenuCRUDPengajuankegiatan()
{
	// DECLARATION
	int PilMenu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    LaporanTransaksiPengajuanKegiatan();
	gotoxy(9,15);	printf("MENU KEGIATAN");
	gotoxy(5,17);	printf("[1] Tambah Kegaitan ");
	gotoxy(5,18);	printf("[2] Update kegiatan");
	gotoxy(5,19);	printf("[3] Delete Kegiatan");
	gotoxy(5,20);	printf("[4] Kembali");
	gotoxy(5,21);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&PilMenu,1);
	switch (PilMenu)
	{
		case 1 : system("cls");
                 TransPengajuanKegiatan();
				 break;
		case 2 : system("cls");
                 UpdateTransPengajuanKegiatan();
				 break;

		case 3 : system("cls");
                 DeleteTransPengajuanKegiatan();
                 break;

		case 4 : system("cls");
                 MenuKasir();
                 break;

		case 5 : system("cls");
				 PrintFile("txt/thankyou.txt", 58,18);
				 exit(0);

		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
				  MenuCRUDPengajuankegiatan();
				  break;
	}
}


void TransPengajuanKegiatan()
{
    //DECLARATION
    SYSTEMTIME t;
    GetLocalTime(&t);
    int last_id=0,found,kode,ulang_tanggal;
    char jawaban[10];
    OutterBorder();
	system("color 8E");

	//ALGORITM
	gotoxy(12,10);	printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(55,16); printf("Transaksi Pengajuan Kegiatan");
    gotoxy(50,44),printf("Klik '0' untuk Batal....");
    TransKegiatan = fopen("dat/ArsPengajuanKegiatan.dat","ab+");
    while (fread(&kegiatan, sizeof(kegiatan),1,TransKegiatan)==1){
        last_id=kegiatan.id_kegiatan;
    }
    last_id++;

    kegiatan.tanggal = t.wDay;
    kegiatan.bulan = t.wMonth;
    kegiatan.tahun = t.wYear;
    kegiatan.jam = t.wHour;
    kegiatan.menit = t.wMinute;
    kegiatan.detik = t.wSecond;
    gotoxy(47,21),printf("Tanggal               : %d/%d/%d   %d:%d:%d",  kegiatan.tanggal, kegiatan.bulan, kegiatan.tahun, kegiatan.jam, kegiatan.menit, kegiatan.detik);

    kegiatan.id_kasir = login.user_id;
    strcpy(kegiatan.namakasir, login.fullname);
    gotoxy(47,23),printf("ID Kasir              : KSR%d",kegiatan.id_kasir);

    gotoxy(47,25),printf("Nama Kasir            : %s",kegiatan.namakasir);

    gotoxy(47,27),printf("ID Kegiatan           : TKG%d", last_id); kegiatan.id_kegiatan = last_id;
    Lihatinisiator();
    //SELESAI BACA DONATUR//
    ulang:
    gotoxy(74,29); printf("   ");
    gotoxy(47,29);printf("ID Inisiator          : ISR"); getnum(&kode,3);fflush(stdin);
    if (kode == 0)
    {
        system("cls");
        MenuCRUDPengajuankegiatan();
    }
    //VALIDASI ID INISIATOR//
    DataINS = fopen("dat/ArsInisiator.dat","rb");
    found = 0;
    if (kode == 0)
    {
        system("cls");
        MenuCRUDPengajuankegiatan();
    }else if (kode != 0)
    {
        while (!found && !feof(DataINS))
        {
            fread(&Inisiator,sizeof(Inisiator),1,DataINS);
            if (Inisiator.id_inisiator == kode)
            {
                found = 1;
            }

        }

        if (found==1)
        {
            kegiatan.id_inisiator = Inisiator.id_inisiator;
            gotoxy(47,31), printf("Nama Inisiator       : %s",Inisiator.Full_Nama);
            strcpy(kegiatan.namainisiator,Inisiator.Full_Nama);
            gotoxy(47,33), printf("Nama Kegiatan        : "); getteks(kegiatan.Nama_Kegiatan,30);fflush(stdin);
            if (strcmp(kegiatan.Nama_Kegiatan, "0")==0)
            {
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
            ulang_tanggal:
            gotoxy(69,35); printf("           ");
            gotoxy(72,35); printf("/  /"); gotoxy(47,35); printf("Tanggal Pengajuan    : "); getnum(&kegiatan.tanggalpengajuan,2);fflush(stdin);
            if (kegiatan.tanggalpengajuan == 0){
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
            gotoxy(73,35); getnum(&kegiatan.bulanpengajuan,2);fflush(stdin);
            if(kegiatan.bulanpengajuan == 0){
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
            gotoxy(76,35); getnum(&kegiatan.tahunpengajuan,4);fflush(stdin);
            if (kegiatan.tahunpengajuan == 0){
                system("cls");
                MenuCRUDPengajuankegiatan();
            }

            //VALIDASI TANGGAL PENGAJUAN//
            if((kegiatan.tahunpengajuan<kegiatan.tahun ) || ((kegiatan.bulanpengajuan<kegiatan.bulan) && (kegiatan.bulanpengajuan > 12)) )
            {
                MessageBox(NULL, "Tanggal pengajuan Tidak boleh masa lampau  !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto ulang_tanggal;
            }else {
                if((kegiatan.tanggalpengajuan<=kegiatan.tanggal) && (kegiatan.tahunpengajuan > 31))
                {
                    MessageBox(NULL, "Tanggal pengajuan Tidak boleh masa lampau  !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                    goto ulang_tanggal;
                }
            }
            //SELESAI VALIDASI TANGGAL//
            gotoxy(47,37), printf("Total Uang           : Rp "); getRp(&kegiatan.total_uang,1,20,73,37);fflush(stdin);
            if (kegiatan.total_uang == 0)
            {
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
            strcpy(kegiatan.status, "PROGRES");
        }
        else
        {
            MessageBox(NULL, "Data Inisiator Belum Terdaftar! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto ulang;
        }
    }fclose(DataINS);
    fwrite(&kegiatan, sizeof(kegiatan),1,TransKegiatan);fflush(stdin);
    MessageBox(NULL, "Transaksi Berhasil ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
    fclose(TransKegiatan);


    jawaban:
    gotoxy(82,40); printf(" ");
    gotoxy(50,40); printf("Ingin Tambah data lagi [Y/N] : ");
    gotoxy(81,40);printf("["); gotoxy(83,40);printf("]");
    gotoxy(82,40);getteks(jawaban,1);
    if (strcmp(jawaban,"0")==0)
    {
        system("cls");
        MenuCRUDPengajuankegiatan();
    }
    else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
    {
        system("cls");
        TransPengajuanKegiatan();
    }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
    {
        MessageBox(NULL, "Terima Kasih  ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        MenuCRUDPengajuankegiatan();
    }
    else
    {
        MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto jawaban;
    }

}

void UpdateTransPengajuanKegiatan()
 {
	//DECLARATION
	int a, cari_id, found,pilih,ulang_status,ulang_cari;
	char jawaban[10];
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
    UpdateKegiatan = fopen("dat/ArsPengajuanKegiatan.dat","ab+");
	Temp = fopen ("dat/tempo.dat", "wb");
    kotakCRUDTransaksi();
    gotoxy(50,16); printf("Update Transaksi Pengajuan Kegiatan");

    ulang_cari:
    gotoxy(85,19);printf("    ");
	gotoxy(50,19); printf("Masukkan ID yang ingin diubah = TKG");
	scanf("%d", &cari_id);

	found = 0;

	if (cari_id == 0)
    {
        system("cls");
        MenuCRUDPengajuankegiatan();
    }
    else if (cari_id !=0)
    {
        while ((!found )&& (!feof(UpdateKegiatan)))
        {
            fread (&kegiatan, sizeof (kegiatan), 1, UpdateKegiatan);
            if(kegiatan.id_kegiatan == cari_id)
            {
                found = 1;
            }
            else
            {
			fwrite (&kegiatan, sizeof (kegiatan),1,Temp);
            }
        }
    }
    if(found == 1)
	{
		gotoxy(50,21);printf("Nama Kasir        :%s",kegiatan.namakasir);
        gotoxy(50,22);printf("Kode Transaksi    :TKG%d",kegiatan.id_kegiatan);
        gotoxy(50,23);printf("Tanggal           :%d/%d/%d   %d:%d:%d ",kegiatan.tanggal, kegiatan.bulan, kegiatan.tahun, kegiatan.jam, kegiatan.menit, kegiatan.detik);
        gotoxy(50,24);printf("Id Inisisator     :%d",kegiatan.id_inisiator);
        gotoxy(50,25);printf("Nama Inisiator    :%s",kegiatan.namainisiator);
        gotoxy(50,26);printf("Nama Kegiatan     :%s",kegiatan.Nama_Kegiatan);
        gotoxy(50,27);printf("Total Uang        :Rp ");RP(kegiatan.total_uang);
        gotoxy(50,28);printf("Status            :%s",kegiatan.status);

		gotoxy(50,30); printf("Pilih data yang akan diupdate ");
		gotoxy(50,31); printf("[1] Nama Kegiatan ");
		gotoxy(50,32); printf("[2] Total Uang ");
		gotoxy(50,33); printf("[3] Status ");
		a:
        gotoxy(58,34);printf("    ");
		gotoxy(50,34); printf("Pilih = "); fflush(stdin);
		scanf("%d", &a);
		if (a == 0)
		{
		   system("cls");
		   MenuCRUDPengajuankegiatan();
		}
		else if (a==1)
		{
			gotoxy(50,36); printf("Masukkan Nama Kegiatan Baru : "); getteks (kegiatan.Nama_Kegiatan,50);
			if(strcmp(kegiatan.Nama_Kegiatan, "0")==0)
            {
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
			fwrite(&kegiatan,sizeof(kegiatan),1,Temp);
			fread(&kegiatan,sizeof(kegiatan),1,UpdateKegiatan);

			while(!feof(UpdateKegiatan))
			{
				fwrite(&kegiatan,sizeof(kegiatan),1,Temp);
				fread(&kegiatan,sizeof(kegiatan),1,UpdateKegiatan);
			}
		}

		else if (a==2)
		{
			gotoxy(50,36); printf("Masukkan Total Uang Baru : Rp "); getRp(&kegiatan.total_uang,1,20,80,36);fflush(stdin);
			fwrite(&kegiatan,sizeof(kegiatan),1,Temp);
			fread(&kegiatan,sizeof(kegiatan),1,UpdateKegiatan);

			while(!feof(UpdateKegiatan))
			{
				fwrite(&kegiatan,sizeof(kegiatan),1,Temp);
				fread(&kegiatan,sizeof(kegiatan),1,UpdateKegiatan);
			}
		}
		else if (a==3)
		{
            ulang_status:
            gotoxy(70,38);printf("    ");
            gotoxy(50,36); printf("[1] Progres");
            gotoxy(50,37); printf("[2] Selesai");
            gotoxy(50,38); printf("Pilih Status Baru : "); fflush(stdin); getnum(&pilih,1);
            if(pilih == 0)
            {
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
            switch (pilih)
            {
                case 1 :strcpy(kegiatan.status,"PROGRES");
                        break;
                case 2 :strcpy(kegiatan.status,"SELESAI");
                        break;
                case 0 :system("cls");
                        MenuCRUDPengajuankegiatan();
                break;
                default: MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                        goto ulang_status;
            }
			fwrite(&kegiatan,sizeof(kegiatan),1,Temp);
			fread(&kegiatan,sizeof(kegiatan),1,UpdateKegiatan);

			while(!feof(UpdateKegiatan))
			{
				fwrite(&kegiatan,sizeof(kegiatan),1,Temp);
				fread(&kegiatan,sizeof(kegiatan),1,UpdateKegiatan);
			}
		}
        else
		{
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
		    goto a;
		}
		fclose(UpdateKegiatan);
		fclose(Temp);

		Temp = fopen("dat/tempo.dat", "rb");
		UpdateKegiatan= fopen("dat/ArsPengajuanKegiatan.dat", "wb");

		fread (&kegiatan, sizeof(kegiatan),1,Temp);
		while(!feof(Temp))
		{
			fwrite (&kegiatan,sizeof (kegiatan),1,UpdateKegiatan);
			fread (&kegiatan, sizeof (kegiatan),1,Temp);
		}

		fclose(UpdateKegiatan);
		fclose(Temp);

		jawaban:
        gotoxy(82,40); printf(" ");
        gotoxy(50,40); printf("Ingin update data lagi [Y/N] : ");
        gotoxy(81,40);printf("["); gotoxy(83,40);printf("]");
        gotoxy(82,40);getteks(jawaban,1);

        if (strcmp(jawaban,"0")==0)
        {
            system("cls");
            MenuCRUDPengajuankegiatan();
        }
        else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            UpdateTransPengajuanKegiatan();
        }
        else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDPengajuankegiatan();
        }
        else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }
    }
    else
    {
        MessageBox(NULL, "ID Kegiatan Belum Terdaftar!", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto ulang_cari;
    }
}


void Lihatinisiator()
{
    //DECLARATION
    int y,i;

    //ALGORITM
    ArsipINS= fopen("dat/ArsInisiator.dat", "rb");
    gotoxy(125,16); printf("=====Lihat Inisiator=====");
    gotoxy(121,15);	printf("______________________________");
    gotoxy(122,18); printf("ID");
    gotoxy(132,18); printf("Nama");
    gotoxy(121,17); printf("______________________________");
    y = 20;
    for (i=16;i<=45;i++) // buat nama di atas
	{
		gotoxy(120,i);
		printf("|",127);
	}
	for (i=16;i<=45;i++) // buat nama di atas
	{
		gotoxy(151,i);
		printf("|",127);
	}
	for (i=121;i<=150;i++) // buat nama di atas
	{
		gotoxy(i,45);
		printf("_",127);
	}
   while (fread(&Inisiator, sizeof (Inisiator),1,ArsipINS)==1){
        gotoxy(122,y); fflush(stdin); printf("ISR%d ", Inisiator.id_inisiator);
        gotoxy(132,y); fflush(stdin); printf("%s ", Inisiator.Full_Nama);
        y=y+1;
    }fclose(ArsipINS);
}

void DeleteTransPengajuanKegiatan()
{
	//DECLARATION
	int cari_id, found,ulang_cari;
	char jawaban[10],yakin[10];
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Hapus Data Kegiatan");
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
	Temp = fopen ("dat/tempo.dat", "wb");
	deleteKegiata = fopen ("dat/ArsPengajuanKegiatan.dat", "rb");

	ulang_cari:
    gotoxy(86,21); printf("    ");
	gotoxy(50,21); printf("Masukkan ID yang ingin dihapus : TKG");
    scanf("%d", &cari_id);
    found = false;

    if (cari_id == 0)
    {
        system("cls");
        MenuCRUDPengajuankegiatan();
    }else if (cari_id != 0)
    {
        fread(&kegiatan, sizeof (kegiatan),1,deleteKegiata);
        while(!found && !feof(deleteKegiata))
        {
            if (kegiatan.id_kegiatan == cari_id)
            {
                found = true;
            }
            else
            {
                fwrite(&kegiatan, sizeof (kegiatan),1,Temp);
                fread(&kegiatan,sizeof(kegiatan),1,deleteKegiata);
            }
        }
        if (found == true)
        {
            gotoxy(50,23);printf("Nama Kasir        :%s",kegiatan.namakasir);
            gotoxy(50,24);printf("Kode Transaksi    :TKG%d",kegiatan.id_kegiatan);
            gotoxy(50,25);printf("Tanggal           :%d/%d/%d   %d:%d:%d ",kegiatan.tanggal, kegiatan.bulan, kegiatan.tahun, kegiatan.jam, kegiatan.menit, kegiatan.detik);
            gotoxy(50,26);printf("Id Inisisator     :ISR%d",kegiatan.id_inisiator);
            gotoxy(50,27);printf("Nama Inisiator    :%s",kegiatan.namainisiator);
            gotoxy(50,28);printf("Nama Kegiatan     :%s",kegiatan.Nama_Kegiatan);
            gotoxy(50,29);printf("Total Uang        :Rp "); RP(kegiatan.total_uang);
            gotoxy(50,30);printf("Status            :%s",kegiatan.status);

            yakin:
            gotoxy(89,32); printf(" ");
			gotoxy(50,32); printf("APAKAH YAKIN INGIN MENGHAPUS? [Y/N]: ");
            gotoxy(88,32); printf("["); gotoxy(90,32);printf("]");
            gotoxy(89,32); getteks(yakin,1);

            if(strcmp(yakin,"0")==0)
            {
                system("cls");
                MenuCRUDPengajuankegiatan();
            }
            else if ((strcmp(yakin,"n")==0) || (strcmp(yakin,"N")==0))
            {
                system("cls");
                MenuCRUDPengajuankegiatan();
            }else if ((strcmp(yakin,"y")==0) || (strcmp(yakin,"Y")==0))
            {
                fread(&kegiatan, sizeof(kegiatan),1,deleteKegiata);
                while(!feof(deleteKegiata))
                {
                    fwrite(&kegiatan, sizeof (kegiatan),1,Temp);
                    fread(&kegiatan, sizeof(kegiatan),1,deleteKegiata);
                }

                fclose(Temp);
                fclose(deleteKegiata);

                deleteKegiata = fopen("dat/ArsPengajuanKegiatan.dat","wb");
                Temp = fopen("dat/tempo.dat","rb");

                fread(&kegiatan, sizeof(kegiatan),1,Temp);
                while(!feof(Temp))
                {
                    fwrite(&kegiatan, sizeof(kegiatan),1,deleteKegiata);
                    fread(&kegiatan, sizeof(kegiatan),1,Temp);
                }fclose(deleteKegiata);
                 fclose(Temp);

            }else{
                MessageBox(NULL, "Inputan Tidak Sesuai !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto yakin;
            }


        }
        else
        {
            MessageBox(NULL, "ID Kegiatan Belum Terdaftar !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto ulang_cari;
        }
    }

    jawaban:
    gotoxy(82,34); printf(" ");
    gotoxy(50,34); printf("Ingin hapus data lagi [Y/N] : ");
    gotoxy(81,34);printf("["); gotoxy(83,34);printf("]");
    gotoxy(82,34);getteks(jawaban,1);

    if (strcmp(jawaban,"0")==0)
    {
        system("cls");
        MenuCRUDPengajuankegiatan();
    }
    else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
    {
        system("cls");
        DeleteTransPengajuanKegiatan();
    }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
    {
        MessageBox(NULL, "Terima Kasih", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        MenuCRUDPengajuankegiatan();
    }
    else
    {
        MessageBox(NULL, "Inputan Tidak Sesuai !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto jawaban;
    }

}

void LaporanTransaksiPengajuanKegiatan()
{
    // DECLARATION
    int y,loop,total=0;
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    TransKegiatan = fopen("dat/ArsPengajuanKegiatan.dat","rb");
	gotoxy(80,14); printf("=====Laporan Pengajuan Kegiatan=====");
    gotoxy(35,15); printf("================================================================================================================================");
    gotoxy(36,16); printf("ID Kegiatan  Nama Inisiator  Nama Kegiatan           Total Uang      Tanggal Pengajuan  Tanggal Transaksi  Status   Nama Kasir");
    gotoxy(35,17); printf("================================================================================================================================");
    gotoxy(35,40); printf("================================================================================================================================");

     y= 19;
    fread(&kegiatan, sizeof(kegiatan),1,TransKegiatan);
    while(!feof(TransKegiatan))
    {fread(&kegiatan, sizeof(kegiatan),1,TransKegiatan);
        loop++;
    }
    fclose(TransKegiatan);
    if(loop == 0)
    {
        gotoxy(110,25); printf("Data Kegiatan Tidak Ada!");
    }
    else
    {
        TransKegiatan = fopen("dat/ArsPengajuanKegiatan.dat","rb");
        while (fread(&kegiatan,sizeof(kegiatan),1,TransKegiatan) == 1){
            gotoxy(38,y); printf("TKG%d",kegiatan.id_kegiatan);
            gotoxy(51,y); printf("%s",kegiatan.namainisiator);
            gotoxy(65,y); printf("%s",kegiatan.Nama_Kegiatan);
            gotoxy(89,y); printf("Rp "); RP(kegiatan.total_uang);
            gotoxy(107,y); printf("%d/%d/%d",kegiatan.tanggalpengajuan,kegiatan.bulanpengajuan,kegiatan.tahunpengajuan);
            gotoxy(128,y); printf("%d/%d/%d",kegiatan.tanggal,kegiatan.bulan,kegiatan.tahun);
            gotoxy(152,y); printf("%s",kegiatan.namakasir);
            gotoxy(143,y); printf("%s",kegiatan.status);

             y= y+1;
            total = kegiatan.total_uang + total;
        }fclose(TransKegiatan);
        gotoxy(41,41),printf("JUMLAH UANG:\t\t\t\t\t     Rp "); RP(total);
    }

}
