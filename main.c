#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(){
    printf("\tSELAMAT DATANG DI MC DONALD'S INDONESIA\n");
    printf("\n\tProgram ini dibuat oleh:\n");
    printf("\t-Fandy (nim)\n\t-Alka (nim)\n\t-Kating (nim)\n\n");
    system("pause");
    HalDepan();
    HalMenu();
return 0;
}
void HalUtama(){
    printf("\tI'M LOVIN IT\n\n");
}
void HalDepan(){
    system("cls");
    HalUtama();
    char kasir;
    printf("Anda seorang kasir? (y/t): ");scanf("%c",&kasir);
    if(kasir=='y')
        HalKasir();
}
void HalKasir(){
    system("cls");
    HalUtama();
    int pilKasir;
    printf("Silahkan Login/Registrasi\n\n"
           "1. Registrasi\n"
           "2. Login\n"
           "3. Kembali\n"
           );
    printf("----------------------------------------\n");
    printf("\nMasukkan pilihan Anda: ");scanf("%d",&pilKasir);fflush(stdin);
    switch(pilKasir){
        case 1: HalRegis();break;
        case 2: HalLogin();break;
        default: HalDepan();
    }
}

struct kasir{ //Variabel untuk database kasir
    char nama[50],user[50],pass[50];
    int umur;
}regKasir,logKasir[50];

void HalRegis(){
    system("cls");
    HalUtama();
    FILE *kasir;
    kasir=fopen("DBkasir.txt", "a");
    printf("Masukkan Username   : ");gets(regKasir.user);
    printf("Masukkan Password   : ");gets(regKasir.pass);
    printf("Masukkan nama Anda  : ");gets(regKasir.nama);
    printf("Masukkan umur Anda  : ");scanf("%d",&regKasir.umur);

    fprintf(kasir, "%s#%s#%s#%d\n",regKasir.user,regKasir.pass,regKasir.nama,regKasir.umur);
    fclose(kasir);

    //Kembali ke halaman kasir
    HalKasir();
}

void HalLogin()
{
    system("cls");
    HalUtama();
    FILE *kasir;
    kasir=fopen("DBkasir.txt", "r");

    //Pembacaan database
    int i,n;
    i=0;n=0;
    while(!feof(kasir)){
        fscanf(kasir, "%[^#]#%[^#]#%[^#]#%d\n",&logKasir[i].user,&logKasir[i].pass,&logKasir[i].nama,&logKasir[i].umur);n++;i++;
    }
    fclose(kasir);

    char userLog[50],passLog[50];
    printf("Masukkan username: ");gets(userLog);
    printf("Masukkan passord : ");gets(passLog);

    /*Pencarian username dan password*/
    int kondisi=0; //variabel sementara untuk kondisi perulangan
    for(i=0;i<n;i++){
        if(strcmp(userLog, logKasir[i].user)==0 && strcmp(passLog, logKasir[i].pass)==0){
            //Aksi lanjutan jika berhasil
            printf("==============================================\n");
            printf("  Selamat Bekerja Kasir %s\n", logKasir[i].nama);
            printf("==============================================\n");
            system("pause");
            kondisi=0;break;
        }
        else{
            kondisi=1; //kondisi jika gagal login
        }
    }
    /*Akhir dari pencarian username dan password */
    if(kondisi !=0)//JIka data tidak ada
    {
        printf("\n---------------------------------------------------------------------------\n");
        printf("Username atau Password tidak terdaftar. Silahkan registrasi dulu!\n\n");
        system("pause");
        HalKasir(); //kembali ke MenuUtama
    }

}
void HalMenu(){
    system("cls");
printf("        Selamat Datang di Mc Donald's Buah Batu\n\n");
printf("            Kami menyediakan Beberapa Menu\n");
printf("=================================================================================\n");
printf("| 1. Paket Hemat:      2. Burger:           3. Minuman:      4. Menu Penutup:   |\n");
printf("|                                                                               |\n");
printf("| a. PaNas Spesial     a. Big Mac           a. Cola          a. Apple Pie       |\n");
printf("| b. PaNas 1           b. Chesse Burger     b. Lemon Tea     b. McFlurry        |\n");
printf("| c. PaNas 2           c. Chicken Burger    c. Milo          c. Cone Ice Cream  |\n");
printf("=================================================================================\n");

int n=1;
    struct PaketHemat{
        char nama[25];
        int jumlah, harga;
    }pakethemat[n];

    struct Burger{
        char nama[25];
        int jumlah, harga;
    }burger[n];

    struct Minuman{
        char nama[25];
        int jumlah, harga;
    }minuman[n];

    struct MenuPenutup{
        char nama[25];
        int jumlah, harga;
    }menupenutup[n];

    int pil1, jumlah, i,j,k,l;char pil2;

    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            for (k=1; k<=n; k++){
                for (l=1; l<=n; l++){
                    printf("\nSilahkan pilih menu Anda (contoh '1'): "); scanf("%d", &pil1);fflush(stdin);
                    printf("Masukkan Kode Menu Anda (contoh 'a'): "); scanf("%c", &pil2);
                    printf("Masukkan Jumlah Pesanan: "); scanf("%d", &jumlah);fflush(stdin);

                    system("cls");

                    if (pil1==1){
                        switch(pil2){
                            case 'a':strcpy(pakethemat[i].nama,"PaNas Spesial");pakethemat[i].harga=45000*jumlah;break;
                            case 'b':strcpy(pakethemat[i].nama,"PaNas 1");pakethemat[i].harga=35000*jumlah;break;
                            case 'c':strcpy(pakethemat[i].nama,"PaNas 2");pakethemat[i].harga=25000*jumlah;break;
                            default:printf("MENU YANG ANDA PILIH TIDAK ADA!\n\n");
                        }
                    }
                    if (pil1==2){
                        switch(pil2){
                            case 'a':strcpy(burger[j].nama,"Big Mac");burger[j].harga=40000*jumlah;break;
                            case 'b':strcpy(burger[j].nama,"Chesse Burger");burger[j].harga=30000*jumlah;break;
                            case 'c':strcpy(burger[j].nama,"Chicken Burger");burger[j].harga=20000*jumlah;break;
                            default:printf("MENU YANG ANDA PILIH TIDAK ADA!\n\n");
                        }
                    }
                    else if (pil1==3){
                        switch(pil2){
                            case 'a':strcpy(minuman[k].nama,"Cola");minuman[k].harga=15000*jumlah;break;
                            case 'b':strcpy(minuman[k].nama,"Lemon Tea");minuman[k].harga=15000*jumlah;break;
                            case 'c':strcpy(minuman[k].nama,"Milo");minuman[k].harga=20000*jumlah;break;
                            default:printf("MENU YANG ANDA PILIH TIDAK ADA!\n\n");
                        }
                    }
                    else if (pil1==4){
                        switch(pil2){
                            case 'a':strcpy(menupenutup[l].nama,"Aple Pie");menupenutup[l].harga=17000*jumlah;break;
                            case 'b':strcpy(menupenutup[l].nama,"McFlurry");menupenutup[l].harga=10000*jumlah;break;
                            case 'c':strcpy(menupenutup[l].nama,"Cone Ice Cream");menupenutup[l].harga=10000*jumlah;break;
                            default:printf("MENU YANG ANDA PILIH TIDAK ADA!\n\n");
                        }
                    }
                }
            }
        }
    }
    HalUtama();
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            for (k=1; k<=n; k++){
                for (l=1; l<=n; l++){
    if (pil1==1){
        printf("Pilihan Anda: %s\nJumlah: %d\nHarga: Rp%d\n", pakethemat[i].nama, jumlah, pakethemat[i].harga);}
    else if (pil1==2){
        printf("\nPilihan Anda: %s\nJumlah: %d\nHarga: Rp%d\n", burger[j].nama, jumlah, burger[j].harga);}
    else if (pil1==3){
        printf("\nPilihan Anda: %s\nJumlah: %d\nHarga: Rp%d\n", minuman[k].nama, jumlah, minuman[k].harga);}
    else if (pil1==4){
        printf("\nPilihan Anda: %s\nJumlah: %d\nHarga: Rp%d\n", menupenutup[l].nama, jumlah, menupenutup[l].harga);}
    fflush(stdin);
    puts("");
    pesanLagi();
                }
            }
        }
    }
}
void pesanLagi(){
    char lagi;
    printf("Ingin memesan kembali? (y/t): ");scanf("%c",&lagi);
    if(lagi=='y')
        HalMenu();
    else exit(0);
}
