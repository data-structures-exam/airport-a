
typedef struct tListaPista ListaPista;

void adicionar_voo_pistaDecolagem(ListaPista *lPista, int numero_pista, Voo *voo);
void retirar_voo_pistaDecolagem(ListaPista *lPista, int numero_pista, Voo *voo);
void adicionar_voo_pistaAterragem(ListaPista *lPista, int numero_pista, Voo *voo);
void retirar_voo_pistaAterragem(ListaPista *lPista, int numero_pista, Voo *voo);
void destruir_lista_pista(ListaPista *lPista);