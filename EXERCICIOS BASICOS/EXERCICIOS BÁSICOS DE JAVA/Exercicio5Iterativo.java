public class Exercicio5Iterativo {
    int contMaiuscula (String s) {
        int cont = 0; 

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                cont++;
            }
        }
        return cont;
    }
}