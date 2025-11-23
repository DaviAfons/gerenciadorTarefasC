```markdown
# 📝 Gerenciador de Tarefas (CLI Task Manager)

Um sistema robusto de gerenciamento de tarefas via linha de comando (CLI), desenvolvido em **C** com foco em boas práticas de engenharia de software.  
Este projeto demonstra domínio de **manipulação manual de memória**, **persistência binária de dados** e **arquitetura modular**, resultando em uma aplicação leve, eficiente e escalável.

---

## 🚀 Funcionalidades

- ✔️ **CRUD Completo**: Criação, leitura, atualização e exclusão de tarefas.  
- 💾 **Persistência Automática**: Os dados são armazenados em um arquivo binário (`dados.bin`), permitindo que as tarefas permaneçam salvas entre execuções.  
- 🧠 **Gerenciamento Dinâmico de Memória**: Utilização de `malloc`, `realloc` e `free` para controle otimizado de alocação durante o crescimento e remoção de tarefas.  
- 🔎 **Filtros de Visualização**: Possibilidade de listar tarefas por status (Pendentes ou Concluídas).  
- 🧱 **Arquitetura Modular**: Separação clara em módulos de Core, IO e View, favorecendo manutenção e evolução do projeto.

---

## 🛠️ Tecnologias e Conceitos Utilizados

- **Linguagem C (ANSI C)**  
- **Structs e Manipulação de Ponteiros**  
- **File I/O com Arquivos Binários** (`fread`, `fwrite`)  
- **Makefile para Automação de Build**  
- **Design Modular e Separação de Responsabilidades**

---

## 📂 Estrutura do Projeto

```

gerenciadorTarefas/
├── include/            # Headers e contratos (.h)
│   └── tarefas.h
├── src/                # Código-fonte (.c)
│   ├── main.c          # Ponto de entrada e loop principal
│   ├── tarefas_core.c  # Lógica de manipulação da lista (CRUD)
│   ├── tarefas_io.c    # Persistência em arquivo binário
│   └── tarefas_view.c  # Exibição, menus e filtros
├── data/               # Armazenamento local
│   └── dados.bin       # Base de dados gerada automaticamente
├── Makefile            # Automação de compilação
└── README.md

````

---

## ⚙️ Como Compilar e Executar

Certifique-se de ter o **GCC** e o **Make** instalados.

### 1. Clone o repositório

```bash
git clone https://github.com/DaviAfons/gerenciadorTarefasC
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

### 4. Limpeza (Opcional)

```bash
make clean
```

---

## 🧠 Principais Desafios

Um dos desafios mais relevantes foi a remoção de elementos do array dinâmico sem causar fragmentação ou desperdício de memória.
Foi necessário implementar a lógica de **shift dos elementos subsequentes** e posteriormente reduzir a alocação com `realloc`, garantindo eficiência tanto em memória quanto em performance.

---

## 👤 Autor

Desenvolvido por **Davi Afonso**

---

## 📄 Licença

Este projeto é distribuído sob a **Licença MIT**.
Você é livre para usar, estudar, modificar e distribuir este software.
