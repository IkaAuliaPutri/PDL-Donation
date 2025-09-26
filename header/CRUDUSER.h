 //CRUD Usera//

 StructUser User;
 StructUser ValidasiUser;//untuk validasi username di tambah
 StructUser validasinik;//untuk validasi nik di tambah
 StructUser updatevalidasi;//untuk validasi username di update
 StructUser updatevalidasiNIK;//untuk validasi NIK di update
 FILE *DataUser;
 FILE *Temp;
 FILE *FileUserValidation;//untuk validasi username
 FILE *ValidasiNIK;//untuk validasi NIK

 void MenuCRUDUser ()
{
	//DECLARATION
	int Menu;
	OutterBorder();
	system("color 8E");

    //ALGORITM
    BacaUser();
	gotoxy(12,10);	printf("%s",login.fullname);
	gotoxy(7,15);	printf("Kelola Data User");
	gotoxy(4,17);	printf("[1] Tambah Data User");
	gotoxy(4,18);	printf("[2] Update Data User");
	gotoxy(4,19);	printf("[3] Hapus Data User");
	gotoxy(4,20);	printf("[4] Kembali");
	gotoxy(4,21);	printf("[5] Keluar Program");
	gotoxy(12,24);	printf("["); gotoxy(16,24);	printf("]");
	gotoxy(14,24); getnum(&Menu,1);
	switch (Menu)
	{
		case 1 : system("cls");
                 TambahUser();
                 break;
		case 2 : system("cls");
                 UpdateUser();
                 break;
		case 3 : system("cls");
                 HapusUser();
                 break;
		case 4 : system("cls");
                 MenuAdmin();
                 break;
		case 5 : system("cls");
                 PrintFile("txt/thankyou.txt", 58,18);
                 exit(0);
                 break;
		default :MessageBox(NULL, "Pilihan Tidak Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                 MenuCRUDUser();
                 break;
	}
}


 void TambahUser()
 {
    //DECLARATION
    char jawaban[10],temp_NIK[20],temp_Pw[20];
    int Last_id,loop=0,pilih,found_user,ulang_pw,ulang_NIK,ulang_US;
    OutterBorder();
    system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    DataUser= fopen("dat/FileUser.dat","ab+");
    fread(&User, sizeof(User),1,DataUser);
    while(!feof(DataUser))
    {
        fread(&User, sizeof(User),1,DataUser);
        Last_id= User.id_user;
        loop++;
    }
    if(loop == 0)
    {
        User.id_user = 1;
    }
    else
    {
        User.id_user = Last_id+ 1;
    }

    fclose(DataUser);

    kotakCRUDTransaksi();
    gotoxy(57,16); printf("Tambah Data user");
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
    /*---------ID----------*/
    gotoxy(50,21); printf("ID       : USR%d", User.id_user);

    /*---------NIK----------*/
    ulang_NIK:
    gotoxy(61,23); printf("                ");
    gotoxy(50,23); printf("NIK      : "); fflush(stdin); getteksnum(temp_NIK,16);
    if(strcmp(temp_NIK, "0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
    //VALIDASI NIK//
     ValidasiNIK = fopen("dat/FileUser.dat", "rb");

    found_user = 0;
    while(fread(&validasinik, sizeof(validasinik),1,ValidasiNIK)==1){
        if(strcmp(temp_NIK, validasinik.Nik) == 0){
           found_user = 1;
        }
    }

    if(found_user == 1) {
        MessageBox(NULL, "NIK Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto ulang_NIK;
    }
    fclose(ValidasiNIK);
    strcpy(User.Nik, temp_NIK);
    //SELESI VALIDASI NIK//

    /*---------Nama----------*/
    gotoxy(50,25); printf("Nama     : "); fflush(stdin); getletter(User.Full_Nama,20);
    if(strcmp(User.Full_Nama, "0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }

    /*---------Username----------*/
    //VALIDASI USERNAME//
    char temp_username[8];
    ulang_US:
    gotoxy(61,27); printf("        ");
    gotoxy(50,27); printf("Username : "); getteks(temp_username,8);fflush(stdin);
    if(strcmp(temp_username, "0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
    FileUserValidation = fopen("dat/FileUser.dat", "rb");

    found_user = 0;
    while(fread(&ValidasiUser, sizeof(ValidasiUser),1,FileUserValidation)==1){
        if(strcmp(temp_username, ValidasiUser.Username) == 0){
           found_user = 1;
        }
    }

    if(found_user == 1) {
        MessageBox(NULL, "Username Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto ulang_US;
    }

    fclose(FileUserValidation);
    strcpy(User.Username, temp_username);
    //SELESI VALIDASI USERNAME//

    /*---------Password----------*/
    gotoxy(50,29); printf("Password : "); fflush(stdin); getpass(User.Password,8);
    if(strcmp(User.Password, "0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
    ulang_pw:
    gotoxy(71,31);printf("                      ");
    gotoxy(50,31); printf("Konfirmasi Password : "); fflush(stdin); getpass(temp_Pw,8);
    if(strcmp(temp_Pw, "0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
    else if (strcmp(User.Password,temp_Pw)==1)
    {
        MessageBox(NULL, "Password Tidak Sama, Silakan Isi Ulang Kembali ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto ulang_pw;
    }
    else if(strcmp(User.Password,temp_Pw)==0)
    {
        MessageBox(NULL, "Password Benar ", "INFORMATION", MB_OK | MB_ICONINFORMATION| MB_DEFAULT_DESKTOP_ONLY);
    }
    /*---------No Telp----------*/
    gotoxy(50,33); printf("No Telp  : "); fflush(stdin); getteksnum(User.NoTelp,13);
    if(strcmp(User.NoTelp, "0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
     /*---------Jabatan----------*/

    gotoxy(50,35); printf("Pilih Jabatan:");
    gotoxy(50,36); printf("[1] Admin");
    gotoxy(50,37); printf("[2] Kasir");
    gotoxy(50,38); printf("[3] Manager");
    lagi:
    gotoxy(60,39);printf("    ");
    gotoxy(50,39); printf("Jabatan : "); fflush(stdin); getnum(&pilih,1);
    if (pilih == 0)
    {
        system("cls");
        MenuCRUDUser();
    }

    switch (pilih)
    {
        case 1 :strcpy(User.Jabatan,"ADMIN");
                break;
        case 2 :strcpy(User.Jabatan,"KASIR");
                break;
        case 3 :strcpy(User.Jabatan,"MANAGER");
                break;
        default :MessageBox(NULL, "Inputan Tidak Sesuai, Silakan Isi Kembali ! ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
                 goto lagi;
                 break;
    }
    DataUser = fopen("dat/FileUser.dat", "ab");
    fwrite(&User, sizeof(User),1, DataUser);
    fclose(DataUser);
    MessageBox(NULL, "Data Berhasil Disimpan ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);

    jawaban:
    gotoxy(82,41);printf(" ");
    gotoxy(50,41); printf("Ingin Tambah data lagi [Y/N] : ");
    gotoxy(81,41);printf("["); gotoxy(83,41);printf("]");
    gotoxy(82,41);getteks(jawaban,1);

     if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
    {
        system("cls");
        TambahUser();
    }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
    {
        MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        MenuCRUDUser();
    }
    else if (strcmp(jawaban,"0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
    else
    {
        MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto jawaban;
    }
 }

 void BacaUser()
 {
    //Deklarasi
    int loop = 0,y;
    OutterBorder();
	system("color 8E");

	//Algoritma
    DataUser= fopen("dat/FileUser.dat", "rb");
    gotoxy(40,14); printf("\t\t\t\t\t=====Lihat Data User=====");
    gotoxy(40,15);	printf("====================================================================================================================");
    gotoxy(41,16); printf("ID\tNIK\t\t\tNama\t\t\tUsername\t\tNo.Telp\t\t\tJabatan");
    gotoxy(40,17);	printf("====================================================================================================================");
    y = 19;

    fread(&User, sizeof(User),1,DataUser);
    while(!feof(DataUser))
    {fread(&User, sizeof(User),1,DataUser);
        loop++;
    }
    fclose(DataUser);
    if(loop == 0)
    {
        gotoxy(40,25); printf("\t\t\t\t\tData User Tidak Ada!");
    }
    else{
        DataUser = fopen("dat/FileUser.dat", "rb");

        while(fread(&User, sizeof(User),1,DataUser)==1){

            gotoxy(41,y); fflush(stdin); printf("USR%d ", User.id_user);
            gotoxy(48,y); fflush(stdin); printf("%s ", User.Nik);
            gotoxy(66,y); fflush(stdin); printf("\t%s ", User.Full_Nama);
            gotoxy(88,y); fflush(stdin); printf("\t%s ", User.Username);
            gotoxy(120,y); fflush(stdin); printf("%s ", User.NoTelp);
            gotoxy(144,y); fflush(stdin); printf("%s ", User.Jabatan);
            y++;
        }fclose(DataUser);
    }
 }
 void UpdateUser()
 {
	//DECLARATION
	int a, cari_id, found,ulang_us,ulang_nik,pilih;
	char jawaban[10];
    OutterBorder();
	system("color 8E");

    //ALGORITM
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(58,46),printf("Klik '0' untuk Batal...");
    DataUser = fopen ("dat/FileUser.dat", "rb");
	Temp = fopen ("dat/tempo.dat", "wb");
    kotakCRUDTransaksi();
    gotoxy(62,16); printf("Update Data user");

    cari_id:
    gotoxy(85,19); printf("    ");
	gotoxy(50,19); printf("Masukkan ID yang ingin diubah = USR");
	scanf("%d", &cari_id);

	found = 0;

	if (cari_id == 0)
    {
        system("cls");
        MenuCRUDUser();
    }
    else if (cari_id !=0)
    {
        while ((!found )&& (!feof(DataUser)))
        {
            fread (&User, sizeof (User), 1, DataUser);
            if(User.id_user == cari_id)
            {
                found = 1;
            }
            else
            {
			fwrite (&User, sizeof (User),1,Temp);
            }
        }
    }
    if(found == 1)
	{


		gotoxy(50,21); printf("ID        = USR%d ", User.id_user);
		gotoxy(50,22); printf("NIK       = %s ", User.Nik);
		gotoxy(50,23); printf("Nama      = %s ", User.Full_Nama);
		gotoxy(50,24); printf("Username  = %s ", User.Username);
		gotoxy(50,25); printf("Password  = %s ", User.Password);
		gotoxy(50,26); printf("No Telp   = %s ", User.NoTelp);
        gotoxy(50,27); printf("Jabatan   = %s ", User.Jabatan);


		gotoxy(50,29); printf("Pilih data yang akan diupdate ");
		gotoxy(50,30); printf("[1] NIK User ");
		gotoxy(50,31); printf("[2] Nama User ");
		gotoxy(50,32); printf("[3] Username User ");
		gotoxy(50,33); printf("[4] Password User ");
		gotoxy(50,34); printf("[5] No Telp User ");
		gotoxy(50,35); printf("[6] Jabatan User ");
		a:
        gotoxy(58,36); printf("    ");
		gotoxy(50,36); printf("Pilih = "); fflush(stdin);
		scanf("%d", &a);
		if (a == 0)
		{
		   system("cls");
		   MenuCRUDUser();
		}
		if(a==1)
		{
		    char temp_NIK[20];
		    ulang_nik:
		    gotoxy(70,38); printf("                ");
			gotoxy(50,38); printf("Masukkan NIK Baru : "); getteksnum(temp_NIK,16);
            if(strcmp(temp_NIK, "0")==0)
            {
                system("cls");
                MenuCRUDUser();
            }
            //VALIDASI NIK//
             ValidasiNIK = fopen("dat/FileUser.dat", "rb");

            int found_user = 0;
            while(fread(&updatevalidasiNIK, sizeof(updatevalidasiNIK),1,ValidasiNIK)==1){
                if(strcmp(temp_NIK, updatevalidasiNIK.Nik) == 0){
                   found_user = 1;
                }
            }

            if(found_user == 1) {
                MessageBox(NULL, "NIK Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto ulang_nik;
            }
            fclose(ValidasiNIK);
            strcpy(User.Nik, temp_NIK);
            //SELESI VALIDASI NIK//

			fwrite(&User,sizeof(User),1,Temp);
			fread(&User,sizeof(User),1,DataUser);

			while(!feof(DataUser))
			{
				fwrite(&User,sizeof(User),1,Temp);
				fread(&User,sizeof(User),1,DataUser);
			}
		}
        else if (a==2)
		{
			gotoxy(50,38); printf("Masukkan Nama Baru : "); getletter(User.Full_Nama,50);
            if(strcmp(User.Full_Nama, "0")==0)
            {
                system("cls");
                MenuCRUDUser();
            }
			fwrite(&User,sizeof(User),1,Temp);
			fread(&User,sizeof(User),1,DataUser);

			while(!feof(DataUser))
			{
				fwrite(&User,sizeof(User),1,Temp);
				fread(&User,sizeof(User),1,DataUser);
			}
		}
		else if(a==3)
		{
		    char validasi_username[10];
		    ulang_us:
		    gotoxy(75,38); printf("        ");
			gotoxy(50,38); printf("Masukkan Username Baru : "); getteks(validasi_username,8);
			if(strcmp(validasi_username, "0")==0)
            {
                system("cls");
                MenuCRUDUser();
            }
            FileUserValidation = fopen("dat/FileUser.dat", "rb");

             int found_user = 0;
            while(fread(&updatevalidasi, sizeof(updatevalidasi),1,FileUserValidation)==1){
                if(strcmp(validasi_username, updatevalidasi.Username) == 0){
                   found_user = 1;
                }
            }

            if(found_user == 1) {
                MessageBox(NULL, "Username Sudah Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto ulang_us;
            }

            fclose(FileUserValidation);
            strcpy(User.Username, validasi_username);
            //SELESI VALIDASI USERNAME//

			fwrite(&User,sizeof(User),1,Temp);
			fread(&User,sizeof(User),1,DataUser);

			while(!feof(DataUser))
			{
				fwrite(&User,sizeof(User),1,Temp);
				fread(&User,sizeof(User),1,DataUser);
			}
		}
		else if (a==4)
		{
			gotoxy(50,38); printf("Masukkan Password Baru : "); getpass(User.Password,8);
			if(strcmp(User.Password, "0")==0)
            {
                system("cls");
                MenuCRUDUser();
            }
			fwrite(&User,sizeof(User),1,Temp);
			fread(&User,sizeof(User),1,DataUser);

			while(!feof(DataUser))
			{
				fwrite(&User,sizeof(User),1,Temp);
				fread(&User,sizeof(User),1,DataUser);
			}
		}
		else if (a==5)
		{
			gotoxy(50,38); printf("Masukkan No Telp  Baru : "); getteksnum(User.NoTelp,13);
			if(strcmp(User.NoTelp, "0")==0)
            {
                system("cls");
                MenuCRUDUser();
            }
			fwrite(&User,sizeof(User),1,Temp);
			fread(&User,sizeof(User),1,DataUser);

			while(!feof(DataUser))
			{
				fwrite(&User,sizeof(User),1,Temp);
				fread(&User,sizeof(User),1,DataUser);
			}
		}
		else if (a==6)
		{
            pilih:
            gotoxy(71,41); printf("     ");
            gotoxy(50,38); printf("[1] Admin");
            gotoxy(50,39); printf("[2] Kasir");
            gotoxy(50,40); printf("[3] Manager");
            gotoxy(50,41); printf("Pilih Jabatan Baru : "); fflush(stdin); getnum(&pilih,1);
            switch (pilih)
            {
                case 1 :strcpy(User.Jabatan,"ADMIN");
                        break;
                case 2 :strcpy(User.Jabatan,"KASIR");
                        break;
                case 3 :strcpy(User.Jabatan,"MANAGER");
                        break;
                case 0 :goto pilih;
                        break;
            }
			fwrite(&User,sizeof(User),1,Temp);
			fread(&User,sizeof(User),1,DataUser);

			while(!feof(DataUser))
			{
				fwrite(&User,sizeof(User),1,Temp);
				fread(&User,sizeof(User),1,DataUser);
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
        MessageBox(NULL, "ID User Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto cari_id;
    }
		fclose(DataUser);
		fclose(Temp);

		Temp = fopen("dat/tempo.dat", "rb");
		DataUser= fopen("dat/FileUser.dat", "wb");

		fread (&User, sizeof(User),1,Temp);
		while(!feof(Temp))
		{
			fwrite (&User,sizeof (User),1,DataUser);
			fread (&User, sizeof (User),1,Temp);
		}

		fclose(DataUser);
		fclose(Temp);

		jawaban:
        gotoxy(82,43);printf(" ");
        gotoxy(50,43); printf("Ingin update data lagi [Y/N] : ");
        gotoxy(81,43);printf("["); gotoxy(83,43);printf("]");
        gotoxy(82,43);getteks(jawaban,1);

         if (strcmp(jawaban,"0")==0)
        {
            system("cls");
            MenuCRUDUser();
        }
        else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
        {
            system("cls");
            UpdateUser();
        }
        else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
        {
            MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
            system("cls");
            MenuCRUDUser();
        }
        else
        {
            MessageBox(NULL, "Input Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto jawaban;
        }

}

void HapusUser()
{
	//DECLARATION
	int cari_id, found;
	char jawaban[10],yakin[10];
    OutterBorder();
	system("color 8E");

    //ALGORITM
    kotakCRUDTransaksi();
    gotoxy(12,10);	printf("%s",login.fullname);
    gotoxy(57,16); printf("Hapus Data user");
    gotoxy(58,44),printf("Klik '0' untuk Batal...");
	Temp = fopen ("dat/tempo.dat", "wb");
	DataUser = fopen ("dat/FileUser.dat", "rb");

	cari_id:
    gotoxy(86,21); printf("    ");
	gotoxy(50,21); printf("Masukkan ID yang ingin dihapus : USR");
    scanf("%d", &cari_id);
    found = false;

    if (cari_id == 0)
    {
        system("cls");
        MenuCRUDUser();
    }else if (cari_id != 0)
    {
        fread(&User, sizeof (User),1,DataUser);
        while(!found && !feof(DataUser))
        {
            if (User.id_user == cari_id)
            {
                found = true;
            }
            else
            {
                fwrite(&User, sizeof (User),1,Temp);
                fread(&User,sizeof(User),1,DataUser);
            }
        }
        if (found == true)
        {
            gotoxy(50,23); printf("ID        = USR%d ", User.id_user);
            gotoxy(50,24); printf("Nama      = %s ", User.Full_Nama);
			gotoxy(50,25); printf("Username  = %s ", User.Username);
			gotoxy(50,26); printf("Password  = %s ", User.Password);
            gotoxy(50,27); printf("No Telp   = %s ", User.NoTelp);
            gotoxy(50,28); printf("Jabatan   = %s ", User.Jabatan);

            yakin:
            gotoxy(89,30); printf(" ");
			gotoxy(50, 30); printf("APAKAH YAKIN INGIN MENGHAPUS? [Y/N]: ");
            gotoxy(88,30); printf("["); gotoxy(90,30);printf("]");
            gotoxy(89,30); getteks(yakin,1);

            if (strcmp(yakin,"0")==0)
            {
                system("cls");
                MenuCRUDUser();
            }
            else if((strcmp(yakin,"n")==0) || (strcmp(yakin,"N")==0))
            {
                system("cls");
                MenuCRUDUser();
            }else if ((strcmp(yakin,"y")==0) || (strcmp(yakin,"Y")==0))
            {
                fread(&User, sizeof(User),1,DataUser);
                while(!feof(DataUser))
                {
                    fwrite(&User, sizeof (User),1,Temp);
                    fread(&User, sizeof(User),1,DataUser);
                }

                fclose(Temp);
                fclose(DataUser);

                DataUser = fopen("dat/FileUser.dat","wb");
                Temp = fopen("dat/tempo.dat","rb");

                fread(&User, sizeof(User),1,Temp);
                while(!feof(Temp))
                {
                    fwrite(&User, sizeof(User),1,DataUser);
                    fread(&User, sizeof(User),1,Temp);
                }
                fclose(DataUser);
                fclose(Temp);
            }else
            {
                MessageBox(NULL, "Inputan Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
                goto yakin;
            }

        }
        else
        {
            MessageBox(NULL, "ID User Belum Terdaftar ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
            goto cari_id;
        }
    }
    jawaban:
    gotoxy(82,32);printf(" ");
    gotoxy(50,32); printf("Ingin hapus data lagi [Y/N] : ");
    gotoxy(81,32);printf("["); gotoxy(83,32);printf("]");
    gotoxy(82,32);getteks(jawaban,1);

    if (strcmp(jawaban,"0")==0)
    {
        system("cls");
        MenuCRUDUser();
    }
    else if((strcmp(jawaban,"y")==0) || (strcmp(jawaban,"Y")==0))
    {
        system("cls");
        HapusUser();
    }
    else if((strcmp(jawaban,"n")==0) || (strcmp(jawaban,"N")==0))
    {
        MessageBox(NULL, "Terima Kasih ", "INFORMATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        MenuCRUDUser();
    }
    else
    {
        MessageBox(NULL, "Inputan Tidak Sesuai ! ", "INFORMATION", MB_OK | MB_ICONEXCLAMATION | MB_DEFAULT_DESKTOP_ONLY);
        goto jawaban;
    }

}





