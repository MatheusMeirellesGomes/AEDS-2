/*Mesmo exercício da pilha flexível porém agora em java */ 

//Criar uma classe para a célula. 
class Celula {
    //Atributos da célula. 
    int elemento; 
    Celula prox; 
}

public class PilhaFlexivel {
    //Atributo da pilha. 
    Celula topo; 

    //Método para inicializar o topo da pilha
    public PilhaFlexivel() {
        //Referindo que o topo aponta para null. 
        topo = null; 
    }

    //Método para empilhar um elemento. 
    public void empilhar (int x) {
        //Criar uma nova célula que vai ter o elemento. 
        Celula novo = new Celula(); 

        novo.elemento = x; //Atribuindo o elemento. 
        novo.prox = topo; //O topo da pilha vai apontar para o novo elemento
        topo = novo; //O novo elemento passsa a ser o topo. 
    }

    //Método para desempilhar um elemento 
    public int desempilhar() {
        //Variável para guardar o elemento removido. 
        int elementoRemovido = 0; 

        //Verificar se a pilha não está vazia
        if (topo != null) { //Para desempilhar uma pilha ela não pode estar vazia. 
            //Inidicar qual elemento vai ser removido
            elementoRemovido = topo.elemento; 

            //Criar uma célula auxiliar para guardar o elemento
            Celula aux = topo; 
            topo = aux.prox; 
        }

        //retornar o elemento. 
        return elementoRemovido; 
    }

    //Método para imprimir os elementos da pilha. 
    public void mostrar() {
        //Loop para percorrer a pilha. 
        for (Celula i = topo; i != null; i = i.prox) {
            //Imprimir
            System.out.print(i.elemento + " "); //Imprimir o elemento mais um espaço. 
        }
        System.out.println(); 
    }

    public static void main(String[] args) {
        //Criar uma pilha do tipo Pilha Flexível. 
        PilhaFlexivel pilha = new PilhaFlexivel(); 

        //Inserir elementos.
        pilha.empilhar(50); 
        pilha.empilhar(40); 
        pilha.empilhar(30); 
        pilha.empilhar(20); 
        pilha.empilhar(10); 

        //Mostrar elementos depois de inseridos. 
        System.out.print("Elemento antes das remocoes"); 
        System.out.println();
        pilha.mostrar(); 

        //Remover elementos. 
        pilha.desempilhar(); 
        pilha.desempilhar();
        pilha.desempilhar(); 

        //Mostrar elementos depois de removidos
        System.out.println();
        System.out.print("Elementos depois das remocoes: Pilha Final"); 
        System.out.println();
        pilha.mostrar(); 
    }
}