class Solution {
public:
    vector<vector<long long>> combinacoes;
    long long modulo = 1e9 + 7;

    long long ways(vector<int>& numeros, int tamanho) {
        if (tamanho <= 2) return 1;
        vector<int> esquerda, direita;
        for (int i = 1; i < tamanho; i++) {
            if (numeros[0] > numeros[i]) {
                esquerda.push_back(numeros[i]);
            } else {
                direita.push_back(numeros[i]);
            }
        }
        long long resultado_esquerda = ways(esquerda, esquerda.size());
        long long resultado_direita = ways(direita, direita.size());
        long long resultado = (((combinacoes[tamanho - 1][esquerda.size()] * resultado_esquerda) % modulo) * resultado_direita) % modulo;
        
        return resultado;
    }

    int numOfWays(vector<int>& v) {
        int tamanho = v.size();
        combinacoes.resize(tamanho + 1);

        for (int i = 0; i < tamanho + 1; ++i) {
            combinacoes[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                combinacoes[i][j] = (combinacoes[i - 1][j - 1] + combinacoes[i - 1][j]) % modulo;
            }
        }
        return (ways(v, tamanho) - 1 + modulo) % modulo;
    }
};