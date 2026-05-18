/*Este é um exercício praticamente igual ao de Lista Dupla, porém agora, a lista é circular, ou seja, nunca vai ter um ponteiro null
o inicio vai apontar pro fim e o fim vai apontar pro inicio, e continua tendo a ligacao dupla entre os elementos */

//Classe para célula da lista
class Celula {
    //Atributos de cada célula (nó) da lista
    Celula ant; 
    int elemento; 
    Celula prox; 
}

class ListaCircular {
    //Ponteiros para as extremidades. 
    Celula inicio; 
    Celula fim; 

    //Construtor para lista
    public ListaCircular() {
        inicio = null; 
        fim = null; 
    }

    //Método para inserir no início. 
    public void inserirInicio(int x) {
        //Criar nova célula
        Celula novo = new Celula(); 
        novo.elemento = x; //Atribuir

        //Se a lista estiver vazia
        if (inicio == null) {
            //Tanto o início quanto o fim vao apontar para o novo elemento. 
            inicio = novo; 
            fim = novo; 

            //Fazer a ligação circular, onde o inicio aponta pro fim e o fim aponta pro inicio. 
            novo.ant = fim; 
            novo.prox = inicio; 
        } else { //Caso já tenha elemento na lista
            //Ligações
            novo.prox = inicio; //O próximo do novo, aponta pro antigo início. 
            inicio.ant = novo; //O anterior do antigo inicio aponta pro novo elemento
            novo.ant = fim; //O anterior do novo elemento aponta pro fim
            fim.prox = novo; //O próximo do fim aponta pro novo elemento.
            inicio = novo; //Inicio agora é o novo elemento. 
        }
    }

    //Método para inserir na posição desejada. 
    public void inserirPos(int x, int pos) {
        //Se a pos for zero
        if (pos == 0) {
            inserirInicio(x); 
        } else {
            //Criar nova célula
            Celula novo = new Celula(); 
            novo.elemento = x; 
            
            //Celula para percorrer a lista
            Celula aux = inicio; 
            for (int i = 0; i < pos - 1; i++) {
                aux = aux.prox; 
            }
            
            //Atribuir ponteiros e inserir o elemento.
            novo.prox = aux.prox;
            aux.prox.ant = novo; 
            novo.ant = aux; 
            aux.prox = novo; 
        }

        //Se o elemento for inserido no final da lista
        if (novo.prox == inicio) {
            fim = novo;
        }
    }

    //Método para inserir no fim da lista. 
    public void inserirFim(int x) {
        //Criar nova célula. 
        Celula novo = new Celula(); 
        novo.elemento = x; 

        //Se a lista estiver vazia
        if (inicio == null) {
            inicio = novo; 
            fim = novo; 
            novo.ant = fim; //O anterior do novo elemento aponta pro fim. 
            novo.prox = inicio; //O próximo do fim aponta pro inicio; 
        } else {
            fim.prox = novo; //Próximo do antigo fim aponta pro novo elemento
            novo.ant = fim; //O anterior do novo elemento aponta pro antigo fim. 
            novo.prox = inicio; //O próximo do novo aponta para o inicio. 
            inicio.ant = novo; //O início agora aponta pro novo elemento.
            fim = novo; //O fim é o novo elemento.
        }
    }

    //Método para remover do início da lista
    public int removerInicio() {
        //Variável de guardar o elemento
        int elementoRemovido = 0; 

        //Se a lista circular tiver um elemento
        if (inicio != null) {
            elementoRemovido = inicio.elemento; //O elemento removido vai ser o do início dela

            //Se a lista tiver apenas um elemento
            if (inicio == fim) {
                //Tanto o fim quanto o início apontam para null 
                inicio = null; 
                fim = null; 
            } else {
                //Mudar os ponteiros
                inicio = inicio.prox; //Início agora é o próximo do antigo início. 
                inicio.ant = fim; //O anterior do início aponta pro fim. 
                fim.prox = inicio; //O próximo do fim aponta para o início
            }
        }

        //Retornar o elemento removido
        return elementoRemovido; 
    }

    //Método para remover na posição desejada. 
    public int removerPos(int pos) {
        int elementoRemovido = 0; 

        //Se for pos 0, chamar o remover no início. 
        if (pos == 0) {
            elementoRemovido = removerInicio(); 
        } else {
            //Celula auxiliar 
            Celula aux = inicio; 

            //Percorrer a lista
            for (int i = 0; i < pos - 1; i++) {
                aux = aux.prox; 
            }

            //Célula para guardar o elemento removido
            Celula tmp = aux.prox; 
            elementoRemovido = tmp.elemento; //O elemento removido é o próximo de aux. 

            aux.prox = tmp.prox; //O próximo de aux agora aponta pro próximo do tmp
            tmp.prox.ant = aux; //O anterior do próximo do tmpo aponta pro aux. 

            //Se tmp for o último elemento.
            if (tmp == fim) {
                fim = aux; 
                fim.prox = inicio; 
                inicio.ant = fim; 
            }
        }

        return elementoRemovido; 
    }

    //Remover elemento no fim da lista
    public int removerFim() {
        int elementoRemovido = 0; 

        //Se a lista tiver elementos
        if (fim != null) {
            elementoRemovido = fim.elemento; //Elemento removido vai ser o elemento final. 
            
            //Se a lista so tiver um elemento. 
            if (inicio == fim) {
                //Ele será removido, e a lista aponta pra null.
                inicio = null;
                fim == null; 
            } else {            
                fim = fim.ant; 
                fim.prox = inicio; 
                inicio.ant = fim;
            }
        }   

        return elementoRemovido; 
    }

    public static void main(String args[]) {
        
    }
}