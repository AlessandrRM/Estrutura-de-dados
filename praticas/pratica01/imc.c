#include <stdio.h>
float calcular_imc(float p, float a){
    float i = 0;
    if(p <=0 || a <=0){
        return printf("Peso ou altura menor ou igual a 0\n");
    }else{
        i = p / (a*a);
        if(i<18.5){
            return printf("Abaixo, IMC : %.2f\n", i);
        }else if (i<25.0)
        {
            return printf("Ideal, IMC : %.2f\n", i);
        }else if (i<30.0)
        {
            return printf("Sobrepeso, IMC : %.2f\n", i);
        }else if (i<35.0)
        {
            return printf("Obesidade 1, IMC : %.2f\n", i);
        }else if (i<40.0)
        {
            return printf("Obesidade 2, IMC : %.2f\n", i);
        }
        else{
            return printf("obesidade 3, IMC : %.2f\n", i);
        }
        return i;
    }

}
int main() {
    float resultado;
    resultado = calcular_imc(0,1.75);
    resultado = calcular_imc(50.0f,0);
    resultado = calcular_imc(50.0f,1.75f);
    resultado = calcular_imc(65.0f,1.75f);
    resultado = calcular_imc(85.0f,1.75f);
    resultado = calcular_imc(95.0f,1.75f);
    
    
    
}
