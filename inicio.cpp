//inclui bibliotecas usadas no projeto
#include <iostream>
#include <random>
#include <limits>

//função que retorna quem ganhou o jogo
void mecanismo_jogo(char opcao_jogador)
{
    //cria uma instância da classe random_device que serve para usar a situação do hardware para gerar números aleatórios chamda rd
    std::random_device rd;

    //cria uma instancia da classe mt19937 que contém o algoritimo para gerar números aleatórios
    std::mt19937 gerador_numeros(rd());

    //define a distribuição entre 1 e 3
    std::uniform_int_distribution<> distribuicao(1,3);

    //armazena o número aleatório na variável opcao_pc
    char opcao_pc = distribuicao(gerador_numeros);

    //verifica se houve empate
    if(opcao_jogador == opcao_pc)
    {

        //exibe o resultado na tela caso empate
        std::cout << "Empate!" << std::endl;
    
    }
    else
    {
        switch (opcao_jogador)
        {

            case '1':
                if(opcao_pc == 2)
                {
                    std::cout <<  "Você venceu" << std::endl;
                }
                else
                {
                    std::cout <<  "Você perdeu" << std::endl;
                }
            break;

            case '2':
                if(opcao_pc == 1)
                {
                    std::cout <<  "Você perdeu" << std::endl;
                }
                else
                {
                    std::cout <<  "Você venceu" << std::endl;
                }
            break;

            case '3':
                if(opcao_pc == 2)
                {
                    std::cout <<  "Você venceu" << std::endl;
                }
                else
                {
                    std::cout <<  "Você perdeu" << std::endl;                    
                }
            break;

        }
    }

}

//função incial do projeto
int main()
{

 
        
        //menu
        std::cout << "Escolha:" << std::endl;
        std::cout << "1. Pedra" << std::endl;
        std::cout << "2. Papel" << std::endl;
        std::cout << "3. Tesoura" << std::endl;

        //cria variável e armazena a opcao selecioda pelo jogador
        char escolha_jogador;
        std::cin >> escolha_jogador;

        //veirifica se a entrada não corresponde aos valores 1,2,3 e 4
        if(std::cin.fail() || escolha_jogador < '1' || escolha_jogador > '3')
        {

            //limpa o buffer de entrada
            std::cin.clear();

            //ignora a próxima linha
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //pede para o usuário que digitou uma opção inválida, digite uma opção válida
            std::cout << "Digite uma opção válida" << std::endl;

        }
        else
        {

                mecanismo_jogo(escolha_jogador);

        }

    


}