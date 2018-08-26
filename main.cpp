/////////////////////////// Conversiones Numéricas y Codificación de Haming ///////////////////////////

//Librerías
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

//////////////// SUBRUTINAS ////////////////
//Comprobación Número Hexadecimal de 3 dígitos
int Comprobacion(char hexaDecimal[1000]){
    int i=0;
    while (hexaDecimal[i]){
        if((int(hexaDecimal[i])<48) || ((int(hexaDecimal[i])>57)&&int(hexaDecimal[i])<65) || (int(hexaDecimal[i])>70)) {
            cout<<"\nERROR: Número NO hexadecimal. \n";
            return 0;}
        i+=1;
    }
    if (strlen(hexaDecimal)>3){
        cout<<"\nERROR: Número con más de 3 dígitos. \n";
        return 0;}
    return 1;
}

// Conversión de Hexadecimal a Binario
long long HexaToBinary(char hexaDecimal[2]){
    int i=0, e=8;
    long long binario=0, n;
    while (i<3){
        n=(int)round(pow(10,e));
        switch(hexaDecimal[i]){
            case '0': binario += n*0000; break;
            case '1': binario += n*0001; break;
            case '2': binario += n*0010; break;
            case '3': binario += n*0011; break;
            case '4': binario += n*0100; break;
            case '5': binario += n*0101; break;
            case '6': binario += n*0110; break;
            case '7': binario += n*0111; break;
            case '8': binario += n*1000; break;
            case '9': binario += n*1001; break;
            case 'A': binario += n*1010; break;
            case 'B': binario += n*1011; break;
            case 'C': binario += n*1100; break;
            case 'D': binario += n*1101; break;
            case 'E': binario += n*1110; break;
            case 'F': binario += n*1111; break;
            default: cout<<"\nDigito Hexadecimal Invalido"<<hexaDecimal[i];
        }
        i++; e=e-4;
    }
    return binario;
}

//Conversión de Binario a Decimal
long BinaryToDecimal(long long binary){
    long NumDecimal =0;
    int i=0;
    long long remainder;
    while (binary!=0){
        remainder=binary%10;
        binary/=10;
        int n=(int)round(pow(2,i));
        NumDecimal += n*remainder;
        ++i; }
    return NumDecimal;
}

//Conversión de Decimal a Binario
long long DecimalToBinary(long long Decimal){
    long long NumBinario = 0, remainder, i = 1;
    while (Decimal!=0) {
        remainder = Decimal%2;
        Decimal /= 2;
        NumBinario += remainder*i;
        i *= 10;
    }
    return NumBinario;
}

//Conversión de Decimal a BCD
long long DecimalToBCD(long Decimal){
    long long NumBCD = 0, remainder;
    int i = 0;
    while (Decimal!=0) {
        remainder = Decimal%10;
        Decimal = Decimal/10;
        int n = (int)round(pow(10,i));
        NumBCD += n*DecimalToBinary(remainder);
        i=i+4;
    }
    return NumBCD;
}

int main() {
    char hexaDecimal[1000];
    long long binario, BCD;
    long decimal;

    //Comprobación
    while (true){
        cout<<"Ingresar un número hexadecimal de 3 dígitos: ";
        cin>>hexaDecimal;
        if (Comprobacion(hexaDecimal)==1)
            break;
    }
    //Conversión a Binario
    binario=HexaToBinary(hexaDecimal);
    cout<<"\nEl número ingresado convertido en binario es: "<<binario;

    //Conversión a Decimal
    decimal=BinaryToDecimal(binario);
    cout<<"\nEl número binario "<<binario<<" convertido en decimal es: "<<decimal;

    //Conversión a BCD
    BCD=DecimalToBCD(decimal);
    cout<<"\nEl número decimal "<<decimal<<" convertido en BCD es: "<<BCD;

    return 0;
}