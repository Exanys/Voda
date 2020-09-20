/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vojta
 *
 * Created on September 19, 2020, 9:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define VSTUP "cisla.txt"
#define VYSTUP "hladiny.txt"

float objem(int pol, int vys){
    float polDM = pol / 10.0;
    float vysDM = vys / 10.0;
    return 3.14 * polDM * polDM * vysDM;
}

float hlad(float pol, float litr){
    float litrCM = litr * 1000;
    return litrCM / (3.14 * pol * pol);
}



int main(int argc, char** argv) {
    
    FILE * vstup;
    FILE * vystup;
    int pol, vys, mnoz;
    int poradi = 0, poradiS = 0;
    
    if((vstup = fopen(VSTUP, "r"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VSTUP);
    if((vystup = fopen(VYSTUP, "w"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VYSTUP);
    
    printf("V A L C E\n");
    printf("---------\n");
    printf("    polomer    vyska   objem valce    mnozstvi vody\n");
    printf("    (cm)       (cm)  (dm krychlove)         (litry)\n"); 
    printf("---------------------------------------------------\n");
    fprintf(vystup, "V A L C E  S  V Y H O V U J I C I M  O B J E M E M\n");
    fprintf(vystup, "--------------------------------------------------\n");
    fprintf(vystup, "    polomer    vyska   objem valce    mnozstvi vody  vyska hladiny\n");
    fprintf(vystup, "    (cm)       (cm)  (dm krychlove)         (litry)           (cm)\n");
    fprintf(vystup, "------------------------------------------------------------------\n");
    while((fscanf(vstup, "%d %d %d", &pol, &vys, &mnoz)) != EOF){
        poradi++;
        float obj = objem(pol, vys);
        printf("%2d.%5d cm%6d cm%11.2f dm%10d l     \n",poradi, pol, vys, obj, mnoz);
        if(obj > (float)mnoz){
            poradiS++;
            fprintf(vystup, "%2d.%5d cm%6d cm%11.2f dm%14d l%13.2f cm\n",poradiS, pol, vys, obj, mnoz, hlad(pol, mnoz));
        }
    }
    printf("---------------------------------------------------\n");
    fprintf(vystup, "------------------------------------------------------------------\n");
    
    if((fclose(vstup))== EOF)
        printf("Soubor %s se nepodarilo uzavrit.\n", VSTUP);
    if((fclose(vystup))== EOF)
        printf("Soubor %s se nepodarilo uzavrit.\n", VYSTUP);
    else
        printf("Soubor %s byl vytvoren.\n", VYSTUP);
    
    
    return (EXIT_SUCCESS);
}

