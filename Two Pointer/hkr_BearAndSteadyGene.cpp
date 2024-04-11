#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */
 
vector<int> gene_count(4, 0); //A, C, T, G
vector<int> exceed(4, 0); 
vector<int> remove_cnt(4, 0); 

bool check() {
    for(int i=0; i<4; i++) {
        if(remove_cnt[i] < exceed[i]) {
            return false;
        }
    }
    return true;
}

void add(char c) {
    if(c == 'A') {
        remove_cnt[0]++;
    } else if(c == 'C') {
        remove_cnt[1]++;
    } else if(c == 'T') {
        remove_cnt[2]++;
    } else if(c == 'G') {
        remove_cnt[3]++;
    }
}

void remove(char c) {
    if(c == 'A') {
        remove_cnt[0]--;
    } else if(c == 'C') {
        remove_cnt[1]--;
    } else if(c == 'T') {
        remove_cnt[2]--;
    } else if(c == 'G') {
        remove_cnt[3]--;
    }
}

int steadyGene(string gene) {
    for(int i=0; i<gene.length(); i++) {
        if(gene[i] == 'A') {
            gene_count[0]++;
        } else if(gene[i] == 'C') {
            gene_count[1]++;
        } else if(gene[i] == 'T') {
            gene_count[2]++;
        } else if(gene[i] == 'G') {
            gene_count[3]++;
        }
    }
    
    int N = gene.length();
    int need = gene.length() / 4;
    
    exceed[0] = gene_count[0] - need > 0 ? gene_count[0] - need : 0;
    exceed[1] = gene_count[1] - need > 0 ? gene_count[1] - need : 0;
    exceed[2] = gene_count[2] - need > 0 ? gene_count[2] - need : 0;
    exceed[3] = gene_count[3] - need > 0 ? gene_count[3] - need : 0;

    int min = 500000;
    int e = 0;
        
    for(int i=0; i<N; i++) {
        while(e < N) {
            if(check()) {
                if((e - i) < min) {
                    min = e - i;
                }
                break;
            }
            add(gene[e]);            
            e++;
        }
        remove(gene[i]);
    }
    
    return min;
}
