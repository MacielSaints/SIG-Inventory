typedef struct produtos Produtos;

Produtos* preencheProduto(void);

void exibeProduto(Produtos*);
void gravaProduto(Produtos*);

Produtos* buscaProduto(void);

void listaProdutos(void);
void listaProdutosPorMarca(void);
void excluiProduto(Produtos*);
Produtos* atualizaProduto(Produtos* pd);
Produtos* entradaProduto(Produtos* pd);
Produtos* saidaProduto(Produtos* pd);