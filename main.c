#include <stdio.h>
#include <stdlib.h>

void FileEncrypt( char *clearFileName, char *encryptedFileName, char password );
void FileDecode( char *encryptedFileName, char *clearFileName,char password );

int main()
{
    int selection;
    char clearFileName[200];
    char encryptedFileName[200];
    char password;

    printf( "1. Dosya Sifrele\n2.Dosya Sifre Coz\n3.Cikis\nSecimizi Yapin:" );
    scanf( "%d" , &selection );

    switch ( selection )
    {
    case 1:
        printf( "Sifrelenecek dosyayi ismini yaziniz:" );
        scanf( "%s" , clearFileName );
        fflush(stdin);
        printf( "Sifreli dosyanin ismini yaziniz:" );
        scanf( "%s" , encryptedFileName );
        fflush(stdin);
        printf( "Sifre giriniz (1-127 arasinda veya tek karakter harf):" );
        scanf( "%s" , &password );
        FileEncrypt( clearFileName, encryptedFileName, password );
        break;
    case 2:
        printf( "Sifreli dosyanin ismini yaziniz:" );
        scanf( "%s" , encryptedFileName );
        fflush(stdin);
        printf( "Sifrelenecek dosyayi ismini yaziniz:" );
        scanf( "%s" , clearFileName );
        fflush(stdin);
        printf( "Sifre giriniz (1-127 arasinda veya tek karakter harf):" );
        scanf( "%s" , &password );
        FileDecode( encryptedFileName, clearFileName, password );
        break;
    case 3:
        printf( "Program kapanmistir." );
        break;
    default:
        printf( "Hatali secim yaptiniz" );
        break;
    }
    return 0;
}

void FileEncrypt( char *clearFileName, char *encryptedFileName, char password )
{
    char temp;
    FILE *clearFile = fopen( clearFileName, "r" );
    if ( clearFile == NULL )
    {
        printf("Sifrelenecek Dosya Acilamadi.\n");
    }
    else
    {
        FILE *encryptedFile = fopen( encryptedFileName, "w" );
        while( ( temp = fgetc( clearFile )) != EOF )
        {
            fputc( temp + password, encryptedFile );
        }
        fclose(clearFile);
        fclose(encryptedFile);
        printf( "Dosyaniz Basariyla Sifrelenmistir. Sifreli dosyanin ismi : %s", encryptedFileName );
    }

}

void FileDecode( char *encryptedFileName, char *clearFileName,char password )
{
    char temp;
    FILE *encryptedFile = fopen( encryptedFileName, "r" );
    if ( encryptedFile == NULL )
    {
        printf("Sifreli Dosya Acilamadi.\n");
    }
    else
    {
        FILE *clearFile = fopen( clearFileName, "w" );
        while( ( temp = fgetc( encryptedFile )) != EOF )
        {
            fputc( temp - password, clearFile );
        }
        fclose(clearFile);
        fclose(encryptedFile);
        printf( "Girdiginiz sifreye gore dosyanizin sifresi cozulmustur. Sifresiz dosyanin ismi : %s", clearFileName);
    }

}