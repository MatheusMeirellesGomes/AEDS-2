/*Questão de Pesquisa Sequencial em Java. */import java.util.Scanner;
import java.io.*;

//Classe Data
class Data {
    private int ano;
    private int mes;
    private int dia;

    //Construtor
    public Data(int ano, int mes, int dia) {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;
    }

    //Parse da data (aaaa-mm-dd)
    public static Data parseData(String str) {
        String[] partes = str.split("-");
        int ano = Integer.parseInt(partes[0]);
        int mes = Integer.parseInt(partes[1]);
        int dia = Integer.parseInt(partes[2]);
        return new Data(ano, mes, dia);
    }

    //Formatar data
    public String formatarData() {
        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }
}

//Classe Hora
class Hora {
    private int hora;
    private int minuto;

    //Construtor
    public Hora(int hora, int minuto) {
        this.hora = hora;
        this.minuto = minuto;
    }

    //Parse da hora (hh:mm)
    public static Hora parseHora(String str) {
        String[] partes = str.split(":");
        int hora = Integer.parseInt(partes[0]);
        int minuto = Integer.parseInt(partes[1]);
        return new Hora(hora, minuto);
    }

    //Formatar hora
    public String formatar() {
        return String.format("%02d:%02d", hora, minuto);
    }
}

//Classe Restaurante
class Restaurante {
    private int id;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String[] tiposCozinha;
    private int faixaPreco;
    private Hora horarioAbertura;
    private Hora horarioFechamento;
    private Data dataAbertura;
    private boolean aberto;

    //Construtor
    public Restaurante(int id, String nome, String cidade, int capacidade, double avaliacao,
                       String[] tiposCozinha, int faixaPreco, Hora horarioAbertura,
                       Hora horarioFechamento, Data dataAbertura, boolean aberto) {
        this.id = id;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tiposCozinha = tiposCozinha;
        this.faixaPreco = faixaPreco;
        this.horarioAbertura = horarioAbertura;
        this.horarioFechamento = horarioFechamento;
        this.dataAbertura = dataAbertura;
        this.aberto = aberto;
    }

    //Gets
    public int getId() { 
        return id; 
    }
    
    public String getNome() { 
        return nome; 
    }

    //Parse do restaurante
    public static Restaurante parseRestaurante(String str) {
        String[] partes = str.split(",");

        int id = Integer.parseInt(partes[0].trim());
        String nome = partes[1].trim();
        String cidade = partes[2].trim();
        int capacidade = Integer.parseInt(partes[3].trim());
        double avaliacao = Double.parseDouble(partes[4].trim());

        String[] tipos = partes[5].trim().split(";");
        int faixaPreco = partes[6].trim().length();

        String[] horario = partes[7].split("-");
        Hora abertura = Hora.parseHora(horario[0].trim());
        Hora fechamento = Hora.parseHora(horario[1].trim());

        Data data = Data.parseData(partes[8].trim());
        boolean aberto = Boolean.parseBoolean(partes[9].trim());

        return new Restaurante(id, nome, cidade, capacidade, avaliacao,
                tipos, faixaPreco, abertura, fechamento, data, aberto);
    }
}

//Classe Coleção
class ColecaoRestaurantes {
    private Restaurante[] restaurantes;
    private int quantidade;

    //Construtor
    public ColecaoRestaurantes() {
        restaurantes = new Restaurante[2000];
        quantidade = 0;
    }

    //Ler CSV
    public void lerCsv(String path) {
        try {
            Scanner sc = new Scanner(new File(path));

            //Ignorar cabeçalho
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

    public Restaurante[] getRestaurantes() {
        return restaurantes;
    }

    public int getQuantidade() {
        return quantidade;
    }
}

//Método de Pesquisa Sequencial
public class Main {

    //Contador de comparações
    public static int comparacoes = 0;

    //Método de busca sequencial
    public static boolean pesquisaSequencial(Restaurante[] array, int n, String nome) {
        for (int i = 0; i < n; i++) {
            comparacoes++; //Contar comparação

            if (array[i].getNome().compareTo(nome) == 0) {
                return true;
            }
        }
        return false;
    }

    //Criar arquivo de log
    public static void criarArqLog(String matricula, int comparacoes, double tempo) {
        try {
            FileWriter arq = new FileWriter(matricula + "_sequencial.txt");
            arq.write(matricula + "\t" + comparacoes + "\t" + tempo);
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

        //Array de selecionados
        Restaurante[] selecionados = new Restaurante[tamanho];
        int n = 0;

        //Entrada de IDs
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

        sc.nextLine(); //Limpar buffer

        //Tempo inicial
        long inicio = System.nanoTime();

        //Entrada de nomes para busca
        String linha = sc.nextLine();
        while (!linha.equals("FIM")) {

            boolean resp = pesquisaSequencial(selecionados, n, linha);

            System.out.println(resp ? "SIM" : "NAO");

            linha = sc.nextLine();
        }

        //Tempo final
        long fim = System.nanoTime();
        double tempo = (fim - inicio) / 1e9;

        //Criar log
        criarArqLog("minha_matricula", comparacoes, tempo);

        sc.close();
    }
}