//Mesmo exercício de lista flexível em c, porém agora em java, utilizando classes e objetos

import java.util.Scanner; 

//Classe para representar um nó da lista. 
class Celula {
    //Atributos. 
    int elemento; 
    Celula prox; 
} 

//Classe para representar a lista. 
public class ListaFlexivel {
    //Atributos
    Celula inicio; 
    Celula fim; 

    //Construtor.
    public ListaFlexivel() {
        //Inicializar a lista vazia. 
        inicio = null; 
        fim = null; 
    }

    //Método para inserir no início da lista.
    public void inserirInicio (int x) {
        //Criar uma nova célula. ( novo[x | prox] )
        Celula novo = new Celula(); //Como se fosse alocar memória em C. 

        //Inserir. 
        novo.elemento = x; 
        novo.prox = inicio; //O novo elemento agora aponta para o antigo início da lista.       
        inicio = novo; //O inicio da lista agora é o novo elemento. 

        //Se a lista estava vazia, o fim também deve apontar para o novo elemento. 
        if (fim == null) {
            fim = novo; 
        }
    }

    //Método para inserir em qualquer posição 
    public void inserirPos (int x, int pos) {
        //Verificar se a posição é zero. 
        if (pos == 0) {
            inserirInicio(x); 
        } else {
            //Criar nova célula. 
            Celula novo = new Celula(); 
            novo.elemento = x; //atribuição. 

            //Criar varíavel auxiliar para percorrer a lista
            Celula aux = inicio; 

            //Percorrer a lista até a posição desejada ou até o fim da lista.
            for (int i = 0; i < pos - 1 && aux != null; i++) {
                aux = aux.prox; //Avançar para o próximo elemento. 
            }

            //Se aux (posição anterior) for diferente de null, ou seja, a posição é válida.
            if (aux != null) {
                novo.prox = aux.prox; //O próximo do novo elemento é o próximo do elemento anterior. 
                aux.prox = novo; //O próximo do elemento anterior agora é o novo elemento. 

                //Se o novo elemento for inserido no final da lista, atualizar o fim da lista.
                if (novo.prox == null) {
                    fim = novo; 
                }
            }
        }
    }

    //Método para inserir no fim da lista. 
    public void inserirFim (int x) {
        //Criar nova célula.
        Celula novo = new Celula(); 

        //Inserir. 
        novo.elemento = x; 
        novo.prox = null; //O próximo do novo é null, pois será o último elemento. 

        //Se a lista estiver vazia
        if (inicio == null) {
            inicio = novo; //O início da lista é o novo elemento. 
        } else {
            fim.prox = novo; //O próximo do fim (antigo fim) da lista aponta para o novo elemento. 
        }

        //O fim da lista agora é o novo elemento. 
        fim = novo;
    }

    //Método para remover do início da lista. 
    public int removerInicio() {
        //Guardar o elemento removido. 
        int elementoRemovido = 0; 

        //Verificar se lista tem algum elemento. 
        if (inicio != null) {
            elementoRemovido = inicio.elemento; //O elemento removido é o inicio da lista, ou seja, o primeiro elemento. 

            //Criar uma variável auxiliar para guardar o elemento do início da lista. 
            Celula aux = inicio; 
            inicio = inicio.prox; //O início da lista agora é o próximo elemento. (elemento que o antigo início apontava).

            //Verificar se a lista ficou vazia após a remoção.
            if (inicio == null) {
                fim = null; //Se ficou vazia, tanto o inicio quanto o fim devem ser null.
            }
        }

        //Retornar o elemento removido.
        return elementoRemovido;
    }

    //Método para remover de uma posição específica da lista.
    public int removerPos (int pos) {
        int elementoRemovido = 0; //Guardar elemento. 

        //Se a posição informada for igual a zero
        if (pos == 0) {
            elementoRemovido = removerInicio(); //o elemento removido vai ser o elemento inicial da lista.
        } else {
            //Criar variável auxiliar 
            Celula aux = inicio; 

            //Percorrer a lista até a posição desejada ou até o fim da lista.
            for (int i = 0; i < pos - 1 && aux != null; i++) {
                aux = aux.prox; //Avançar para o próximo elemento.
            }

            //Se aux (posição anterior) for diferente de null e o próximo de aux (elemento a ser removido) for diferente de null, ou seja, a posição é válida.
            if (aux != null && aux.prox != null) {
                //Criar célula auxiliar
                Celula tmp = aux.prox; 
                elementoRemovido = tmp.elemento; //O elemento removido é o elemento da posição desejada.
                
                aux.prox = tmp.prox; //O próximo do elemento anterior agora aponta para o próximo do elemento a ser removido, cortando a ligação com o elemento removido.
                
                //Se o elemento removido for o último elemento da lista, atualizar o fim da lista.
                if (tmp == fim) {
                    fim = aux; //O novo fim da lista é o elemento anterior.
                }
            }
        }
        return elementoRemovido;
    }

    //Método para remover do fim da lista.
    public int removerFim(){
        //Guardar o elemento removido.
        int elementoRemovido = 0; 

        //Verificar se a lista tem algum elemento. 
        if (inicio != null) {
            elementoRemovido = fim.elemento; //O elemento removido é o fim da lista, ou seja, o último elemento. 

            //Criar variável auxiliar para guardar o elemento do início da lista. 
            Celula aux = inicio; 

            //Percorrer a lista até o penúltimo elemento, que aponta para o final da lista. 
            while (aux.prox != fim) {
                aux = aux.prox; //Avançar para o próximo elemento. 
            }

            //Criar outra variável auxiliar para guardar o elemento do fim da lista.
            Celula tmp = fim;

            //Indicar o novo fim da lista. 
            fim = aux; //O novo fim da lista é o penúltimo elemento. 
            fim.prox = null; //Cortar a ligação do novo fim com o antigo fim. 
        }

        //Retornar o elemento removido.
        return elementoRemovido;
    }

    //Método para imprimir a lista.
    public void imprimir() {
        //Loop para percorrer do início ao fim da lista, imprimindo os elementos.
        for (Celula i = inicio; i != null; i = i.prox) {
            System.out.print(i.elemento + " "); //Imprimir o elemento mais o espaço.
        }

        System.out.println(); //Pular linha após imprimir a lista.
    }

    //Método principal da classe
    public static void main (String args[]) {
        //Criar um objeto da classe Lista Flexível. 
        ListaFlexivel lista = new ListaFlexivel();

        //Criar scanner para ler a entrada do usuário. 
        Scanner sc = new Scanner(System.in);

        //Inserir elementos no início da lista
        System.out.println("Digite 3 números para inserir no início da lista:");

        //Loop para ler 3 número e inserir no início da lista
        for (int i = 0; i < 3; i++) {
            //Ler o número do usuário. 
            int num = sc.nextInt();

            //Chamar o inserir Inicio 
            lista.inserirInicio(num);
        }

        //Espaçamento. 
        System.out.println();

        //Loop para ler 3 números e inserir no fim da lista
        System.out.println("Digite 3 números para inserir no fim da lista:");
        for (int i = 0; i < 3; i++) {
            int num = sc.nextInt();
            lista.inserirFim(num);
        }

        //Espaçamento. 
        System.out.println();

        //Imprimir a lista após as inserções.
        System.out.println("Lista após as inserções:");
        lista.imprimir();

        //Espaçamento.
        System.out.println();

        //Remover um elemento do início da lista e imprimir o elemento removido.
        int removidoInicio = lista.removerInicio();
        System.out.println("Elemento removido do início da lista: " + removidoInicio);

        //Espaçamento.
        System.out.println();

        //Remover um elemento do fim da lista e imprimir o elemento removido.
        int removidoFim = lista.removerFim();
        System.out.println("Elemento removido do fim da lista: " + removidoFim);

        //Espaçamento.
        System.out.println();

        //Lista após as remoções.
        System.out.println("Lista após as remoções:");
        lista.imprimir();

        //Fechar o scanner.
        sc.close();
    }
}   