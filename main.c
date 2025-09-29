#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, posX, posY, tempx, tempy, teste_charX, teste_charY ;
    char mov;

    char M[tam][tam] = {{'.', '.', '.', '#', '.'},
                        {'.', '#', '.', '#', '.'},
                        {'.', '#', '.', '.', '.'},
                        {'.', '.', '.', '#', 'G'},
                        {'.', '#', '.', '.', '.'}};
    posX= 0;
    posY= 0;
//-------------------------------------------------------------------------------------------
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
             if((i==posX) && (j==posY))
            {
            M[posX][posY] = 'S';
            }
            printf("%c\t", M[i][j]);
        }
        printf("\n");
    }

//-------------------------------------------------------------------------------------------------------------
    while (M[3][4]=='G')
    {

        printf("\n\tPara se mover digite w, s, d ou a: \n\nW-cima\nS-baixo\nD-direita\nA-esquerda\n ");
        scanf (" %c", &mov);

        int heuri = 0;

        heuri = abs (posX - 3) + abs (posY - 4);

        tempx = posX;
        tempy = posY;
        teste_charX = posX;
        teste_charY = posY;

            switch(mov)
        {
            case 'w'://cima
                tempx=teste_charX;
                teste_charX-=1;

                break;

            case 's': //baixo
                tempx=teste_charX;
                teste_charX+=1;

                break;

            case 'd': //direita
                tempy=teste_charY;
                teste_charY+=1;
                break;

            case 'a': //esquerda
                tempy=teste_charY;
                teste_charY-=1;
                break;
        }

        if(M[teste_charX][teste_charY] != ('#'))
        {
            if ((teste_charX >= 0) && (teste_charY >= 0) && (teste_charX < 5) && (teste_charY < 5))
            {
                posX = teste_charX;
                posY = teste_charY;
            }
        }
        else
        {
            posX = tempx;
            posY = tempy;
        }
//------------------------------------------------------------------------------------------------------------------------
            printf ("\nHeurística para Goal: %d\n", heuri);
//------------------------------------------------------------------------------------------------------------------------
            for(i=0; i<tam; i++)
            {
                for(j=0; j<tam; j++)
                {
                    if((i==tempx) && (j==tempy))
                    {
                        M[tempx][tempy] = '.';

                    }
                    if((i==posX) && (j==posY))
                    {
                        M[posX][posY] = 'S';
                    }
                printf("%c\t", M[i][j]);
                }
            printf("\n");
//-----------------------------------------------------------------------------------------------------------------------------
            }
    }

    printf("\n\tParabéns! Você chegou ao objetivo!");

    return 0;
}
