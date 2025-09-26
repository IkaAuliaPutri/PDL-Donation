//LOGIN
StructLogin login;//SESSION
StructUser User;


FILE *DataUser;
FILE *DataKasir;
void Masuklogin();
void Logout();

void Masuklogin()
{

    char username[20], pass[20];
    int found;


	KotakLogin();
	system("color 8E");
	Createdby();
	gotoxy(57,47),printf("Klik '0' untuk batal!     ||      Klik ENTER untuk Masuk...");
	gotoxy(69,28);	printf("Masukan Username & Password");
	gotoxy(66, 30);	printf("Username = ");
	gotoxy(80, 30);	getteks(&username,8);
	if (strcmp(username, "0")== 0)
	{
	    system("cls");
	    PrintFile("txt/thankyou.txt", 58,18);
        exit(0);
	}

	gotoxy(66, 32);	printf("Password = ");
	gotoxy(80, 32);	getpass(pass, 8);

	if (strcmp(pass , "0")==0)
    {
        system("cls");
	    PrintFile("txt/thankyou.txt", 58,18);
        exit(0);
    }


	found = false;
	DataUser = fopen("dat/FileUser.dat", "rb");
	while(fread(&User, sizeof(User),1,DataUser)==1){
        if(strcmp(User.Jabatan, "ADMIN") == 0) {
            if(strcmp(username,User.Username)==0 && strcmp(pass,User.Password)==0){
                login.user_id = User.id_user;
                strcpy(login.category, "ADMIN");
                strcpy(login.fullname, User.Full_Nama);

                gotoxy(69, 34),	printf("-BERHASIL LOGIN SEBAGAI ADMIN-");
                getch();
                system("cls");
                MenuAdmin();
                found = true;
            }
        }
	}
	DataUser = fopen("dat/FileUser.dat", "rb");
	while(fread(&User, sizeof(User),1,DataUser)==1){
        if(strcmp(User.Jabatan, "KASIR") == 0) {
            if(strcmp(username,User.Username)==0 && strcmp(pass,User.Password)==0){
                login.user_id = User.id_user;
                strcpy(login.category, "KASIR");
                strcpy(login.fullname, User.Full_Nama);

                gotoxy(69, 34),	printf("-BERHASIL LOGIN SEBAGAI KASIR-");
                getch();
                system("cls");
                MenuKasir();
                found = true;
            }
        }
	}
    DataUser = fopen("dat/FileUser.dat", "rb");
	while(fread(&User, sizeof(User),1,DataUser)==1){
        if(strcmp(User.Jabatan, "MANAGER") == 0) {
            if(strcmp(username,User.Username)==0 && strcmp(pass,User.Password)==0){
                login.user_id = User.id_user;
                strcpy(login.category, "MANAGER");
                strcpy(login.fullname, User.Full_Nama);

                gotoxy(69, 34),	printf("-BERHASIL LOGIN SEBAGAI MANAGER-");
                getch();
                system("cls");
                MenuManager();
                found = true;
            }
        }
	}
	fclose(DataUser);
	if(found == false) {
        gotoxy(69, 34),	printf("-USERNAME ATAU PASSWORD ANDA SALAH-");
        getch();
        system("cls");
        Masuklogin();
	}
}




