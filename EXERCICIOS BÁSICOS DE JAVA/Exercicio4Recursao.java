//Exercicio para contar o número de letras maiúsculas em uma string usando recursão
public class Exercicio4Recursao { //Inicializar a classe com o mesmo nome que foi salvo no arquivo.
    //Construtor com parâmetro para contar as letras maiúsculas, que chama o método recursivo com a posição inicial 0.
    int contMaiuscula (String s) { 
        return contMaiuscula (s,0); //Chama o método recursivo com a string e a posição inicial 0.
    }

    //Método recursivo para contar as letras maiúsculas, que recebe a string e a posição atual.
    int contMaiuscula (String s, int pos) { //s = string a ser analisada, pos = posição atual na string.
        //Variável para contar as letras maiúsculas, inicializada com 0.
        int qntdMaiuscula = 0; 

        //Verificar se a posição atual é menor que o comprimento da string, para evitar acessar índices fora do limite.
        if (pos < s.length()) { //Se a posição atual for menor que o comprimento da string, continue a análise.
            //Verificar se o caractere na posição atual é uma letra maiúscula, comparando com os caracteres 'A' e 'Z'.
            if (s.charAt(pos) >= 'A' && s.charAt(pos) <= 'Z') { //Se o caractere na posição atual for uma letra maiúscula. (s.charAT(pos) = caractere na posição atual da string)
             qntdMaiuscula = 1  + contMaiuscula(s, pos + 1);  //Se o caractere na posição atual for uma letra maiúscula, adicione 1 à contagem e chame o método recursivo para a próxima posição (pos + 1).
            }
            else { //Senão o caractere na posição atual não é uma letra maiúscula, apenas chame o método recursivo para a próxima posição (pos + 1) sem adicionar à contagem.
             qntdMaiuscula = 0 + contMaiuscula(s, pos + 1);
            }
        }
        return qntdMaiuscula; //Vai retornar a quantidade total de letras maiúsculas encontradas na string após a análise completa. (quando pos >= s.length(), a contagem final será retornada).
    }
}