#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char opcode[10], operand[10], label[10], code[10], mnemonic[10];
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4;
    
    fp1 = fopen("input.txt","r");
    fp2 = fopen("optab.txt","r");
    fp3 = fopen("symtab.txt","w");
    fp4 = fopen("output.txt","w");
    
    if(fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL)
    {
        printf("Error opening files!\n");
        return 1;
    }
    
    fscanf(fp1,"%s\t%s\t%s", label, opcode, operand);
    
    if(strcmp(opcode, "START") == 0)
    {
        start = (int) strtol(operand, NULL, 16);
        locctr = start;
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
    }
    
    while(strcmp(opcode, "END") != 0)
    {    
        fprintf(fp4, "%X\t", locctr);
        
        if(strcmp(label, "**") != 0)
        {
            fprintf(fp3, "%s\t%X\n", label, locctr);
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
        
     
        if(!found)
        {
            if(strcmp(opcode, "WORD") == 0)
            {
                locctr += 3;
            }
            else if(strcmp(opcode, "RESW") == 0)
            {
                locctr += (3 * atoi(operand));
            }
            else if(strcmp(opcode, "RESB") == 0)
            {
                locctr += atoi(operand);
            }
            else if(strcmp(opcode, "BYTE") == 0)
            {
          
                if(operand[0] == 'C')  
                {
                    locctr += (strlen(operand) - 3);  
                }
                else if(operand[0] == 'X')  
                {
                    locctr += (strlen(operand) - 3) / 2;  
                }
                else
                {
                    locctr += 1;  
                }
            }
        }
        
        fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);
        
   
        if(fscanf(fp1, "%s\t%s\t%s", label, opcode, operand) != 3)
        {
            break;  
        }
    }
    
  
    fprintf(fp4, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    
    length = locctr - start;
    printf("Length of the code: %X\n", length);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);    
    fclose(fp4);
    
    return 0;
}
