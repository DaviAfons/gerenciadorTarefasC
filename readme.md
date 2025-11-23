````markdown
# 📝 Gerenciador de Tarefas (CLI Task Manager)

Aplicação de linha de comando (CLI) escrita em **C** com foco em boas práticas de engenharia de software.
O projeto demonstra controle manual de memória, persistência binária e arquitetura modular — resultando em um programa leve, eficiente e fácil de manter.

---

## 🚀 Funcionalidades

- ✔️ **CRUD Completo**: criar, listar, editar e remover tarefas.
- 💾 **Persistência Automática**: dados salvos em arquivo binário (`data/dados.bin`) entre execuções.
- 🧠 **Gerenciamento Dinâmico de Memória**: uso de `malloc`, `realloc` e `free` para ajustar a lista dinamicamente.
- 🔎 **Filtros de Visualização**: listar tarefas por status (Pendentes ou Concluídas).
- 🧱 **Arquitetura Modular**: separação em módulos `core`, `io` e `view` para facilitar manutenção.

---

## 🛠️ Tecnologias e Conceitos Utilizados

- **Linguagem C (ANSI C / C99 compatível)**
- **Structs e ponteiros**
- **File I/O com arquivos binários** (`fread`, `fwrite`)
- **Makefile** para compilação automatizada
- **Design modular e separação de responsabilidades**

---

## 📂 Estrutura do Projeto

```text
gerenciadorTarefas/
├── include/            # Headers (.h)
│   └── tarefas.h
├── src/                # Código-fonte (.c)
│   ├── main.c
│   ├── tarefas_core.c  # Lógica (CRUD)
│   ├── tarefas_io.c    # Persistência (arquivo binário)
│   └── tarefas_view.c  # Menus e exibição
├── data/               # Armazenamento local
│   └── dados.bin       # Base de dados (gerada automaticamente)
├── Makefile
└── README.md
````

---

## ⚙️ Como Compilar e Executar

Certifique-se de ter **GCC** e **make** instalados.

### 1. Clone o repositório

```bash
git clone https://github.com/DaviAfons/gerenciadorTarefasC.git
cd gerenciadorTarefasC
```

### 2. Compile o projeto

```bash
make
```

### 3. Execute a aplicação

```bash
./app_tarefas
```

### 4. Limpeza (opcional)

```bash
make clean
```

---

## 🧠 Principais Desafios

Um dos desafios mais relevantes foi remover elementos do array dinâmico sem deixar espaços vazios.
A solução envolve **deslocar (shift) os elementos subsequentes** e ajustar a alocação com `realloc`, garantindo boa performance e uso eficiente da memória.

---

## 👤 Autor

Desenvolvido por **Davi Afonso**

---

## 📄 Licença

Distribuído sob a **Licença MIT** — sinta-se livre para usar, estudar, modificar e distribuir.

```

Se quiser, posso gerar uma versão **mais curta**, **mais formal**, ou **mais visual** (com emojis removidos).
```
