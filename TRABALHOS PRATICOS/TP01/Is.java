//Crie um metodo iterativo que recebe uma string como parâmetro e retorna true se a mesma é composta por voagis. Crie outro método iterativo 
//que recebe uma string como parâmetro e retorna true se a mesma é composta por consoantes. Crie outro método iterativo que recebe uma string 
//e retorna true se a mesma é corresponde a um número inteiro. Crie um quarto método iterativo que recebe uma string e retorna true se a 
//mesma corresponde a um número real. Na saída padrão, para cada linha de entrada, escreva outra saida da seguinte forma: X1 X2 X3 X4, onde 
//x1 é um booleano indicando se a entrada é composta por vogais, X2 é um booleano composto somente por consoantes, x3 é um número inteiro
//x4 é um número real. seu valor sera sim, caso contrario nao. 

import java.util.Scanner; 

//Criar a classe IS. 
class Is {
    //Verificar se a string nao é FIM. 
    public static boolean isFim (String str) {
        return (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M');
    }

    //Primeiro criar o método booleano para verificar se a string é composta por vogais. 
    public static boolean isVogal (String str) {
        //Loop para percorrer cada caracter da string de entrada. 
        for (int i = 0; i < str.length(); i++) {
            //Obter o caracter atual, ou seja, o caracter na posição i da string de entrada. 
            char caracter = str.charAt(i); 

            //Verificar se o caracter atual é uma vogal (considerando maiúsculas e minúsculas).
            if (!(caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u' || caracter == 'A' || 
                caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U')) {
                    //Se o caracter atual não for uma vogal, retornar false.
                    return false;
                }
            }   
            //Se todos os caracteres forem vogais, retornar true.
            return true;
    }

    //Criar o método booleano para verificar se a string é composta por consoantes.
    public static boolean isConsoante (String str) {
        //Loop para percorrer cada caracter da string de entrada.
        for (int i = 0; i < str.length(); i++) {
            //Obter o caracter atual. 
            char caracter = str.charAt(i); 

            //Verificar se não é um número. 
            if (!((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z'))) {
                return false;
            }

            //Verificar quase na mesma coisa que fizemos na vogal, porém agora se for diferentes das vogais retorna true, e se for igual a uma vogal retorna false.
            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u' || caracter == 'A' || 
                caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U') {
                    return false;   
            }
        }
        //Se nao tiver vogal, então é so consoante. 
        return true;
    }

        //Criar o método booleano para verificar se a string corresponde a um número inteiro. 
        public static boolean isInt (String str) {
            //Loop
            for (int i = 0; i < str.length(); i++) {
                //Obter o caracter atual. 
                char caracter = str.charAt(i); 

                //Verificar se o caracter atual é um dígito (entre '0' e '9').
                if (!(caracter >= '0' && caracter <= '9')) {
                    //Se o caracter atual não for um dígito, retornar false.
                    return false;
                }
            }
            return true;
        }

        //Metodo boolean para verificiar se é número real. 
        public static boolean isReal (String str) {
            //Loop. 
            for (int i = 0; i < str.length(); i++) {
                //Caracter atual.
                char caracter = str.charAt(i);

                //Verificar se o caracter atual é um dígito ou um ponto decimal.
                if (!(caracter >= '0' && caracter <= '9') && caracter != '.' && caracter != ',') {
                    //Se o caracter atual não for um dígito ou um ponto decimal, retornar false.
                    return false;
                }
            }
            return true;
        }

        //Principal. 
        public static void main (String[] args) {
            //Criar Scanner. 
            Scanner sc = new Scanner (System.in); 

            //Ler a primeira linha do arquivo.
            String linha = sc.nextLine(); 

            //Continuar lendo, se for diferente de FIM. 
            while (!isFim(linha)) {
                //Chamar métodos. 
                boolean vogal = isVogal(linha); 
                boolean consoante = isConsoante(linha);
                boolean inteiro = isInt(linha);
                boolean real = isReal(linha);

                //Imprimir no formato SIM / NAO, utilizado operador ternário. 
                System.out.println (
                (vogal ? "SIM" : "NAO") + " " +
                (consoante ? "SIM" : "NAO") + " " +
                (inteiro ? "SIM" : "NAO") + " " +
                (real ? "SIM" : "NAO")
                );

                //Ler a próxima linha para dar continuidade. 
                linha = sc.nextLine();
            }

            //Fechar o Scanner. 
            sc.close();
        }
}