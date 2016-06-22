#include <iostream>
#include "Parser.h"

/*
INFOS:
1. O documento H.222.0 apresenta a especifica��o do pacote TS na p�gina 18;
da tabela PAT na p�gina 43; e da tabela PMT na p�gina 46.
2. PMT S� APARECE QUANDO PAT TABLE_ID = 2

TODO:
1. Corrigir erro do program_map_PID/netword_PID da tabela PAT, est� imprimindo um valor incorreto (rever os bytes/bits)
2. Inserir tabela PMT
3. Inserir v�deo como argumento - FEITO, FALTA APENAS RETIRAR OS COMENT�RIOS
4. N�o ficar chamando a fun��o readBytes() direto, fazer um loop
5. Salvar o que for impresso em um arquivo txt, para n�o poluir o console
*/

int main(int argc, char ** argv) {
	/*
	if (argc != 2) {
		std::cerr << "Uso: mpegtsreader <video.extensao>" << std::endl;
		return EXIT_FAILURE;
	}
	*/

	Parser *tsParser = new Parser("C:\\Users\\nycho\\Documents\\GitHub\\mpegtsreader\\Debug\\video.ts");
	//Parser* tsParser = new Parser(argv[1]);

	tsParser->readBytes();
	tsParser->readBytes();
	tsParser->readBytes();

	system("pause");
	delete tsParser;
	return 0;
}
