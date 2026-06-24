import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;

public class HashIndireta {
	public static void main(String[] args) throws Exception{

        colecaoRestaurantes col = colecaoRestaurantes.lerCsv();
		Scanner sc = new Scanner(System.in);

		int[] compMov = new int[2];
		String nomeArquivo = "889989_arvore_trie_hash.txt";
		Trie a = new Trie();
		int id = sc.nextInt();

		while(id > 0){
			a.inserir(col.restaurantes[id - 1]);
			id = sc.nextInt();
		}

		long inicio = System.currentTimeMillis();

		sc.nextLine();
		String nome = sc.nextLine();

		while(nome.equals("FIM") == false){
			Restaurante resp = a.pesquisar(nome, compMov);

			if(resp != null){
				System.out.println("SIM " + resp.formatar_restaurante());
			}
			else{
				System.out.println("NAO");
			}

			nome = sc.nextLine();
		}

		long tempo = System.currentTimeMillis() - inicio;

		FileWriter writer = new FileWriter(nomeArquivo);
        writer.write("889989" + "\t" + compMov[0] + "\t" + compMov[1] + "\t" + tempo);
        writer.close();

        sc.close();
	}	
}

class Data{
	int dia, mes, ano;

	public static Data parseData(String s){
        Data d = new Data();
		d.ano = Integer.parseInt("" + s.charAt(0) + s.charAt(1) + s.charAt(2) + s.charAt(3));					
		d.mes = Integer.parseInt("" + s.charAt(5) + s.charAt(6));
		d.dia = Integer.parseInt("" + s.charAt(8) + s.charAt(9));

		return d;
	}

	public String formatar_data(){
		String s = String.format("%02d/%02d/%04d", dia, mes, ano);
		return s;
	}

	public String invFormatar_data(){
		String s = String.format("%04d/%02d/%02d", ano, mes, dia);
		return s;
	}
}

class Hora{
	int hora, minuto;

	public static Hora parseHora(String s){
        Hora h = new Hora();
		h.hora = Integer.parseInt("" + s.charAt(0) + s.charAt(1));
		h.minuto = Integer.parseInt("" + s.charAt(3) + s.charAt(4));

        return h;
	}

	public String formatar_hora(){
		String s = String.format("%02d:%02d", hora, minuto);
		return s;
	}
}

class Restaurante{
	int id;
	String nome;
	String cidade;
	int capacidade;
	double avaliacao;
	String[] tiposCozinha;
	String faixaPreco;
	Hora horarioAbertura;
	Hora horarioFechamento;
	Data dataAbertura;
	boolean aberto;

	public static Restaurante parseRestaurante(String s){
        Restaurante r = new Restaurante();
        int i = 0, tam = s.length();
        String[] valores = new String[10];

        for(int j = 0; j < 10; j++){
            valores[j] = "";
        }

        for(int j = 0; j < tam; j++){
            if(s.charAt(j) != ','){
				valores[i] += s.charAt(j);
			}
            else{
				i++;
			}
        }

        r.id = Integer.parseInt(valores[0]);
        r.nome = valores[1];
        r.cidade = valores[2];
        r.capacidade = Integer.parseInt(valores[3]);
        r.avaliacao = Double.parseDouble(valores[4]);
        r.tiposCozinha = valores[5].split(";");
        r.faixaPreco = valores[6];

		String h[] = valores[7].split("-");
        r.horarioAbertura = Hora.parseHora(h[0]);
        r.horarioFechamento = Hora.parseHora(h[1]);

        r.dataAbertura = Data.parseData(valores[8]);
        r.aberto = Boolean.parseBoolean(valores[9]);

        return r;
    }

	public String formatar_restaurante(){
		String s = "[" + id + " ## "+  nome + " ## " + cidade + " ## " + capacidade + " ## " + avaliacao + " ## [" + String.join(",", tiposCozinha)
			+ "] ## " + faixaPreco + " ## " + horarioAbertura.formatar_hora() + "-" + horarioFechamento.formatar_hora()
			+ " ## " + dataAbertura.formatar_data() + " ## "
			+ aberto + "]";

		return s;
	}
}

// COLEÇÃO RESTAURANTES ###############################################

class colecaoRestaurantes{
	Restaurante restaurantes[];

	public void lerCsv(String path) throws FileNotFoundException{
		Scanner sc = new Scanner(new File(path));
		restaurantes = new Restaurante[500];

		sc.nextLine();

		for(int i = 0; i < 500; i++){
            String s = sc.nextLine();
            restaurantes[i] = Restaurante.parseRestaurante(s);
        }

		sc.close();
	}

	public static colecaoRestaurantes lerCsv() throws FileNotFoundException{
		colecaoRestaurantes col = new colecaoRestaurantes();
		String path = "/tmp/restaurantes.csv";

		col.lerCsv(path);

		return col;
	}

	public void mostrar(int tam){
		for(int i = 0; i < tam; i++){
			String s = this.restaurantes[i].formatar_restaurante();
			System.out.println(s);
		}
	}

	public void selecaoParcial(int k, int[]compMov, int tam){
		for(int i = 0; i < k; i++){
			int menor = i;

			for(int j = i + 1; j < tam; j++){
				compMov[0]++;

				if(this.restaurantes[menor].nome.compareTo(this.restaurantes[j].nome) > 0){
					menor = j;
				}
			}

			this.swap(i, menor);
			compMov[1]++;
		}
	}

	public void quicksort(int[] coMov, int esq, int dir){
    	int i = esq, j = dir;
    	Restaurante pivoR = this.restaurantes[(esq + dir) / 2];
    	double pivo = pivoR.avaliacao;

    	while(i <= j){
        	while(this.restaurantes[i].avaliacao < pivo || (this.restaurantes[i].avaliacao == pivo &&
            this.restaurantes[i].nome.compareTo(pivoR.nome) < 0)){
            	i++;
				coMov[0]++;
        	}

        	while(this.restaurantes[j].avaliacao > pivo || (this.restaurantes[j].avaliacao == pivo &&
            this.restaurantes[j].nome.compareTo(pivoR.nome) > 0)){
            	j--;
				coMov[0]++;
        	}

        	if(i <= j){
            	swap(i, j);
            	coMov[1]++;
            	i++;
				j--;
   			}
    	}

    	if(esq < j){
    		quicksort(coMov, esq, j);
		}

    	if(i < dir){
    		quicksort(coMov, i, dir);
		}
	}

	public void quicksortParcial(int[]coMov, int esq, int dir){
    	int i = esq, j = dir;
    	double pivo = this.restaurantes[(esq + dir) / 2].avaliacao;
    	int k = 9;
		Restaurante pivoR = this.restaurantes[(esq + dir) / 2];

    	while(i <= j) {
        	while(this.restaurantes[i].avaliacao < pivo || (this.restaurantes[i].avaliacao == pivo && this.restaurantes[i].nome.compareTo(pivoR.nome) < 0)){
				i++;
				coMov[0]++;
			}

        	while(this.restaurantes[j].avaliacao > pivo || (this.restaurantes[j].avaliacao == pivo && this.restaurantes[j].nome.compareTo(pivoR.nome) > 0)){
				j--;
				coMov[0]++;
			}

        	if(i <= j) {
            	swap(i, j);
				coMov[1]++;
            	i++;
            	j--;
        	}
    	}

    	if(esq < j && j >= k){
    		quicksortParcial(coMov, esq, j);
		}

    	if(i < dir && i < k){
    		quicksortParcial(coMov, i, dir);
		}
	}

	public int comparaData(int i, int j){
		String d1 = this.restaurantes[i].dataAbertura.invFormatar_data();
		String d2 = this.restaurantes[j].dataAbertura.invFormatar_data();
		int resp = d1.compareTo(d2);

		if(resp == 0){
			resp = this.restaurantes[i].nome.compareTo(this.restaurantes[j].nome);
		}

		return resp;
	}

	public void swap(int i, int j){
		Restaurante tmp = this.restaurantes[i];
		this.restaurantes[i] = this.restaurantes[j];
		this.restaurantes[j] = tmp;
	}

	public static boolean pesquisaS(String s, colecaoRestaurantes array, int tamanho){
		boolean resp = false;

		for(int i = 0; i < tamanho; i++){
    		if(s.equals(array.restaurantes[i].nome)){
				i = tamanho;
				resp = true;
			}
		}

		return resp;
	}
}

// TRIE COM HASH #######################################################

class No {
    public char elemento;
    public int tamanho = 255;
    public No[] prox;
    public boolean folha;
    public Restaurante restaurante;

    public No() {
        this(' ');
    }

    public No(char elemento) {
        this.elemento = elemento;
        prox = new No[tamanho];

        for (int i = 0; i < tamanho; i++) {
            prox[i] = null;
        }

        folha = false;
        restaurante = null;
    }

    public static int hash(char x) {
        return (int) x;
    }
}

class Trie {
    private No raiz;

    public Trie() {
        raiz = new No();
    }

    public void inserir(Restaurante r) throws Exception {
        inserir(r.nome, r, raiz, 0);
    }

    private void inserir(String s, Restaurante r, No no, int i) throws Exception {
        int pos = No.hash(s.charAt(i));

        if (no.prox[pos] == null) {
            no.prox[pos] = new No(s.charAt(i));
        }

        if (i == s.length() - 1) {
            no.prox[pos].folha = true;
            no.prox[pos].restaurante = r;
        } 
        else {
            inserir(s, r, no.prox[pos], i + 1);
        }
    }

    public Restaurante pesquisar(String s, int[] cM) throws Exception {
        return pesquisar(s, raiz, 0, cM);
    }

    private Restaurante pesquisar(String s, No no, int i, int[] cM) throws Exception {
        Restaurante resp = null;

        if (i < s.length()) {
            char c = s.charAt(i);
            int pos = No.hash(c);

            cM[0]++;

            if (no.prox[pos] != null) {
                System.out.print(c + " ");

                if (i == s.length() - 1) {
                    cM[0]++;

                    if (no.prox[pos].folha == true) {
                        resp = no.prox[pos].restaurante;
                    }
                } 
                else {
                    resp = pesquisar(s, no.prox[pos], i + 1, cM);
                }
            }
        }

        return resp;
    }
}