# 📝 Gerenciador de Tarefas (CLI Task Manager)

Aplicação de linha de comando (**CLI**) escrita em **C**, com foco em boas práticas de engenharia de software.  
O projeto demonstra **controle manual de memória**, **persistência binária** e **arquitetura modular** — resultando em um programa leve, eficiente e fácil de manter.

---

## 🚀 Funcionalidades

✔️ **CRUD Completo** — criar, listar, editar e remover tarefas  
💾 **Persistência Automática** — salva dados em `data/dados.bin`  
🧠 **Gerenciamento Dinâmico de Memória** — `malloc`, `realloc` e `free`  
🔎 **Filtros por Status** — Pendentes ou Concluídas  
🧱 **Arquitetura Modular** — módulos `core`, `io` e `view` separando responsabilidades

---

## 🛠️ Tecnologias e Conceitos Utilizados

- Linguagem **C** (ANSI C / C99)
- **Structs** e ponteiros
- **File I/O** com arquivos binários (`fread`, `fwrite`)
- **Makefile** para automação de compilação
- **Design modular** e separação clara de responsabilidades

---

## 📂 Estrutura do Projeto

```

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
````

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

Um dos pontos críticos foi **remover elementos do array dinâmico sem deixar buracos**.
A solução envolve:

* deslocar os elementos com *shift*;
* realocar com `realloc`;
* ajustar o tamanho real da lista.

Isso garante **performance**, **consistência** e **uso eficiente da memória**.

---

## 👤 Autor

Desenvolvido por **Davi Afonso**.

---

## 📄 Licença

Distribuído sob a **Licença MIT** — você pode usar, estudar, modificar e distribuir livremente.

---

```
```
