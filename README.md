# Descrição

> Este programa em sua execução realiza operacoes basicas, soma e multiplicao de estruturas matriciais. Nele estao presentes funçoes para alocaçao de memoria, geraçao e preenchimento de todas posiçoes da matriz, liberaçao da memoria, etc. Alem destas operaçoes basicas foram desenvolvidas funçoes para multiplicar e somar os elementos das matrizes de diferentes formas alterando a forma de acesso aos dados. Para isto foram desenvolvidas 2 funçoes de soma e 6 funçoes de multiplicacao a fim de verificar as diferenças nos tempos de execuçao
	

# Compilação

__Importante__

__Este código e demais arquivos auxiliares foram desenvolvidos e executados em sistema operacional linux.__


> Para compilar os códigos é necessário executar o arquivo "Makefile", neste arquivo estão todas as flags e comandos necessários para a compilação da aplicação e bibliotecas auxiliares. Navegar atraves do terminal em sistema operacional linux até o diretório onde se encontram os arquivos ".c", ".h", além do "Makefile" (exemplo: $ cd /home/MM_Lib_GE), basta executar o comando abaixo:

> $ make

> Após execução deste comando os códigos seram compilados e gerados os executáveis e binarios.

> O arquivo "Makefile" compila e gera o executavel responsavel pela geracao de um arquivo onde a matriz e armazenada.

# Execução

> Para executar a aplicação é preciso gerar um ou dois arquivos de entrada, e logo após executar a aplicação principal usando o(s) arquivo(s) de entrada na execuação da aplicação principal. 
 
> Para gerar o arquivo basta executar o comando abaixo:

> $./geraMatriz2 10 10

> O primeiro parametro corresponde ao executavel gerado na compilacao, ja o segundo e o terceiro parametros correspondem as dimensoes da matriz N x M (10 x 10).
> O nome do arquivo segue o padrao adotado pelo professor da disciplina.

	
# Execução

> Para executar a aplicação principal é necessário que os códigos tenham sido compilados anteriormente através da execução do arquivo "Makefile". Uma vez compilados os códigos das aplicaçoes, e gerados os arquivos de entrada basta executar o seguinte comando:

> $ ./main_matriz 10x5-mat.map 5x10-mat.map

> O primeiro parâmetro corresponde ao executável gerado na compilação atraves do arquivo Makefile, o segundo e o terceiro parametros corresponde aos arquivos de entrada onde as matrizes estao armazenadas. 



# Contato

> Quaisquer dúvidas ou problemas favor entrar em contato pelo endereço escobarvasques@gmail.com.

# Autor

> Gabriel Escobar.

# Data
> 29/03/2019.
