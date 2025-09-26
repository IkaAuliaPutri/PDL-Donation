//CRUD DONATUR//
 structdonatur Donatur;
 structdonatur vnik;//validasi NIK di tambah
 structdonatur upVnik;//validasi NIK di update
 FILE *DataDonatur;
 FILE *Temp;
 FILE *validasiNIK;//validasi NIK

 void MenuCRUDDonatur ()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    BacaDonatur();
	gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(7,15);	printf("Kelola Data Donatur");
	gotoxy(4,17);	printf("[1] Tambah Data Donatur");
	gotoxy(4,18);	printf("[2] Update Data Donatur");
	gotoxy(4,19);	printf("[3] Hapus Data Donatur");
	gotoxy(4,20);	printf("[4] Kembali");
	gotoxy(4,21);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&Menu,1);
	switch (Menu)
	{
		case 1 : system("cls");
                 TambahDonatur();
                 break;
		case 2 : system("cls");
                 UpdateDonatur();
                 break;
		case 3 : system("cls");
                 HapusDonatur();
                 break;
		case 4 : system("cls");
                 MenuAdmin ();
                 break;
		case 5 : system("cls");
                 PrintFile("txt/thankyou.txt", 58,18);
                 exit(0);
                 break;
		default : MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                MenuCRUDDonatur ();
                break;
	}
}


 void TambahDonatur()
 {
     //DECLARATION
    char jawaban[10],temp_NIK[20];
    int Last_id,loop=0,found_user,ulang_NIK;
    OutterBorder();
    system("color 8E");

    //ALGORITM
	gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
    DataDonatur= fopen("dat/ArsDonatur.dat","ab+");
    fread(&Donatur, sizeof(Donatur),1,DataDonatur);
    while(!feof(DataDonatur))
    {
        fread(&Donatur, sizeof(Donatur),1,DataDonatur);
        Last_id= Donatur.id_Donatur;
        loop++;
    }
    if(loop == 0)
    {
        Donatur.id_Donatur = 1;
    }
    else
    {
        Donatur.id_Donatur = Last_id+ 1;
    }

    fclose(DataDonatur);

    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Tambah Data Donatur");

    /*---------ID----------*/
    gotoxy(50,21); printf("ID     : DNT%d", Donatur.id_Donatur);

     /*---------NIK----------*/
    ulang_NIK:
    gotoxy(59,23); printf("                ");
    gotoxy(50,23); printf("NIK    : "); fflush(stdin); getteksnum(temp_NIK,16);
    if(strcmp(temp_NIK, "0")==0)
    {
        system("cls");
        MenuCRUDDonatur();
    }
    //VALIDASI NIK//
     validasiNIK = fopen("dat/ArsDonatur.dat", "rb");

    found_user = 0;
    while(fread(&vnik, sizeof(vnik),1,validasiNIK)==1){
        if(strcmp(temp_NIK, vnik.Nik) == 0){
           found_user = 1;
        }
    }

    if(found_user == 1) {
        MessageBox(NULL, "NIK Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
       goto ulang_NIK;
    }
    fclose(validasiNIK);
    strcpy(Donatur.Nik, temp_NIK);
    //SELESI VALIDASI NIK//
    /*---------Nama----------*/
    gotoxy(50,25); printf("Nama   : "); fflush(stdin); getletter(Donatur.Full_Nama,20);
    if(strcmp(Donatur.Full_Nama, "0")==0)
    {
        system("cls");
        MenuCRUDDonatur();
    }
    /*---------Umur----------*/
    gotoxy(62,27); printf("Tahun"); gotoxy(50,27); printf("Umur   : ");  fflush(stdin); getnum(&Donatur.Umur,2);
    if(Donatur.Umur == 0)
    {
        system("cls");
        MenuCRUDDonatur();
    }
    /*---------NoTelp----------*/
    gotoxy(50,29); printf("NoTelp : "); fflush(stdin); getteksnum(Donatur.NoTelp,13);
    if(strcmp(Donatur.NoTelp, "0")==0)
    {
        system("cls");
        MenuCRUDDonatur();
    }


    DataDonatur = fopen("dat/ArsDonatur.dat", "ab");
    fwrite(&Donatur, sizeof(Donatur),1, DataDonatur);
    fclose(DataDonatur);
    MessageBox(NULL, "Data Berhasih Disimpan ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);


    jawaban:
    gotoxy(82,31); printf(" ");
    gotoxy(50,31); printf("Ingin Tambah data lagi [Y/N] : ");
    gotoxy(81,31);printf("["); gotoxy(83,31);printf("]");
    gotoxy(82,31);getteks(jawaban,1);

    if ((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            TambahDonatur();
        }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDDonatur();
        }
    else if (strcmp(jawaban,"0")==0)
        {
            system("cls");
            MenuCRUDDonatur();
        }
    else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }
 }

 void BacaDonatur()
 {
    //DECLARATION
    int y, loop = 0;
    OutterBorder();
	system("color 8E");

	//ALGORITM
    DataDonatur= fopen("dat/ArsDonatur.dat", "rb");
    gotoxy(40,14); printf("\t\t\t\t\t=====Lihat Data Donatur=====");
    gotoxy(40,15);	printf("====================================================================================================================");
    gotoxy(41,16); printf("      ID\t\tNIK\t\t\tNama\t\t\tUmur\t\t\tNo Telp");
    gotoxy(40,17);	printf("====================================================================================================================");
    y = 19;

    fread(&Donatur, sizeof(Donatur),1,DataDonatur);
    while(!feof(DataDonatur))
    {fread(&Donatur, sizeof(Donatur),1,DataDonatur);
        loop++;
    }
    fclose(DataDonatur);
    if(loop == 0)
    {
        gotoxy(110,25); printf("Data Donatur Tidak Ada!");
    }
    else
    {
        DataDonatur = fopen("dat/ArsDonatur.dat", "rb");

        while (fread(&Donatur, sizeof(Donatur), 1,DataDonatur)==1){

            gotoxy(47,y); fflush(stdin); printf("DNT%d ", Donatur.id_Donatur);
            gotoxy(64,y); fflush(stdin); printf("%s ", Donatur.Nik);
            gotoxy(88,y); fflush(stdin); printf("%s ", Donatur.Full_Nama);
            gotoxy(113,y); fflush(stdin); printf("%d Tahun", Donatur.Umur);
            gotoxy(136,y); fflush(stdin); printf("%s ", Donatur.NoTelp);
            y=y+1;

        }fclose(DataDonatur);

    }

 }
 void UpdateDonatur()
 {
	//DECLARATION
	int a, loop = 0, cari_id, found,ulang_NIK;
	char jawaban[10];
    OutterBorder();
	system("color 8E");

	//ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
    DataDonatur = fopen ("dat/ArsDonatur.dat", "rb");
	Temp = fopen ("dat/tempo.dat", "wb");

    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Update Data Donatur");
    cari_id:
    gotoxy(85,21); printf("    ");
	gotoxy(50,21); printf("Masukkan ID yang ingin diubah = DNT");
	scanf("%d", &cari_id);
	found = 0;

	if (cari_id == 0)
    {
        system("cls");
        MenuCRUDDonatur();
    }
    else if (cari_id !=0)
    {
        while ((!found )&& (!feof(DataDonatur)))
        {
            fread (&Donatur, sizeof (Donatur), 1, DataDonatur);
            if(Donatur.id_Donatur == cari_id)
            {
                found = 1;
            }
            else
            {
                fwrite (&Donatur, sizeof (Donatur),1,Temp);
            }
        }
    }

    if(found == 1)
	{

		gotoxy(50,23); printf("ID     = DNT%d ", Donatur.id_Donatur);
		gotoxy(50,24); printf("Nama   = %s ", Donatur.Full_Nama);
		gotoxy(50,25); printf("NIK    = %s ", Donatur.Nik);
		gotoxy(50,26); printf("Umur   = %d ", Donatur.Umur);
		gotoxy(50,27); printf("NoTelp = %s ", Donatur.NoTelp);

		gotoxy(50,29); printf("Pilih data yang akan diupdate ");
		gotoxy(50,30); printf("[1] NIK  ");
		gotoxy(50,31); printf("[2] Nama  ");
		gotoxy(50,32); printf("[3] Umur  ");
		gotoxy(50,33); printf("[4] No Telp  ");
		a:
        gotoxy(58,34); printf("    ");
		gotoxy(50,34); printf("Pilih = "); fflush(stdin);
		scanf("%d", &a);
        if(a==0){
            system("cls");
            MenuCRUDDonatur();
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
                MenuCRUDDonatur();
            }
            //VALIDASI NIK//
             validasiNIK = fopen("dat/ArsDonatur.dat", "rb");

            int found_user = 0;
            while(fread(&upVnik, sizeof(upVnik),1,validasiNIK)==1){
                if(strcmp(temp_NIK, upVnik.Nik) == 0){
                   found_user = 1;
                }
            }

            if(found_user == 1) {
                MessageBox(NULL, "NIK Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto ulang_NIK;
            }
            fclose(validasiNIK);
            strcpy(Donatur.Nik, temp_NIK);
            //SELESI VALIDASI NIK//

			fwrite(&Donatur,sizeof(Donatur),1,Temp);
			fread(&Donatur,sizeof(Donatur),1,DataDonatur);

			while(!feof(DataDonatur))
			{
				fwrite(&Donatur,sizeof(Donatur),1,Temp);
				fread(&Donatur,sizeof(Donatur),1,DataDonatur);
			}
		}
		else if(a==2)
		{
			gotoxy(50,36); printf("Masukkan Nama Baru : "); getletter(Donatur.Full_Nama,20);
			if(strcmp(Donatur.Full_Nama, "0")==0)
            {
                system("cls");
                MenuCRUDDonatur();
            }
			fwrite(&Donatur,sizeof(Donatur),1,Temp);
			fread(&Donatur,sizeof(Donatur),1,DataDonatur);

			while(!feof(DataDonatur))
			{
				fwrite(&Donatur,sizeof(Donatur),1,Temp);
				fread(&Donatur,sizeof(Donatur),1,DataDonatur);
			}
		}
		else if(a==3)
		{
			gotoxy(50,36); printf("Masukkan Umur Baru : "); getnum(&Donatur.Umur,2);
			if( Donatur.Umur == 0)
            {
                system("cls");
                MenuCRUDDonatur();
            }
			fwrite(&Donatur,sizeof(Donatur),1,Temp);
			fread(&Donatur,sizeof(Donatur),1,DataDonatur);

			while(!feof(DataDonatur))
			{
				fwrite(&Donatur,sizeof(Donatur),1,Temp);
				fread(&Donatur,sizeof(Donatur),1,DataDonatur);
			}
		}
		else if (a==4)
		{
			gotoxy(50,36); printf("Masukkan NoTelp Baru : "); getteksnum(Donatur.NoTelp,13);
			if(strcmp(Donatur.NoTelp, "0")==0)
            {
                system("cls");
                MenuCRUDDonatur();
            }
			fwrite(&Donatur,sizeof(Donatur),1,Temp);
			fread(&Donatur,sizeof(Donatur),1,DataDonatur);

			while(!feof(DataDonatur))
			{
				fwrite(&Donatur,sizeof(Donatur),1,Temp);
				fread(&Donatur,sizeof(Donatur),1,DataDonatur);
			}
		}
        else
		{
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto a;
		}
		fclose(DataDonatur);
		fclose(Temp);

		Temp = fopen("dat/tempo.dat", "rb");
		DataDonatur= fopen("dat/ArsDonatur.dat", "wb");

		fread (&Donatur, sizeof(Donatur),1,Temp);
		while(!feof(Temp))
		{
			fwrite (&Donatur,sizeof (Donatur),1,DataDonatur);
			fread (&Donatur, sizeof (Donatur),1,Temp);
		}
    }else
    {
        MessageBox(NULL, "ID Donatur Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto cari_id;
    }

		fclose(DataDonatur);
		fclose(Temp);
        jawaban:
        gotoxy(82,38); printf(" ");
        gotoxy(50,38); printf("Ingin update data lagi [Y/N] : ");
        gotoxy(81,38);printf("["); gotoxy(83,38);printf("]");
        gotoxy(82,38);getteks(jawaban,1);

        if ((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            UpdateDonatur();
        }
        else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDDonatur();
        }
        else if(strcmp(jawaban,"0")==0){
            system("cls");
            MenuCRUDDonatur();
        }
        else
        {
            MessageBox(NULL, "Input Tidak Sesuai !", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }


}

void HapusDonatur()
{
	//DECLARATION
	int cari_id, id, found;
	char jawaban[10],yakin[10];
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
	Temp = fopen ("dat/tempo.dat", "wb");
	DataDonatur = fopen ("dat/ArsDonatur.dat", "rb");
    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Hapus Data Donatur");
    cari_id:
    gotoxy(86,21);printf("    ");
	gotoxy(50,21); printf("Masukkan ID yang ingin dihapus : DNT");
    scanf("%d", &cari_id);
    found = false;

    if (cari_id == 0)
    {
        system("cls");
        MenuCRUDDonatur();
    }else if (cari_id != 0)
    {
        fread(&Donatur, sizeof (Donatur),1,DataDonatur);
        while(!found && !feof(DataDonatur))
        {
            if (Donatur.id_Donatur == cari_id)
            {
                found = true;
            }
            else
            {
                fwrite(&Donatur, sizeof (Donatur),1,Temp);
                fread(&Donatur,sizeof(Donatur),1,DataDonatur);
            }
        }
        if (found == true)
        {
            gotoxy(50,23); printf("ID     = DNT%d ", Donatur.id_Donatur);
            gotoxy(50,24); printf("Nama   = %s ", Donatur.Full_Nama);
			gotoxy(50,25); printf("Umur   = %d ", Donatur.Umur);
			gotoxy(50,26); printf("NoTelp = %s ", Donatur.NoTelp);
			yakin:
            gotoxy(89,28); printf(" ");
			gotoxy(50,28); printf("APAKAH YAKIN INGIN MENGHAPUS? [Y/N]: ");
            gotoxy(88,28); printf("["); gotoxy(90,28);printf("]");
            gotoxy(89,28); getteks(yakin,1);

            if ((strcmp(yakin,"n")==0) || (strcmp(yakin,"N")==0))
            {
                system("cls");
                MenuCRUDDonatur();
            }else if ((strcmp(yakin,"y")==0) || (strcmp(yakin,"Y")==0))
            {
                fread(&Donatur, sizeof(Donatur),1,DataDonatur);
                while(!feof(DataDonatur))
                {
                    fwrite(&Donatur, sizeof (Donatur),1,Temp);
                    fread(&Donatur, sizeof(Donatur),1,DataDonatur);
                }

                fclose(Temp);
                fclose(DataDonatur);

                DataDonatur = fopen("dat/ArsDonatur.dat","wb");
                Temp = fopen("dat/tempo.dat","rb");

                fread(&Donatur, sizeof(Donatur),1,Temp);
                while(!feof(Temp))
                {
                    fwrite(&Donatur, sizeof(Donatur),1,DataDonatur);
                    fread(&Donatur, sizeof(Donatur),1,Temp);
                }
                fclose(DataDonatur);
                fclose(Temp);
            }else if (strcmp(yakin,"0")==0){
                system("cls");
                MenuCRUDDonatur();
            }else{
                MessageBox(NULL, "Inputan tidak sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto yakin;
            }

        }
        else
        {
            MessageBox(NULL, "ID Donatur Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto cari_id;
        }
    }
    jawaban:
    gotoxy(82,30); printf(" ");
    gotoxy(50,30); printf("Ingin hapus data lagi [Y/N] : ");
    gotoxy(81,30);printf("["); gotoxy(83,30);printf("]");
    gotoxy(82,30);getteks(jawaban,1);

     if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            HapusDonatur();
        }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDDonatur();
        }
    else if (strcmp(jawaban,"0")==0)
        {
            system("cls");
            HapusDonatur();
        }
    else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }

}



