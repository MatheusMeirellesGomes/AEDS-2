/* Questão 7 - Ordenação por Mergesort em Java */
import java.util.Scanner;
import java.io.*;

//Classe Data
class Data {
    private int ano, mes, dia;

    //Construtor
    public Data(int ano, int mes, int dia) {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;
    }

    //Parse
    public static Data parseData(String str) {
        String[] partes = str.split("-");
        int ano = Integer.parseInt(partes[0]);
        int mes = Integer.parseInt(partes[1]);
        int dia = Integer.parseInt(partes[2]);
        return new Data(ano, mes, dia);
    }

    //Formatar
    public String formatar() {
        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }
}

//Classe Hora
class Hora {
    private int hora, minuto;

    public Hora(int hora, int minuto) {
        this.hora = hora;
        this.minuto = minuto;
    }

    public static Hora parseHora(String str) {
        String[] partes = str.split(":");
        int hora = Integer.parseInt(partes[0]);
        int minuto = Integer.parseInt(partes[1]);
        return new Hora(hora, minuto);
    }

    public String formatar() {
        return String.format("%02d:%02d", hora, minuto);
    }
}

//Classe Restaurante
class Restaurante {
    private int id;
    private String nome, cidade;
    private int capacidade;
    private double avaliacao;
    private String[] tipos;
    private int faixaPreco;
    private Hora abertura, fechamento;
    private Data data;
    private boolean aberto;

    //Construtor
    public Restaurante(int id, String nome, String cidade, int capacidade, double avaliacao,
                       String[] tipos, int faixaPreco, Hora abertura,
                       Hora fechamento, Data data, boolean aberto) {

        this.id = id;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tipos = tipos;
        this.faixaPreco = faixaPreco;
        this.abertura = abertura;
        this.fechamento = fechamento;
        this.data = data;
        this.aberto = aberto;
    }

    //Gets
    public int getId() { return id; }
    public String getNome() { return nome; }
    public String getCidade() { return cidade; }

    //Parse Restaurante
    public static Restaurante parseRestaurante(String linha) {
        String[] p = linha.split(",");

        int id = Integer.parseInt(p[0].trim());
        String nome = p[1].trim();
        String cidade = p[2].trim();
        int capacidade = Integer.parseInt(p[3].trim());
        double avaliacao = Double.parseDouble(p[4].trim());

        String[] tipos = p[5].split(";");
        int faixa = p[6].length();

        String[] h = p[7].split("-");
        Hora ab = Hora.parseHora(h[0].trim());
        Hora fe = Hora.parseHora(h[1].trim());

        Data data = Data.parseData(p[8].trim());
        boolean aberto = Boolean.parseBoolean(p[9].trim());

        return new Restaurante(id, nome, cidade, capacidade, avaliacao,
                tipos, faixa, ab, fe, data, aberto);
    }

    //Formatar saída
    public String formatar() {
        String resp = "[" + id + " ## " + nome + " ## " + cidade + " ## " +
                capacidade + " ## " + avaliacao + " ## [";

        for (int i = 0; i < tipos.length; i++) {
            resp += tipos[i];
            if (i < tipos.length - 1) resp += ", ";
        }

        resp += "] ## ";

        for (int i = 0; i < faixaPreco; i++) resp += "$";

        resp += " ## " + abertura.formatar() + "-" + fechamento.formatar() +
                " ## " + data.formatar() + " ## " + aberto + "]";

        return resp;
    }
}

//Coleção
class ColecaoRestaurantes {
    private Restaurante[] restaurantes;
    private int quantidade;

    public ColecaoRestaurantes() {
        restaurantes = new Restaurante[2000];
        quantidade = 0;
    }

    public void lerCsv(String path) {
        try {
            Scanner sc = new Scanner(new File(path));

            if (sc.hasNextLine()) sc.nextLine();

            while (sc.hasNextLine()) {
                String linha = sc.nextLine();
                if (linha.length() > 0) {
                    restaurantes[quantidade++] = Restaurante.parseRestaurante(linha);
                }
            }

            sc.close();
        } catch (Exception e) {
            System.out.println("Erro ao ler arquivo.");
        }
    }

    public Restaurante[] getRestaurantes() { return restaurantes; }
    public int getQuantidade() { return quantidade; }
}

//Classe principal
public class Main {

    public static int comparacoes = 0;
    public static int movimentacoes = 0;

    //Comparar (cidade -> nome)
    public static int comparar(Restaurante a, Restaurante b) {
        comparacoes++;
        int resp = a.getCidade().compareTo(b.getCidade());

        if (resp == 0) {
            comparacoes++;
            resp = a.getNome().compareTo(b.getNome());
        }

        return resp;
    }

    //Merge
    public static void merge(Restaurante[] arr, Restaurante[] aux, int esq, int meio, int dir) {

        //Copiar para auxiliar
        for (int i = esq; i <= dir; i++) {
            aux[i] = arr[i];
            movimentacoes++;
        }

        int i = esq;
        int j = meio + 1;

        for (int k = esq; k <= dir; k++) {

            if (i > meio) {
                arr[k] = aux[j++];
                movimentacoes++;
            }
            else if (j > dir) {
                arr[k] = aux[i++];
                movimentacoes++;
            }
            else if (comparar(aux[i], aux[j]) <= 0) {
                arr[k] = aux[i++];
                movimentacoes++;
            }
            else {
                arr[k] = aux[j++];
                movimentacoes++;
            }
        }
    }

    //MergeSort
    public static void mergesort(Restaurante[] arr, Restaurante[] aux, int esq, int dir) {
        if (esq >= dir) return;

        int meio = (esq + dir) / 2;

        mergesort(arr, aux, esq, meio);
        mergesort(arr, aux, meio + 1, dir);

        merge(arr, aux, esq, meio, dir);
    }

    //Log
    public static void criarLog(String matricula, int comp, int mov, double tempo) {
        try {
            FileWriter arq = new FileWriter(matricula + "_mergesort.txt");
            arq.write(matricula + "\t" + comp + "\t" + mov + "\t" + tempo);
            arq.close();
        } catch (Exception e) {
            System.out.println("Erro ao criar log.");
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        //Carregar CSV
        ColecaoRestaurantes colecao = new ColecaoRestaurantes();
        colecao.lerCsv("/tmp/restaurantes.csv");

        Restaurante[] todos = colecao.getRestaurantes();
        int tamanho = colecao.getQuantidade();

        //Selecionados
        Restaurante[] selecionados = new Restaurante[tamanho];
        int n = 0;

        //Entrada IDs
        int id = sc.nextInt();

        while (id != -1) {
            for (int i = 0; i < tamanho; i++) {
                if (todos[i].getId() == id) {
                    selecionados[n++] = todos[i];
                    break;
                }
            }
            id = sc.nextInt();
        }

        //Auxiliar
        Restaurante[] aux = new Restaurante[n];

        long inicio = System.nanoTime();

        //Ordenar
        mergesort(selecionados, aux, 0, n - 1);

        long fim = System.nanoTime();
        double tempo = (fim - inicio) / 1e9;

        //Saída
        for (int i = 0; i < n; i++) {
            System.out.println(selecionados[i].formatar());
        }

        //Log
        criarLog("minha_matricula", comparacoes, movimentacoes, tempo);

        sc.close();
    }
}