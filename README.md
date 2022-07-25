# Trabalhos-Eletronica
Repositório com os trabalhos da disciplina de eletrônica


## Integrantes

| Membros | Número USP |
|:-------------------- |:------|
|Arthur Queiroz Moura|13671532|
|Miguel Prates Ferreira de Lima Catanhede|13672745|
|Amanda Kasat Baltor|13727210|
|Lucas Issao Omati|13673090|

## 1 - Projeto da Fonte

| Lista de componentes | Quantidade | Preço unitário | Preço total|
|:-------------------- |:------|:------|:------|
|LM-317|1|R$3.00||R$3.00|
|Potenciômetro de 10k|1|R$4.00|R$4.00|
|Diodo 1N-4004|4|R$0.10|R$0.40|
|Capacitor Eletrolítico 470uF / 25V|1|R$0.45|R$0.45|
|LED|1|R$0.50|R$0.50|
|Resistor de 1k|8|R$0,10|R$0.80|
|Total|**R$9.15**|

Quanto ao transformador, o do laboratório foi utilizado. Uma protoboard
do laboratório também foi utilizada.

**Imagem do circuito no simulador falstad:**

![simulador](https://i.imgur.com/CEwkDFq.jpg)

**Link do circuito no simulador falstad:**

https://tinyurl.com/25fb49nr

**Projeto do esquemático no EAGLE:**

![eagleschem](https://i.imgur.com/5eDKxFX.jpg)

**Projeto do PCB no EAGLE:**

(imagem)

### Explicação do circuito

**0) Considerações iniciais**

Considerou-se o fornecimento de 110V RMS para um transformador que converteu para 18V RMS.
E, para simular esse comportamento, no simulador Falstad, foi colocada a razão N1/N2 = 18/110 = 0.1636
aproximadamente.

Para entender o circuito, foram utilizados outros circuitos "parciais" mais simples
que ajudam a explicar melhor cada parte.

**1) Fonte alternada, transformador, ponte de diodo e um resistor:**

![Apenas resistor](https://i.imgur.com/x59rjGm.jpg)

(Disponível em https://tinyurl.com/224l2huz)

Esse elemento do circuito mais a esquerda é uma fonte de corrente alternada de 60Hz. Quando 
o associamos ao elemento de circuito a sua direita, um transformador, é possível mudar os 
níveis de tensão com os quais se trabalha.

No caso, essa fonte de corrente alternada representaria uma tomada comum de 110V 
RMS e esse transformador é capaz de _transformar_ esses 110V RMS em 18V RMS. Esse "RMS"
significa root mean square e, quando se diz que algo relacionado a uma fonte de tensão
alternada é x volts RMS, isso significa que a tensão de pico dessa fonte de corrente 
alternada é x vezes raiz de 2. Ou seja, a tensão de pico dessa fonte de 110V RMS é,
na verdade, 110V vezes raiz de 2 = 155,56V. Portanto, ao passar pelo transformador, temos
que a voltagem é dada por uma onda seinodal de pico 18V vezes raiz de 2 = 25,46V.

Depois disso, temos 4 diodos associados ao resto do circuito de uma maneira específica, num
arranjo conhecido como ponte de diodos. Para entender como ele funciona, é necessário
entender primeiro o que um diodo faz. Esse elemento de circuito permite que a corrente
passe em apenas um sentido. Ou seja, caso a voltagem seja aplicada como na imagem a seguir:

![explicacaodiodo](https://www.circuitbasics.com/wp-content/uploads/2020/08/What-is-a-Diode-Diode-in-Forward-Bias-300x177.png)

(disponível em https://www.circuitbasics.com/what-is-a-diode/)

então esse diodo poderá ser tratado como um fio liso. E, caso isso não ocorra, o diodo atuará
como uma chave aberta, isto é, não permitirá a interação entre seus dois terminais. Vale 
ressaltar que, na prática, o que ocorre é que em tensões grandes (quando comparadas ao valor
fixo de 0.7V para o diodo 1N-4004), quando a corrente passa por um diodo, ocorre o 
desconto de 0.7V fixo para o diodo 1N-4004. 

Feita essa breve explicação, é possível agora explicar como funciona uma ponte de diodo.
Então suponha que, em um determinado instante de tempo, o ponto de cima da ponte fique
com uma voltagem maior que o ponto de baixo (em cima um + e em baixo um -), como mostra
a figura:

![explicapontediodo](https://i.imgur.com/uLni5jr.jpg)

Como a função do diodo é não deixar a corrente ir no sentido contrário, então, para que a
corrente consiga ir do (+) para o (-), ela obrigatoriamente deve, inicialmente, passar pelo
diodo do canto superior direito. Depois disso, ela passa pelo resistor e chega no diodo
do canto inferior esquerdo. Analogamente, em um outro instante de tempo em que o (+) e o (-)
estão invertidos (já que a corrente é alternada), a corrente também passará de cima para baixo 
pelo resistor. Ou seja, note que, se do transformador sai uma voltagem alternada cujo gráfico 
é uma onda seinodal, o gráfico da voltagem no resistor seria o "módulo" aplicado
nessa função, como mostram as seguintes imagens:

Gráfico da tensão de entrada produzida pelo transformador e pela fonte de corrente
alternada

![senonormal](https://i.imgur.com/3aPkOew.jpg)

Gráfico da tensão de saída nos terminais do resistor, resultante da interação
da tensão de entrada do gráfico anterior com a ponte de diodo:

![senodiodos](https://i.imgur.com/73I4PcT.jpg)

ou seja, a corrente só passa em um único sentido pelo resistor. **Entretanto**, vale
ressaltar que a voltagem de pico no segundo gráfico seria, na verdade, V_p - 1,4V=25.46V-1.4V=24.06V, uma
vez que, como foi mencionado, para voltagens grandes em comparação com 0.7V, há 
uma queda de 0.7V quando a corrente passa por um diodo e, nesse circuito, a corrente
passa por dois diodos ao mesmo tempo, gerando duas quedas de 0.7V, resultando nos 1.4V.

Ademais, outro aspecto a se notar é que tensões de entrada correspondentes 
a valores próximos de zero no gráfico, por estarem abaixo de 0.7V, não conseguem
passar pelo diodo. Isso resulta na não passagem de corrente pelo resistor, de modo
que por um breve período de tempo a tensão em seus terminais seja nula (o que é confirmado
pelo trecho muito pequeno do gráfico entre cada meia onda). 

Outro ponto importante é que a frequência que antes era de 60Hz na corrente 
alternada agora dobra para 120Hz, pois a diferença entre os instantes de tempo
em que ocorre um pico caiu pela metade. 

Isso conclui
a explicação da primeira parte do circuito.

**2) A adição de um capacitor**

![comcapacitor](https://i.imgur.com/S67Ut1t.jpg)

(Disponível em https://tinyurl.com/2dneh7xk)

Apesar de termos conseguido converter CA em CC (a corrente pelo resistor
só passa em um único sentido), não temos uma fonte que oferece uma 
determinada voltagem constante (a voltagem fica sempre variando de acordo com o gráfico
mostrado para a voltagem no resistor). Um passo nessa direção é utilizar um capacitor
como mostrado no circuito acima, o que faz com que tenhamos um circuito
 genericamente denominado de _Retificador de Onda Completa_. Quando ele
é colocado no circuito, a tensão em seus dois terminais (e, 
consequentemente, nos terminais do resistor de 1000 ohms) vai da 
mostrada nesse primeiro gráfico para a do segundo: 

![filtro](https://www.allaboutcircuits.com/uploads/articles/full-wave-rectified-DC-voltage.jpg)

(Disponível em https://www.allaboutcircuits.com/textbook/experiments/chpt-5/rectifier-filter-circuit/)

Ou seja, a introdução do capacitor no circuito fez com que a variação de voltagem
no resistor fosse diminuída drasticamente. Se antes havia várias meias ondas
variando de 0 até a tensão máxima, agora temos um gráfico em que a tensão varia
muito pouco, principalmente em nosso caso porque a capacitância do capacitor
utilizado é alta (470 micro farads). Essa nova variação de tensão seria o Vpp 
representado pelo seguinte gráfico:

![vpp](https://www.homemade-circuits.com/wp-content/uploads/2015/11/smoothing-2.png)

(Disponível em https://www.homemade-circuits.com/calculating-filter-capacitor-for/)

Essa mudança no gráfico pode ser interpretada como intervalos de tempo em que 
o capacitor carrega e descarrega sucessivamente:

![vppchargedischarge](https://blog.programmablepower.com/hs-fs/hubfs/Imported_Blog_Media/ripple.jpg?width=552&height=240&name=ripple.jpg)

(Disponível em https://blog.programmablepower.com/blog/know-your-power-supply-jargon-ripple)

Então, o Vpp pode ser calculado subtraindo a voltagem de quando o capacitor termina de
carregar pela voltagem em que ele termina de descarregar. Durante esse intervalo de tempo
(no qual o capacitor descarrega), 
por sua vez, observa-se que foi formado um circuito RC, o qual, ao ser equacionado, forma
uma equação diferencial cuja solução é 

![vdet](https://i.imgur.com/pj7EXgw.jpg)

Note que esse tempo de carregamento equivale, aproximadamente, ao tempo entre dois picos 
do gráfico (na verdade, pelo gráfico, é possível ver que é um pouco menor, então isso é uma
aproximação), que é T/2 = 1/(2f) (já que o período é o inverso da frequência). Então, pondo
t = 1/(2f), obtém-se a tensão do capacitor depois de terminar de ser descarregado, que é 
Vmin = Vmax x e^(-1/(2f R C)) em que f=60Hz, R=1000ohms, C=470 micro farads e Vmax = 24.06V. Logo,
Vmin vale aproximadamente 23.64V e Vpp = Vmax - Vmin = 24.06V - 23.64V = 0.42V, que é pequeno
comparado aos 24.06V iniciais.

No entanto, mesmo que tenhamos deixado essa variação bem menor, ela ainda é um valor
perceptível, sendo que queremos uma voltagem constante. 

**Nota:** No simulador, valores ligeiramente diferentes foram obtidos depois que o circuito estabiliza, 
provavelmente por conta da nossa aproximação de que t=T/2. Mas o que importa é que Vpp,
apesar de pequeno, é perceptível e o simulador confirma isso.

**3) Circuito final completo**

Como mostrado no início, aqui estão novamente uma foto e o link para o simulador do circuito final

![simulador](https://i.imgur.com/CEwkDFq.jpg)

https://tinyurl.com/25fb49nr

Mas antes de continuarmos, é preciso, primeiramente, entender como funciona o regulador 
de tensão LM-317. Ele é composto de três pinos: um de ajuste, um de saída e um de 
entrada, como mostra a imagem

![lm317](https://5.imimg.com/data5/JL/MK/MY-8829402/lm317-3-terminal-adjustable-regulator-500x500.jpg)

(Disponível em https://www.indiamart.com/proddetail/lm317-3-terminal-adjustable-regulator-20285661873.html)

A função dele é, basicamente, manter a tensão entre os pinos de ajuste e de saída
de aproximadamente 1.25V (segundo o datasheet) para uma tensão de entrada arbitrária
entre 3V e 30V. A partir desse fato e da imagem a seguir, é possível chegar na 
equação Vout = 1.25V x (1 + R2/R1).

![lm317formula](https://daumemo.com/wp-content/uploads/2020/02/LM317-voltage-source.png)

(Disponível em https://daumemo.com/lm317-voltage-regulator-calculator-voltage-source/)

Além desse componente, é importante também entender o potenciômetro:

![pot](https://i1.wp.com/www.paulobrites.com.br/wp-content/uploads/2017/10/FIG.-3-Potenciometro-ligado-como-reostato-min.jpg?resize=500%2C215)

(Disponível em http://www.squids.com.br/arduino/index.php/hardware/componentes-eletronicos/75-potenciometro)

Basicamente, o potenciômetro seria equivalente a dois resistores em série (cuja 
soma das resistências é constante), mas com um fio saindo do meio deles. Ao girá-lo,
é possível alterar os valores dessas duas resistências, mas sua soma será sempre 
a mesma: 10k ohms. 

Feitas essas explicações, agora é possível descrever a parte final do circuito, que
pode ser representada pelo seguinte desenho

![fim](https://i.imgur.com/9Tg65Qw.jpg)

Primeiramente, ocorre alimentação por um Vin (maior que 3V e menor que 30V) que varia 
conforme o circuito com capacitor (variando aproximadamente entre 23.1V e 22.6V, 
portanto
dentro dessa faixa). Também note que adicionamos um LED para mostrar se o circuito
está funcionando.

Perceba que no desenho foi aplicada a fórmula do LM317 para o cálculo de Vout. Além
disso, note que no numerador da fração foi utilizado R1 + 1kohm, porque, considerando
a presença do potenciômetro, apenas um de seus resistores internos é considerado (R1) e ele
é somado a 1Kohm. Como o potenciômetro é de 10kohm, o R1 pode ser regulado de aproximadamente
50ohms até 9950ohms. Isso faz com que a tensão de saída varie entre 2.3V até 12.2V (que é, 
aproximadamente, o que se pede). No simulador foi colocado um resistor de 1k para representar
o celular.

Como não tínhamos resistores de 1.25k a disposição, fizemos uma associação em série de um 
resistor de 1k com 4 resistores de 1k em paralelo (1k + 1k/4 = 1.25k).


## 2 - Projeto de Arduino - Robô equilibrista
Usando o Arduino UNO e mais alguns componentes, como a MPU6050, desenvolvemos um robô que se equilibra sozinho em apenas duas rodas. A sua principal característica é sua condição naturalmente instável, com dinâmica altamente não-linear.

| Lista de componentes | Preço |
|:-------------------- |:------|
|Arduino UNO|R$85.00|
|Jumper 20cm Macho x Fêmea 40 unidades para protoboard|R$19.98|
|Ponte H L9110S|R$8.93|
|MPU6050 (acelerômetro)|R$19.90|
|(Motor DC 3-6V)x2|(R$13,90)x2=R$27,80|
|(Roda arduíno)x2|(R$13,50)x2=R$27,00|
|Protoboard|R$12,50|
|Total|**R$201,11**|
