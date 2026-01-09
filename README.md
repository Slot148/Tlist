# Tlist(POSIX)

Implementação C para listas encadeadas e arrays dinâmicos, com suporte a multiplos tipos, gerenciamento seguro de memória e documentação Doxygen.

Esta Biblioteca fornece estruturas de listas e arrays flexiveis que podem armazenar diferentes tipos de dados, incluindo `int`, `float`, `double`, `char*`(string) e ponteiros genéricos(`void*`). A biblioteca copia automaticamente valores para tipos primitivos e strings; para ponteiros genéricos(tipo `T`/`void*`) a lista armazena o ponteiro do valor — Veja a seção "[Gerenciamento de memória](#memoria)" para mais detalhes.

    Status do projeto: Ativo ✅

### Indice
- [Funcionalidades](#funcionalidades)
- [Requisitos]()
- [Instalação]()
- [Compilação]()
- [Uso Rápido]()
    - [Gerenciamento de Memória](#gerenciamento-de-memóriaimportante)
    - [Exemplos]()
- [Documentação(Doxygen)](#documentacao)
- [Licença]()
- [Contatos]()

## Funcionalidades
- Tipagem dinâmica: listas/arrays para `int`, `float`, `double`, `char*` e ponteiros genéricos(`void*`/`T`).
- Gerenciamento de memória para tipos primitivos e strings(valores copiados)
- Operações suportadas:
    - Listas Encadeadas:
        - `new_list`: cria uma nova lista vazia.
        - `list_print`: imprime os elementos da lista.
        - `list_length`: retorna a quantidade de elementos da lista.
        - `list_free`: libera a memória alocada pela lista.
        - `list_push`: adiciona o elemento ao final da lista.
        - `list_pop`: remove e retorna o primeiro elemento da lista.
        - `list_get`: retorna um ponteiro para uma cópia do elemento na posição especificada.
        - `list_set`: define o elemento na posição especificada.
        - `list_delete`: remove o elemento na posição especificada.
        - `list_insert`: insere um elemento na posição especificada.
        - `list_pick`: remove e retorna o elemento na posição especificada.
        - `list_foreach`: executa uma função para cada elemento da lista.
    - Arrays Dinâmicos:
        - `new_array_list`: cria um novo array vazio.
        - `array_list_clone`: cria uma cópia do array.
        - `array_list_print`: imprime os elementos do array.
        - `array_list_length`: retorna a quantidade de elementos do array.
        - `array_list_free`: libera a memória alocada pelo array.
        - `array_list_get`: retorna um ponteiro para o elemento na posição especificada.
        - `array_list_set`: define o elemento na posição especificada.
        - `array_list_clear`: remove todos os elementos do array e define como NULL.
        - `array_list_resize`: altera o tamanho do array.
        - `array_list_push_back`: adiciona o elemento ao final do array.
        - `array_list_toString`: define a função de callback com a formatção da string a ser retornada.
        - `array_list_clearFunctio`: Define a função usada para liberar a memória utilizada por tipos personalizados.

## Requisitos
- CMake
- Compilador C(POSIX)
- (Opcional) Doxygen para gerar documentação da API.
- (Opcional - Apenas MinGW) VCPKG para fácil instalação no windows.

## Compilação
1. Clone o repositório do projeto

    ```bash
    git clone https://github.com/Slot148/Tlist
    cd Tlist
    ```
2. Crie o diretorio de build e compile:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```
3. O arquivo `.a` deve ser gerado em `build/lib` conforme CMakeLists. Os `.h` estão em `include/tlist`. (A partir daqui, fica a escolha do usuário adiciona-la ao path do projeto ou do sistema)
    - Para compilar um programa que usa a biblioteca:
        ```bash
        gcc meu_arquivo.c -Iinclude -Llib -ltlist -o meu_programa
        ```

## Uso Rápido
1. Inclua o header:

    ```c
    #include "Tlist.h"
    ```
    Observação: O caminho pode ser relativamente diferente caso instalado via VCPKG.

2. Crie a lista(exemplo com inteiros):
    ```c
    int main(){
        List list = new_list(INT);
        list_push(list, 1);
        list_push(list, 2);
        list_push(list, 3);
        list_push(list, 4);
        list_print(list);
        list_free(list);
    }
    ```


## Gerenciamento de Memória(Importante)

## Work in Progress 🚧

<div align="center">
    <!-- Space for a large image or banner -->
    <img src="data:image/png;base64,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" alt="maintenance">
    <h3>Documentation and features are currently being updated. Stay tuned!</h3>
</div>
