//LIBRARY//
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
//HEADER//
#include "header/Gotoxy.h"
#include "header/lib.h"
#include "header/Struct.h"
#include "header/LOGIN.h"
#include "header/MenuUTAMA.h"
#include "header/CRUDDONATUR.h"
#include "header/CRUDINISIATOR.h"
#include "header/CRUDYAYASAN.h"
#include "header/CRUDUSER.h"
#include "header/CRUDPengajuanKegiatan.h"
#include "header/Transaksi_Donatur.h"
#include "header/Transaksi_Distribusi_Kegiatan.h"
#include "header/Transaksi_Distribusi_Yayasan.h"
#include "header/Laporan_Distribusi_Kegiatan.h"
#include "header/Laporan_Distribusi_Yayasan.h"
#include "header/Laporan_Transaksi_Donatur.h"
main ()
{
	FullScreen();
	system("color 8E");
	Createdby();
    loading();
    getch();
	system("cls");
	Masuklogin();
    system ("cls");

}
