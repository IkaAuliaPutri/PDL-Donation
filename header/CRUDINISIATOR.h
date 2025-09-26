//CRUD INISIATOR//

structinisiator Inisiator;
structinisiator validNIK;//untuk validasi di tambah
structinisiator upvalidNIK;//validasi untuk di update
FILE *DataINS;
FILE *Temp;
FILE *ValidasiNIK;//untuk validasi di tambah

 void MenuCRUDInisiator ()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

	//ALGORITM
	BacaInisiator();
	gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(5,15);	printf("Kelola Data Inisiator");
	gotoxy(4,17);	printf("[1] Tambah Data Inisiator");
	gotoxy(4,18);	printf("[2] Update Data Inisiator");
	gotoxy(4,19);	printf("[3] Hapus Data Inisiator");
	gotoxy(4,20);	printf("[4] Kembali");
	gotoxy(4,21);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&Menu,1);
	switch (Menu)
	{
		case 1 : system("cls");
                TambahInisiator();
                break;
		case 2 : system("cls");
                UpdateInisiator();
                break;
		case 3 : system("cls");
                HapusInisiator();
                break;
		case 4 : system("cls");
                MenuAdmin ();
                break;
		case 5 : system("cls");
                PrintFile("txt/thankyou.txt", 58,18);
                exit(0);break;
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                MenuCRUDInisiator ();
                break;
	}
}


 void TambahInisiator()
 {
    //DECLARATION
    char jawaban[10],temp_NIK[20];
    int Last_id,loop=0,found_user,ulang_NIK;
    OutterBorder();
    system("color 8E");

    //ALGORITM
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
    gotoxy(12,10);	printf("%s",login.fullname);

    DataINS= fopen("dat/ArsInisiator.dat","ab+");
    fread(&Inisiator, sizeof(Inisiator),1,DataINS);
    while(!feof(DataINS))
    {
        fread(&Inisiator, sizeof(Inisiator),1,DataINS);
        Last_id = Inisiator.id_inisiator;
        loop++;
    }
    if(loop == 0)
    {
        Inisiator.id_inisiator = 1;
    }
    else
    {
        Inisiator.id_inisiator = Last_id+ 1;
    }

    fclose(DataINS);

    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Tambah Data Inisisator");

    /*---------ID----------*/
    gotoxy(50,21); printf("ID    : ISR%d\n", Inisiator.id_inisiator);

    /*---------NIK----------*/
    ulang_NIK:
    gotoxy(58,23); printf("                ");
    gotoxy(50,23); printf("NIK   : "); fflush(stdin); getteksnum(temp_NIK,16);
    if(strcmp(temp_NIK, "0")==0)
    {
        system("cls");
        MenuCRUDInisiator();
    }
    //VALIDASI NIK//
     ValidasiNIK = fopen("dat/ArsInisiator.dat", "rb");

    found_user = 0;
    while(fread(&validNIK, sizeof(validNIK),1,ValidasiNIK)==1){
        if(strcmp(temp_NIK, validNIK.Nik) == 0){
           found_user = 1;
        }
    }

    if(found_user == 1) {
        MessageBox(NULL, "NIK Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto ulang_NIK;
    }
    fclose(ValidasiNIK);
    strcpy(Inisiator.Nik, temp_NIK);
     //SELESAI VALIDASI NIK//
    /*---------Nama----------*/
    gotoxy(50,25); printf("Nama  : "); fflush(stdin); getletter(Inisiator.Full_Nama,30);
    if(strcmp(Inisiator.Full_Nama, "0")==0)
    {
        system("cls");
        MenuCRUDInisiator();
    }
    /*---------Umur----------*/
    gotoxy(61,27); printf("Tahun"); gotoxy(50,27); printf("Umur  : "); fflush(stdin); getnum(&Inisiator.Umur,2);
    if(Inisiator.Umur == 0)
    {
        system("cls");
        MenuCRUDInisiator();
    }
    /*---------NoTelp----------*/
    gotoxy(50,29); printf("NoTelp : "); fflush(stdin); getteksnum(Inisiator.NoTelp,13);
    if(strcmp(Inisiator.NoTelp, "0")==0)
    {
        system("cls");
        MenuCRUDInisiator();
    }


    DataINS = fopen("dat/ArsInisiator.dat", "ab");
    fwrite(&Inisiator, sizeof(Inisiator),1, DataINS);
    fclose(DataINS);
    MessageBox(NULL, "Data Berhasil Disimpan ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    jawaban:
    gotoxy(82,31);printf(" ");
    gotoxy(50,31); printf("Ingin Tambah data lagi [Y/N] : ");
    gotoxy(81,31);printf("["); gotoxy(83,31);printf("]");
    gotoxy(82,31);getteks(jawaban,1);
     if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            TambahInisiator();
        }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDInisiator();
        }
    else if(strcmp(jawaban,"0")==0)
        {
            system("cls");
            MenuCRUDInisiator();
        }
    else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }

 }

 void BacaInisiator()
 {
    //DECLARATION
    int y, loop = 0;
    OutterBorder();
	system("color 8E");

    //ALGORITM
    DataINS= fopen("dat/ArsInisiator.dat", "rb");
    gotoxy(40,14); printf("\t\t\t\t\t=====Lihat Data Inisiator=====");
    gotoxy(40,15);	printf("====================================================================================================================");
    gotoxy(41,16); printf("      ID\t\tNIK\t\t\tNama\t\t\tUmur\t\t\tNo Telp");
    gotoxy(40,17);	printf("====================================================================================================================");
    y = 19;

    fread(&Inisiator, sizeof(Inisiator),1,DataINS);
    while(!feof(DataINS))
    {fread(&Inisiator, sizeof(Inisiator),1,DataINS);
        loop++;
    }
    fclose(DataINS);
    if(loop == 0)
    {
        gotoxy(110,25); printf("Data Inisiator Tidak Ada!");
    }
    else
    {
        DataINS = fopen("dat/ArsInisiator.dat", "rb");
        while(fread(&Inisiator, sizeof(Inisiator), 1,DataINS)==1){
            gotoxy(47,y); fflush(stdin); printf("ISR%d ", Inisiator.id_inisiator);
            gotoxy(64,y); fflush(stdin); printf("%s", Inisiator.Nik);
            gotoxy(88,y); fflush(stdin); printf("%s", Inisiator.Full_Nama);
            gotoxy(113,y); fflush(stdin); printf("%d Tahun", Inisiator.Umur);
            gotoxy(136,y); fflush(stdin); printf("%s", Inisiator.NoTelp);
            y=y+1;
        }fclose(DataINS);

    }
 }
 void UpdateInisiator()
 {
	//DECLARATION
	int a, cari_id,found,ulang_NIK;
	char jawaban[10];
    OutterBorder();
	system("color 8E");

	//ALGORITM
	gotoxy(58,44),printf("Klik '0' untuk Batal...");
	gotoxy(12,10);	printf("%s",login.fullname);

    DataINS = fopen ("dat/ArsInisiator.dat", "rb");
	Temp = fopen ("dat/tempo.dat", "wb");

	kotakCRUDTransaksi();
	cari_id:
    gotoxy(75,21); printf("    ");
    gotoxy(57,16); printf("Update Data Inisiator");
	gotoxy(50,21); printf("Masukkan ID yang ingin diubah = ISR");
	scanf("%d", &cari_id);
	found = 0;
	if (cari_id == 0)
    {
        system("cls");
        MenuCRUDInisiator();
    }
    else if (cari_id !=0)
    {
        while ((!found )&& (!feof(DataINS)))
        {
            fread (&Inisiator, sizeof (Inisiator), 1, DataINS);
            if(Inisiator.id_inisiator == cari_id)
            {
                found = 1;
            }
            else
            {
                fwrite (&Inisiator, sizeof (Inisiator),1,Temp);
            }
        }
    }

    if(found == 1)
	{

		gotoxy(50,23); printf("ID     = ISR%d ", Inisiator.id_inisiator);
		gotoxy(50,24); printf("NIK   = %s ", Inisiator.Nik);
		gotoxy(50,25); printf("Nama   = %s ", Inisiator.Full_Nama);
		gotoxy(50,26); printf("Umur   = %d ", Inisiator.Umur);
		gotoxy(50,27); printf("NoTelp = %s ", Inisiator.NoTelp);

		gotoxy(50,29); printf("Pilih data yang akan diupdate ");
		gotoxy(50,30); printf("[1] NIK  ");
		gotoxy(50,31); printf("[2] Nama  ");
		gotoxy(50,32); printf("[3] Umur  ");
		gotoxy(50,33); printf("[4] No Telp  ");
		a:
        gotoxy(58,34); printf("   ");
		gotoxy(50,34); printf("Pilih = "); fflush(stdin);
		scanf("%d", &a);
        if (a== 0)
        {
            system("cls");
            MenuCRUDInisiator();
        }
        else if(a==1)
		{
		    char temp_NIK[20];
		    ulang_NIK:
		    gotoxy(70,36); printf("                ");
			gotoxy(50,36); printf("Masukkan NIK Baru : "); getteksnum(temp_NIK,16);
			if(strcmp(temp_NIK, "0")==0)
            {
                system("cls");
                MenuCRUDInisiator();
            }
            //VALIDASI NIK//
             ValidasiNIK = fopen("dat/ArsInisiator.dat", "rb");

            int found_user = 0;
            while(fread(&upvalidNIK, sizeof(upvalidNIK),1,ValidasiNIK)==1){
                if(strcmp(temp_NIK, upvalidNIK.Nik) == 0){
                   found_user = 1;
                }
            }

            if(found_user == 1) {
                MessageBox(NULL, "NIK Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto ulang_NIK;
            }
            fclose(ValidasiNIK);
            strcpy(Inisiator.Nik, temp_NIK);
            //SELESAI VALIDASI NIK//
			fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
			fread(&Inisiator,sizeof(Inisiator),1,DataINS);

			while(!feof(DataINS))
			{
				fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
				fread(&Inisiator,sizeof(Inisiator),1,DataINS);
			}
		}
		else if(a==2)
		{
			gotoxy(50,36); printf("Masukkan Nama Baru : "); getletter(Inisiator.Full_Nama,30);
			if(strcmp(Inisiator.Full_Nama, "0")==0)
            {
                system("cls");
                MenuCRUDInisiator();
            }
			fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
			fread(&Inisiator,sizeof(Inisiator),1,DataINS);

			while(!feof(DataINS))
			{
				fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
				fread(&Inisiator,sizeof(Inisiator),1,DataINS);
			}
		}
		else if(a==3)
		{
			gotoxy(50,36); printf("Masukkan Umur Baru : "); getnum(&Inisiator.Umur,2);
			if(Inisiator.Umur==0)
            {
                system("cls");
                MenuCRUDInisiator();
            }
			fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
			fread(&Inisiator,sizeof(Inisiator),1,DataINS);

			while(!feof(DataINS))
			{
				fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
				fread(&Inisiator,sizeof(Inisiator),1,DataINS);
			}
		}
		else if (a==4)
		{
			gotoxy(50,36); printf("Masukkan NoTelp Baru : "); getteksnum( Inisiator.NoTelp,13);
			if(strcmp(Inisiator.NoTelp, "0")==0)
            {
                system("cls");
                MenuCRUDInisiator();
            }
			fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
			fread(&Inisiator,sizeof(Inisiator),1,DataINS);

			while(!feof(DataINS))
			{
				fwrite(&Inisiator,sizeof(Inisiator),1,Temp);
				fread(&Inisiator,sizeof(Inisiator),1,DataINS);
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
        MessageBox(NULL, "ID Inisiator Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto cari_id;
    }
		fclose(DataINS);
		fclose(Temp);

		Temp = fopen("dat/tempo.dat", "rb");
		DataINS= fopen("dat/ArsInisiator.dat", "wb");

		fread (&Inisiator, sizeof(Inisiator),1,Temp);
		while(!feof(Temp))
		{
			fwrite (&Inisiator,sizeof (Inisiator),1,DataINS);
			fread (&Inisiator, sizeof (Inisiator),1,Temp);
		}

		fclose(DataINS);
		fclose(Temp);

        jawaban:
        gotoxy(82,38); printf(" ");
        gotoxy(50,38); printf("Ingin update data lagi [Y/N] : ");
        gotoxy(81,38);printf("["); gotoxy(83,38);printf("]");
        gotoxy(82,38);getteks(jawaban,1);

        if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            UpdateInisiator();
        }
        else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDInisiator();
        }
        else if (strcmp(jawaban,"0")==0)
        {
            system("cls");
            MenuCRUDInisiator();
        }
        else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }

}

void HapusInisiator()
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
    gotoxy(57,16); printf("Hapus Data Inisisator");

	Temp = fopen ("dat/tempo.dat", "wb");
	DataINS = fopen ("dat/ArsInisiator.dat", "rb");

	cari_id:
    gotoxy(86,21); printf("    ");
	gotoxy(50,21); printf("Masukkan ID yang ingin dihapus : ISR");
    scanf("%d", &cari_id);
    found = false;

    if (cari_id == 0)
    {
        system("cls");
        MenuCRUDInisiator();
    }else if (cari_id != 0)
    {
        fread(&Inisiator, sizeof (Inisiator),1,DataINS);
        while(!found && !feof(DataINS))
        {
            if (Inisiator.id_inisiator == cari_id)
            {
                found = true;
            }
            else
            {
                fwrite(&Inisiator, sizeof (Inisiator),1,Temp);
                fread(&Inisiator,sizeof(Inisiator),1,DataINS);
            }
        }
        if (found == true)
        {
            gotoxy(50,23); printf("ID     = ISR%d ", Inisiator.id_inisiator);
            gotoxy(50,24); printf("Nama   = %s ", Inisiator.Full_Nama);
			gotoxy(50,25); printf("Umur   = %d ", Inisiator.Umur);
			gotoxy(50,26); printf("NoTelp = %s ", Inisiator.NoTelp);

			yakin:
            gotoxy(89,28); printf(" ");
			gotoxy(50,28); printf("APAKAH YAKIN INGIN MENGHAPUS? [Y/N]: ");
            gotoxy(88,28); printf("["); gotoxy(90,28);printf("]");
            gotoxy(89,28); getteks(yakin,1);
            if (strcmp(yakin,"0")==0)
            {
                system("cls");
                MenuCRUDInisiator();
            }
            else if ((strcmp(yakin,"n")==0) || (strcmp(yakin,"N")==0))
            {
                system("cls");
                MenuCRUDInisiator();
            }else if ((strcmp(yakin,"y")==0) || (strcmp(yakin,"Y")==0))
            {
                fread(&Inisiator, sizeof(Inisiator),1,DataINS);
                while(!feof(DataINS))
                {
                    fwrite(&Inisiator, sizeof (Inisiator),1,Temp);
                    fread(&Inisiator, sizeof(Inisiator),1,DataINS);
                }

                fclose(Temp);
                fclose(DataINS);

                DataINS = fopen("dat/ArsInisiator.dat","wb");
                Temp = fopen("dat/tempo.dat","rb");

                fread(&Inisiator, sizeof(Inisiator),1,Temp);
                while(!feof(Temp))
                {
                    fwrite(&Inisiator, sizeof(Inisiator),1,DataINS);
                    fread(&Inisiator, sizeof(Inisiator),1,Temp);
                }
                fclose(DataINS);
                fclose(Temp);
            }else
            {
                    MessageBox(NULL, "Inputan Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                    goto yakin;
            }

        }
        else
        {
            MessageBox(NULL, "ID Inisiator Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto cari_id;
        }
    }
    jawaban:
    gotoxy(82,30);printf(" ");
    gotoxy(50,30); printf("Ingin hapus data lagi [Y/N] : ");
    gotoxy(81,30);printf("["); gotoxy(83,30);printf("]");
    gotoxy(82,30);getteks(jawaban,1);

     if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            HapusInisiator();
        }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDInisiator();
        }
    else if (strcmp(jawaban,"0")==0)
        {
             system("cls");
             MenuCRUDInisiator();
        }
    else
        {
            MessageBox(NULL, "Inputan Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }


}







