#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char opcode[20], operand[20], label[20], code[20], mnemonic[20];
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4;
    
    fp1 = fopen("input.txt","r");
    if(fp1 == NULL) {
        printf("Error opening input.txt\n");
        exit(1);
    }
    
    fp2 = fopen("optab.txt","r");
    if(fp2 == NULL) {
        printf("Error opening optab.txt\n");
        exit(1);
    }
    
    fp3 = fopen("symtab.txt","w");
    if(fp3 == NULL) {
        printf("Error opening symtab.txt\n");
        exit(1);
    }
    
    fp4 = fopen("output.txt","w");  
    if(fp4 == NULL) {
        printf("Error opening output.txt\n");
        exit(1);
    }
    

    if(fscanf(fp1,"%s\t%s\t%s", label, opcode, operand) != 3) {
        printf("Error reading first line from input\n");
        exit(1);
    }
    
    if(strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;  
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
        if(fscanf(fp1, "%s\t%s\t%s", label, opcode, operand) != 3) {
            printf("Error reading second line from input\n");
            exit(1);
        }
    }
    else
    {
        locctr = 0;
        start = 0;
    }
    
    while(strcmp(opcode, "END") != 0)
    {    
        fprintf(fp4, "%d\t", locctr);
        
        if(strcmp(label, "**") != 0)
        {
            fprintf(fp3, "%s\t%d\n", label, locctr);
        }
        
        rewind(fp2);
        
        int found = 0;
        while(fscanf(fp2, "%s\t%s", code, mnemonic) == 2)
        {
            if(strcmp(opcode, code) == 0)
            {
                locctr += 3;
                found = 1;
                break;
            }
        }
        
        if(!found) {
            if(strcmp(opcode, "WORD") == 0)
            {
                locctr += 3;
            }
            else if(strcmp(opcode, "RESW") == 0)
            {
                locctr += (3 * (atoi(operand)));
            }
            else if(strcmp(opcode, "RESB") == 0)
            {
                locctr += (atoi(operand));
            }
            else if(strcmp(opcode, "BYTE") == 0)
            {
              
                if(operand[0] == 'C') {
                    locctr += (strlen(operand) - 3); 
                }
                else if(operand[0] == 'X') {
                    locctr += ((strlen(operand) - 3) / 2); 
                }
                else {
                    locctr += 1; 
                }
            }
        }
        
        fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);
        
        if(fscanf(fp1, "%s\t%s\t%s", label, opcode, operand) != 3) {
            break; 
        }
    }
    
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    length = locctr - start;
    printf("Length of the code: %d\n", length);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);    
    fclose(fp4);
}
