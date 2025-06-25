struct SegmentTree {
    int tamanho;
    vector<int> arvore;

    SegmentTree(int tamanho_inicial) : tamanho(tamanho_inicial), arvore(4 * tamanho_inicial, 0) {}

    void atualiza(int indice, int esq, int dir, int posicao, int valor) {
        if (esq == dir) {
            arvore[indice] += valor;
            return;
        }
        int meio = (esq + dir) / 2;
        if (posicao <= meio)
            atualiza(2 * indice, esq, meio, posicao, valor);
        else
            atualiza(2 * indice + 1, meio + 1, dir, posicao, valor);
        arvore[indice] = arvore[2 * indice] + arvore[2 * indice + 1];
    }

    int procura(int indice, int esq, int dir, int consulta_esq, int consulta_dir) {
        if (consulta_dir < esq || dir < consulta_esq) return 0;
        if (consulta_esq <= esq && dir <= consulta_dir) return arvore[indice];
        int meio = (esq + dir) / 2;
        return procura(2 * indice, esq, meio, consulta_esq, consulta_dir) +
               procura(2 * indice + 1, meio + 1, dir, consulta_esq, consulta_dir);
    }

    void adiciona(int posicao, int valor) {
        atualiza(1, 0, tamanho - 1, posicao, valor);
    }

    int soma(int posicao) {
        return procura(1, 0, tamanho - 1, 0, posicao);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int tamanho = nums1.size();
        vector<int> posicoes_vetor2(tamanho);
        for (int i = 0; i < tamanho; i++)
            posicoes_vetor2[nums2[i]] = i;
        vector<int> permutacao(tamanho);
        for (int i = 0; i < tamanho; i++)
            permutacao[posicoes_vetor2[nums1[i]]] = i;

        SegmentTree arvore_segmentos(tamanho);

        long long resposta = 0;
        for (int x = 0; x < tamanho; x++) {
            int posicao = permutacao[x];
            long long menores_a_esquerda = arvore_segmentos.soma(posicao);
            arvore_segmentos.adiciona(posicao, 1);
            long long maiores_a_direita = (tamanho - 1 - posicao) - (x - menores_a_esquerda);
            resposta += menores_a_esquerda * maiores_a_direita;
        }
        return resposta;
    }
};