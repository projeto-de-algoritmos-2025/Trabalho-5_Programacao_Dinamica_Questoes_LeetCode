class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;          // ponteiros para s e p
        int starIdx = -1;          // última posição de '*' em p
        int matchIdx = 0;          // posição correspondente em s quando '*' apareceu
        
        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                // caracteres casam
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                // salva posição do '*' e tenta casar vazio
                starIdx = j;
                matchIdx = i;
                j++;
            } else if (starIdx != -1) {
                // houve '*', então tenta casar mais caracteres
                j = starIdx + 1;
                matchIdx++;
                i = matchIdx;
            } else {
                // não casa e não há '*'
                return false;
            }
        }
        
        // ignora '*' restantes no padrão
        while (j < p.size() && p[j] == '*') j++;
        
        return j == p.size();
    }
};
