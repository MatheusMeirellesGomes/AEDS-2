/*Exercício para ordenar os atletas pela quantidade de peso e pelo nome, se a quantidade de peso for igual 
ordenar pelo nome, do maior para o menor. Uitlize o método de ordenção. Nesse caso estou utilizando o ordenação por seleção
Os dados dos atletas vao estar assim: nome peso*/
import java.util.Scanner; 

class Atleta {
    //Atributos da classe atleta. 
    int peso; 
    String nome; 
    
    //Construtor da classe atleta
    public Atleta(String nome, int peso) {
        //Inicializar e atribuir.
        this.peso = peso; 
        this.nome = nome; 
    }

    //Getters 
    int getPeso() {
        return this.peso; 
    }
    String getNome() {
        return this.nome; 
    }

    //Método troca, para ordenar os atletas. 
    static void troca(Atleta atletas[], int first, int last) {
        //Variável auxiliar para fazer a troca
        Atleta temp = atletas[first]; 
        atletas[first] = atletas[last]; 
        atletas[last] = temp;
    }
    
    //Ordenar os atletas pela quantidade de peso que ele carrega.
    static void ordenarAtletas(Atleta atletas[], int n) {
        //Primeiro loop para percorrer o array de atletas. 
        for (int i = 0; i < n - 1; i++) {
            //Guardar posição do maior peso.
            int maiorPeso = i;

            //Procurar o maior elemento.
            for (int j = i + 1; j < n; j++) {
                //Comparar pesos.
                if (atletas[j].getPeso() > atletas[maiorPeso].getPeso()) {
                    maiorPeso = j;
                } 
                
                //Se os pesos forem iguais, comparar os nomes.
                else if (atletas[j].getPeso() == atletas[maiorPeso].getPeso()) {
                    //Se o nome do atleta j for menor que o atleta com o maior peso, atualiza ele. 
                    if (atletas[j].getNome().compareTo(atletas[maiorPeso].getNome()) < 0) {
                        maiorPeso = j;
                    }
                }
            }

            //Trocar o maior elemento encontrado com o primeiro elemento.
            troca(atletas, i, maiorPeso);
        }
    }
}


public class Competicao {
    public static void main(String args[]) {
        //Criar um array de atletas. 
        Atleta atletas[]= new Atleta[31]; 

        //Objeto scanner. 
        Scanner sc = new Scanner(System.in); 

        //Inicializar variáveis. 
        String nome = "";
        int peso = 0;

        int i = 0; //Controlar a qntd de atletas. 

        //Ler os dados dos atletas enquanto nao chegar no fim do arquivo. 
        while (sc.hasNext()) {
            //Ler o nome e o peso do atleta. 
            nome = sc.next(); 
            peso = sc.nextInt(); 

            //Criar um novo atleta e adicionar ao array.
            Atleta atleta = new Atleta(nome, peso); //Adiciona no array para ordenar depois. 

            //Adicionar o atleta ao array de atletas.
            atletas[i] = atleta;
            i++; //Incrementar o contador de atletas.
        }

        //Chamar o método para ordenar os atletas. 
        Atleta.ordenarAtletas(atletas, i);

        //Imprimir os atletas ordenados.
        for (int qntd = 0; qntd < i; qntd++) {
            //Imprimir o nome e o peso do atleta. 
            System.out.println(atletas[qntd].getNome() + " " + atletas[qntd].getPeso());
        }

        sc.close(); 
    }
}
