#include"wc_command.h"
#include<stdio.h>
#include<string.h>
int main() {
    FILE *file, *fr;
    char ch, path[100], f[100];
    char cc1[1000][1000];
    int con = 0;
    list l1;
    list1 l2;
    init(&l1);
    init_(&l2);
    printf("****----IMPLEMENTATION OF 'WC(WORD COUNT)' COMMAND ----****\n");
    up:printf("Enter file path with file name(include extension like '.txt')\n");
    scanf("%s", path);
    int chh = 0, cho = 0, line = 0, charws1 = 0, charws2 = 0, c = 0, cc = 0, e, wdd = 0, ii = 0, j = 0;
    file = fopen(path, "r");
    if(file == NULL) {
        printf("Unable to open file\n");
        goto up;
    }
    else {
        printf("****----FILE OPENED----**** \n");
        printf("Wait for file contents to load(if file is too larger)\n");
        while((ch = fgetc(file)) != EOF) {
            chh++;
            insert_char_in_list(&l1, ch);
        }
    }
    node* pp = l1;
    while(1) {
        printf("1.count lines(-l)\n2.count words(-w)\n3.count char or bytes(-m/-c)\n4.get longest line(-L)\n5.display file\n6.change file\n7.count digit/char/speial symbols\n8.check file contents of file changed or not\n9.copy file\n10.sort file contents\n11.get total number of lines/words/char from different files\n12.exit\nEnter choice ");
        scanf("%d", &cho);
        if(cho >= 12 || cho <= 0)
            break;
        switch(cho) {
            case 1:
                line = count_lines_in_file(l1);
                printf("Number of lines in file = %d\n", line);
                break;
            case 2:
                wdd = count_word(l1);
                printf("Number words in file = %d\n", wdd);
                break;
            case 3:
                charws1 = count_char(l1);
                break;
            case 4:
                c = longest_len(l1, &l2);
                if(c == 0)
                    printf("File is empty \nlongest line length is = 0\n");
                else
                    printf("longest line length is = %d\n", c);
                destroy_LL(&l2);
                break;
            case 5:
                printf("FILE CONTENTS ARE\n");
                display_file_content(l1);
                break;
            case 6:
                destroy_LL(&l1);
                init(&l1);
                path[100] = NULL;
                fclose(file);
                goto up;
                printf("File changed\n");
                break;
            case 7:
                count_difftype_char(l1);
                break;
            case 8:
                c = countt(l1);
                destroy_LL(&l1);
                init(&l1);
                rewind(file);
                while((ch = fgetc(file)) != EOF)
                    insert_char_in_list(&l1, ch);
                cc = countt(l1);
                if(c == cc)
                    printf("No change in content\n");
                else
                    printf("Content of file changed\n");
                break;
            case 9:
                printf("Enter file name(with path) with .txt extension to copy data\n");
                scanf("%s", f);
                fr = fopen(f, "w");
                if(fr != NULL) {
                    node* p = l1;
                    while(p) {
                        fputc(p->chr, fr);
                        p = p->next;
                    }
                    printf("Data copied to %s file....\n", f);
                    fclose(fr);
                }
                else
                    printf("unable to open file\n");
                break;
            case 10:
                while(pp) {
                    if(pp->chr == ' ' || pp->chr == '\n') {
                        pp = pp->next;
                        ii++;
                        j = 0;
                        continue;
                    }
                    else if(pp->next == NULL) {
                        if(pp->chr != '\n')
                            cc1[ii][j] = pp->chr;
                        else
                            break;
                    }
                    else {
                        cc1[ii][j] = pp->chr;
                        j++;
                    }
                pp = pp->next;
                }
                cc1[ii][j] = '\0';
                int l, k, m;
                for(l = 0; l < ii; l++) {
                    for(k = 0; k < ii; k++) {
                        if(strcmp(cc1[k], cc1[k + 1] ) > 0) {
                            char* temp;
                            temp = (char*)calloc(30, sizeof(char));
                            strcpy(temp, cc1[k]);
                            strcpy(cc1[k], cc1[k + 1]);
                            strcpy(cc1[k + 1], temp);
                        }
                    }
                }
                 printf("t");
                    fr = fopen(path, "w");
                    for(m = 0; m <= ii; m++) {
                        fputs(cc1[m], fr);
                        fputs(" ", fr);
                    }
                    fclose(fr);

                break;
            case 11:
                printf("Enter how many files want to open\n");
                scanf("%d", &con);
                int lines[con], words[con], chars[con];
                for(int i = 1; i <= con; i++) {
                    list li[i];
                    init(&li[i]);
                    upp:printf("Enter file path with file name(include extension like '.txt')\n");
                    scanf("%s", path);
                    file = fopen(path, "r");
                    if(file == NULL) {
                        printf("Unable to open file\n");
                        goto upp;
                    }
                    else {
                        while((ch = fgetc(file)) != EOF)
                            insert_char_in_list(&li[i], ch);
                        }
                    int a = count_lines_in_file(li[i]);
                    lines[i] = a;
                    int b = count_word(li[i]);
                    words[i] = b;
                    int c = count_charr(li[i]);
                    chars[i] = c;
                    fclose(file);
                }
                int total = 0, choice = 0;
                while(1) {
                    printf("1.get total of lines\n2.get total of words\n3.get total of chars\n4.exit\nEnter choice ");
                    scanf("%d", &choice);
                        if(choice == 1) {
                            total = 0;
                            for(int j = 1; j <= con; j++) {
                                printf("lines from file %d are %d\n", j, lines[j]);
                                total += lines[j];
                            }
                            printf("Total lines from different file is %d\n", total);
                            continue;
                        }
                        else if(choice == 2) {
                            total = 0;
                            for(int j = 1; j <= con; j++) {
                                printf("words from file %d are %d\n", j, words[j]);
                                total += words[j];
                            }
                            printf("Total words from different file is %d\n", total);
                            continue;
                        }
                        else if(choice == 3) {
                            total = 0;
                            for(int j = 1; j <= con; j++) {
                                printf("char from file %d are %d\n", j, chars[j]);
                                total += chars[j];
                            }
                            printf("Total char from different file is %d\n", total);
                            continue;
                        }
                        else
                            break;
                }
                break;
        }
        //file = fopen("C:\Users\Aditya\Desktop\DSA1\wc.txt", "r");
    }
    fclose(file);
    destroy_LL(&l1);
    printf("***---FILE CLOSED---***");
    return 0;
}
