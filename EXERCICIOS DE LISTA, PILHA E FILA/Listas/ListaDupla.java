/*Lista Duplamente Encadeada em Java, diferente da lista simples encandeada, a dupla adiciona um ponteiro ant, que aponta pra célula anterior. 
agora a célula da lista tem [ant | elemento | prox] */

//Classe para célula da lista.
class Celula {
    //Elements da célula da lista
    Celula ant; 
    int elemento; 
    Celula prox; 
}

//Classe para Lista 
public class ListaDupla {
    Celula inicio; 
    Celula fim; 

    public ListaDupla() {
        //Tanto o inicio como fim apontam para null
        inicio = null; 
        fim = null; 
    }

    //Método para inserir no início da lista
    public void inserirInicio (int x) {
        //Criar nova célula
        Celula novo = new Celula(); 

        //Atribuir
        novo.elemento = x; 

        //Se a lista estiver com algum elemento
        if (inicio != null) {
            //Inserir e posicionar o ponteiro
            novo.prox = inicio; //Novo elemento aponta pro antigo início.
            inicio.ant = novo; //Anterior do antigo início aponta pro novo. 
            inicio = novo; //Inicio agora é o novo elemento. 
        } else { //Se ela estiver vazia. 
            //Tanto o inicio quanto o fim apontam pro novo elemento. 
            inicio = novo;
            fim = novo;
        }
    }

    public void inserirPos(int x, int pos) {
        //Se for na posição 0, chamar o inserir início 
        if (pos == 0) {
            inserirInicio(x); 
        } else {
            //Criar nova célula 
            Celula novo = new Celula(); 
            novo.elemento = x; //Atribuir

            //criar célula auxiliar para percorrer a lista
            Celula aux = inicio; 

            //Percorrer a lista. 
            for (int i = 0; i < pos - 1 && aux != null; i++) {
                aux = aux.prox; //Aux é o elemento anterior da posição. 
            }

            //Enquanto aux nao apontar pra null.
            if (aux != null) {
                //Inserir e atribuir.
                novo.prox = aux.prox; //O próximo do novo aponta pro próximo do aux. 
                novo.ant = aux; //O anterior do novo aponta pro aux. 
                aux.prox = novo; //O novo elemento é o próximo do aux. 

                //Se o próximo do novo elemento não for null
                if (novo.prox != null) {
                    //O anterior do próximo aponta para o novo elemento. 
                    novo.prox.ant = novo;
                }
            }

            //Se o novo elemento inserido for na última pos (fim da lista)
            if (novo.prox == null) {
                fim = novo; 
            }
        }
    }

    //Método para inserir no fim. 
    public void inserirFim(int x) {
        //Criar nova célula
        Celula novo = new Celula(); 
        novo.elemento = x; //Atribuir

        //Se a lista estiver vazia
        if (inicio == null) {
            inicio = novo; 
        } else {
            fim.prox = novo; //o próximo do antigo fim aponta pro novo elemento
            novo.ant = fim; //O anterior do novo aponta pro antigo fim. 
        }

        fim = novo; //Fim é o novo elemento. 
    }

    //Método para remover do início. 
    public int removerInicio() {
        //Variável para guardar
        int elementoRemovido = 0; 

        //Se a lista não estiver vazia
        if (inicio != null) {
            elementoRemovido = inicio.elemento; //Elemento removido é o primeiro elemento

            //Criar uma célula auxiliar para guardar
            Celula aux = inicio; 
            inicio = inicio.prox; //Inicio agora é o próximo do antigo início
            if (inicio != null) {
                inicio.ant = null; 
            }
        }

        //Se não tiver nada na lista
        if (inicio == null) {
            fim = null; 
        }
        
        //Retornar o elemento removido.
        return elementoRemovido;
    }

    //Método para remover na posição 
    public int removerPos (int pos) {
        int elementoRemovido = 0; //Variável

        //Se pos for zero, chama o remover no incício. 
        if (pos == 0) {
            elementoRemovido = removerInicio(); 
        } else {
            Celula aux = inicio; //Aux começa no inicio da lista
            for (int i = 0; i < pos - 1 && aux != null; i++) { 
                aux = aux.prox; //Aux = anterior do elemento. 
            }

            //Se o aux e o prox do aux for diferente de null (posição é válida)
            if (aux != null && aux.prox != null) {
                Celula tmp = aux.prox; //Tmp é o próximo de aux, ou seja, é o elemento da pos informada. 
                elementoRemovido = tmp.elemento; //o tmp vai ser o elemento removido

                aux.prox = tmp.prox;
                if (tmp.prox != null) {
                    tmp.prox.ant = aux;
                } 

                //Se o elemento removido for o último elemento da lista
                if (tmp == fim) {
                    fim = aux; //O fim agora é o aux, ou seja, o elemento anterior do elemento removido. 
                }
            }
        }

        return elementoRemovido; 
    }

    //Método para remover do fim da lista
    public int removerFim() {
        int elementoRemovido = 0; //Variável para remover o elemento removido. 

        //Se tiver elementos na lista
        if (fim != null) {
            elementoRemovido = fim.elemento; //Elemento removido é o último elemento.

            //Atribuir ponteiros.
            fim = fim.ant; //O fim agora é o anterior do antigo fim.

            //Se o novo fim não for null, o próximo do novo fim aponta para null.
            if (fim != null) {
                fim.prox = null; //O próximo do novo fim aponta para null.
            } else {
                inicio = null; //Se lista ficar vazia, inicio também é null
            }
        }

        return elementoRemovido; 
    }

    //Método para mostrar os elementos da lista
    public void mostrar() {
        for (Celula i = inicio; i != null; i = i.prox) {
            System.out.print(i.elemento + " "); 
        }
        System.out.println(); 
    }

    public static void main(String args[]) {
        //Criar um array para lista. 
        ListaDupla lista = new ListaDupla(); 

        //Inserir alguns elementos.
        lista.inserirInicio(10); 
        lista.inserirInicio(5); 
        lista.inserirFim(20); 
        lista.inserirPos(15, 2); 
        lista.inserirFim(30); 
        lista.inserirPos(25, 4); 

        //Remover alguns elementos. 
        lista.removerInicio(); 
        lista.removerFim(); 
        lista.removerPos(3); 

        //Imprimir a lista após remoções
        lista.mostrar(); 
    }
}