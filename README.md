# perceptron
Implementação de um Perceptron com três entradas como atividade extra na matéria Redes Neurais Artificias.

O conjunto de treinamento por padrao deve ser carregado de um arquivo e contem 30 amostras. Ele obedece a formatação:   

%f "1 espaço" %f "1 espaço" %f "1 espaço" %f   
%f "1 espaço" %f "1 espaço" %f "1 espaço" %f   
%f "1 espaço" %f "1 espaço" %f "1 espaço" %f   

Ex:  
    
-1.0000 2.4542 5.6734 -1.0000  
4.2312 2.4322 1.4523 1.0000  
5.8934 -5.8982 3.9821 1.0000  

...  

Sendo as três primeiras colunas o valor de treinamento para as entradas x1, x2 e x3 e a ultima coluna o valor esperado da saída.

No codigo, é atribuido automaticamente o valor -1.0000 a x0 e o peso[0] faz o papel de limiar de ativação, convenção usada para fins de melhorar a facilidade na implementação computacional.
