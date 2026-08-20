    /* Questão 1: Criar uma classe restaurante que tenha outras classes dentro dela, como, id, nome, cidade, capacidade, avaliacao, tipos cozinha, faixa preco
    horario, data abertura, aberto. Esse é o dicionário de dados. 
    Especificação dos tipos: 
    Tipo Data: ano, mes, dia (inteiro)
    Tipo Hora: hora, minuto (inteiro)
    Tipo Restaurante: id, nome, cidade, capacidade, avaliacao, tipos cozinha, faixa preco, horario, data abertura, aberto */ 

    import java.util.Scanner; 

    //Classe Data 
    class Data { 
        //Inicializar atributos privados. 
        private int ano; 
        private int mes; 
        private int dia;
        
        //Construtor.  
        public Data (int ano, int mes, int dia) {
            this.ano = ano; 
            this.mes = mes; 
            this.dia = dia;
        }

        //Método parse para converter uma string: dd-mm-aaaa para dd/mm/aaaa. 
        public static Data parseData(String str) {
            //Dividir a string em partes usando o caractere '-' como delimitador. 
            String[] partes = str.split("-");

            //Converter em inteiro. 
            int ano = Integer.parseInt(partes[0]);
            int mes = Integer.parseInt(partes[1]);
            int dia = Integer.parseInt(partes[2]);

            //Criação do objeto Data com os valores convertidos.
            return new Data(ano, mes, dia); 
        }

        /*Método para setar ano. 
        public void setAno (int ano) {
            this.ano = ano; 
        }*/

        //Get - Retorno. 
        public int getAno() {
            return this.ano;
        }

        /*Método para setar mês. 
        public void setMes (int mes) {
            if (mes >= 1 && mes <= 12) this.mes = mes; 
        }*/

        //Get
        public int getMes() {
            return this.mes; 
        }

        /*Método para setar dia. 
        public void setDia (int dia) {
            if (dia >= 1 && dia <= 31) this.dia = dia; 
        }*/

        //Get
        public int getDia() {
            return this.dia;
        }

        //Verificar cada valor, para formatar a data com dois dígitos.
        public String doisDigitos(int valor) { 
            //String vazia para armazenar a data formatada.
            String resp = ""; 

            //Verificação, tanto para dia, mês e ano. 
            if (valor < 10) resp = "0" + valor; 
            else resp = "" + valor; 

            //Retornando a data formatada no formato de String. 
            return resp; 
        }

        //Formatar a data no formato dd/mm/aaaa.
        public String formatarData() {
            return doisDigitos(this.dia) + "/" + doisDigitos(this.mes) + "/" + this.ano; 
        }
    }

    //Classe Hora
    class Hora { 
        //Inicializar atributos privados.
        private int hora; 
        private int minuto; 

        //Construtor. 
        public Hora (int hora, int minuto) {
            this.hora = hora; 
            this.minuto = minuto; 
        }

        //Método parse. Converte string hh:mm para objeto Hora. 
        public static Hora parseHora (String str) {
            //Dividir a string. Usando ':' como delimitador.
            String[] partes = str.split(":");

            //Converter em inteiro. 
            int hora = Integer.parseInt(partes[0]);
            int minuto = Integer.parseInt(partes[1]);

            //Criação do objeto Hora com os valores convertidos.
            return new Hora(hora, minuto);
        }

        /*Método para setar hora. 
        public void setHora (int hora) {
            if (hora >= 0 && hora <= 23) this.hora = hora; 
        }*/

        /* Setar minuto. 
        public void setMinuto (int minuto) {
            if (minuto >= 0 && minuto <= 59) this.minuto = minuto; 
        }
        */

        //Métodos getters.
        public int getHora() {
            return this.hora; 
        }

        public int getMinuto() {
            return this.minuto; 
        }

        //Verificar o valor para formatar hora e minuto com dois dígitos.
        public String doisDigitos (int valor) {
            //String vazia para armazenamento. 
            String resp = ""; 

            //Verificação. 
            if (valor < 10) resp = "0" + valor; 
            else resp = "" + valor;

            //Retorna a hora ou minuto formatado com dois dígitos.
            return resp; 
        }

        //Formatar a hora no formato hh:mm.
        public String formatar() {
            return doisDigitos(this.hora) + ":" + doisDigitos(this.minuto);
        }
    }

    //Classe Restaurante
    class Restaurante { 
        //Inicializar os atributos privados. 
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

        //Construtor. 
        public Restaurante (int id, String nome, String cidade, int capacidade, double avaliacao, String[] tiposCozinha, int faixaPreco, 
            Hora horarioAbertura, Hora horarioFechamento, Data dataAbertura, boolean aberto) {
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

            //Get do atributo id. 
            public int getId() { //Como id é chave primária, não precisa do método set. 
                return this.id; 
            }

            //Get do atributo nome. 
            public String getNome() { //Não precisa do set. 
                return this.nome;
            }

            //Get do atributo cidade.
            public String getCidade() { //Não precisa do set.
                return this.cidade; 
            }

            //Get do atrubuto capacidade.
            public int getCapacidade() { //Não precisa do set.
                return this.capacidade;
            }

            //Get do atributo avaliação.
            public double getAvaliacao() { //Não precisa do set.
                return this.avaliacao; 
            }

            //Método parse para o atributo tiposCozinha. 
            public static String[] parseTiposCozinha (String str) {
                //Dividir com o delimitador ';'.
                String[] partes = str.split(";");
                
                //Loop. 
                for (int i = 0; i < partes.length; i++) {
                    //Remover espaços em branco. 
                    partes[i] = partes[i].trim();
                }

                //Retornar o array de tipos de cozinha.
                return partes;
            }

            //Get do atributo tiposCozinha. 
            public String[] getTiposCozinha() {
                return this.tiposCozinha; 
            }

            //Formatar os tipos de cozinha em uma string, separando por ';'.
            public String formatarTiposCozinha() { 
                //String iniciando com '[' para formatar a saída. 
                String resp = "["; 

                //Loop. 
                for (int i = 0; i < tiposCozinha.length; i++) {
                    resp += tiposCozinha[i]; 

                    //Adicionar o delimitador. 
                    if (i < tiposCozinha.length - 1) resp += ", "; //Adicionar o ; e um espaço. 
                }

                //Fechar a formatação com ']'.
                resp += ']';

                //Retornar a string formatada.
                return resp;
            }

            //Método parse para o atributo faixaPreco.
            public static int parseFaixaPreco (String str) {
                //Retornar o tamanho da string. $ = 1 / $$ = 2 ... 
                return str.length();
            }

            //Método para formatar a faixa de preço. 
            public String formatarFaixaPreco() {
                //String vazia para armazenar a faixa de preco formatada. 
                String formatada = ""; 

                //Loop para adicionar o símbolo '$' de acordo com a faixa de preço.
                for (int i = 0; i < faixaPreco; i++) {
                    formatada += "$";
                }

                //Retornar a string formatada.
                return formatada;
            }

            //Get do atributo faixaPreco.
            public int getFaixaPreco() {
                return this.faixaPreco;
            }

            //Get do atributo horário, então vai ser um get para abertura e outro para o fechamento.
            public Hora getHorarioAbertura() {
                return this.horarioAbertura;
            }

            public Hora getHorarioFechamento() {
                return this.horarioFechamento;
            }

            //Get do atributo dataAbertura.
            public Data getDataAbertura() { //Não preciso do set, nem do parse. 
                return this.dataAbertura; 
            }

            //Get do atributo aberto.
            public boolean isAberto() {
                return this.aberto;
            }

            //Método para organizar a saída dos dados do restaurante.
            public static Restaurante parseRestaurante (String str) {
                //Dividir com o delimitador ','.
                String[] partes = str.split(","); 

                //Converter os valores. 
                int id = Integer.parseInt(partes[0].trim()); //trim = remover os espaços em branco.
                String nome = partes[1].trim();
                String cidade = partes[2].trim();
                int capacidade = Integer.parseInt(partes[3].trim()); 
                double avaliacao = Double.parseDouble(partes[4].trim());
                String[] tiposCozinha = parseTiposCozinha(partes[5].trim());
                int faixaPreco = parseFaixaPreco(partes[6].trim());
                String[] horario = partes[7].split("-");
                Hora horarioAbertura = Hora.parseHora(horario[0].trim()); 
                Hora horarioFechamento = Hora.parseHora(horario[1].trim());
                Data dataAbertura = Data.parseData(partes[8].trim());
                boolean aberto = Boolean.parseBoolean(partes[9].trim());

                //Objeto restaurante com os valores convertidos.
                return new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, 
                horarioAbertura, horarioFechamento, dataAbertura, aberto);
            }

            //Método para formatar a saída dos dados do restaurante.
            public String formatar() {
                return "[" +
                        this.id + " ## " +
                        this.nome + " ## " +
                        this.cidade + " ## " +
                        this.capacidade + " ## " +
                        this.avaliacao + " ## " +
                        formatarTiposCozinha() + " ## " +
                        formatarFaixaPreco() + " ## " +
                        this.horarioAbertura.formatar() + "-" +
                        this.horarioFechamento.formatar() + " ## " +
                        this.dataAbertura.formatarData() + " ## " +
                        this.aberto +
                        "]";
            }
    }

    //Classe Colecao Restaurante. 
    class ColecaoRestaurantes {
        //Atributos. 
        private Restaurante[] restaurantes; 
        private int quantidade; //Quantidade de restaurantes na coleção. 

        //Construtor. 
        public ColecaoRestaurantes() {
            this.restaurantes = new Restaurante[100]; //tamanho máximo da coleção. 
            this.quantidade = 0; //até então a coleção está vazia.
        }

        //Método ler uma linha do arquivo. 
        public void lerCsv (String path) {
            //Tentar abrir o arquivo para leitura
            try {
                //Ler a linha do arquivo usando Scanner.
                Scanner sc = new Scanner (new File(path)); 
                
                //Loop para ler cada linha do arquivo. 
                while (sc.hasNextLine()) {
                    //Ler a linha. 
                    String linha = sc.nextLine(); 

                    //Chamar o método parseRestaurante. 
                    Restaurante restaurante = Restaurante.parseRestaurante(linha);

                    //Adicionar o restaurante a coleção. 
                    if (quantidade < restaurantes.length) {
                        restaurantes[quantidade] = restaurante; 
                        quantidade++;
                    }
                }

                //Fechar o Scanner.
                sc.close();
            } catch (FileNotFoundException e) {
                System.out.println("Arquivo nao encontrado ou erro ao abrir o arquivo"); ; 
            }
        }

    }
        
    //Classe Principal. 
    public class Main {
        public static void main(String[] args ) {
            //Scanner. 
            Scanner sc = new Scanner(System.in);

            //Criar a coleção de restaurantes.
            ColecaoRestaurantes colecao = new ColecaoRestaurantes();

            //Ler o arquivo Csv, chamando o método lerCsv. 
            colecao.lerCsv("/tmp/restaurantes.csv");

            //Ler a primeira linha de entrada
            String linha = sc.nextLine(); 

            //Loop
            while (!linha.equals("-1")) {
                //Converter a linha para inteiro, para saber o id. 
                int id = Integer.parseInt(linha); 

                //Procurar o restaurante
                Restaurante encontrado = null; //até que prove o contrário. 

                //Loop. 
                for (int i = 0; i < colecao.quantidade; i++) {
                       //Verificar se o id do restaurante na coleção é igual ao id procurado.
                       if (colecao.restaurantes[i].getId() == id) {
                            encontrado = colecao.restaurantes[i]; 
                       }
                }

                //Verificar se o restaurante foi encontrado.
                if (encontrado != null) {
                    //Imprimir os dados do restaurante, chamando formatar. 
                    System.out.println(encontrado.formatar());
                }

                //Ler a próxima linha de entrada. 
                linha = sc.nextLine();
            }

            //Fechar o Scanner.
            sc.close();
        }
    }