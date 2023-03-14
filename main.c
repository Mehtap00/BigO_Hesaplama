#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fonk_list{
char fonk_ismi [20];
int zaman_karmasikligi[20];
int k_katsayi[11][11];
int yer_karmasikligi [20];
};

struct fonk_list fonksiyonlar[10];

int yer[10];
int karmasiklik[20][20];
int y_karmasiklik[20][20];
int donguler[20];
int dongulerin_donus_s[20];
int karmasiklik_katsayi[11][11];
int karsilastirma[20][2];
int y_karsilastirma[20][2];
int zaman_n=0,zaman_log_n=0,yer_n=0,yer_log_n=0,fonk_n=0,fonk_log_n=0,cag_n=0,cag_log_n=0,dongu_n=0,dongu_log_n=0,v=0,k=0,j=0,i,y=0,r,g,z,b,p=0,c=0,d,h=0,x,u,t,l,o,aa=0,parantez=0,p_sayi=0,kontrol=0,kontrol2=0,w_var,parantez_var=0,imlec,w_dongusu=0,f_cagirma,recursive_f,cagirma,yineleme_sayisi,tekrar=0,ic_ice_dongu,harf;

char degisken [25];

FILE* fp;

void katar_arama(char *aranilan,char *aranan){
    int indis=0;
    j=0;
    y=0;
    i=0;

    while(i<=(strlen(aranilan)-strlen(aranan))){
       for(y=0;y<strlen(aranan);y++){
       if(aranan[y]!=aranilan[i])
       break;
       i++;}

    if(y==strlen(aranan)){
    yer[j]=indis;
    j++;
    }
    indis++;
    i=indis;}
}



int main()
{
    for(i=0;i<20;i++){
    for(g=0;g<20;g++){
    karmasiklik[i][g]=7;}}

    for(i=0;i<20;i++){
    for(g=0;g<20;g++){
    y_karmasiklik[i][g]=7;}}

    for(i=0;i<11;i++){
        for(j=0;j<11;j++){
        karmasiklik_katsayi[i][j]=0;}}
    g=0;

    fp=fopen("input1.txt","r");

    if(fp==NULL)
    {
        printf("Aranilan dosya bulunamadi.");
        goto cikis;
    }

    char satir[80];
    char satir2[80];


    while(fgets(satir,79,fp)){

    if(strstr(satir,"#include") || strstr(satir,"printf") || strstr(satir,"scanf") && p!=1){
    printf("\n 1-Dosyadaki kod C kodudur.\n\n");
    p=1;}

    if(p!=1){
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32 || satir[i]!='\n'){
    j=1;
    break;}}}

    if(p==1){
    fseek(fp,0,SEEK_SET);
    j=1;
    break;}
    }

    if(j==0){
    printf("\n 1-Dosyada veri bulunmamaktadir.\n\n");}

    if(p==0 && j!=0){
    printf("\n 1-Dosyadaki kodda C koduna özgü bir ifade yoktur.(Kod C kodu olmayabilir.)\n\n");}

    p=0;

    fseek(fp,0,SEEK_SET);

    bas:
    while(fgets(satir,79,fp)){
    imlec=ftell(fp);

    for(x=0;x<h;x++){
    if(strstr(satir,fonksiyonlar[x].fonk_ismi)){

    if(x==h-1)
    recursive_f=1;

    else
    f_cagirma=1;

    ic_ice_dongu++;
    cagirma=1;
    break;}}

    if(parantez==0){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==40)
    break;}

    if(i!=strlen(satir)){
    g=0;
    for(i=0;i<strlen(satir);i++){
    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122))
    break;
    }

    for(i=i+1;i<strlen(satir);i++){
    if(satir[i]==32)
    break;}

    for(i=i+1;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    for(;i<strlen(satir);i++){
    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122))
    break;
    }

    for(;i<strlen(satir);i++){
    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    fonksiyonlar[h].fonk_ismi[g]=satir[i];
    g++;}

    if(satir[i]==40 || satir[i]==32)
    break;}
    h++;}
    }

    if(parantez==0)
    y_karmasiklik[0][0]=1;

    if(strstr(satir,"int ") || strstr(satir,"float ") || strstr(satir,"char ") || strstr(satir,"long ") || strstr(satir,"double ")){
    for(i=0;i<strlen(satir);i++){
    if(satir[i]==44)
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;}

    j=0;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]==91){
    for(y=i+1;;y++){
    if(satir[y]!=32)
    break;}
    if(48>satir[y] || 57<satir[y])
    j++;}}

    if((2*j)>y_karmasiklik[0][0])
    y_karmasiklik[0][0]=2*j;
    }

    if(strstr(satir,"if") ||  strstr(satir,"else") || strstr(satir,"switch") || strstr(satir,"case"))
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;

    if(strstr(satir,";") && (strstr(satir,"while")==0) && (strstr(satir,"for")==0)) //;
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;


    if(strstr(satir,"while")){
    w_var=1;

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==59)
    w_var=0;}

    if(w_var!=0){
    w_dongusu=1;
    ic_ice_dongu++;}}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123)
    parantez++;}


    if(strstr(satir,"for")){
    ic_ice_dongu++;

    karmasiklik_katsayi[dongu_n][dongu_log_n]+=2;

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123){
    parantez_var=1;
    donguler[v]=parantez;
    v++;
    break;}}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==59)
    break;}

    for(i=i+1;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    strcpy(degisken,"a");
    y=0;

    for(;i<strlen(satir);i++){
    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    degisken[y]=satir[i];
    y++;}
    else
    break;}

    for(;i<strlen(satir);i++){
    if(satir[i]==59){
    break;}

    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    harf=1;
    break;}}

    if(harf==1){

    for(;i<strlen(satir);i++){
    if(satir[i]==59)
    break;}

    for(i=i+1;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}

    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];
    kontrol=0;
    }

    strcpy(satir2,"a");
    j=0;
    for(;i<strlen(satir);i++){
    satir2[j]=satir[i];
    j++;}

    if(strstr(satir2,degisken)){
    if(strstr(satir2,"++") || strstr(satir2,"--") || strstr(satir2,"+=") || strstr(satir2,"-=")){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;
    p=1;}

    else if(strstr(satir2,"/=") || strstr(satir2,"*=")){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;
    p=1;}

    else{
    katar_arama(satir2,degisken);
    j=yer[0]+strlen(degisken);

    for(;j<strlen(satir2);j++){
    if(satir2[j]!=32)
    break;}

    if(satir2[j]==61){
    j++;

    for(;j<strlen(satir2);j++){
    if(satir2[j]!=32)
    break;}

    if(j==yer[1]){
    if(satir2[j+strlen(degisken)]==43 || satir2[j+strlen(degisken)]==45){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;
    p=1;}

    else if(satir2[j+strlen(degisken)]==42 || satir2[j+strlen(degisken)]==47){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;
    p=1;}}}
    }}

    else if(strstr(satir2,degisken)==0)
    karmasiklik[k][ic_ice_dongu]=1;

    if(p!=1){
    if(parantez_var==1)
    p_sayi++;}

    tekrar=0;
    while(fgets(satir,79,fp)){

    if(tekrar==0 && parantez_var!=1){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32 && satir[i]!=123)
    break;

    if(satir[i]==123){
    parantez_var=1;
    donguler[v]=parantez+1;
    v++;
    break;}}}

    if(p!=1){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123)
    p_sayi++;}

    if(strstr(satir,degisken)){

    printf("a");
    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}

    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];
    kontrol=0;}

    if(strstr(satir,"++") || strstr(satir,"--") || strstr(satir,"+=") || strstr(satir,"-=")){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;}

    else if(strstr(satir,"/=") || strstr(satir,"*=")){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;}

    else{
    katar_arama(satir,degisken);
    j=yer[0]+strlen(degisken);

    for(;j<strlen(satir);j++){
    if(satir[j]!=32)
    break;}

    if(satir[j]==61){
    j++;

    for(;j<strlen(satir);j++){
    if(satir[j]!=32)
    break;}

    if(j==yer[1]){
    if(satir[j+strlen(degisken)]==43 || satir[j+strlen(degisken)]==45){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;}

    else if(satir[j+strlen(degisken)]==42 || satir[j+strlen(degisken)]==47){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;}}}
    }}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==125)
    p_sayi--;}
    }

    if(p!=1 && p_sayi==0 && tekrar>0){
    karmasiklik_katsayi[dongu_n][dongu_log_n]--;
    p=0;}

    tekrar++;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}
    if(satir[i]=='\n')
    tekrar--;
    harf=0;
    if(p_sayi==0 && tekrar>0)
    break;
    }}

    else if (harf==0){
    tekrar=0;

    while(fgets(satir,79,fp)){

    if(tekrar==0 && parantez_var!=1){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32 && satir[i]!=123)
    break;

    if(satir[i]==123){
    parantez_var=1;
    donguler[v]=parantez+1;
    v++;
    break;}}}

    dongulerin_donus_s[aa]=1;
    aa++;

    tekrar++;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}
    if(satir[i]=='\n')
    tekrar--;

    if(tekrar>0)
    break;
    }

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}
    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];
    kontrol=0;}

    karmasiklik[k][ic_ice_dongu]=1;
    }

    if(parantez_var!=1){
    ic_ice_dongu--;
    kontrol=1;
    k++;
    dongulerin_donus_s[aa-1]=1;
    aa--;}

    karmasiklik_katsayi[dongu_n][dongu_log_n]+=2;

    parantez_var=0;
    fseek(fp,imlec,SEEK_SET);
    goto bas;
    }


    if(w_dongusu==1){
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==40)
    break;
    }

    for(i=i+1;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    strcpy(degisken,"a");
    y=0;

    for(;i<strlen(satir);i++){
    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    degisken[y]=satir[i];
    y++;}
    else
    break;}

    for(;i<strlen(satir);i++){
    if(satir[i]==41){
    break;}

    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    harf=1;
    break;}}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123){
    parantez_var=1;
    p_sayi++;
    donguler[v]=parantez;
    v++;
    break;}}

    if(harf==1){
    tekrar=0;

    while(fgets(satir,79,fp)){

    if(tekrar==0 && parantez_var!=1){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32 && satir[i]!=123)
    break;

    if(satir[i]==123){
    parantez_var=1;
    donguler[v]=parantez+1;
    v++;
    break;}}}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123)
    p_sayi++;}

    if(strstr(satir,degisken)){

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}

    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];
    kontrol=0;}

    if(strstr(satir,"++") || strstr(satir,"--") || strstr(satir,"+=") || strstr(satir,"-=")){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;}

    else if(strstr(satir,"/=") || strstr(satir,"*=")){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;}

    else{
    katar_arama(satir,degisken);
    j=yer[0]+strlen(degisken);

    for(;j<strlen(satir);j++){
    if(satir[j]!=32)
    break;}

    if(satir[j]==61){
    j++;

    for(;j<strlen(satir);j++){
    if(satir[j]!=32)
    break;}

    if(j==yer[1]){
    if(satir[j+strlen(degisken)]==43 || satir[j+strlen(degisken)]==45){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;}

    else if(satir[j+strlen(degisken)]==42 || satir[j+strlen(degisken)]==47){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;}}}
    }}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==125)
    p_sayi--;}

    tekrar++;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}
    if(satir[i]=='\n')
    tekrar--;
    harf=0;

    if(p_sayi==0 && tekrar>0)
    break;}
    }

    else if (harf==0){
    tekrar=0;

    while(fgets(satir,79,fp)){

    if(tekrar==0 && parantez_var!=1){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32 && satir[i]!=123)
    break;

    if(satir[i]==123){
    parantez_var=1;
    donguler[v]=parantez+1;
    v++;
    break;}}}

    tekrar++;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    if(satir[i]=='\n')
    tekrar--;

    if(tekrar>0)
    break;
    }

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}
    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];
    kontrol=0;}

    dongulerin_donus_s[aa]=1;
    aa++;

    karmasiklik[k][ic_ice_dongu]=1;
    }

    if(parantez_var!=1){
    ic_ice_dongu--;
    kontrol=1;
    k++;
    dongulerin_donus_s[aa-1]=1;
    aa--;}

    parantez_var=0;
    w_dongusu=0;
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;
    fseek(fp,imlec,SEEK_SET);
    goto bas;
    }


    if(strstr(satir,"do")){
    ic_ice_dongu++;
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123){
    parantez_var=1;
    p_sayi++;
    donguler[v]=parantez;
    v++;
    p=1;
    break;}}

    tekrar=0;
    while(fgets(satir,79,fp)){

    if(tekrar==0 && parantez_var!=1){
    for(i=0;i<strlen(satir);i++){

    if(satir[i]!=32 && satir[i]!=123)
    break;

    if(satir[i]==123){
    parantez_var=1;
    donguler[v]=parantez+1;
    v++;
    break;}}}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==123)
    p_sayi++;}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==125)
    p_sayi--;}

    if(p_sayi==0 && tekrar>0){

    if(strstr(satir,"while")){

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==40)
    break;}

    for(i=i+1;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    strcpy(degisken,"a");
    y=0;

    for(;i<strlen(satir);i++){

    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    degisken[y]=satir[i];
    y++;}

    else
    break;}

    goto ileri;}
    }

    tekrar++;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}
    if(satir[i]=='\n')
    tekrar--;
    }

    ileri:
    for(;i<strlen(satir);i++){
    if(satir[i]==41){
    break;}

    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    harf=1;
    break;}}

    if(harf==1){

    fseek(fp,imlec,SEEK_SET);

    if(p==1){
    p_sayi++;
    p=0;}

    tekrar=0;
    while(fgets(satir,79,fp)){

    for(i=0;i<=strlen(satir);i++){
    if(satir[i]==123)
    p_sayi++;}

    if(strstr(satir,degisken)){

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}
    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];}

    if(strstr(satir,"++") || strstr(satir,"--") || strstr(satir,"+=") || strstr(satir,"-=")){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;}

    else if(strstr(satir,"/=") || strstr(satir,"*=")){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;}

    else{
    katar_arama(satir,degisken);
    j=yer[0]+strlen(degisken);

    for(;j<strlen(satir);j++){
    if(satir[j]==32)
    j++;
    else
    break;}

    if(satir[j]==61){
    j++;

    for(;j<strlen(satir);j++){
    if(satir[j]==32)
    j++;
    else
    break;}

    if(j==yer[1]){
    if(satir[j+strlen(degisken)]==43 || satir[j+strlen(degisken)]==45){
    karmasiklik[k][ic_ice_dongu]=2;
    dongu_n++;
    dongulerin_donus_s[aa]=2;
    aa++;}

    else if(satir[j+strlen(degisken)]==42 || satir[j+strlen(degisken)]==47){
    karmasiklik[k][ic_ice_dongu]=3;
    dongu_log_n++;
    dongulerin_donus_s[aa]=3;
    aa++;}}}
    }}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==125)
    p_sayi--;}

    tekrar++;
    for(i=0;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}
    if(satir[i]=='\n')
    tekrar--;
    harf=0;
    if(p_sayi==0 && tekrar>0)
    break;}
    }

    else if (harf==0){

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}
    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];}

    karmasiklik[k][ic_ice_dongu]=1;
    dongulerin_donus_s[aa]=1;
    aa++;
    }

    if(parantez_var!=1){
    ic_ice_dongu--;
    kontrol=1;
    k++;
    dongulerin_donus_s[aa-1]=1;
    aa--;}

    parantez_var=0;
    karmasiklik_katsayi[dongu_n][dongu_log_n]++;
    fseek(fp,imlec,SEEK_SET);
    goto bas;
    }


    if(f_cagirma==1 && cagirma==1){

    if(kontrol==1){
    for(i=k-1;i>=0;i--){
    if(karmasiklik[i][1]!=7)
    break;}
    for(y=1;y<ic_ice_dongu;y++)
    karmasiklik[k][y]=karmasiklik[i][y];}

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==40){
    i++;
    break;}}

    for(;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    y=ic_ice_dongu;
    i=1;

    for(i=1;;i++){
    if(fonksiyonlar[x].zaman_karmasikligi[i]!=0){
    karmasiklik[k][y]=fonksiyonlar[x].zaman_karmasikligi[i];
    y++;
    }
    else
    break;}

    if(dongu_n!=0){
    for(i=10;i>=0;i--){
    for(j=10;j>=0;j--){
    if((i-dongu_n)>=0 && (j-dongu_log_n)>=0){
    karmasiklik_katsayi[i][j]+=fonksiyonlar[x].k_katsayi[i-dongu_n][j-dongu_log_n];}}}
    }

    else if(dongu_n==0){
    for(i=10;i>=0;i--){
    for(j=10;j>=0;j--){
    karmasiklik_katsayi[i][j]+=fonksiyonlar[x].k_katsayi[i][j];}}
    }}

    j=1;
    for(i=0;;i++){
    if(fonksiyonlar[x].yer_karmasikligi[i]!=0){
    y_karmasiklik[k][j]=fonksiyonlar[x].yer_karmasikligi[i];
    j++;}
    else
    break;}

    for(i=1;i<ic_ice_dongu;i++){
    y_karmasiklik[k][j]=karmasiklik[k][i];
    j++;}

    if(y_karmasiklik[k][0]==2)
    fonk_n++;
    if(y_karmasiklik[k][0]==3)
    fonk_log_n++;
    if(y_karmasiklik[k][0]>=4)
    fonk_n=fonk_n+(y_karmasiklik[k][0]/2);

    i=1;
    while(y_karmasiklik[k][i]!=7){
    if(y_karmasiklik[k][i]==2)
    cag_n++;
    if(y_karmasiklik[k][i]==3)
    cag_log_n++;
    if(y_karmasiklik[k][i]>=4)
    cag_n=cag_n+(y_karmasiklik[k][i]/2);
    i++;}

    if(cag_n>fonk_n)
    y_karmasiklik[k][0]=1;

    else if(cag_n==fonk_n && cag_log_n>=fonk_log_n)
    y_karmasiklik[k][0]=1;

    else if(cag_n<fonk_n && (fonk_n-cag_n)*4>=cag_log_n){
    i=1;
    while(y_karmasiklik[k][i]!=7){
    y_karmasiklik[k][i]=1;
    i++;
    }}

    else
    y_karmasiklik[k][0]=1;

    fonk_n=0;
    fonk_log_n=0;
    cag_n=0;
    cag_log_n=0;

    ic_ice_dongu--;
    k++;
    kontrol=1;
    f_cagirma=0;
    cagirma=0;
    }

    if(recursive_f==1 && cagirma==1){
    for(i=0;i<strlen(satir);i++){
    if(satir[i]==40){
    i++;
    break;}}

    for(;i<strlen(satir);i++){
    if(satir[i]!=32)
    break;}

    if((65<=satir[i] && satir[i]<=90) || (97<=satir[i] && satir[i]<=122)){
    yineleme_sayisi=2;
    dongu_n++;
    b=dongu_n;
    l=k;
    }

    else{
    dongu_n--;
    p=0;}

    ic_ice_dongu--;
    cagirma=0;
    }

    for(i=0;i<strlen(satir);i++){
    if(satir[i]==125){
    parantez--;
    for(y=v-1;y>=0;y--){
    if(donguler[y]==parantez+1){
    ic_ice_dongu--;
    v--;
    kontrol=1;
    k++;

    if(dongulerin_donus_s[aa-1]==2)
    dongu_n--;

    if(dongulerin_donus_s[aa-1]==3)
    dongu_log_n--;

    dongulerin_donus_s[aa-1]=1;
    aa--;
    break;}}
    kontrol2=1;}
    }

    z=0;
    if(parantez==0 && h>0 && kontrol2==1){
    r=1;
    for(i=0;i<20;i++){
    r=1;
    while(karmasiklik[i][r]!=7){
    if(karmasiklik[i][r]==2)
    zaman_n++;
    if(karmasiklik[i][r]==3)
    zaman_log_n++;
    r++;
    z++;}
    karsilastirma[i][0]=zaman_n;
    karsilastirma[i][1]=zaman_log_n;
    zaman_n=0;
    zaman_log_n=0;
    r=1;}

    y=0;
    if(z>1){
    for(i=0;i<20;i++){
    if(karsilastirma[y][0]<karsilastirma[i][0])
    y=i;

    if(karsilastirma[y][0]==karsilastirma[i][0]){
    if(karsilastirma[y][1]<karsilastirma[i][1])
    y=i;
    }}}

    zaman_n=0;
    zaman_log_n=0;
    r=1;
    while(karmasiklik[y][r]!=7){
    if(karmasiklik[y][r]==2)
    zaman_n++;
    if(karmasiklik[y][r]==3)
    zaman_log_n++;
    r++;}

    u=0;
    o=0;
    for(i=0;i<20;i++){
    o=0;
    while(y_karmasiklik[i][o]!=7){
    if(y_karmasiklik[i][o]==2)
    yer_n++;
    if(y_karmasiklik[i][o]==3)
    yer_log_n++;
    if(y_karmasiklik[i][o]>=4)
    yer_n=yer_n+(y_karmasiklik[i][o]/2);
    o++;
    u++;}
    y_karsilastirma[i][0]=yer_n;
    y_karsilastirma[i][1]=yer_log_n;
    yer_n=0;
    yer_log_n=0;
    o=0;}

    t=0;
    if(u>1){
    for(i=0;i<20;i++){
    if(y_karsilastirma[t][0]<y_karsilastirma[i][0])
    t=i;

    if(y_karsilastirma[t][0]==y_karsilastirma[i][0]){
    if(y_karsilastirma[t][1]<y_karsilastirma[i][1])
    t=i;
    }}}

    yer_n=0;
    yer_log_n=0;
    r=0;
    while(y_karmasiklik[t][r]!=7){
    if(y_karmasiklik[t][r]==2)
    yer_n++;
    if(y_karmasiklik[t][r]==3)
    yer_log_n++;
    if(y_karmasiklik[t][r]>=4)
    yer_n=yer_n+(y_karmasiklik[t][r]/2);
    r++;}


    if(recursive_f==1){

    if(z==0){
    r=2;
    karmasiklik[0][1]=yineleme_sayisi;
    if(yineleme_sayisi==2)
    zaman_n++;

    for(i=1;i<2;i++){
    fonksiyonlar[h-1].zaman_karmasikligi[i]=karmasiklik[0][i];
    }
    recursive_f=0;

    for(i=1;i>=0;i--){
    for(j=1;j>=0;j--){
    if((i-b)>=0){
    karmasiklik_katsayi[i][j]+=karmasiklik_katsayi[i-b][j];
    karmasiklik_katsayi[i-b][j]=0;}}}

    for(i=0;i<2;i++){
    for(j=0;j<2;j++){
    fonksiyonlar[h-1].k_katsayi[i][j]=karmasiklik_katsayi[i][j];}}


    if(u!=0){
    for(i=0;;i++){
    if(y_karmasiklik[t][i]==7)
    break;}
    r=i;

    y_karmasiklik[t][r]=yineleme_sayisi;
    if(yineleme_sayisi==2)
    yer_n++;

    for(i=0;i<=r;i++){
    fonksiyonlar[h-1].yer_karmasikligi[i]=y_karmasiklik[t][i];}
    recursive_f=0;}
    }

    if(u==0){
    fonksiyonlar[h-1].yer_karmasikligi[0]=1;
    recursive_f=0;}

    if (z!=0){
    for(i=1;;i++){
    if(karmasiklik[y][i]==7)
    break;}
    r=i;

    karmasiklik[y][r]=yineleme_sayisi;
    if(yineleme_sayisi==2)
    zaman_n++;

    for(i=1;i<=r;i++){
    fonksiyonlar[h-1].zaman_karmasikligi[i]=karmasiklik[y][i];}
    recursive_f=0;

    for(i=10;i>=0;i--){
    for(j=10;j>=0;j--){
    if((i-b)>=0){
    karmasiklik_katsayi[i][j]+=karmasiklik_katsayi[i-b][j];
    karmasiklik_katsayi[i-b][j]=0;}}}

    for(i=0;i<11;i++){
    for(j=0;j<11;j++){
    fonksiyonlar[h-1].k_katsayi[i][j]=karmasiklik_katsayi[i][j];}}

    if(u!=0){
    i=1;
    while(karmasiklik[l][i]!=7){
    y_karmasiklik[t][i]=karmasiklik[l][i];
    i++;
    }

    if(yineleme_sayisi==2)
    yer_n++;

    for(j=0;j<i;j++){
    fonksiyonlar[h-1].yer_karmasikligi[j]=y_karmasiklik[t][j];}

    for(o=1;o<i;o++){
    if(y_karmasiklik[t][o]==2)
    yer_n++;
    if(y_karmasiklik[t][o]==3)
    yer_log_n++;
    if(y_karmasiklik[t][o]>=4)
    yer_n=yer_n+(y_karmasiklik[t][o]/2);}}
    }}

    else{
    if(z==0){
    r=2;

    for(i=1;i<r;i++){
    fonksiyonlar[h-1].zaman_karmasikligi[i]=karmasiklik[0][i];}}

    if(u==0){
    fonksiyonlar[h-1].yer_karmasikligi[0]=y_karmasiklik[0][0];}

    if(z!=0){
    for(i=1;;i++){
    if(karmasiklik[y][i]==7)
    break;}
    r=i;

    for(i=1;i<=r;i++)
    fonksiyonlar[h-1].zaman_karmasikligi[i]=karmasiklik[y][i];}

    if(u!=0){
    for(i=0;;i++){
    if(y_karmasiklik[t][i]==7)
    break;}
    r=i;

    for(i=0;i<=r;i++)
    fonksiyonlar[h-1].yer_karmasikligi[i]=y_karmasiklik[t][i];}
    }

    for(i=0;i<20;i++){
    for(g=0;g<20;g++){
    karmasiklik[i][g]=7;}}

    for(i=0;i<20;i++){
    for(g=0;g<20;g++){
    y_karmasiklik[i][g]=7;}}

    for(i=0;i<20;i++){
    donguler[i]=0;}

    for(i=0;i<20;i++){
    dongulerin_donus_s[i]=0;}

    g=0;

    if(c==(h-1)){
    if(strcmp(fonksiyonlar[c].fonk_ismi,"main")==0)
    printf(" %s Fonksiyonunun (Kodun Tamaminin) Karmasiklik Analizi:\n",fonksiyonlar[c].fonk_ismi);

    else
    printf(" %s Fonksiyonunun Karmasiklik Analizi:\n",fonksiyonlar[c].fonk_ismi);}
    c++;

    if(zaman_log_n==0 && zaman_n==0)
    printf(" 2-Zaman Karmasikligi: O(1)\n");

    else if(zaman_log_n==0){
    if(zaman_n==1){
    printf(" 2-Zaman Karmasikligi: O(n)\n");}

    else if(zaman_n>1)
    printf(" 2-Zaman Karmasikligi: O(n^%d)\n",zaman_n);
    }

    else if(zaman_n==0){
    if(zaman_log_n==1)
    printf(" 2-Zaman Karmasikligi: O(logn)\n");

    else if(zaman_log_n>1)
    printf(" 2-Zaman Karmasikligi: O(logn^%d)\n",zaman_log_n);
    }

    else{
    printf(" 2-Zaman Karmasikligi: O(n^%d * logn^%d)\n",zaman_n,zaman_log_n);}

    if(yer_log_n==0 && yer_n==0)
    printf(" 3-Yer(Hafiza) Karmasikligi: O(1)\n");

    else if(yer_log_n==0){
    if(yer_n==1){
    printf(" 3-Yer(Hafiza) Karmasikligi: O(n)\n");}

    else if(yer_n>1)
    printf(" 3-Yer(Hafiza) Karmasikligi: O(n^%d)\n",yer_n);}

    else if(yer_n==0){
    if(yer_log_n==1)
    printf(" 3-Yer(Hafiza) Karmasikligi: O(logn)\n");

    else if(yer_log_n>1)
    printf(" 3-Yer(Hafiza) Karmasikligi: O(logn^%d)\n",yer_log_n);}

    else {
    printf(" 3-Yer(Hafiza) Karmasikligi: O(n^%d * logn^%d)\n",yer_n,yer_log_n);
    }

    printf(" 4-Kod Calistirildiginda Gecen Sure:");
       d=0;
       for(i=10;i>=0;i--){
        for(j=10;j>=0;j--){
        if(karmasiklik_katsayi[i][j]!=0){

        if(i==0 && j==0){
        if(d==1){
        printf("+");
        d=0;}
        printf(" %d",karmasiklik_katsayi[i][j]);
        d=1;}

        else if(i==0){
        if(d==1){
        printf("+");
        d=0;}
        printf(" %d*logn^%d ",karmasiklik_katsayi[i][j],j);
        d=1;}

        else if(j==0){
        if(d==1){
        printf("+");
        d=0;}
        printf(" %d*n^%d ",karmasiklik_katsayi[i][j],i);
        d=1;}

        else{
        if(d==1){
        printf("+");
        d=0;}
        printf(" %d*n^%d*logn^%d ",karmasiklik_katsayi[i][j],i,j);
        d=1;}
        }}}

    printf("\n\n");
    if(c==1)
    printf("\n");

    kontrol2=0;
    for(i=10;i>=0;i--){
        for(j=10;j>=0;j--){
        karmasiklik_katsayi[i][j]=0;}}

    parantez_var=0;
    p=0;
    v=0;
    dongu_n=0;
    dongu_log_n=0;
    zaman_log_n=0;
    yer_log_n=0;
    zaman_n=0;
    yer_n=0;
    k=0;
    kontrol=0;
    ic_ice_dongu=0;
    yineleme_sayisi=0;
    j=0;
    }
    }

    fclose(fp);
    cikis:
    return 0;
}
