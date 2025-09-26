//CRUD YAYASAN//
structYayasan Yayasan;
structYayasan ValidasiYayasan;//untuk validasi di tambah
structYayasan UpYayasan; // untuk validasi di update

FILE *DataYayasan;
FILE *Temp;
FILE *validasiNoPokok;

 void MenuCRUDYayasan ()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

	//ALGORITM
    BacaYayasan();
	gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(7,15);	printf("Kelola Data Yayasan");
	gotoxy(4,17);	printf("[1] Tambah Data Yayasan");
	gotoxy(4,18);	printf("[2] Update Data Yayasan");
	gotoxy(4,19);	printf("[3] Hapus Data Yayasan");
	gotoxy(4,20);	printf("[4] Kembali");
	gotoxy(4,21);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&Menu,1);
	switch (Menu)
	{
		case 1 : system("cls");
				 TambahYayasan();
				 break;
		case 2 : system("cls");
				 UpdateYayasan();
				 break;
		case 3 : system("cls");
				 HapusYayasan();
				 break;
		case 4 : system("cls");
                 MenuAdmin ();
				 break;
		case 5 : system("cls");
				PrintFile("txt/thankyou.txt", 58,18);
				exit(0);
                break;
		default : MessageBox(NULL, "Pilihan Tidak Ada ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                  MenuCRUDYayasan ();
                  break;
	}
}


 void TambahYayasan()
 {
    //DECLARATION
    char jawaban[10],temp_nopokok[20];
    int Last_id,loop=0,found,ulang_NO;
    OutterBorder();
    system("color 8E");

    //ALGORITM
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
	gotoxy(12,10);	printf("%s",login.fullname);
    DataYayasan= fopen("dat/ArsYayasan.dat","ab+");
    fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
    while(!feof(DataYayasan))
    {
        fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
        Last_id= Yayasan.id_Yayasan;
        loop++;
    }
    if(loop == 0)
    {
        Yayasan.id_Yayasan = 1;
    }
    else
    {
        Yayasan.id_Yayasan = Last_id+ 1;
    }

    fclose(DataYayasan);
    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Tambah Data Yayasan");
    /*---------ID----------*/
    gotoxy(50,21); printf("ID     : YYS%d\n", Yayasan.id_Yayasan);

     /*---------NomorPokokYayasan----------*/\
    ulang_NO:
    gotoxy(69,23); printf("      ");
    gotoxy(50,23); printf("No Pokok Yayasan : "); fflush(stdin); getteks(temp_nopokok,6);
    if(strcmp(temp_nopokok, "0")==0)
    {
        system("cls");
        MenuCRUDYayasan();
    }
    //VALIDASI No.Pokok Yayasan//
     validasiNoPokok = fopen("dat/ArsYayasan.dat", "rb");

    found = 0;
    while(fread(&ValidasiYayasan, sizeof(ValidasiYayasan),1,validasiNoPokok)==1){
        if(strcmp(temp_nopokok, ValidasiYayasan.NoPokok) == 0){
           found = 1;
        }
    }

    if(found == 1) {
        MessageBox(NULL, "No.Pokok Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto ulang_NO;
    }
    fclose(validasiNoPokok);
    strcpy(Yayasan.NoPokok, temp_nopokok);
    //SELESI VALIDASI No.Pokok Yayasan//
    /*---------Nama----------*/
    gotoxy(50,25); printf("Nama   : "); fflush(stdin); getteks(Yayasan.Nama,50);
    if(strcmp(Yayasan.Nama, "0")==0)
    {
        system("cls");
        MenuCRUDYayasan();
    }

    /*---------NoTelp----------*/
    gotoxy(50,27); printf("NoTelp : "); fflush(stdin); getteksnum(Yayasan.NoTelp,13);
    if(strcmp(Yayasan.NoTelp, "0")==0)
    {
        system("cls");
        MenuCRUDYayasan();
    }
    /*---------Alamat----------*/
    gotoxy(50,29); printf("Alamat : "); fflush(stdin); getteks(Yayasan.alamat,50);
    if(strcmp(Yayasan.alamat, "0")==0)
    {
        system("cls");
        MenuCRUDYayasan();
    }
    DataYayasan = fopen("dat/ArsYayasan.dat", "ab");
    fwrite(&Yayasan, sizeof(Yayasan),1, DataYayasan);
    fclose(DataYayasan);
    MessageBox(NULL, "Data Berhasil Disimpan ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    jawaban:
    gotoxy(82,31); printf(" ");
    gotoxy(50,31); printf("Ingin Tambah data lagi [Y/N] : ");
    gotoxy(81,31);printf("["); gotoxy(83,31);printf("]");
    gotoxy(82,31);getteks(jawaban,1);
    if (strcmp(jawaban,"0")==0)
    {
        system("cls");
        MenuCRUDYayasan();
    }
    else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
    {
        system("cls");
        TambahYayasan();
    }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
    {
        MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        MenuCRUDYayasan();
    }
    else
    {
        MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto jawaban;
    }
 }

 void BacaYayasan()
 {
    //Deklarasi
    int  loop = 0, y;
    OutterBorder();
	system("color 8E");

	//Algoritma
    DataYayasan= fopen("dat/ArsYayasan.dat", "rb");
    gotoxy(40,14); printf("\t\t\t\t\t=====Lihat Data Yayasan=====");
    gotoxy(40,15);printf("====================================================================================================================");
    gotoxy(41,16); printf("ID\t\tNo.Pokok\tNama\t\t\t\tNo.Telpt\tAlamat");
    gotoxy(40,17);printf("====================================================================================================================");
    y = 19;

    fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
    while(!feof(DataYayasan))
    {fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
        loop++;
    }
    fclose(DataYayasan);
    if(loop == 0)
    {
        gotoxy(110,25); printf("Data Yayasan Tidak Ada!");
    }
    else
    {
        DataYayasan = fopen("dat/ArsYayasan.dat", "rb");
        fread(&Yayasan, sizeof(Yayasan), 1,DataYayasan);
        while (!feof(DataYayasan)){

            gotoxy(41,y); fflush(stdin); printf("YYS%d ", Yayasan.id_Yayasan);
            gotoxy(56,y); fflush(stdin); printf("%s ", Yayasan.NoPokok);
            gotoxy(72,y); fflush(stdin); printf("%s ", Yayasan.Nama);
            gotoxy(104,y); fflush(stdin); printf("%s ", Yayasan.NoTelp);
            gotoxy(120,y); fflush(stdin); printf("%s ", Yayasan.alamat);

            y=y+1;
            fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
        }fclose(DataYayasan);

    }

 }
 void UpdateYayasan()
 {
	//DECLARATION
	int a, cari_id, found,ulang_NO;
	char jawaban[10],temp_nopokok[20];
    OutterBorder();
	system("color 8E");

	//Algoritma
	gotoxy(58,44),printf("Klik '0' untuk Batal...");
	gotoxy(12,10);	printf("%s",login.fullname);
    DataYayasan = fopen ("dat/ArsYayasan.dat", "rb");
	Temp = fopen ("dat/tempo.dat", "wb");
    kotakCRUDTransaksi();
    cari_id:
    gotoxy(85,21); printf("    ");
    gotoxy(57,16); printf("Update Data Yayasan");
	gotoxy(50,21); printf("Masukkan ID yang ingin diubah = YYS");
	scanf("%d", &cari_id);
	found = 0;

	if (cari_id == 0)
    {
        system("cls");
        MenuCRUDYayasan();
    }
    else if(cari_id !=0)
    {
        while ((!found )&& (!feof(DataYayasan)))
        {
            fread (&Yayasan, sizeof (Yayasan), 1, DataYayasan);
            if(Yayasan.id_Yayasan == cari_id)
            {
                found = 1;
            }
            else
            {
                fwrite (&Yayasan, sizeof (Yayasan),1,Temp);
            }
        }
    }

    if(found == 1)
	{

		gotoxy(50,23); printf("ID     = YYS%d ", Yayasan.id_Yayasan);
		gotoxy(50,24); printf("No.Pokok   = %s ", Yayasan.NoPokok);
		gotoxy(50,25); printf("Nama   = %s ", Yayasan.Nama);
		gotoxy(50,26); printf("No.Telp = %s ", Yayasan.NoTelp);
		gotoxy(50,27); printf("Alamat = %s ", Yayasan.alamat);


		gotoxy(50,29); printf("Pilih data yang akan diupdate ");
        gotoxy(50,30); printf("[1] No.Pokok  ");
		gotoxy(50,31); printf("[2] Nama  ");
		gotoxy(50,32); printf("[3] No Telp  ");
		gotoxy(50,33); printf("[4] Alamat  ");
		a:
        gotoxy(58,34);printf("  ");
		gotoxy(50,34); printf("Pilih = "); getnum(&a,1);

		if (a == 0)
        {
            system("cls");
            MenuCRUDYayasan();
        }

        else if(a==1)
		{
		    temp_nopokok:
		    gotoxy(74,36); printf("       ");
			gotoxy(50,36); printf("Masukkan No.Pokok Baru : "); getteks(temp_nopokok,6);
			if(strcmp(temp_nopokok, "0")==0)
            {
                system("cls");
                MenuCRUDYayasan();
            }
            //VALIDASI No.Pokok Yayasan//
             validasiNoPokok = fopen("dat/ArsYayasan.dat", "rb");

            found = 0;
            while(fread(&UpYayasan, sizeof(UpYayasan),1,validasiNoPokok)==1){
                if(strcmp(temp_nopokok, UpYayasan.NoPokok) == 0){
                   found = 1;
                }
            }

            if(found == 1) {
                MessageBox(NULL, "No.Pokok Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto temp_nopokok;
            }
            fclose(validasiNoPokok);
            strcpy(Yayasan.NoPokok, temp_nopokok);
            //SELESI VALIDASI No.Pokok Yayasan//

			fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
			fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);

			while(!feof(DataYayasan))
			{
				fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
				fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);
			}
		}
		if(a==2)
		{
			gotoxy(50,36); printf("Masukkan Nama Baru : "); getteks(Yayasan.Nama,50);
			if(strcmp(Yayasan.Nama, "0")==0)
            {
                system("cls");
                MenuCRUDYayasan();
            }
			fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
			fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);

			while(!feof(DataYayasan))
			{
				fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
				fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);
			}
		}
		else if (a==3)
		{
			gotoxy(50,36); printf("Masukkan NoTelp Baru : "); getteksnum(Yayasan.NoTelp,13);
			if(strcmp(Yayasan.NoTelp, "0")==0)
            {
                system("cls");
                MenuCRUDYayasan();
            }
			fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
			fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);

			while(!feof(DataYayasan))
			{
				fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
				fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);
			}
		}
        else if (a==4)
		{
			gotoxy(50,38); printf("Masukkan Alamat Baru : "); getteks(Yayasan.alamat,50);
			if(strcmp(Yayasan.alamat, "0")==0)
            {
                system("cls");
                MenuCRUDYayasan();
            }
			fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
			fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);

			while(!feof(DataYayasan))
			{
				fwrite(&Yayasan,sizeof(Yayasan),1,Temp);
				fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);
			}
		}
        else
		{
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
			goto a;
		}
    }
    else
    {
        MessageBox(NULL, "ID Yayasan Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto cari_id;
    }
		fclose(DataYayasan);
		fclose(Temp);

		Temp = fopen("dat/tempo.dat", "rb");
		DataYayasan= fopen("dat/ArsYayasan.dat", "wb");

		fread (&Yayasan, sizeof(Yayasan),1,Temp);
		while(!feof(Temp))
		{
			fwrite (&Yayasan,sizeof (Yayasan),1,DataYayasan);
			fread (&Yayasan, sizeof (Yayasan),1,Temp);
		}

		fclose(DataYayasan);
		fclose(Temp);
        jawaban:
        gotoxy(82,40);printf(" ");
        gotoxy(50,40); printf("Ingin update data lagi [Y/N] : ");
        gotoxy(81,40);printf("["); gotoxy(83,40);printf("]");
        gotoxy(82,40);getteks(jawaban,1);

        if(strcmp(jawaban,"0")==0)
        {
            system("cls");
            MenuCRUDYayasan();
        }
        else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            UpdateYayasan();
        }
         else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDYayasan();
        }
        else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }

}

void HapusYayasan()
{
	//DECLARATION
	int found = 0, cari_id;
	char jawaban[10],yakin[10];
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
	gotoxy(12,10);	printf("%s",login.fullname);
    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Hapus Data Yayasan");
	Temp = fopen ("dat/tempo.dat", "wb");
	DataYayasan = fopen ("dat/ArsYayasan.dat", "rb");

	cari_id:
    gotoxy(86,21); printf("    ");
	gotoxy(50,21); printf("Masukkan ID yang ingin dihapus : YYS");
    scanf("%d", &cari_id);
    found = false;

    if (cari_id == 0)
    {
        system("cls");
        MenuCRUDYayasan();
    }else if (cari_id != 0)
    {
        fread(&Yayasan, sizeof (Yayasan),1,DataYayasan);
        while(!found && !feof(DataYayasan))
        {
            if (Yayasan.id_Yayasan == cari_id)
            {
                found = true;
            }
            else
            {
                fwrite(&Yayasan, sizeof (Yayasan),1,Temp);
                fread(&Yayasan,sizeof(Yayasan),1,DataYayasan);
            }
        }
        if (found == true)
        {
            gotoxy(50,23); printf("ID     = DNT%d ", Yayasan.id_Yayasan);
            gotoxy(50,25); printf("Nama   = %s ", Yayasan.Nama);
			gotoxy(50,27); printf("NoTelp = %s ", Yayasan.NoTelp);

			yakin:
            gotoxy(89,29); printf(" ");
			gotoxy(50,29); printf("APAKAH YAKIN INGIN MENGHAPUS? [Y/N]: ");
            gotoxy(88,29); printf("["); gotoxy(90,29);printf("]");
            gotoxy(89,29); getteks(yakin,1);
            if(strcmp(yakin,"0")==0)
            {
                system("cls");
                MenuCRUDYayasan();
            }
            else if ((strcmp(yakin,"n")==0) || (strcmp(yakin,"N")==0))
            {
                system("cls");
                MenuCRUDYayasan();
            }else if ((strcmp(yakin,"y")==0) || (strcmp(yakin,"Y")==0))
            {
                fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
                while(!feof(DataYayasan))
                {
                    fwrite(&Yayasan, sizeof (Yayasan),1,Temp);
                    fread(&Yayasan, sizeof(Yayasan),1,DataYayasan);
                }

                fclose(Temp);
                fclose(DataYayasan);

                DataYayasan = fopen("dat/ArsYayasan.dat","wb");
                Temp = fopen("dat/tempo.dat","rb");

                fread(&Yayasan, sizeof(Yayasan),1,Temp);
                while(!feof(Temp))
                {
                    fwrite(&Yayasan, sizeof(Yayasan),1,DataYayasan);
                    fread(&Yayasan, sizeof(Yayasan),1,Temp);
                }
                fclose(DataYayasan);
                fclose(Temp);
            }else
            {
                MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto yakin;
            }

        }
        else
        {
            MessageBox(NULL, "ID Yayasan Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto cari_id;
        }
    }
    jawaban:
    gotoxy(81,31); printf(" ");
    gotoxy(50,31); printf("Ingin hapus data lagi [Y/N] : ");
    gotoxy(80,31);printf("["); gotoxy(82,31);printf("]");
    gotoxy(81,31);getteks(jawaban,1);

    if (strcmp(jawaban,"0")==0)
        {
             system("cls");
             MenuCRUDInisiator();
        }
    else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            HapusYayasan();
        }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDYayasan();
        }
    else
        {
            MessageBox(NULL, "Inputan Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }

}






