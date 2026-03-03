//Biblioteca para ler daddos do teclado. 
import java.util.Scanner;

//Primeiro método para trocar os elementos de posição do vetor, para deixar eles ordenados em ordem crescente. 
public class SelectionSort {
    //Inicialização do método swap, que recebe um vetor de inteiros e dois índices i e j, e troca os elementos nessas posições. 
    public static void swap (int vetor[], int i, int j) {
        //Inicializar variável temporária para armazenar o valor do elemento na posição i, para que ele não seja perdido durante a troca. 
        int temp; 

        //Função do swap, realizando as devidas trocas de posição. 
        temp = vetor[i]; //Variável temp recebe o valor do elemento na posição i do vetor. 
        vetor[i] = vetor[j]; //Variável vetor[i] recebe o valor do elemento vetor[j]. Resumo: o elemento na posição i do vetor é substituído pelo elemento na posição j.
        vetor[j] = temp; //Variável vetor[j] recebe o valor armazenado em temp, que é o valor original do elemento na posição i. Resumo: o elemento na posição j do vetor é substituído pelo valor original do elemento na posição i, que foi armazenado em temp.
    }

    //Método principal onde o programa começa a execução. 
    public static void main (String args[]) {
        //Inicializar Variável n para armazenar o número de elementos do vetor e criar um objeto Scanner para ler a entrada do usuário. 
        int n; 
        Scanner sc = new Scanner(System.in); 

        //Receber dados do usuário para preencher o vetor, começando pelo número de elementos do vetor. 
        System.out.print("Informe o numero de elementos do vetor: "); 
        n = sc.nextInt();

        //Criar um vetor de inteiros com o tamanho especificado pelo usuário e preencher o vetor com os elementos informados pelo usuário.
        int vetor[] = new int[n];

        //Primeiro loop para preencher o vetor com os elementos informados pelo usuário, onde i é o índice do vetor e vai de 0 até n-1.
        for (int i = 0; i < n; i++) {
            //Receber os valores de cada elemento do vetor.
            System.out.print("Informe o elemento " + (i+1) + ": "); 
            vetor[i] = sc.nextInt(); 
        }

        //Segundo Loop, para ordenar o vetor usando o algoritmo de ordenação Selection Sort, onde vai percorrer de i = 0, até n - 2, já que o último elemento do vetor já estará ordenado quando chegar na penúltima posição.
        for (int i = 0; i < (n - 1); i++) {
            //Inicializar variável. 
            int menor = i; //menor recebe o valor da posição i, que é o valor na pos[0] do vetor, ou seja, o primeiro elemento do vetor.

            //Terceiro Loop, para encontrar o índice do menor elemento no restante do vetor, onde j é o índice que vai de i + 1 até n - 1, ou seja, percorre o restante do vetor a partir da posição i.
            for (int j = (i + 1); j < n; j++) {
                //Comparar o elemento na posição menor com o elemento na posição j, se o elemento na posição menor for maior do que o elemento na posição j, então a variável menor é atualizada para j, indicando que o menor elemento encontrado até agora está na posição j.
                if (vetor[menor] > vetor[j]) { //Se o elemento na posição menor for maior do que o elemento na posição j, então a variável menor é atualizada para j, indicando que o menor elemento encontrado até agora está na posição j.
                    menor = j; //Atualizar a variável menor para j, indicando que o menor elemento encontrado até agora está na posição j.
                }
            }
            //Após encontrar o índice do menor elemento no restante do vetor, o método swap é chamado para trocar o elemento na posição i com o elemento na posição menor, ou seja, o menor elemento encontrado é colocado na posição i, e o elemento que estava na posição i é colocado na posição menor.
            swap(vetor, menor, i); 
        }

        //Imprimir o vetor ordenado, usando um loop para percorrer o vetor e imprimir cada elemento, separado por um espaço.
        System.out.println("Vetor ordenado: "); 
        for (int i = 0; i < n; i++) {
            System.out.print(vetor[i] + " "); 
        }
 
        //Fechar o scanner para evitar vazamento de memória.
        sc.close(); 
    }
}