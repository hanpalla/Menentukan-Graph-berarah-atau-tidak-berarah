#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,j,z=0,inputBaris, inputKolom,cek=1,matriks[10][10];
    int c=0,x=1,y=1,tanda[100];
    INPUT:
    system("cls");
    printf("Program Matriks Ketetanggaan\n\n");
    printf("Masukkan jumlah baris dan kolom: ");
    scanf("%d",&inputBaris);
    while (inputBaris <= 1)
    {
        printf("Jumlah kolom dan baris harus lebih dari 1");
        getch();
        goto INPUT;
    }
    inputKolom = inputBaris;

    puts("=====================================\n");
    for (i=1; i<=inputBaris; i++)
    {
        for (j=1; j<=inputKolom; j++)
        {
            if (i != j)
            {
            printf("Jika Vertek %d dan Vertek %d memiliki hubungan, Input berapa hubungan yang ada, Input 0 Jika tidak ada : ",i,j);
            scanf("%d",&matriks[i][j]); // input vertex
            }
        }
    }

    puts("\nMatriks Ketetanggaan.");
    for (i=1; i<=inputBaris; i++)
    {
        printf("\n");
        for (j=1; j<=inputKolom; j++)
        {
            if (i == j)
            {
                matriks[i][j] = z;
                printf("%d ",matriks[i][j]);
            }
            else
            {
                printf("%d ",matriks[i][j]);
            }
        }
    }

    for (i=1; i<=inputBaris; i++) // Mengubah Posisi matriks
    {
        for (j=1; j<=inputKolom; j++)
        {   
            if (i != j)
            {
                tanda[x] = matriks[i][j];
                x++;
            }
            
            else
            {
                tanda[x] = z;
                x++;
            }
        }
    }

    printf("\n\n");
    for (i=1; i<=inputBaris; i++) // Pengecekan graph berarah atau tidak
    {
        for (j=1; j<=inputKolom; j++)
        {
            if (tanda[y] != matriks[i][j])
            {
                printf("%d ",tanda[y]);
                y=y+inputBaris;
                cek=cek*0;
            }
            else if (tanda[y] == matriks[i][j])
            {
                printf("%d ",tanda[y]);             
                y=y+inputBaris;
                cek=cek*1;
            }
        }
        c=c+1;
        y=1;
        y=y+c;
        printf("\n");
    }

    if (cek == 0)
    {
        printf("\nGraph ini memiliki arah");
    }
    else if (cek == 1)
    {
        printf("\nGraph ini tidak memiliki arah");
    }

    return 0;
}
