// Registration & Login system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// locale PT-BR
#include <locale.h>


struct login {
    char username[20];
    char password[20];
};


int main () {
    // LOCALE PT-BR   
    setlocale(LC_ALL, "Portuguese_Brazil");
    FILE *database;
    
    int opcao;
    
    printf("Sistema de Login e Registro\n--------------\n1- Registrar\n2- Logar\n3- Sair\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        
        database = fopen("database.txt", "w+");
        struct login usuario;
        // scanf do usuario e senha 
        printf("Digite seu nome: ");
        scanf("%s", usuario.username);
        printf("Digite sua senha: ");
        scanf("%s", usuario.password);
        // write username and password to database
        fwrite(&usuario, sizeof(usuario), 1, database);
        fclose(database);
        printf("Usuario cadastrado com sucesso!\n");

    } else if (opcao == 2) {
        // logar
        database = fopen("database.txt", "r");
        struct login usuario;
        struct login usuariosistema;
        printf("Digite seu nome: ");
        scanf("%s", usuario.username);
        printf("Digite sua senha: ");
        scanf("%s", usuario.password);
        // read username and password from database and compare 
        fread(&usuariosistema, sizeof(usuariosistema), 1, database);
        if (strcmp(usuario.username, usuariosistema.username) == 0 && strcmp(usuario.password, usuariosistema.password) == 0) {
            printf("Logado com sucesso!\n");
        } else {
            printf("Usuario ou senha incorretos!\n");
        }
    } else if (opcao == 3) {
        // sair
        return 0;
    }
    return 0;
}