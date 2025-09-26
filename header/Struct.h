typedef struct
 {
     int id_user;
     char Nik[20];
     char Full_Nama[50];
     char Username[20];
     char Password[30];
     char NoTelp[20];
     char Jabatan[10];

 }StructUser;

 typedef struct
 {
     int id_inisiator;
     char Nik[20];
     char Full_Nama[50];
     int Umur;
     char NoTelp[13];

 }structinisiator;

 typedef struct {
    int user_id;
    char fullname[20];
    char category[20];
} StructLogin;

 typedef struct
 {
     int id_Yayasan;
     char Nama[50];
     char NoTelp[20];
     char alamat[100];
     char NoPokok[10];
 }structYayasan;


  typedef struct
 {
     int id_Donatur;
     char Nik[20];
     char Full_Nama[50];
     int Umur;
     char NoTelp[20];
     char Username[8];
     char Password[8];

 }structdonatur;

 typedef struct
 {
     int id_kegiatan;
     char Nama_Kegiatan[30];
     char Tanggal_pengajuan[20];
     int tanggal;
     int bulan;
     int tahun;
     int jam;
     int menit;
     int detik;
     int id_kasir;
     int id_inisiator;
     char namakasir[20];
     char namainisiator[20];
     int total_uang;
     char status[20];
     int bulanpengajuan;
     int tanggalpengajuan;
     int tahunpengajuan;
 }TransaksiPengajuanKegiatan;

 typedef struct
 {
     int id_donasi_uang;
     int id_donatur;
     int id_kasir;
     int total_uang;
     int tanggal;
     int bulan;
     int tahun;
     int jam;
     int menit;
     int detik;
     char NamaDonatur[20];
     char NamaKasir[20];
 }TransaksiDonatur;

 typedef struct
 {
    int id_distribusi_yayasan;
    int id_yayasan;
    int id_kasir;
    int tanggal;
    int bulan;
    int tahun;
    int jam;
    int menit;
    int detik;
    int total_uang;
    char namayayasan[20];
    char namakasir[20];

 }TransaksiDistribusiYayasan;

 typedef struct
 {
     int id_distribusi_kegiatan;
     int id_kegiatan;
     int id_kasir;
     int tanggal;
     int bulan;
     int tahun;
     int jam;
     int menit;
     int detik;
     int total_uang;
     char namakegiatan[50];
     char namakasir[20];
     int Uang_disumbangkan;
 }TransaksiDistribusiKegiatan;


