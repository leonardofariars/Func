#include "manipuladorxml.h"

manipuladorXML::manipuladorXML(){

}

QString manipuladorXML::b2QS(bool valor){
    if (valor) return "Sim";
            else return "Nao";
}

void manipuladorXML::salvaXML(QString nomeDoArquivo){

    QFile arquivo(nomeDoArquivo);
    arquivo.open(QIODevice::WriteOnly);


    QXmlStreamWriter xmlWriter(&arquivo);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("PESSOAL");
        xmlWriter.writeTextElement("nome",dadosPessoais.nome);
        xmlWriter.writeTextElement("cpf",dadosPessoais.cpf);
        xmlWriter.writeTextElement("pis",dadosPessoais.pis);
        xmlWriter.writeTextElement("nascimento",dadosPessoais.dtNascimento);
        xmlWriter.writeTextElement("mae",dadosPessoais.nomeMae);
        xmlWriter.writeTextElement("seguro",dadosPessoais.recebeSeg);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("ENDERECO");
        xmlWriter.writeTextElement("logradouro",dadosEndereco.logradouro);
        xmlWriter.writeTextElement("numero",dadosEndereco.numero);
        xmlWriter.writeTextElement("complemento",dadosEndereco.complemento);
        xmlWriter.writeTextElement("bairro",dadosEndereco.bairro);
        xmlWriter.writeTextElement("municipio",dadosEndereco.cidade);
        xmlWriter.writeTextElement("uf",dadosEndereco.uf);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("EMPRESA");
        xmlWriter.writeTextElement("filial",QString::number(dadosEmpresa.unidade));
        xmlWriter.writeTextElement("gestor",dadosEmpresa.gestor);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("FUNCIONARIO");
        xmlWriter.writeTextElement("cargo",dadosFuncionario.cargo);
        xmlWriter.writeTextElement("departamento",dadosFuncionario.departamento);
        xmlWriter.writeTextElement("telefone",dadosFuncionario.telefone);
        xmlWriter.writeTextElement("dupla",dadosFuncionario.vendParc);
        xmlWriter.writeTextElement("inicio_atividades",dadosFuncionario.dtInicio);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("LISTAS");
        xmlWriter.writeTextElement("especialistasRS",b2QS(listas.especialistasRS));
        xmlWriter.writeTextElement("especialistasPR",b2QS(listas.especialistasPR));
        xmlWriter.writeTextElement("externosRS",b2QS(listas.externosRS));
        xmlWriter.writeTextElement("externosPR",b2QS(listas.externosPR));
        xmlWriter.writeTextElement("internosRS",b2QS(listas.internosRS));
        xmlWriter.writeTextElement("internosPR",b2QS(listas.internosPR));
        xmlWriter.writeTextElement("lideranca",b2QS(listas.lideres));
        xmlWriter.writeTextElement("geral",b2QS(listas.geral));
        xmlWriter.writeTextElement("filialPOA",b2QS(listas.filialPOA));
        xmlWriter.writeTextElement("filialCXS",b2QS(listas.filialCXS));
        xmlWriter.writeTextElement("filialCTA",b2QS(listas.filialCTA));
        xmlWriter.writeTextElement("filialLND",b2QS(listas.filialLND));
        xmlWriter.writeTextElement("filialRGR",b2QS(listas.filialRGR));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();

    arquivo.close();

}
