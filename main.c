#include "ykr_cc.h"

char *user_input;

int main(int argc, char **argv) {
    if (argc != 2) {
        error("引数の個数が正しくありません");
        return 1;
    }

    user_input = argv[1];
    tokenize(user_input);
    program();

    codegen();
    return 0;
}

