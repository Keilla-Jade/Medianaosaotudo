#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <utility>
#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>

double media(int qtd = 10) {
    float soma = 0, media = 0; 
    float n[qtd];  
    
    for (int cont = 0; cont < qtd; cont++) { 
        printf("Digite o %2d valor: ", cont + 1); 
        scanf("%f", &n[cont]); 
        soma += n[cont]; 
    } 
    
    media = soma / qtd; //calcula a media geral 	
    return media;
}

std::pair<double, double> desvioPadrao(double media, int qtd = 10) {
    float variancia = 0, desvPadrao = 0, somaQuad = 0; 
    float n[qtd], desvio[qtd], quadDesvio[qtd]; 
		
    for (int cont = 0; cont < qtd; cont++) { 
        desvio[cont] = n[cont] - media; 
        quadDesvio[cont] = pow(desvio[cont], 2.0); 
        somaQuad += quadDesvio[cont]; 
    } 
    variancia = 1.0 / (10.0 - 1.0) * somaQuad; 
    desvPadrao = sqrt(variancia);	
    
    return {variancia, desvPadrao};
}

int normal_distribution_pdf(double x, double mu = 0, double std_dev = 1) { 
	// os paramentros 'mu' e 'std_dev' tem valores padrões, ou seja, caso o parametro não seja informado, ele irá respeitar o valor padrão;
	
    std::random_device rd{};
    std::mt19937 gen{rd()};
 
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d{mu, std_dev};
 
    std::map<int, int> hist{};
    for(int n = 0; n < 10000; ++n) {
        ++hist[std::round(d(gen))];
    }
    
    for(auto p : hist) {
        std::cout << std::setw(2) << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }		

}

int main() {
	int qtd = 10;
    printf("Digite a quantidade de elementos: ", qtd); 
    scanf("%d", &qtd); 
	
	double _media = media(qtd);
	std::pair<double, double> _desvioPadrao = desvioPadrao(_media, qtd);
	
	printf("\nA media dos valores digitados e        : %f \n", _media); 
    printf("\nA variancia dos valores digitados e	 : %f \n", _desvioPadrao.first); 
    printf("\nO desvio padrao dos valores digitados e: %f \n", _desvioPadrao.second); 
	
	normal_distribution_pdf(0, _media, _desvioPadrao.second);	
}
