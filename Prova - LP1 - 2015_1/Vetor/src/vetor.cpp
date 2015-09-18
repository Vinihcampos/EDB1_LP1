#include "vetor.h"
#include <iostream>
#include <algorithm>

namespace MeuVetor {

    Vetor::Vetor( int _iSz, int _iFillVal ) : 
        miSize( _iSz ),
        mpiData( new int[ miSize ] )
    {
        if ( _iSz <= 0 )
            throw std::invalid_argument( "[Vetor::Vetor(int,int)]: Size of Vetor is invalid!" );

        // Initialize with filling value provided.
        for ( int i(0) ; i<miSize ; i++ )
            mpiData[ i ] = _iFillVal; // 
    }

    Vetor::~Vetor()
    {
        delete [ ] mpiData;
    }

    // Copy constructor
    Vetor::Vetor( const Vetor &rhs ) :
        miSize( rhs.miSize ), 
        mpiData( new int[ rhs.miSize ] )
    {
        // copiar elementos da fonte original
        for ( int i(0) ; i<miSize ; ++i )
            this->mpiData[ i ] = rhs.mpiData[ i ];
    }

    void
    Vetor::fill( int val )
    {
        for( int i(0); i<miSize; ++i  )
            mpiData[ i ] = val;
    }

    void
    Vetor::fillN( void )
    {
        for( int i(0); i<miSize; ++i  )
            mpiData[ i ] = i+1;
    }

    void
    Vetor::fillNShuffle( void )
    {
        // Fill Vetor with { 1, 2, 3... N }.
        fillN();

        // Shuffle data
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(mpiData, mpiData + miSize, g);
    }




    // ================================================================================
    //TODO Começa aqui. Implemente os métodos da classe abaixo.

    //! Segundo construtor que recebe um arranjo para inicializar o objeto.
    /*! Cria um Vetor com o tamanho especificado e o preenche com os valores fornecidos
     *  por meio de um arranjo passado como argumento.
     *  Lembre-se que no construtor precisamos alocar nova memória para armazenar os
     *  elementos fornecidos.
     *  Se o tamanho do arranjo for negativo, proceda como no construtor principal
     *  e lançe uma exceção 'invalid_argument()'.
     *  @param _iSz Tamanho do arranjo passado como argumento.
     *  @param _piVals Ponteiro para um arranjo com os dados para preencher o objeto Vetor.
     *  
     *  Exemplo:
     *  int vet[] = { 5, 4, 3, 2, 1 };
     *  Vetor a( 5, vet )
     *  'a' será criado com 5 posições, sendo a:[ mpiData = { 5, 4, 3, 2, 1 }, miSize = 5 ].
     */
    Vetor::Vetor( int _iSz, int * _piVals ) : 
        miSize( _iSz ),
        mpiData( new int[ miSize ] )
    {
        if ( _iSz <= 0 )
            throw std::invalid_argument( "[Vetor::Vetor(int,int)]: Size of Vetor is invalid!" );

        // Initialize with filling value provided.
        for ( int i(0) ; i<miSize ; i++ )
            mpiData[ i ] = _piVals[i]; // 
    }


    //! Modifica o conteudo do vetor em uma posicao especificada.
    /*! Modifica o conteudo do vetor em uma posicao especificada.
     *  Você deve ter o cuidado de garantir que o indice eh válido, ou seja, corresponde
     *  a uma posicao válida dentro do objeto Vetor.
     *
     *  Se o índice for inválido você pode lançar uma exeção assim:
     *  throw std::out_of_range( "Index provided out of valid range!" );
     *
     *  @param _idx Localização do elemento requisitado.
     *  @param _iNewVal Novo valor a ser atribuido na posicao solicitada.
     *  
     *
     *  A forma de uso eh do tipo:
     *  a.assignAt( 0, 3 ); // Atribui o valor 3 na posição zero do Vetor 'a'.
     *  a[0] = 3; 
     */
    void 
    Vetor::assignAt( int _idx, int _iNewVal )
    {
        // TODO
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    int&
    Vetor::operator[]( int _idx )
    {
        if(_idx < 0 || _idx > miSize - 1)
            throw std::out_of_range( "Index provided out of valid range!" );
        else
            return mpiData[_idx];
    }




    //! Retorna o conteudo do vetor em uma posicao especificada.
    /*! Recupera o conteudo do vetor em uma posicao especificada.
     *  Você deve ter o cuidado de garantir que o indice eh válido, ou seja, corresponde
     *  a uma posicao válida dentro do objeto Vetor.
     *
     *  Se o índice for inválido você pode lançar uma exeção assim:
     *  throw std::out_of_range( "Index provided out of valid range!" );
     *
     *  @param _idx Localização do elemento requisitado
     *  @return Retorna o valor do vetor na posição requisitada.
     *
     *  A forma de uso eh do tipo:
     *  int x = a.at( 0 ); // recupera o valor na posição zero do Vetor 'a'.
     *  ou
     *  int x = a[0];
     */
    int
    Vetor::at( int _idx ) const
    {
        // TODO

        // STUB, o codigo abaixo deve ser substituido pelo codigo apropriado.
        return 0;
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    const int
    Vetor::operator[]( int _idx ) const
    {
        if(_idx < 0 || _idx > miSize - 1)
            throw std::out_of_range( "Index provided out of valid range!" );
        else
            return mpiData[_idx];
    }



    //! Verifica se um vetor eh idêntico a outro.
    /*! Verifica se o vetor do lado esquerdo da comparação é igual ao vetor do lado direito da comparação.
     *  Se forem iguais, retorna verdadeiro, caso contrário retorna falso.
     *  @param _rhs Objeto Vetor do lado direito da comparação.
     *  @return true se os vetores forem iguais ou false, caso contrário.
     *
     *  Para um vetor ser considero idêntico ele deve possuir o mesmo tamanho e os mesmos elementos.
     *
     *  A forma de uso eh do tipo:
     *  if ( a.isEqual( b ) )  // Verifica se Vetor 'a' é igual ao Vetor 'b'.
     *  OU
     *  if ( a == b ) 
     */
    bool Vetor::isEqual( const Vetor& _rhs ) const
    {
        // TODO

        // STUB, o codigo abaixo deve ser substituido pelo codigo apropriado.
        return true;
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    bool
    Vetor::operator==( const Vetor& _rhs ) const
    {
        if(miSize != _rhs.miSize){
            return false;
        }else{
            for(auto i(0); i < miSize; ++i){
                if(mpiData[i] != _rhs.mpiData[i]){
                    return false;
                }
            }
        }
        return true;
    }




    //! Atribui um vetor a outro.
    /*! Atribui um vetor a outro, alterando seu tamanho se necessário.
     *  Um cuidado especial deve ser tomado para evitar vazamento de memória.
     *  Se o vetor do lado direito da atribuição possuir o mesmo tamanho do vetor que recebe (lado esquerdo),
     *  não é necessário desalocar/alocar nova memória.
     *  Caso contrário, você deve modificar o tamanho da área de armazenamento do vetor adequadamente.
     *  
     *  @param _rhs Objeto Vetor do lado direito da atribuição.
     *  @return Retorna o próprio objeto modificado ou *this. // só para sobrecarga.
     *
     *  A forma de uso eh do tipo:
     *  a.assign( b ); // Atribui o conteúdo de 'b' para 'a', modificando o tamanho de 'a' se necessário.
     *  OU
     *  a = b;
     */
    void
    Vetor::assign( const Vetor& _rhs ) // a.assign( b );
    {
        // TODO
    }
    // Alternativamente, implemente o metodo abaixo no lugar do de cima.
    const Vetor&
    Vetor::operator=( const Vetor& _rhs )
    {
        // Teste para evitar auto-atribuição, como a = a.
        if ( this != &_rhs )
        {
            if(miSize != _rhs.miSize){
                delete[] mpiData;
                mpiData = new int[_rhs.miSize];
                miSize = _rhs.miSize;
            }
            for(auto i(0); i < miSize; ++i){
                mpiData[i] = _rhs.mpiData[i];
            }  
        }

        return *this;
    }

    
    //! Retorna o menor elemento de um vetor.
    /*! Retorna o menor elemento armazenado no vetor.
     *  @return O valor do menor elemento encontrado.
     */
    int
    Vetor::min( void ) const
    {
        int min = mpiData[0];
        for(auto i(1); i < miSize; ++i){
            if(min < mpiData[i])
                min = mpiData[i];
        }
        return min;
    }

    //! Retorna o maior elemento de um vetor.
    /*! Retorna o maior elemento armazenado no vetor.
     *  @return O valor do maior elemento encontrado.
     */
    int
    Vetor::max( void ) const
    {
        int max = mpiData[0];
        for(auto i(1); i < miSize; ++i){
            if(max < mpiData[i])
                max = mpiData[i];
        }
        return max;
    }

    //! Troca os elementos de dois vetores.
    /*! O método troca os elementos de dois vetores envolvidos na operação.
     *  Se os vetores forem de tamanhos diferentes, a troca deve ser realizada até o
     *  tamanho do menor vetor.
     *
     *  @param _rhs Objeto Vetor que será alvo da troca.
     *
     *  Exemplo:
     *  a = { 4, 5, 6, 7, 1, 2, 8 }, b = { 10, 20, 30 };
     *  Após a.swap( b ), fica
     *  a = { 10, 20, 30, 7, 1, 2, 8 }, b = { 4, 5, 6 };
     */
    void
    Vetor::swap( Vetor & _rhs )
    {
        if(_rhs.miSize > 0){
            auto maxSize = miSize < _rhs.miSize ? miSize : _rhs.miSize;
            for(auto i(0); i < maxSize; ++i){
                auto aux = mpiData[i];
                mpiData[i] = _rhs.mpiData[i];
                _rhs.mpiData[i] = aux;
            }
        }
    }


    //! Retorna a média dos elementos presentes no vetor.
    /*! Retorna a média aritmética simples dos elementos presentes no vetor.
     *  @return A média dos elementos armazenados no vetor.
     *
     *  Exemplo de uso:
     *  cout << "A media eh: " << a.average() << endl;
     */
    float
    Vetor::average( void ) const
    {
        float average = mpiData[0];
        for(auto i(1); i < miSize; ++i){
            average += mpiData[i];
        }
        return average/miSize;
    }


    //! Reverte a ordem dos elementos em um vetor.
    /*! Retorna a ordem interna dos elementos armazenados no vetor.
     *  
     *  Exemplo:
     *  Se a = { 5, 4, 3, 2, 1 }
     *  a.reverse() implica em a = { 1, 2, 3, 4, 5 }.
     */
    void
    Vetor::reverse( void )
    {
        for(auto(i) = 0; i <= miSize/2; ++i){
            auto aux = mpiData[i];
            mpiData[i] = mpiData[miSize - 1 - i];
            mpiData[miSize - 1 - i] = aux;
        }
    }


    //! Altera o tamanho do vetor, mantendo os elementos originais até o novo tamanho.
    /*! Modifica o tamanho original do vetor para o novo tamanho informado.
     *  Se o novo tamanho for MENOR do que o anterior, o método mantém apenas
     *  os elementos que cabem no novo tamanho.
     *  Se o novo tamanho for MAIOR do que o anterior, o método preserva todos
     *  os elementos originais e preencher o restante com zeros.
     *
     *  @param _iNewSz O novo tamanho do vetor.
     *
     *  Cuidado especial deve ser tomado para evitar vazamento de memória.
     *  Você também deve ve/rificar que o tamanho informado é válido, ou seja, maior do que zero.
     *
     *  Se o tamanho for inválido você pode lançar a seguinte exceção assim:
     *  throw std::invalid_argument( "Novo tamanho de vetor invalido!" );
     *  
     *
     *  Exemplo:
     *  Suponha a = [ mpiData = { 1, 2, 3, 4, 5 }, miSize = 5 ]
     *  a.resize( 8 );
     *  O vetor ficaria a = [ mpiData = { 1, 2, 3, 4, 5, 0, 0, 0 }, miSize = 8 ]
     *
     *  E se fizermos a.resize( 3 );
     *  O vetor ficaria a = [ mpiData = { 1, 2, 3 }, miSize = 3 ]
     */
    void
    Vetor::resize( int _iNewSz )
    {
        if(_iNewSz < 1){
            throw std::invalid_argument( "Novo tamanho de vetor invalido!" );            
        }
        else{
            int * auxiliar = new int[_iNewSz];
            for(auto i(0); i < _iNewSz; ++i){
                if(i < miSize)
                    auxiliar[i] = mpiData[i];
                else{
                    auxiliar[i] = 0;
                }
            }
            delete [] this->mpiData;            
            mpiData = new int[_iNewSz];
            miSize = _iNewSz;

            for(auto i(0); i < miSize; ++i){
                mpiData[i] = auxiliar[i];
            }

            delete [] auxiliar;
        }
    }


    //! Preencher o Vetor com os elementos fornecidos via arranjo.
    /*! Modifica o Vetor original alterando seu tamanho (se necessário)
     *  de maneira que seus novos elementos sejam os fornecidos via arranjo.
     *  Cuidado especial deve ser tomado para evitar vazamento de memória
     *  se for necessário fazer ajuste da área de armazenamento.
     *
     *  Você também deve varificar que o tamanho informado é válido, ou seja, maior do que zero.
     *  Se o tamanho for inválido você pode lançar uma exeção assim:
     *  throw std::invalid_argument( "Novo tamanho de vetor invalido!" );
     *
     *  @param _Sz O tamanho do arranjo e o novo tamanho do Vetor.
     *  @param _aiNewVals Arranjo contendo os novos valores para o Vetor.
     *
     *  Exemplo:
     *  Vetor a ( 10 ); // Cria um vetor com 10 zeros. a = [ mpiData = {0,0,0,0,0,0,0,0,0,0}, miSize = 10 ]
     *  int arr[] = { 5, 6, 4, 0, 2 };
     *  a.fill ( 5, arr ) faria
     *  a = [ mpiData = { 5, 6, 4, 0, 2 }, miSize = 5 ]
     */
    void
    Vetor::fill( int _iSz, int _aiNewVals[] )
    {
        if(_iSz < 1){
            throw std::invalid_argument( "Novo tamanho de vetor invalido!" );            
        }else{
            delete[] mpiData;
            mpiData = new int[_iSz];
            miSize = _iSz;

            for(auto i(0); i < miSize; ++i){
                mpiData[i] = _aiNewVals[i];
            }
        }
    }

    //! Elimina elementos repetidos no vetor.
    /*! O método procura eliminar todas as ocorrências de elementos repetidos no Vetor.
     *  @return O número de elementos que restaram no vetor.
     *
     *  Exemplo: a = [ mpiData = { 1, 2, 2, 3, 2, 2, 1 }, miSize = 7 ]
     *  após unique(a) fica, a = [ mpiData = {1, 2, 3 }, miSize = 3 ].
     *
     *  O método também deve ter o cuidado de modificar o tamanho do vetor original,
     *  de maneira que ele tenha o tamanho reduzido se necessário.
     *  O método retorna o número de elementos que restaram no vetor.
     */
    int
    Vetor::unique( void )
    {
        int * aux_v = new int[miSize];
        int index = 0;
        for(auto i(0); i < miSize; ++i){
            bool nao_tem = true;
            for(auto j(0); j < index; ++j){
                if(mpiData[i] == aux_v[j]){
                    nao_tem = false;
                    break;
                }
            }
            if(nao_tem){
                aux_v[index] = mpiData[i];
                ++index;
            }            
        }
        miSize = index;
        delete[] mpiData;
        
        mpiData = aux_v;

        return miSize;
    }

    //! Ordena os elementos no Vetor.
    /*! O método ordena os elementos do Vetor.
     *
     *  Exemplo: a = { 4, 5, 2, 3, 1, 2, 8 },
     *  após a.sort() fica, a = { 1, 2, 2, 3, 4, 5, 8 }.
     */
    void
    Vetor::sort( void )
    {
        std::sort(mpiData, mpiData + miSize);
    }
}

// ==============================[ Fim vetor.cpp ]============================== //