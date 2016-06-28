/*
* File:   Main.cpp
* Author: Nycholas de Sousa
* Email: nych.sousa@gmail.com
*
* Created on June 21, 2016
*/

#include "Parser.h"

/*
INFOS:
1.  O documento H.222.0 apresenta a especifica��o do pacote TS na p�gina 18;
	da tabela PAT na p�gina 43; e da tabela PMT na p�gina 46.
2.  Corre��es e verifica��es dos valores foram feitos atrav�s do software disponibilizado em:
	http://www.pjdaniel.org.uk/mpeg/.
*/

int main(int argc, char ** argv) {
	//Usando o programa atrav�s de argumentos
	if (argc != 2) {
		std::cerr << "Uso: mpegtsreader.exe <arquivo>" << std::endl;
		return EXIT_FAILURE;
	}

	Parser* tsParser = new Parser(argv[1]);
	//argv[1] = "video.ts";
	//Parser *tsParser = new Parser("C:\\Users\\nycho\\Documents\\GitHub\\mpegtsreader\\Debug\\video.ts");

	//Para evitar erros e devido o append ao abrir o arquivo, o packets.txt antigo sempre ser� deletado ao executar o programa
	remove("packets.txt");

	std::cout << "Comecando a ler o "<< argv[1] << ", aguarde o aviso de que o arquivo foi lido completamente." << std::endl;
	tsParser->readBytes();
	std::cout << "Arquivo lido e packet.txt com as informacoes do pacote TS criado." << std::endl;

	system("pause");
	delete tsParser;
	return 0;
}
