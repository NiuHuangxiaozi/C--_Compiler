#include "ir.h"
#include "graph.h"
#include "simplify.h"
#include <stdio.h>
#include <string.h>

extern int b_lnt;
void transform(char* stmt, int line) {
    if (strlen(stmt)) {
    // printf("%d\t%s\n", line, stmt);
        ir_from_str(stmt, line);
    }
}

int main(int argc, char** argv) {
    FILE* in = fopen(argv[1], "r");
    char buffer[101];
    int pos = 0, line = 0;
    char c;
    init();
    do {
        c = fgetc(in);
        if (feof(in))
            break;
        if (c == '\n') {
            buffer[pos++] = '\0';
            transform(buffer, line++);
            pos = 0;
        } else {
            buffer[pos++] = c;
        }
    } while (1);
    if (pos > 0) {
        buffer[pos++] = '\0';
        transform(buffer, line++);
    }
    fclose(in);

    //build();
    //print_succ();
    //printf("%d\n", b_lnt);
    //init_live_variable();
    // iter_live_variable();
    FILE* out = fopen(argv[2], "w");

    simplify();

    output_all_ir(out);
    return 0;
}