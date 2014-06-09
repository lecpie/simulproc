#include "machine.h"

#include <stdio.h>
#include <stdlib.h>

void load_program(Machine *pmach,
                  unsigned textsize, Instruction text[textsize],
                  unsigned datasize, Word data[datasize],  unsigned dataend)
{
    //TODO piege ? recopier tableau ?
    pmach->_textsize = textsize;
    pmach->_text     = text;
    pmach->_datasize = datasize;
    pmach->_data     = data;
    pmach->_dataend  = dataend;

    // initialisation des registres
    for (int i = 0; i < NREGISTERS; ++i)
        pmach->_registers[i] = 0;
}

void read_program(Machine *mach, const char *programfile)
{
    unsigned textsize, datasize, dataend;
    Instruction * text;
    Word * data;

    FILE * file = fopen(programfile, "r");

    fread(&textsize, 1, sizeof(unsigned), file);
    fread(&datasize, 1, sizeof(unsigned), file);
    fread(&dataend,  1, sizeof(unsigned), file);

    // Allocation memoire instruction et texte
    //TODO faire mieux
    //TODO verifier si il ne faut pas utiliser un seul tableau

    text = malloc(sizeof(Instruction) * textsize);
    data = malloc(sizeof(Word)        * datasize);

    fread (text, sizeof(Instruction), textsize, file);
    fread (data, sizeof(Word),        datasize, file);

    load_program(mach, textsize, text, datasize, data, dataend);

    fclose(file);
}

void dump_memory(Machine *pmach)
{

}

void print_program(Machine *pmach)
{

}

void print_data(Machine *pmach)
{

}

void print_cpu(Machine *pmach)
{
    printf("*** CPU ***\n");

    for (int i = 0; i < NREGISTERS; )
    {
        for (int j = 0; i < NREGISTERS && j < 3; ++i, ++j) {
            printf("R%02d %#010x % 6d ", i, pmach->_registers[i], pmach->_registers[i]);
        }

        printf("\n");
    }

    printf("\n\n");
}

void simul(Machine *pmach, bool debug)
{

}
