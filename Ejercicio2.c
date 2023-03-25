/* Ejercicio 2: Desarrolle un programa en C que permita registrar las citas médicas de la clínica ABC de n
cantidad de pacientes, permitiendo mostrar por pantalla: 1) Cantidad de pacientes femeninos y masculinos.
2) Cantidad de pacientes mayores y menores de edad. 3) Que permita validar las fechas de nacimiento de cada
paciente. 4) Los pacientes cuya cédula de identidad termine en un número par y sean del sexo femenino tendrán
un descuento del 15% sobre el costo de la consulta. 5) Los pacientes del sexo masculino que tengan una edad
mayor a 60 años tendrán un descuento del 30% */

//Código hecho por Andrés Gubaira (31.006.669) y Gustavo Rivas (30.988.485)
#include <stdio.h>
#include <conio.h>

void main()
{
    int n, i, cedula, dia, mes, year;
    int contfem = 0, contmasc = 0, contmayor = 0, contmenor = 0;
    char sexo, confirmacion;
    printf("Indique el n%cmero de pacientes a registrar.\n", 163);
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        do
        {
            printf("\n\nIndique el g%cnero del paciente %d (M/m/F/f)\n", 130, i);
            scanf(" %c", &sexo);
        } while((sexo != 'M') && (sexo != 'F')&&(sexo != 'm') && (sexo != 'f'));    //Validación de caracter

        if(sexo == 'm' || sexo == 'M')  //Verificación de género
        {
            contmasc++;
        }
        else
        {
            contfem++;
        }

        //Verificación de fecha
        do
        {
        do
        {
            printf("Ingrese su a%co de nacimiento\n", 164);
            scanf("%d", &year);
        } while(year < 1901 || year > 2023);    //Verificación de año
        do
        {
            printf("Ingrese su mes de nacimiento \n");
            scanf("%d", &mes);
        } while(mes < 1 || mes > 12);    //Verificación de mes

        if((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10)||(mes == 12))
        {
            do
            {
                printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 31)\n", 161);
                scanf("%d", &dia);
            } while(dia < 1 || dia > 31);   //Verificación de día para meses de 31 días
        }
        else
        {
            if((mes == 4)||(mes == 6)||(mes == 9)||(mes == 11))
            {
            do
            {
                printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 30)\n", 161);
                scanf("%d", &dia);
            } while(dia < 1 || dia > 30);   //Verificación de día para meses de 30 días
            }
            else
            {
                if((mes == 2)&&(year % 4 == 0))
                {
                do
                {
                    printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 29)\n", 161);
                    scanf("%d", &dia);
                } while(dia < 1 || dia > 29);   //Verificación de día para febrero en años bisiestos
                }
                else
                {
                do
                {
                    printf("Ingrese su d%ca de nacimiento (Entre el 1 y el 28)\n", 161);
                    scanf("%d", &dia);
                } while(dia < 1 || dia > 28);   //Verificación de día para febrero en años no bisiestos
                }
            }
        }
        printf("Fecha de nacimiento: %d/%d/%d. Si desea corregir la fecha escriba C. Si no, escriba cualquier letra.\n", dia, mes, year);
        scanf(" %c", &confirmacion);
        }while(confirmacion == 'C' || confirmacion == 'c');
        
        if(year < 2006)     //Verificación de mayoría de edad
        {
            contmayor++;
        }
        else
        {
            contmenor++;
        }

        do
        {
            printf("Escriba su c%cdula de identidad \n", 130);
            scanf("%d",&cedula);
        } while(cedula <= 0);       //Verificación de cédula

        if(((sexo == 'f')||(sexo == 'F'))&&(cedula % 2 == 0))   //Verificación de descuento del 15%
        {
            printf("Descuento del 15%% disponible.\n");
        }
        if(((sexo == 'm')||(sexo == 'M'))&&(year < 1964))   //Verificación de descuento del 30%
        {
            printf("Descuento del 30%% disponible.\n");
        }
    }
    printf("Contador de hombres: %d. Contador de mujeres: %d. Contador de mayores de edad: %d. Contador de menores de edad: %d \n", contmasc, contfem, contmayor, contmenor);
    getch();
}