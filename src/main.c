#include <include_all_std.h>
#include <server.h>
#include <host.h>

bool invalidArgs(int argc, char *argv[]);
void showUsage();

int main(int argc, char *argv[]) {
    if (invalidArgs(argc, argv))
        exit(1);
    const char *port = argc == 3 ? argv[2] : "10101";
    if (strcmp(argv[1], "-S") == 0)
        return runServer(port);
    if (strcmp(argv[1], "host") == 0)
        return runHost(port);
    return 0;
}

bool invalidArgs(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Erro! Quantidade invalida de argumentos.\n");
        showUsage();
        return true;
    }
    if (strcmp(argv[1], "-S") != 0 && strcmp(argv[1], "host") != 0) {
        fprintf(stderr, "Erro! Argumento invalido: %s\n", argv[1]);
        showUsage();
        return true;
    }
    return false;
}

void showUsage() {
    printf("Uso do programa:\n");
    printf("./gossip -S [port]\n");
    printf("./gossip host [port]\n");
}
