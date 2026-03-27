#include <stdio.h>
int main(){
    int n;
    
    double total = 0;
    printf("Quantidade de valores\n");
    scanf("%d", &n);
    int valores[n];
    for(int i = 0; i<n; i++){
        printf("Digite o valor:\n");
        scanf("%d", &valores[i]);
        
    }
    
    for(int i =0; i<n; i++){
        total += valores[i];
        printf("teste %d\n", valores[i]);
    }
    double media; 
    media = total/n;
    printf("A média é: %.2f\n", media);
    return 0;
}
