#ifndef MANIPULADORXML_H
#define MANIPULADORXML_H

#include <QFile>
#include <QString>
#include <QDomDocument>
#include <QXmlStreamWriter>
#include <QXmlReader>
#include <iostream>

class pessoa{
public:
    QString nome;
    QString cpf;
    QString pis;
    QString dtNascimento;
    QString nomeMae;
    QString recebeSeg;
};

class endereco{
public:
    QString cep;
    QString logradouro;
    QString numero;
    QString complemento;
    QString bairro;
    QString cidade;
    QString uf;
};

class empresa{
public:
    int unidade;
    QString gestor;
};

class funcionario{
public:
    QString departamento;
    QString cargo;
    QString telefone;
    QString dtInicio;
    QString vendParc;
};

class listaEmail{
public:
    bool internosRS;
    bool internosPR;
    bool externosRS;
    bool externosPR;
    bool especialistasRS;
    bool especialistasPR;
    bool filialPOA;
    bool filialCXS;
    bool filialCTA;
    bool filialLND;
    bool filialRGR;
    bool geral;
    bool lideres;
};

class manipuladorXML
{
public:
    manipuladorXML();

    pessoa dadosPessoais;
    endereco dadosEndereco;
    empresa dadosEmpresa;
    funcionario dadosFuncionario;
    listaEmail listas;

    QString b2QS(bool valor);
    // Converte o valor booleano em uma QSTring com valores Sim ou Nao

    void salvaXML(QString nomeDoArquivo);
};



#endif // MANIPULADORXML_H
